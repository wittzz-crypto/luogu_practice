#include<stdio.h>
#include<math.h>
int main(void){
	int a,b,c,t,m,s2;
	char s[10];
	scanf("%d-%d-%d-%s",&a,&b,&c,s);
	if(s[0]=='X')
		s2=10;
	else
		s2=atoi(s);
	t=(a+b/100*2+b%100/10*3+b%10*4+c/10000*5+c%10000/1000*6+c%1000/100*7+c%100/10*8+c%10*9)%11;
	if(t==s2)
		printf("Right");
	else{
		if(t==10)
			printf("%d-%d-%d-X",a,b,c);
		else
			printf("%d-%d-%d-%d",a,b,c,t);
	}
	return 0;
}
