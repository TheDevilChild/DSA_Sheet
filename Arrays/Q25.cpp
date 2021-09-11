// { Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    //Here we would use a map to count the freq of all the numbers occuring and will do count++ 
    //if the freq is more than n/k
    //Time complexity - O(n) Space complexity - O(n)
    public:
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int,int> m;
        for(int i = 0;i<n;i++){
            m[arr[i]]++;
        }
        int count = 0;
        for(auto x:m){
            if(x.second>n/k){
                count++;
            }
        }
        return count;
    }
};


// { Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends