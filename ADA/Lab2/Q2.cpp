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
int n,m;
int arr[21][21];

int solve(int icnt, int x, int y){
	if (x>n || y>m)
	{
		return -1;
	}
	if (x == n && y == m)
	{
		return icnt;
	}

	icnt += 1;
	int mov1 = solve(icnt,x+1,y+2);
	int mov2 = solve(icnt,x+2,y+1);

	if (mov1 == -1||mov2 == -1)
	{
		if (mov1== -1 && mov2 ==-1)
		{
			return -1;
		}
		else if (mov1 == -1)
		{
			return mov2;
		}
		else{
			return mov1;
		}
	}
	else{
		return min(mov1, mov2);
	}
}
signed main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	cin>>n>>m;

	cout<<solve(0, 1, 1)<<"\n";

	#ifndef ONLINE_JUDGE
    cout<<"\nTime taken: " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
	#endif
}