#include<bits/stdc++.h>
using namespace std;
int main(void){
	long long ans1,ans2=0;
	long long n,m,i,j;
	cin>>n>>m;
	if(n>m)
		swap(n,m);
	ans1=m*(m+1)*n*(n+1)/4;
	ans2=m*n*n-(m+n)*(n-1)*n/2+n*(n-1)*(2*n-1)/6;
	cout<<ans2<<" "<<ans1-ans2;
	return 0;
}
