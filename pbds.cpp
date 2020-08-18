#include <bits/stdc++.h>
using namespace std;
///////////////////////////
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<
long long,
null_type,
less_equal<long long>,// _equal for multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
///////////////////////////
#define int long long
#define F(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define R(i,b,a) for(int i=(int)(b);i>=(int)(a);i--)
#define endl "\n"
#define ios std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define out(x) cout<<x<<endl,exit(0);
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define I first
#define S second
    
//find always returns end when less_equal is used
//use this to erase -con.erase(con.find_by_order(con.order_of_key(val))); 
int32_t main(){
    ios;
    ordered_set con;
    con.insert(6);
    con.insert(67);
    con.insert(67);
    
  
/*    con.erase(67);
    for(auto it:con) cout<<it<<" ";
*/

    cout<<con.order_of_key(67);
}