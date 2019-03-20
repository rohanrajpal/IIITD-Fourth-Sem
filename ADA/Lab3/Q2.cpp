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
int diff(char a,char b){
	if (a == b)
	{
		return 2;
	}
	else{
		return 0;
	}
}
int solve(char arr[],int low,int high){
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
		memo[low][high] = ans;
		return ans;
	}
}
void convInpToArr(string &str){
	int n = str.length();

	char arr[n];

	strcpy(arr,str.c_str());
	cout<<solve(arr,0,n-1)<<"\n";
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int t;cin>>t;
	for (int i = 0; i < t; ++i)
	{
		string inp;
		cin>>inp;
		// cout<<inp<<"\n";
		mst(memo);
		convInpToArr(inp);
	}
	// cout<<increasedecrease(k,arr)<<"\n";

	#ifndef ONLINE_JUDGE
    cout<<"\nTime taken: " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
	#endif
}
