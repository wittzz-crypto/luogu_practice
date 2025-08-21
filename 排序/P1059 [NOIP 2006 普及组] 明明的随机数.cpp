#include<bits/stdc++.h>
using namespace std;
int main(void){
	set<int> s;
	int n,a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		s.insert(a);
	}
	cout<<s.size()<<endl;
	for(auto i:s)
		cout<<i<<" ";
	return 0;
}