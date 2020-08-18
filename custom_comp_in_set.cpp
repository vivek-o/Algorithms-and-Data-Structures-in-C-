#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define R(i,b,a) for(int i=(int)(b);i>=(int)(a);i--)
#define endl "\n"
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define out(x) cout<<x<<endl,exit(0);
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define I first
#define S second

struct cmp{
	bool operator()(const pii a,const pii b)const{
		if(a.I==b.I) return a.S<b.S;
		return a.I>b.I;
	}
};
int32_t main(){
    ios;
    
    set <pii,cmp> con={{2,6},{1,5}};

    for(auto it:con){
    	cout<<it.I<<" "<<it.S<<endl;
    }
}