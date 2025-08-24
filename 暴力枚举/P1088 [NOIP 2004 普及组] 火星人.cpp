#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,m,i,a;
	vector<int> s;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a;
		s.push_back(a);
	}
	do{
		m--;
	}while(next_permutation(s.begin(),s.end()) && m>0);
	for(auto it:s)
		cout<<it<<" ";
	return 0;
}
