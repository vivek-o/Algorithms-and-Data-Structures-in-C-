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

int main(){
	ios;

	string s;
	cin>>s;

	int lps[s.size()+4];
	lps[0]=0;

	int i=1,len=0;
	while(i<s.size()){
		if(s[i]==s[len]) lps[i++]=++len;
		else{
			if(len!=0) len=lps[len-1];
			else lps[i++]=0;
		}
	}

	cout<<lps[s.size()-1];

}