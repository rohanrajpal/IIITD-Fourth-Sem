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

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n;
    read(n);

    vll arr(n);
    read(arr);

    vector< pair<int,int> > collectarr;
    int len=1;
    for1(i,n-1){
        if (arr[i]>=arr[i-1])
        {
            len++;
        }
        else{
            collectarr.pb(mp(i-len,len)) ;
            len=1;
        }
    }
    collectarr.pb(mp(n-len,len));

    int size_of_collectarr = (collectarr.size());
    int maxnum = 0,maxalt=0;

    forn(i,size_of_collectarr){
        // cout<<collectarr[i].first<<" "<<collectarr[i].scd<<"\n";
        forab(j,i+1,size_of_collectarr-1,1){
            int a_start = collectarr[i].first;
            int a_end = collectarr[i].first + collectarr[i].second -1;

            int b_start = collectarr[j].first;

            while(arr[a_end] > arr[b_start] && a_end >= a_start){
                a_end--;
            }
            int lentocomp;
            if (a_end < a_start)
            {
                lentocomp=0;
            }
            else{
                lentocomp = a_end - a_start + 1 + collectarr[j].second;
            }

            if (maxnum < lentocomp)
            {
                maxnum = lentocomp;
            }
        }

        int lensubarr = collectarr[i].second;
        if (maxalt<lensubarr)
        {
            maxalt = lensubarr;
        }
    }
    if (maxalt>maxnum && maxalt > 1)
    {
        maxnum = maxalt;
    }
    printf("%d\n",maxnum);
    // write(arr);
}