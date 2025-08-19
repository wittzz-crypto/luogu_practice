#include<stdio.h>
#include<math.h>
float s,v;
int h,m,t;
int main(void){
	scanf("%d %d",&s,&v);
	t=ceil(s/v)+10;
	int y=60*32-t;
	h=(y/60)%24;
	m=y%60;
	printf("%02d:%02d",h,m);
	return 0;
}
