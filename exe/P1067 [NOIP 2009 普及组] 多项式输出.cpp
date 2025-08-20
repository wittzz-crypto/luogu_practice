#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,i;
	int a[101];
	cin>>n;
	for(i=n;i>=0;i--){
		cin>>a[i];
	}
	while(a[n]==0 && n>0)
		n--;
	if(n>=2){
		if(a[n]==-1)
			cout<<"-x^"<<n;
		else {
			if(a[n]==1)
				printf("x^%d",n);
			else
				printf("%dx^%d",a[n],n);
		}
		for(i=n-1;i>=2;i--)
			if(a[i]!=0){
				if(a[i]==-1)
					cout<<"-x^"<<i;
				else {
					if(a[i]==1)
						printf("+x^%d",i);
					else
						printf("%+dx^%d",a[i],i);
				}
			}
		if(a[1]!=0){
			if(a[1]==1)
				printf("+x");
			else {
				if(a[1]==-1)
					printf("-x");
				else
					printf("%+dx",a[1]);
			}
		}
		if(a[0]!=0)
			printf("%+d",a[0]);
	}
	if(n==1){
		if(a[1]==1)
			printf("+x");
		else {
			if(a[1]==-1)
				printf("-x");
			else
				printf("%+dx",a[1]);
		}
		if(a[0]!=0)
			printf("%+d",a[0]);
	}
	if(n==0) printf("%d",a[0]);
	return 0;
}
