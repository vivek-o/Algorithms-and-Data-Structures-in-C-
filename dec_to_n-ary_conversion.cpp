
//base n ; can be negative
//decimal x;

vector <int> v;
while(x){
	int r=x%n;
	x/=n;
	if(r<0) r+=n,x++;
	v.pb(r);
}