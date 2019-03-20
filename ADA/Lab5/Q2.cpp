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

signed main(){
	#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int length = pow(2,n);
    	
    	multiset <int> originalset;

    	for (int i = 0; i < length; ++i)
    	{
    		int input;
    		cin>>input;
    		originalset.insert(input);
    	}

    	multiset <int > :: iterator itr;

    	itr= originalset.begin();
    	originalset.erase(originalset.find(0));

    	// for (itr=originalset.begin();itr != originalset.end();++itr)
    	// {
    	// 	cout<<*itr<<" ";
    	// }
    	// cout<<"\n";

		multiset <int> knownelements,knownsums;

		// itr = originalset.begin();
		multiset <int > :: iterator knownsumsitr,enditr,altitr;
		for (itr=originalset.begin();itr != originalset.end();)
    	{
    		int elem = *itr;

    		// originalset.erase(itr);

    		knownelements.insert(elem);
    		
    		// knownsums.insert(elem);

    		knownsumsitr = knownsums.begin();
    		enditr = knownsums.end();
    		int lentogo = knownsums.size();
    		// cout<<"At elem: "<<elem<<"\n";
    		// cout<<"Lentogo: "<<lentogo<<"\n";
    		// for(int i=0;i<lentogo;i++){
    		// 	int toInsDel =*knownsumsitr+elem;
    		// 	// if (i<lentogo-1)
    		// 	// {
    		// 		knownsumsitr++;
    		// 	// }
    		// 	// knownsums.insert(toInsDel);
    		// 	cout<<"Inserted:"<<toInsDel;
    		// 	originalset.erase(originalset.find(toInsDel));
    		// 	cout<<"\ndeleted: "<<toInsDel<<"\n";

    		// }
    		vll toaddarr(0);
    		for(knownsumsitr;knownsumsitr!=enditr;knownsumsitr++){
    			int toInsDel =*knownsumsitr+elem;
    			// knownsums.insert(knownsumsitr++,toInsDel);
    			originalset.erase(originalset.find(toInsDel));
    			toaddarr.pb(toInsDel);
    		}
    		for (int i = 0; i < toaddarr.size(); ++i)
    		{
    			knownsums.insert(toaddarr[i]);
    		}
    		
    		knownsums.insert(elem);
    		itr = originalset.erase(originalset.find(elem));
    		
    		// cout<<"Known elements array\n";
	    	// for (altitr=knownelements.begin();altitr != knownelements.end();++altitr)
	    	// {
	    	// 	cout<<*altitr<<" ";
	    	// }
	    	// cout<<"\nKnown sums array \n";
	    	// for (altitr=knownsums.begin();altitr != knownsums.end();++altitr)
	    	// {
	    	// 	cout<<*altitr<<" ";
	    	// }
	    	// cout<<"\nOriginal sum arr\n";
	    	// for (altitr=originalset.begin();altitr != originalset.end();++altitr)
    		// {
    		// 	cout<<*altitr<<" ";
    		// }
	    	// cout<<"\n";
    	}

    	// multiset <int > :: iterator itr;
    	// cout<<"Known elements array\n";
    	for (altitr=knownelements.begin();altitr != knownelements.end();++altitr)
    	{
    		cout<<*altitr<<" ";
    	}
    	// cout<<"\nKnown sums array \n";
    	// for (altitr=knownsums.begin();altitr != knownsums.end();++altitr)
    	// {
    	// 	cout<<*altitr<<" ";
    	// }
    	cout<<"\n";
    }
}