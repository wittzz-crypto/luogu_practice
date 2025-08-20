#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    char m[12][12];
    int x,y,fx,fy,cx,cy,t=0,it;
    int fdx=-1,fdy=0,cdx=-1,cdy=0;
    for(int i=0;i<=11;i++)
		for(int j=0;j<=11;j++)
			m[i][j]='*';
    for(x=1;x<=10;x++){
        cin>>s;
        for(y=0;y<=9;y++){
            if (s[y]=='.')
                m[x][y+1]='.';
            if (s[y]=='F'){
                fx=x; fy=y+1; m[x][y+1]='.';
            }
            if (s[y]=='C'){
                cx=x; cy=y+1; m[x][y+1]='.';
            }
        }
    }
 /*   for(int i=0;i<=11;i++){
		for(int j=0;j<=11;j++){
			cout<<m[i][j];
		}
		cout<<endl;
	}*/
    while(fx!=cx || fy!=cy){
        t++;
        if( m[ fx+fdx ][ fy+fdy ] == '.'){
        	fx+=fdx; fy+=fdy;
		} else{
			it=fdy; fdy=-fdx; fdx=it;
		}
		if( m[ cx+cdx ][ cy+cdy ] == '.'){
        	cx+=cdx; cy+=cdy;
		} else{
			it=cdy; cdy=-cdx; cdx=it;
		}
		if (t>2000){
			cout<<"0";
			return 0;
		}
    }
    cout<<t;
    return 0;
}