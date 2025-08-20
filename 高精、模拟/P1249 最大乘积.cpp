#include <bits/stdc++.h>
using namespace std;
long long n,ans[100001]={0,1},len=1;
bool f[100001];

void mul(int x){
	int cnt=0;
	for (int i=1;i<=len;i++){
		ans[i]*=x;
		ans[i]+=cnt;
		cnt=0;
		if (ans[i]>=10){
			cnt=ans[i]/10;
			ans[i]%=10;
		}
	}
	ans[len+1]+=cnt;
	while (ans[len+1]!=0){
		len++;
		ans[len+1]+=(ans[len]/10);
		ans[len]%=10;
	}
}

int main(){
	cin>>n;
	if (n<=4){
		cout<<n<<"\n"<<n;
		return 0;
	}
	long long now=n,i;
	for (i=2;i<=now;i++){
		f[i]=true;
		now-=i;
	}
	f[i]=true; now-=i;
	if (now==-1){
		f[2]=false;
		f[i]=false;
		f[i+1]=true;
	}
	else{
		f[-now]=false;
	}
	for (int j=2;j<=i+1;j++){
		if (f[j]){
			cout<<j<<" ";
			mul(j);
		}
	}
	cout<<endl;
	for (i=len;i>=1;i--){
		cout<<ans[i];
	}
    return 0;
}
