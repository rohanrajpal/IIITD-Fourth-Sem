#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vbb vector<bool>
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
int sieveOfPrimes(int n, vll &sPrimeNum){
	vbb primeChk(n+1,false);
	int i=2;
	while(i<n+1){
		sPrimeNum[i] = 2;
		i+=2;
	}
	i=3;
	while (i < n+1)
	{
		if (!primeChk[i])
		{
			sPrimeNum[i] = i;

			int j = i;
			while (j*i < n+1)
			 {
			 	if (!primeChk[i*j])
			 	{
			 		sPrimeNum[i*j] = i;

			 		primeChk[i*j] = true;
			 	}
			 	j+=2;
			 } 
		}

		i+=2;
	}
}
int nchooserarr[5005][5005];
signed main(){
	fast;
	mst(nchooserarr);
    for(int i =0;i<= 5004;i++){
        for(int j=0; j<= i;j++){
            if (j == i || j == 0)
            {
                nchooserarr[i][j] = 1;
            }
            else{
                nchooserarr[i][j] = (nchooserarr[i-1][j-1] + nchooserarr[i-1][j]);
            }
        }
    }
	int n;
	cin>>n;

	vll sPrimeNum(n+1);
	sieveOfPrimes(n,sPrimeNum);

	// forn(i,sPrimeNum.size()){
	// 	cout<<sPrimeNum[i]<<" ";
	// }
	// cout<<"\n";
	//counting the powers

	int count = 1,curr = sPrimeNum[n];
	int mul =1;
	for(;n != 1;){
		n = n / sPrimeNum[n];

		if (sPrimeNum[n] == curr)
		{
			count++;
		}
		else{
			// cout<<"Power of "<<curr<<" is "<<count<<"\n";
			mul = mul * nchooserarr[count+2][2];
			count = 1;
			curr = sPrimeNum[n];
			
		}
	}

	cout<<mul<<"\n";

}