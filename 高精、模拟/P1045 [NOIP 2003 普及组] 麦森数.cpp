#include<bits/stdc++.h>
using namespace std;
vector<int> ans;

void print_num(vector<int> num){
	int j=0;
    for(int i=num.size()-1; i>=0; --i){
		cout<<num[i]; j++;
		if(j%50==0)
			cout<<endl;
	}
}

vector<int> mul(vector<int> n1, vector<int> n2) {
    int size1 = n1.size(), size2 = n2.size();
    vector<int> c(size1+size2, 0);  // 结果数组，最大长度是 n1.size + n2.size

    for(int i=0; i<size1; i++)
        for(int j=0; j<size2; j++) {
            c[i+j] += n1[i] * n2[j];  // 对应位置相乘并累加
            c[i+j+1] += c[i+j] / 10;  // 处理进位
            c[i+j] %= 10;  // 当前位保持在0-9范围
        }
    // 去掉多余的前导零
    while(c.size()>1 && c.back()==0)
        c.pop_back();
    while(c.size()>500)
    	c.pop_back();
    return c;
}

vector<int> fastpow(int b){
	vector<int> res,a;
	res.push_back(1);
	a.push_back(2);
	while(b>0){
		if(b & 1)
			res=mul(res,a);
		a=mul(a,a);
		b>>=1;
	}
	return res;
}

int main(void){
	int p;
	cin>>p;
	cout<<ceil(p*0.30103)<<endl;
	ans=fastpow(p);
	while(ans.size()<500)
		ans.push_back(0);
	ans[0]-=1;
	print_num(ans);
	return 0;
}
