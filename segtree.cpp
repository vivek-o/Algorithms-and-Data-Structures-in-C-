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

const int N=1e6+9;
int n,a[N],seg[N],pfx[N];

void update(int idx,int val, int x=1,int l=1,int r=n){
    if(l==r){
        seg[x]=a[x]=val;
        return;
    }
    int mid=l+r>>1;
    if(idx<=mid) update(idx,val,2*x,l,mid);
    else update(idx,val,2*x,mid+1,r);

    seg[x]=seg[2*x]+seg[2*x+1];
}

int query(int p,int q,int x=1,int l=1,int r=n){
    if(r<p || l>q) return 0;
    if(r<=q && l>=p) return seg[x];
    int mid=l+r>>1;
    int a=query(p,q,2*x,l,mid);
    int b=query(p,q,2*x+1,mid+1,r);
    return a+b;
}

int32_t main(){
    ios;
    cin>>n;

    F(i,1,n){
        int x;
        cin>>x;
        a[i]=i-x;
        pfx[0]+=abs(x-i);
        if(i<n) con.insert(i-x);
    }

    int cur=0;
    F(i,1,n-1){
        int tol=con.order_of_key(cur--);
        int tmp=a[n-i+1]+i-1;

        pfx[i]=n-1-2*tol+abs(tmp-n+1)-tmp;

        con.insert(a[n-i+1]-n);
        con.erase(con.find_by_order(con.order_of_key(a[n-i])));
    }

    int mn=pfx[0],id=0;
    F(i,1,n){
        pfx[i]+=pfx[i-1];
        if(pfx[i]<mn){
            mn=pfx[i];
            id=i;
        }
    }

    cout<<mn<<" "<<id;
}