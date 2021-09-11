// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    //Here we fix one number say at ith position then we use the 2 pointer approach from i+1 to end
    //to find if there exists a pair that sums to X-A[i] 
    //Time complexity - O(n^2) Space complexity - O(1)
    public:
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        for(int i = 0;i<n-2;i++){
            int cal = X-A[i];
            int j = i+1;
            int end = n -1;
            while(j<end){
                if(A[j]+A[end]>cal){
                    end--;
                }else if(A[j]+A[end]<cal){
                    j++;
                }else{
                    return true;
                }
            }
        }
    return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends
