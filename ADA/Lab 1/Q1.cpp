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
int binsearch(vll &arr, int toFind){
	int low = 0,high = arr.size()-1;
	// int mid = (high-low)/2+ low/2;

	while(low<=high){
		int mid = (high-low)/2+ low;

		if (arr[mid] == toFind)
		{
			return mid;
		}
		else if (arr[mid] < toFind)
		{
			low = mid+1;
		}
		else{
			high = mid -1;
		}
	}

}
signed main(){
	fast;
	int n,q;
	cin>>n>>q;
	vll arr(n);
	forn(i,n){
		cin>>arr[i];
	}
	// forn(i,n){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<"\n";
	for (int i = 0; i < q; ++i)
	{
		int a,b;
		cin>>a>>b;

		int l = binsearch(arr,a);
		int h = binsearch(arr,b);
		// cout<<arr.size();
		// cout<<l<<" "<<h<<"\n";
		int ans = h-l+1;

		cout<<ans<<"\n";
	}
}