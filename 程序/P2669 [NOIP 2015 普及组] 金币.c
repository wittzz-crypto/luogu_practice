#include<stdio.h>
#include<math.h>
int main(void){
	int n,i,sum;
	scanf("%d",&n);
	i=1;
	while((i+1)*i/2<=n)
		i++;
	sum=i*(i-1)*(2*i-1)/6+(n-i*(i-1)/2)*i;
	printf("%d",sum);
	return 0;
}
