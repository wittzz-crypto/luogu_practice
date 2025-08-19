#include<stdio.h>
#include<math.h>
int main(void){
	int n,m,i,m1;
	int a,b;
	scanf("%d",&n);
	scanf("%d",&b);
	m1=1;m=1;
	for(i=1;i<=n-1;i++){
		scanf("%d",&a);
		if(a==b+1)	
			m1++;
		else{			
			if(m1>m) m=m1;
			m1=1;
		}
		b=a;
	}
	if(m1>m) m=m1;
	printf("%d",m);
	return 0;
}