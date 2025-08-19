#include<stdio.h>
#include<math.h>
int n,x1,x2;
int main(void){
	scanf("%d",&n);
	x1=(n%2==0);
	x2=(n>4&&n<=12);
	printf("%d %d %d %d",x1&&x2,x1||x2,(x1&&!x2)||(!x1&&x2),!x1&&!x2);
	return 0;
}
