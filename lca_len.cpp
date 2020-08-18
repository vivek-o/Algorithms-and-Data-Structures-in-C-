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

const int N=1e5+7,lg=17;
int dep[N],prt[N][lg+1];
vector <int> v[N];

void dfs(int ver,int par){
	dep[ver]=dep[par]+1;

	prt[ver][0]=par;
	F(i,1,lg){
		prt[ver][i]=prt[prt[ver][i-1]][i-1];
	}

	for(auto it:v[ver]){
		if(it==p) continue;
		dfs(it,ver);
	}
}

int lca_dis(int p,int q){
	int dis=0;

	if(dep[p]<dep[q]) swap(p,q);

	for(int i=lg;i>=0;i--){
		if(dep[p]-(1<<i)>=dep[q]){
			p=prt[p][i];
			dis+=(1<<i);
		}
	}
	if(p==q) return dis;

	for(int i=lg;i>=0;i--){
		if(prt[p][i]!=prt[q][i]){
			p=prt[p][i];
			q=prt[q][i];
			dis+=(1<<i)*2;
		}
	}
	//return prt[p][0] for lca
	return dis+2;
}

int main(){
	ios;
	int n,x,y,a,b,k,d1,d2;
	cin>>n;

	F(i,1,n-1){
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1,0);
	
	int q;
	cin>>q;
	while(q--){
		cin>>x>>y>>a>>b>>k;

		d1=lca_dis(a,b);
		d2=min(lca_dis(a,x)+lca_dis(y,b),lca_dis(a,y)+lca_dis(x,b))+1;

		if((d1%2==k%2 && d1<=k) || (d2%2==k%2 && d2<=k)) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}