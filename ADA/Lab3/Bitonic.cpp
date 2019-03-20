
//////////////////////////////////////////
 
ll increasedecrease(  int n,vll &arr )
{
	 vll ptrinc(n,1);

	 for1(i,n-1){
			forn(j,i){
				if (ptrinc[i] < ptrinc[j] + 1 && arr[i] > arr[j] ){
					ptrinc[i] = 1 +ptrinc[j] ;
				}  
			} 
	 }
 

	 vll ptrdec(n,1);
 
	 
	 forr(i,n-1) {
			for (int j = n-1; j > i; j--){
				if (ptrdec[i] < ptrdec[j] + 1 && arr[i] > arr[j] ){
					ptrdec[i] = 1+ ptrdec[j];
				}
			}
	 }
 
 
	 ll maxnum ;
	 maxnum= ptrinc[0]  - 1 + ptrdec[0];
	 for1(i,n-1){
		 if (ptrinc[i] - 1 + ptrdec[i]  > maxnum){
				maxnum = ptrinc[i] - 1 + ptrdec[i] ;
		 }  
	 }
	 

	 cout<< maxnum<<"\n";
}
void convInpToArr(string &str){
	int n = str.length();

	char arr[str.length()];
	vll numarr(n);

	strcpy(arr,str.c_str());
	
	for (int i = 0; i < n; ++i)
	{
		numarr[i] = int(arr[i]);
		cout<<numarr[i]<<" ";
	}
	cout<<"\n";
	increasedecrease(n,numarr);
}