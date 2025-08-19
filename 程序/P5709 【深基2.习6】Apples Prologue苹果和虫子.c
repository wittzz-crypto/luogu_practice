#include<stdio.h>
#include<math.h>
int main(void){
	int t,m,s,n;
	scanf("%d %d %d",&m,&t,&s);
	if(t==0)
		printf("0");
	else{
		if(s%t==0)
			n=m-s/t;
		else	
			n=m-s/t-1;
		printf("%d",(int)fmax(n,0));
	}
	return 0;
}
