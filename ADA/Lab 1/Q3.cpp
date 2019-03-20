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
 
#define mst(A) memset( (A) , -1 , sizeof(A) );
 
using namespace std;
int findUnmatchedProf(int profMatches[],int n){
	for (int i = 1; i < n+1; ++i)
	{
		if (profMatches[i] == -1)
		{
			return i;
		}
	}
	return -1;
}
int findBestAvailStudent(int profProposed[][505],int n,int profNo){
	for (int j = 2; j < n+2; ++j)
	{
		if (profProposed[profNo][j] == -1)
		{
			return j;
		}
	}
}
int getRank(int stdPref[][505],int n, int profToCheck,int studentNumber){
	for (int j = 2; j < n+2; ++j)
	{
		if (stdPref[studentNumber][j] == profToCheck)
		{
			return j;
		}
	}
}
void solve(int stdPref[][505],int profPref[][505],int n){
	// for1(i,n){
	// 	for1(j,n+1){
	// 		cout<<stdPref[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	// for1(i,n){
	// 	for1(j,n+1){
	// 		cout<<profPref[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	int complMatches =0;
	int profMatches[n+1],studentMatches[n+1];
	int profProposed[n+1][505];
	mst(profProposed);
	mst(profMatches);mst(studentMatches);

	// cout<<"Propose list:\n";
	// for1(i,n){
	// 	for1(j,n+1){
	// 		cout<<profProposed[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// cout<<"proMatches list: \n";
	// for1(i,n)
	while(complMatches != n){
		// finding an unmatched prof
		int profNo = findUnmatchedProf(profMatches,n);
		//finding a student to which prof hasnt proposed yet
		int studentToProposeIdx = findBestAvailStudent(profProposed,n,profNo);
		int studentToPropose = profPref[profNo][studentToProposeIdx];

		//set proposed status to one
		profProposed[profNo][studentToProposeIdx] = 1;

		//if the selected student isnt matched yet
		if (studentMatches[studentToPropose] == -1)
		{
			//put prof in the student list
			studentMatches[studentToPropose] = profNo;
			//put student in prof list
			profMatches[profNo] = studentToPropose;
			complMatches +=1;
		}
		else{
			//student already has a match

			//find the prof student is engaged to 
			int profWhichStudentisEngagedTo = studentMatches[studentToPropose];
			//current prof competing is profNo

			// go to students list and get rank of both the professors
			int oldProfRank = getRank(stdPref,n,profWhichStudentisEngagedTo,studentToPropose);
			int newProfRank = getRank(stdPref,n,profNo,studentToPropose);

			// the one that has lesser rank is preffered
			if (newProfRank < oldProfRank)
			{
				//delete old professors student connection
				profMatches[profWhichStudentisEngagedTo] = -1;
				// replace with the new prof

				//put prof in the student list
				studentMatches[studentToPropose] = profNo;
				//put student in prof list
				profMatches[profNo] = studentToPropose;
			}

			//else the prof is rejected do nothing
		}
	}

	for (int i = 1; i < n+1; ++i)
		{
			cout<<i<<" "<<profMatches[i]<<"\n";
		}
}
signed main(){
	fast;

	int t,n;

	cin>>t;

	
	forn(r,t){
		cin>>n;
		int stdPref[n+1][505],profPref[n+1][505];
		for1(i,n){
			for1(j,n+1){
				cin>>stdPref[i][j];
			}
		}

		for1(i,n){
			for1(j,n+1){
				cin>>profPref[i][j];
			}
		}

		solve(stdPref,profPref,n);
	}
}