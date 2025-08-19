#include<stdio.h>
#include<math.h>
int main(void){
	int n,i,j;
	j=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(;j<=(2*n-i+1)*i/2;j++)
			printf("%02d",j);
		printf("\n");
	}
	return 0;
}
