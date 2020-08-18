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

const int N=3e5+7;
vector <int> v[N];
int vis[N],deg[N];

//if the graph has cycle topological ordering is not possible
void dfs(int x){
	vis[x]=1;
	for(auto it:v[x]){
		if(vis[it]==1) out(-1);
		if(vis[it]==2) continue;
		else dfs(it);
	}
	vis[x]=2;
}

int main(){
	ios;
	int n,m,x,y;
	cin>>n>>m;

	F(i,1,m){
		cin>>x>>y;
		deg[y]++;
		v[x].pb(y);
	}

	queue <int> q;
	F(i,1,n){
		if(vis[i]==0) dfs(i);
		if(deg[i]==0) q.push(i);
	}

	while(!q.empty()){
		int p=q.front();
		q.pop();
		cout<<p<<" "; // printing in topological order
		for(auto it:v[p]){
			deg[it]--;
			if(deg[it]==0) q.push(it);
		}
	}
}