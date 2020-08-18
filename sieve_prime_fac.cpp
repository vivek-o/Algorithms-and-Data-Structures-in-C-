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

const int N=1e7+9;
int pm[N+3];

int main(){
	ios;
	//sieve in Nloglog(N) where N is max(a[i])
	//which stores the smallest prime factor of each no

	F(i,2,N){
		if(!pm[i]){
			pm[i]=i;
			for(int j=i;j<=N;j+=i) pm[j]=i;
		}
	}


	//prime factorisation in O(log n) time per query
	//by recursively dividing each no till it becomes one

	int x=30;
	while(x!=1){
		cout<<pm[x]<<" ";
		while(x%pm[x]==0) x/=pm[x];
	}
}