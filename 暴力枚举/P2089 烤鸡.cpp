#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,i,j,max3,min3,num2;
	int ans=0;
	vector<int> a;
	set<vector<int>> s;
	cin>>n;
	if(n<=9 || n>=31){
		cout<<"0"<<endl;
		return 0;
	}
	max3=(n-10)/2; min3=max(0,n-20);
	for(i=min3;i<=max3;i++){
		num2=n-10-2*i;                 
		a.clear();
		for(j=1;j<=10-num2-i;j++)
			a.push_back(1);
		for(j=1;j<=num2;j++)
			a.push_back(2);
		for(j=1;j<=i;j++)
			a.push_back(3);
		do{
			s.insert(a);
			ans++;
		}while(next_permutation(a.begin(),a.end()));
	}
	cout<<ans<<endl;
	for(auto it:s){
		for(auto it2:it)
			cout<<it2<<" ";
		cout<<endl;
	}
}
