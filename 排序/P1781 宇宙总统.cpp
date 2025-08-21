#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> n1,vector<int> n2){
	if(n1.size()!=n2.size()) return n1.size()>n2.size();
	else return n1>n2;
}
string s;
vector<int> m,x;
int i,j,n,maxn;
int main(void){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>s;
		x.clear();
		for(j=0;j<s.size();j++)
			x.push_back(s[j]-'0');
		if(cmp(x,m)){
			m=x;
			maxn=i;
		}
	}
	cout<<maxn<<endl;
	for(auto it:m)
		cout<<it;
	return 0;
}
