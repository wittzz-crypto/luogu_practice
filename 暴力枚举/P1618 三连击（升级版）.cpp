#include<bits/stdc++.h>
using namespace std;
bool testre(int x1,int y1,int z1){
	int a1[10]={0};
	int n=x1*1000000+y1*1000+z1;
	while(n>0){
		if(a1[n%10]==1)
			return false;
		a1[n%10]=1;
		n/=10;
	}
	if(a1[0]==1)
		return false;
	return true;
}
int main(void){
	int x,y,z,a,b,c,m;
	int i,flag=0;
	cin>>a>>b>>c;
	if(a==0){
		cout<<"No!!!";
		return 0;		
	}
/*	if(a==123 && b==456 && c==789){
		cout<<"123 456 789";
		return 0;
	}*/
	for(i=max(1,ceil(100/a));i<=floor(999/c);i++){
		x=i*a; y=i*b; z=i*c;
		if(testre(x,y,z)){
			cout<<x<<" "<<y<<" "<<z<<endl;
			flag=1;
		}
	}
	if(flag==0)
		cout<<"No!!!";
	return 0;
}
