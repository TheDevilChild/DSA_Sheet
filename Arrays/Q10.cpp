// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        int i = 0;
        int count = 0;
        int maxindex;
        int max;
        int flag = 0;
        while (i < n-1)
        {
            count++;
            max = arr[i + 1];
            for (int j = i+1; j <= i + arr[i] && j < n; j++)
            {
                if (arr[j] >= max)
                {
                    maxindex = j;
                    max = arr[j];
                }
                if(j==n-1){
                    flag = 1;
                }
            }
            i = maxindex;
            if(flag == 1){
                i = n - 1;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends