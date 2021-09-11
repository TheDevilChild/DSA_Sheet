#include <bits/stdc++.h>
using namespace std;

class Solution
{
    //Here we maintain a start pointer and start traversing the array when the sum becomes greater
    //than x we start increasing the start pointer and subtracting the a[start] from the sum until 
    //sum again becomes less than x and along with this we maintain the minimum length of this 
    //subarray with sum>x.
    //Time complexity - O(n) Space complexity - O(1)
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int start = 0;
        int currSum = 0;
        int index = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            currSum += arr[i];
            if (currSum > x)
            {
                while (currSum > x)
                {
                    currSum -= arr[start];
                    index = min(index, i - start + 1);
                    start++;
                }
            }
            if (currSum < 0)
            {
                currSum = 0;
                start = i + 1;
            }
        }
        return index;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.smallestSubWithSum(a, n, x) << endl;
    }
    return 0;
}