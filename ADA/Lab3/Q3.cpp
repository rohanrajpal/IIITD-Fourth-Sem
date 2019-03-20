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
int memo[1005][1005];
int disjointset[100005];
int root(int arr[],int i){
	while(arr[i] != i){
		arr[i] = arr[arr[i]];
		// cout<<"infrec";
		i = arr[i];
	}
	return i;
}

int diff(int a,int b){
	// cout<<"here";
	if (root(disjointset,b) == root(disjointset,a))
	{
		// cout<<"Equal: "<<a<<" "<<b<<"\n";
		return 2;
	}
	else{
		// cout<<a<<" and "<<b<<" are not equal \n";
		return 0;
	}
}
int solve(int arr[],int low,int high){
	if (memo[low][high] != -1)
	{
		return memo[low][high];
	}
	if (low > high)
	{
		return 0;
	}
	else if (low == high)
	{
		return 1;
	}
	else{
		int ans =  max(max(solve(arr,low,high-1),solve(arr,low+1,high)),solve(arr,low+1,high-1)+diff(arr[low],arr[high]));
		// cout<<"reaching to the answer "<<ans<<" with string: ";
		// forab(i,low,high,1){
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<"\n";
		memo[low][high] = ans;
		return ans;
	}
}


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int n,k,m;
	mst(disjointset);
	mst(memo);
	cin>>n>>k>>m;
	forn(i,n+1){
		disjointset[i] = i;
	}
	for (int i = 0; i < k; ++i)
	{
		int a,b;
		cin>>a>>b;
		// disjointset[b] = disjointset[a];
		disjointset[root(disjointset,b)] = root(disjointset,a);
		// if (root(disjointset,b) == root(disjointset,a))
		// {
		// 	cout<<"joined\n";
		// }
	}
	
	// forn(i,n+1){
	// 	cout<<disjointset[i]<<" ";
	// }
	// cout<<"\n";

	int givenarr[m];
	forn(i,m){
		cin>>givenarr[i];
	}

	cout<<solve(givenarr,0,m-1)<<"\n";

	#ifndef ONLINE_JUDGE
    cout<<"\nTime taken: " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
	#endif
}
