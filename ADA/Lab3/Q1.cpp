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

int invcount = 0;
vii finalarr;

void mergefn(vii &arr,int low,int mid,int high);
void create_temp_then_sort(int n){
	finalarr.clear();
	finalarr.resize(n);
}
void mergesort(vii &arr, int low,int high){
	if (low<high)
	{
		int mid = (high-low)/2 + low;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		mergefn(arr,low,mid+1,high);
	}
}
void mergefn(vii &arr,int low,int mid,int high){
	int i=low,j=mid,k=low;

	while(i< mid && j <= high){
		if (arr[i]<=arr[j])
		{
			finalarr[k++] = arr[i++];
		}
		else{
			invcount += mid - i;
			finalarr[k++] = arr[j++];
		}
	}

	while(i<mid){
		finalarr[k++] = arr[i++];
	}
	while(j<=high){
		finalarr[k++] = arr[j++];
	}
	// k=low;

	forab(r,low,high,1){
		arr[r]=finalarr[r];
	}
	// arr = finalarr;
}
signed main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int t,n;
	cin>>t;
	forn(r,t){
		invcount = 0;
		cin>>n;
		vii arr(n);
		forn(i,n){
			cin>>arr[i];
		}
		create_temp_then_sort(n);
		mergesort(arr,0,n-1);
		// forn(i,n){
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<"\n";
		cout<<invcount<<"\n";	
	}
	
	#ifndef ONLINE_JUDGE
    cout<<"\nTime taken: " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
	#endif
}