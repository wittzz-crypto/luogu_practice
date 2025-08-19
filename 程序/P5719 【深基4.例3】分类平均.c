#include<stdio.h>
#include<math.h>
int k,n,i;
float ave1,ave2;
float m,k1,n1,i1;
int main(void){
	scanf("%d %d",&n,&k);
	i=n;
	while(i>0&&i%k!=0)
		i--;
	k1=k;n1=n;i1=i;
	if(i<k){
		ave1=0;
		ave2=(n1+1)/2;
	}
	else{
		ave1=(k1+i1)/2;
		m=(i1-k1)/k1+1;
		ave2=((n1+1)*n1/2-ave1*m)/(n1-m);
	}
	printf("%0.1f %0.1f",ave1,ave2);
	return 0;
}