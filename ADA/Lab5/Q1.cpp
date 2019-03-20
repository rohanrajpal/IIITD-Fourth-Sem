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

signed main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int k; string str;

	cin>>k>>str;

	// int count[26];
	// mst(count);
	vll count(26,0);
	int lenstr= str.length();
	// cout<<lenstr<<"\n";
	for (int i = 0; i < (lenstr); ++i)
	{
		count[str[i]-'a']++;
	}
	int altk=0;
	bool firstodd= true;
	for (int i = 0; i < 26; ++i)
	{
		// cout<<('a'+i)<<" is"<<count[i]<<"\n";
		if (count[i]%2 != 0 && firstodd)
		{
			firstodd=false;
			// altk+=1;
		}else if (count[i]%2 != 0 && !firstodd)
		{
			altk+=1;
		}
	}
	bool ans= false;
	// cout<<k<<" "<<lenstr<<"\n";
	if (k - altk > 0 && k<=lenstr)
	{
		ans = true;
	}

	if (ans)
	{
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	cout<<"\n";
	// cout<<k<<str;

}