// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    //Called as Kadane's algorithm
    //The one concept to remember here is that if current_max becomes negative then there is no
    //use to carry along with it we should reset it to zero while max_so_far will have stored the max
    //version of that current_max in it already
    //Time complexity - O(n) Space complexity - O(1)
    int maxSubarraySum(int arr[], int n)
    {
        int max_so_far = INT_MIN;
        int current_max = 0;
        int i = 0;
        while (i < n)
        {
            current_max += arr[i++];
            if (max_so_far < current_max)
            {
                max_so_far = current_max;
            }
            if (current_max < 0)
            {
                current_max = 0;
            }
        }
        return max_so_far;
    }
};

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends