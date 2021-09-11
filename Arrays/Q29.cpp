#include<bits/stdc++.h>
using namespace std;

class Solution{

    //In this que we use dp to calculate the max block till ith position from left and another
    //array to store the max block from ith to n block. Now the amount of water that can be 
    //stored is the minimum of the max of 2 sides height.
    //Time complexity - O(n) Space complexity - O(n)
    public:
    long long trappingWater(int arr[], int n){
        int dp1[n];
        dp1[0] = arr[0];
        int dp2[n];
        for(long long i = 1;i<n;i++){
            dp1[i] = max(dp1[i-1],arr[i]);
        }
        dp2[n-1] = arr[n-1];
        for(long long i = n-2;i>=0;i--){
            dp2[i] = max(dp2[i+1],arr[i]);
        }
        long long count = 0;
        for(long long i = 0;i<n;i++){
            count += (min(dp1[i],dp2[i]) - arr[i]);
        }
        return count;
    }
};


int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends