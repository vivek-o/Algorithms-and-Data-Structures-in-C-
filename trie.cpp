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

struct Node{
	Node* child[2];
	int cnt;
	Node(): cnt(0){
		child[0]=child[1]=nullptr;
	}
};

Node* root;

void insert(int x){
	Node* cur=root;
	R(j,30,0){
		cur->cnt++;
		int idx=(((1ll<<j)&x)?1:0);
		if(!cur->child[idx]) cur->child[idx]=new Node;
		cur=cur->child[idx];
	}
	cur->cnt++;
}

int query(int x){
	Node* cur=root;
	int res=0;
	R(j,30,0){
		cur->cnt--;
		int idx=(((1ll<<j)&x)?1:0),f=0;
		if(!cur->child[idx] || cur->child[idx]->cnt==0) idx^=1,f=1;

		res+=(1ll<<j)*f;
		cur=cur->child[idx];
	}
	cur->cnt--;
	return res;
}

int32_t main(){
    ios;
    root=new Node;
    int n;
    cin>>n;

    vector <int> v;
    F(i,1,n){
    	int x;
    	cin>>x;
    	v.pb(x);
    }

    F(i,1,n){
    	int x;
    	cin>>x;
    	insert(x);
    }

   	for(auto it:v) cout<<query(it)<<" ";
}