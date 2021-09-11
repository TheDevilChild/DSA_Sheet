// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    //Function to return the count of number of elements in union of two arrays.
    //Approach 1 - Merge sort approach
    //This approach is applicable when both the given arrays doesn't contain duplicate elements in itself
    //Time complexity - O(n+m) Space complexity - O(n+m)
    // int doUnion(int a[], int n, int b[], int m)
    // {
    //     int first = 0;
    //     int second = 0;
    //     int c[n + m];
    //     int i = 0;
    //     while (first < n && second < m)
    //     {
    //         if(a[first]>b[second]){
    //             c[i++] = b[second++];
    //         }
    //         else if(a[first]<b[second]){
    //             c[i++] = a[first++];
    //         }
    //         else{
    //             c[i++] = a[first++];
    //             second++;
    //         }
    //     }
    //     while(first<n){
    //         c[i++] = a[first++];
    //     }
    //     while(second<m){
    //         c[i++] = b[second++];
    //     }
    //       return i;
    // }

    //Approach 2 - Using built in set data type
    //This method will also take into account the possiblity of duplicate elements in both the arrays
    //The time complexity of insert function in set is O(log(n))
    //Now we perform that operation n+m times so the total time complexity of the fuction is
    //Time complexity - O(n+mlog(n+m)) Space complexity - O(n+m)
    int doUnion(int a[], int n, int b[], int m)
    {
        set<int> s;
        for (int i = 0; i < n; i++)
            s.insert(a[i]);
        for (int i = 0; i < m; i++)
            s.insert(b[i]);
        return s.size();
    }

    //Approach 3 - To push all the elements into a single array
    //Sort the array and then count the number of unique elements in the array
    //Time complexity - O(n+mlog(n+m)) Space complexity - O(n+m)
    //...
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }

    return 0;
} // } Driver Code Ends