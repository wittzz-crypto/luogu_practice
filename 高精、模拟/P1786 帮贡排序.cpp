#include<bits/stdc++.h>
using namespace std;
int main(void){
	// 原来用的容器（做了最小改动）
	// multimap<int,string,greater<int>> bg; // 改为 vector 并在读完后排序，保证等帮贡时按输入顺序
	unordered_map<string,int> dj;
	// multimap<int,string,greater<int>> fbz; // 副帮主要保留输入顺序，改为 vector
	vector<pair<int,string>> fbz; // 存 {level, name}，按读入顺序输出

	vector<tuple<int,string,int>> bg; // 存 {bg1, name, id}，读完后排序（帮贡降序，id升序）

	int a[4]={2,4,7,25};
	string tx[4]={"HuFa","ZhangLao","TangZhu","JingYing"}; // 去掉多余空格
	string m,z,bz;
	int bg1,dj1,n,bzdj,num;
	cin>>n;
	int idcnt = 0; // 记录输入序
	for(int i=1;i<=n;i++){
		idcnt++;
		cin>>m>>z>>bg1>>dj1;
		if(z=="BangZhu"){
			bz=m;
			bzdj=dj1;
		}
		else if(z=="FuBangZhu"){
			// 保持输入顺序，直接 push 到 vector
			fbz.push_back({dj1,m});
		}
		else{
			// 非帮主/副帮主，放入 bg 向量，记录输入序 idcnt
			bg.push_back(make_tuple(bg1,m,idcnt));
			dj.insert({m,dj1});
		}
	}

	// 输出帮主与副帮主（按输入顺序）
	cout<<bz<<" BangZhu "<<bzdj<<endl;
	for(auto &p: fbz)
		cout<<p.second<<" FuBangZhu "<<p.first<<endl;

	// 对 bg 排序：按帮贡降序；帮贡相同按输入序（id）升序（即先输入的在前）
	stable_sort(bg.begin(), bg.end(), [](const tuple<int,string,int> &A, const tuple<int,string,int> &B){
		if (get<0>(A) != get<0>(B)) return get<0>(A) > get<0>(B);
		return get<2>(A) < get<2>(B);
	});

	// 剩余人数
	int rem = (int)bg.size();
	int j=0;

	int cur = 0; // bg 的当前索引
	while(rem>0 && j<=3){
		num=min(a[j],rem);
		// 选出 num 人，放到临时 vector (用于按等级排序)
		vector<tuple<int,int,string>> group; // {level, id, name}
		for(int i=0;i<num;i++){
			// 取 bg[cur]
			string name = get<1>(bg[cur]);
			int id = get<2>(bg[cur]);
			int level = dj[name];
			group.push_back(make_tuple(level, id, name));
			cur++;
		}
		// 组内按等级降序，等级相同按输入序（id）升序
		stable_sort(group.begin(), group.end(), [](const tuple<int,int,string> &A, const tuple<int,int,string> &B){
			if (get<0>(A) != get<0>(B)) return get<0>(A) > get<0>(B);
			return get<1>(A) < get<1>(B);
		});
		// 输出这一组
		for(auto &t: group){
			cout<< get<2>(t) <<" "<< tx[j] <<" "<< get<0>(t) <<endl;
		}
		rem -= num; j++;
	}
	// 剩余的人（如果还有）都为 BangZhong
	if(rem>0){
		vector<tuple<int,int,string>> group;
		for(int i=0;i<rem;i++){
			string name = get<1>(bg[cur]);
			int id = get<2>(bg[cur]);
			int level = dj[name];
			group.push_back(make_tuple(level, id, name));
			cur++;
		}
		// 同样按等级降序，等级相同按输入序
		stable_sort(group.begin(), group.end(), [](const tuple<int,int,string> &A, const tuple<int,int,string> &B){
			if (get<0>(A) != get<0>(B)) return get<0>(A) > get<0>(B);
			return get<1>(A) < get<1>(B);
		});
		for(auto &t: group)
			cout<< get<2>(t) <<" BangZhong "<< get<0>(t) <<endl;
	}
	return 0;
}
