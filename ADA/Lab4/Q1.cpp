#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vvll vector< vll >
#define pll pair<ll ,ll >
#define MOD 1000000007
#define rall(v) v.rbegin(),v.rend()
#define fst first
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define int long long
#define all(v) v.begin(),v.end()
#define scd second
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
 
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
 
#define mst(A) memset( (A) , -1 , sizeof(A) );
 
using namespace std;
 
void read(ll &x,ll &y,ll &z){
	scanf("%lld%lld%lld",&x,&y,&z);
}
void read(ll &x,ll &y,ll &z,ll &w){
	scanf("%lld%lld%lld%lld",&x,&y,&z,&w);
}
void read(ll &x){
	scanf("%lld",&x);
}
void read(ll &x,ll &y){
	scanf("%lld%lld",&x,&y);
}

 
void write(vll &oneD){
	for(ll i=0;i<oneD.size();i++){
		printf("%lld ",oneD[i]);
	}
	printf("\n");
}
void write(vvll &twoD){
	for(ll i=0;i<twoD.size();i++){
		write(twoD[i]);
	}
}
 
void read(vll &oneD){
	for(ll i=0;i<oneD.size();i++){
		read(oneD[i]);
	}
}
void read(vvll &twoD){
	for(ll i=0;i<twoD.size();i++){
		read(twoD[i]);
	}
}
///////////////////////////////
vll howmany(55);
map<pair<int, int>, int> m;
ll solve(int firsti, int num, int numbits){
	if(m.find(make_pair(firsti, num)) != m.end())
	{
		return m[mp(firsti, num)];
	}
	// cout<<firsti<<" "<<numbits<<" "<<num<<"\n";
	int &r = m[mp(firsti, num)];
	if (numbits == 1)
	{
		// cout<<"returning\n";
		return r = num;
	}

	if (firsti <= howmany[numbits-1])
	{
		return r = solve(firsti,num>>1LL,numbits-1);
	}
	else if(firsti == howmany[numbits-1] + 1){
		return r = solve(firsti,num>>1LL,numbits-1) + (int)(num%2 == 1);
	}
	else if(firsti > howmany[numbits-1] + 1){
		// cout<<howmany[numbits-1]<<"\n";
		return r = solve(howmany[numbits-1],num>>1LL,numbits-1) + (int)(num%2 == 1)+ \
		solve(firsti - howmany[numbits-1] - 1,num>>1LL, numbits-1);
	}
}
int countbits(int n){
	int cnt=0;
	while(n>0){
		n = n>>1;
		cnt++;
	}
	return cnt;
}
signed main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int n,l,r;
	cin>>n>>l>>r;
	
	int nbits = countbits(n);
	// cout<<nbits<<"\n";
	
	howmany.resize(nbits+1);
	howmany[0] = 0;
	howmany[1] = 1;

	forab(i,2,nbits,1){
		howmany[i] = 2 * howmany[i-1] + 1;
	}
	// cout<<howmany[50];
	int prefixl,prefixr;

	if (l == 1)
	{
		prefixl =0;
	}
	else{
		prefixl = solve(l-1,n,nbits);
 		}
	
	// cout<<"here";
	prefixr = solve(r,n,nbits);
	// cout<<prefixl<<" "<<prefixr<<"\n";
	ll ans = prefixr - prefixl;

	cout << (ans)<<"\n";
	// cout<<m.size()<<"\n";
	// write(howmany);
}