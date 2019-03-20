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

signed main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    int arr[n];

    forn(i,n){
    	cin>>arr[i];
    }

    // forn(i,n){
    // 	cout<<arr[i]<<" ";
    // }
    // cout<<"\n";

    int maxsum=0;

    forn(i,pow(2,n)){
    	bitset<20> bset1(i);
    	
    	int temSum=0;
    	if ((i &(i>>1)) != 0)
    	{
    		// cout<<bset1<<"\n";
    		continue;
    	}
    	else{
    		
    		forn(j,n){
    			if (bset1.test(j))
    			{
    				temSum += arr[j];
    			}
    		}
    	}

    	if(maxsum < temSum){
    		maxsum = temSum;
    	}
    }

    cout<<maxsum<<"\n";

    #ifndef ONLINE_JUDGE
    cout<<"\nTime taken: " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
	#endif
}