/* A Naive recursive implementation of 0-1 Knapsack problem */
#include<stdio.h> 

// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 

// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, float wt[], float val[], int n) 
{ 
// Base Case 
if (n == 0 || W == 0) 
	return 0; 

// If weight of the nth item is more than Knapsack capacity W, then 
// this item cannot be included in the optimal solution 
if (wt[n-1] > W) 
	return knapSack(W, wt, val, n-1); 

// Return the maximum of two cases: 
// (1) nth item included 
// (2) not included 
else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), 
					knapSack(W, wt, val, n-1) 
				); 
} 

// Driver program to test above function 
int main() 
{ 
	float val[] = {50, 100, 40, 95, 30}; 
	float wt[] = {3.14, 1.98, 2, 5, 3}; 
	int W = 10; 
	int n = sizeof(val)/sizeof(val[0]); 
	printf("%d", knapSack(W, wt, val, n)); 
	return 0; 
} 
