#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,m,i,j,gj,sj1,jq1,et=0,st,flag;
	int jg[401];
	int tl[21][10000]={0};
	int jq[21][21],sj[21][21],gx[21],gjsj[21]={0};
	fill(&gx[0],&gx[21],1);
	cin>>m>>n;
	for(i=1;i<=n*m;i++)
		cin>>jg[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>jq[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>sj[i][j];
	for(i=1;i<=n*m;i++){
		gj=jg[ i ]; sj1=sj[ gj ][ gx[gj] ]; jq1=jq[ gj ][ gx[gj] ];
		j=gjsj[gj]+1; flag=1;
		while(flag==1){
			if(tl[jq1][j]==0){
				st=j;
				while(tl[jq1][j]==0 && j-st<sj1)
					j++;
				if(j-st>=sj1){
					flag=0;
					fill(&tl[jq1][st],&tl[jq1][j],1);
					gx[gj]+=1; gjsj[gj]=j-1;
					et=max(j-1,et);
				}
			}
			else
				j++;
		}
	}
	cout<<et;
	return 0;
}
