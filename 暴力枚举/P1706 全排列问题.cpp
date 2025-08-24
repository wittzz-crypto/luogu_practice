#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,i;
	vector<int> a;
	cin>>n;
	for(i=1;i<=n;i++)
		a.push_back(i);
	do{
		for(auto it:a){
			cout<<setw(5)<<it;
		}
		cout<<endl;
	}while(next_permutation(a.begin(),a.end()));
	return 0;
}
