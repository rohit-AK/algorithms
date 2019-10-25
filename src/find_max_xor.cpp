//Cpp program to find Maximum Xor in an array using Dynamic Programming.
 
#include <bits/stdc++.h> 
using namespace std; 

#define MAX 10000 
#define MAX_ELEMENT 50 

int dp[MAX_ELEMENT][MAX_ELEMENT][MAX]; 

// Function to return the maximum xor for a 
// subset of size k from the given array 
int Max_Xor(int arr[], int i, int j, int mask, int n) 
{ 
	if (i >= n) { 

		// If the subset is complete then return 
		// the xor value of the selected elements 
		if (j == 0) 
			return mask; 
		else
			return 0; 
	} 

	// Return if already calculated for some 
	// mask and j at the i'th index 
	if (dp[i][j][mask] != -1) 
		return dp[i][j][mask]; 

	// Initialize answer to 0 
	int ans = 0; 

	// If we can still include elements in our subset 
	// include the i'th element 
	if (j > 0) 
		ans = Max_Xor(arr, i + 1, j - 1, mask ^ arr[i], n); 

	// Exclude the i'th element 
	// ans store the max of both operations 
	ans = max(ans, Max_Xor(arr, i + 1, j, mask, n)); 

	return dp[i][j][mask] = ans; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 2, 5, 4, 1, 3, 7, 6, 8 }; 
	int n = sizeof(arr) / sizeof(int); 
	int k = 3; 

	memset(dp, -1, sizeof(dp)); 

	cout << Max_Xor(arr, 0, k, 0, n); 

	return 0; 
} 
