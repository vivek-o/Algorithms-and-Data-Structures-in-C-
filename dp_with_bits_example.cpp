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

const int N=55;
bool dp[N][N];
ll sum[N][N],a[N],ans;

int main(){
	ios;
	ll n,k;
	cin>>n>>k;

	F(i,1,n) cin>>a[i];

	F(i,1,n){
		F(j,1,n){
			ll tmp=0;
			F(l,i,j) tmp+=a[l];
			sum[i][j]=tmp;
		}
	}

	for(int lg=60;lg>=0;lg--){
		ll tmp=ans+(1ll<<lg);

		memset(dp,false,sizeof dp);
		dp[0][0]=true;
		
		F(i,1,n){
			F(j,1,k){
				F(l,1,i){
					if(dp[i-l][j-1] && (sum[i-l+1][i]&tmp)==tmp){
						dp[i][j]=true;
						break;
					}
				}
			}
		}
		if(dp[n][k]) ans+=(1ll<<lg);
	}
	cout<<ans;
}