#include <stdlib.h>
#include<iostream>
using namespace std;

// function to return max of two numbers
int max(int a, int b) { return (a > b) ? a : b; }

// Function to return longest Zig-Zag subsequence length
int zigzag(int arr[], int n)
{
	/*Z[i][0] = Length of the longest Zig-Zag subsequence
		ending at index i and last element is greater
		than its previous element
	Z[i][1] = Length of the longest Zig-Zag subsequence
		ending at index i and last element is smaller
		than its previous element */
	int Z[n][2];

	
	for (int i = 0; i < n; i++)
		Z[i][0] = Z[i][1] = 1;

	int res = 1; // Initialize result


	for (int i = 1; i < n; i++)
	{
		
		for (int j = 0; j < i; j++)
		{
			// If arr[i] is greater, then check with Z[j][1]
			if (arr[j] < arr[i] && Z[i][0] < Z[j][1] + 1)
				Z[i][0] = Z[j][1] + 1;

			// If arr[i] is smaller, then check with Z[j][0]
			if( arr[j] > arr[i] && Z[i][1] < Z[j][0] + 1)
				Z[i][1] = Z[j][0] + 1;
		}

		if (res < max(Z[i][0], Z[i][1]))
			res = max(Z[i][0], Z[i][1]);
	}

	return res;
}


int main()
{	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<"Length of longest zigzag subsequence is "<<zigzag(arr, n);
	return 0;
}
