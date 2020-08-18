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

const int N=2e5+9;
int bt[N];

void update(ll x,ll del){
	for(;x<=n;x+=x&-x) bt[x]+=del;
}

ll qry(ll x){
	ll sum=0;
	for(;x>0;x-=x&-x) sum+=bt[x];
	return sum;
}

int main(){
	ios;

}