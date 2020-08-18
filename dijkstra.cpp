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

const int N=3e5+9;
vector <pll> v[N];
ll dis[N],vis[N];

int main(){
	ios;
	ll n,m,x,y,w;
	cin>>n>>m;

	F(i,1,m){
		cin>>x>>y>>w;
		v[x].pb({w,y});
		v[y].pb({w,x});
	}

	//simpler version of dijkstra

	ll source=1;
	set <pll> con;
	con.insert({0,source});

	while(!con.empty()){
		pll p=*con.begin();
		w=p.I;
		y=p.S;
		con.erase(con.begin());

		if(vis[y]) continue;
		dis[y]=w;
		vis[y]=1;
		for(auto it:v[y]){
			con.insert({it.I+w,it.S});
		}
	}

	F(i,1,n) cout<<dis[i]<<" ";
}