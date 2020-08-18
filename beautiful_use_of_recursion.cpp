#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define F(i,a,b) for(int i=int(a);i<=int(b);i++)
#define endl "\n"
#define ios std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define out(x) cout<<x<<endl,exit(0);
#define pb push_back
#define all(v) v.begin(),v.end()
#define I first
#define S second

ll fac[25],cnt[10],now[10],ans;

//recursion to build the various arrays
// and using combinatorics on those arrays

void slv(int cur=0){
	if(cur==10){
		ll tl=0;
		F(i,1,9) tl+=now[i];

		tl*=fac[tl-1+now[0]];			//a1=tl!/(i!j!k!..)										
		F(i,0,9) tl/=fac[now[i]];		//a2=(tl-1+cnt(zero)!)/((tl-1)!*cnt(zero)!)
										//firstly arranging non zero digits
		ans+=tl;						//then keeping one non-zero digit in the beginnning and arranging all other digits and the zeroes
		return;
	}
	if(cnt[cur]==0){
		now[cur]=0;
		slv(cur+1);
	}
	for(int i=cnt[cur];i>0;i--){
		now[cur]=i;
		slv(cur+1);
	}
}
int main(){
	ios;
	string s;
	cin>>s;

	for(auto it:s) cnt[it-'0']++;

	fac[0]=1;
	F(i,1,20) fac[i]=fac[i-1]*i;

	slv();
	cout<<ans;
}