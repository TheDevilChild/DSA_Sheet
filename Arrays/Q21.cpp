#include <bits/stdc++.h>
using namespace std;

class Solution{
    //In this que we would take the sum of the first i numbers and will push them into a set
    //and if we encounter the same sum twice it means the numebers between i and j have to sum
    //to 0 to give the same sum back.Also if the sum itself becomes 0 at any point then also we
    //would return true(To avoid the sum condition we could push 0 into set initially so if 0 comes
    //we would return true).
    //Eg:-  5  6 -3 2  1 -5
    //sum:- 5 11 8 10 11 6 .. Here we can see we get 11 twice which means from -3 to 1 the sum
    //comes to be 0 to give the same total sum back
    //Time complexity - O(n) Space Complexity - O(n)
public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> s;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += arr[i];
            if(s.count(sum)>0||sum==0){
                return true;
            }
            s.insert(sum);
        }
        return false;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends