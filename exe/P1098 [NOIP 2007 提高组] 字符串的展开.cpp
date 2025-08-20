#include<bits/stdc++.h>
using namespace std;
int main(void){
	int x,y,z,s,i,j,k,n,m,l;
	string a;
	cin>>x>>y>>z;
	cin>>a;
		s=a.length();
		for(i=0;i<s;i++){
			if(a[i]=='-'){
				l=0;
				n=a[i-1]; m=a[i+1];
				if(n>='0' && n<='9' && m>='0' && m<='9' && a[i-1]<a[i+1]){
					l=1;
					if(x<=2)
						for(j=1;j<=m-n-1;j++)
							for(k=1;k<=y;k++)
								if(z==1) cout<<(char)(n+j);
								else cout<<(char)(m-j);
					else
						for(k=1;k<=(m-n-1)*y;k++) cout<<"*";
				}
				if(n>='a' && n<='z' && m>='a' && m<='z' && a[i-1]<a[i+1]){
					l=1;
					if(x<=2){
						if(x==2){
							n-=32; m-=32;
						}
						for(j=1;j<=m-n-1;j++)
							for(k=1;k<=y;k++)
								if(z==1) cout<<(char)(n+j);
								else cout<<(char)(m-j);						
					}
					else
						for(k=1;k<=(m-n-1)*y;k++) cout<<"*";
				}
				if(l==0) cout<<"-";
			}
			else cout<<a[i];
		}
	return 0;
}
