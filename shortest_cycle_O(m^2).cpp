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

int32_t main(){
    ios;
    int n,ans=1e9;
    cin>>n;

    F(i,1,n){
        int dis[n+2]={0},par[n+2]={0};

        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int p=q.front();
            q.pop();

            for(auto it:v[p]){
                if(dis[it]==0 && it!=i){
                    dis[it]=dis[p]+1;
                    q.push(it);
                    par[it]=p;
                }
                else if(par[p]!=it && par[it]!=p){
                    ans=min(ans,dis[p]+dis[it]+1);
                }
            }
        }
    }

    if(ans==inf) cout<<-1;
    else cout<<ans;
}  