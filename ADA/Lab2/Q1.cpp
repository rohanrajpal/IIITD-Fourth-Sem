#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vii vector<int>
#define vvll vector< vll >
#define pll pair<ll ,ll >
#define MOD 1000000007
#define rall(v) v.rbegin(),v.rend()
#define fst first
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define int long long

#define all(v) v.begin(),v.end()
#define scd second
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
 
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
 
#define mst(A) memset( (A) , 0 , sizeof(A) );
 
using namespace std;
int gbsteps = 0;

int solve(int n){
	if (n == 1)
	{
		return 0;
	}

	gbsteps +=1 ;
	if (n &1)
	{
		solve(3*n +1);
	}
	else{
		solve(n/2);
	}
}
signed main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t,n;
    cin>>t;
    forn(i,t){
    	cin>>n;
    	gbsteps = 0;
    	solve(n);
    	cout<<gbsteps<<"\n";
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime taken: " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
	#endif
}