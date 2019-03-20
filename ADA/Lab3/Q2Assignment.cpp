findmissingnumber(array A, int i, int j):
	find median m using selection argorithm
	if m not in A: return m
	else divide A into P and Q
		P: elements <= m
		Q: elements > m
	if size(P) < m+1:
		findmissingnumber(P,startP,endP)
	else:
		findmissingnumber(Q,startQ,endQ)

// Pseudocode:
// Given: k
// arrnum[]
// for i=0 , i < len(array A):
// 	j=0
// 	while(j < k):
// 		arrnum[j] = arrnum[j] XOR BIT-LOOKUP(i,j)
// 	

We first take the array, have two variables of count_0 and count_1.
Now we list down all the elements in their binary representation and start
from the 0th bit till the kth bit.
At the ith bit.
Lets have two arrays to keep elements with that bit 0 and that bit 1.
Now the one with lesser elements is the group that has lesser elements and that
missing bit is the bit of that group.

k = logn
zero_array
one_array
missingnum[len(A)]
from j = 0 to k:
	for i=0 to A:
		set = BIT-LOOKUP(i,j)
		if (set == 0):
			zero_array.append(A[i])
		else:
			one_array.append(A[i])

	if len(zero_array) < len(one_array):
		A = zero_array
		missingnum[j] = 0
	else:
		A = one_array
		missingnum[j] = 0

missing_number = convtonum(missingnum)

Runtime analysis
T(n) = T(n/2) + c

By masters theorem we get the time complexity of T(n) as O(n)

multiply(Arr,1,k){
	if (k == 2)
	{
		return Arr[1] * Arr[0]
	}
	left  = multiply(Arr,1,k/2)
	right = multiply(Arr,k/2+1,k)

	return left*right
}