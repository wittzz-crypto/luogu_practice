#include<bits/stdc++.h>
using namespace std;
struct stu{
	int yw,zf,bh;
}a[301];
bool cmp(stu x,stu y){
	if(x.zf!=y.zf) return x.zf>y.zf;
	if(x.yw!=y.yw) return x.yw>y.yw;
	else return x.bh<y.bh;
}
int main(void){
	int n,i,sx,yy;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].yw>>sx>>yy;
		a[i].bh=i;
		a[i].zf=a[i].yw+sx+yy;
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=min(n,5);i++)
		cout<<a[i].bh<<" "<<a[i].zf<<endl;
	return 0;
}
