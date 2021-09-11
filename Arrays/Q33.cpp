#include <bits/stdc++.h>
using namespace std;

int minSwap(int *arr, int n, int k);

int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}

//Approach 1 : My solution
//
int minSwap(int *arr, int n, int k) {
    int start = -1;
	int count = 0;
	for (int i = 0; i < n;i++){
		if(start == -1 && arr[i]<=k){
			start = i;
		}
		if(arr[i]<=k){
			count++;
		}
	}
	int minCount = INT_MAX;
	int end = start;
	int swapers = 0;
	while(end<n){
		if(arr[start]>k){
			swapers--;
			start++;
		}
		else if(arr[end]<=k){
			count--;
			if(count>=swapers){
				minCount = min(minCount, count);
				end++;
			}else{
				count+=2;
				start++;
			}
		}else{
			swapers++;
			end++;
		}
	}
	return minCount;
}

//Approach 2
//Sliding window approach
//Fist we calculate the number of values less than equal to k and store it in count
//Now after swaps we know that we would get a subarray of count size with all numbers <= k
//Here we take the window of count size from the beginning and move it ahead one by one alongside
//calculating the no. of bad elements in that window and keeping track of the minimum no. of bad 
//elements in a window which will be our ans as that window will be the easiest one to fill with min
//swaps
//Time complexity - O(n) Space Complexity - O(1)
int minSwapE(int *arr, int n, int k) {
     
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++count;
     
    int bad = 0;
    for (int i = 0; i < count; ++i)
        if (arr[i] > k)
            ++bad;

    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j) {
         
        if (arr[i] > k)
            --bad;
         
        if (arr[j] > k)
            ++bad;
         
        ans = min(ans, bad);
    }
    return ans;
}