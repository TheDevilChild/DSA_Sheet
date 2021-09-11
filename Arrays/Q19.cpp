// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    //We will traverse all the arrays and if all three elements are equal and the last element pushed
    //in the vector is not the same we push this number otherwise we increment the array having the least
    //number among the three
    //Time complexity - O(n1+n2+n3) Space complexity - O(min(n1,n2,n3))
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i1 = 0, i2 = 0, i3 = 0;
            vector<int> ans;
            while (i1 < n1 && i2 < n2 && i3 < n3)
            {
                if(A[i1] ==B[i2]&&B[i2] == C[i3]){
                    if(ans.size()){
                        if(ans[ans.size()-1]!=A[i1])
                        {
                            ans.push_back(A[i1]);
                        }
                    }
                    else{
                        ans.push_back(A[i1]);
                    }
                    i1++;
                    i2++;
                    i3++;
                }
                else {
                    if(A[i1] <= B[i2] && A[i1] <= C[i3]) {
                        i1++;
                    } else if(B[i2] <= A[i1] && B[i2] <= C[i3]) {
                        i2++;
                    } else {
                        i3++;
                    }
                }
            }
            return ans;
    }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends