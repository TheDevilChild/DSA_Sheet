#include <bits/stdc++.h>
using namespace std;

class Solution{
    //Here since we have to find the minimum difference between the max and min chocolate given
    //we sort the array and for every window of size m we calculate the difference between
    //the 2 edges of that window and find their minimum.
    //Eg:- {3, 4, 1, 9, 56, 7, 9, 12} .. Sorted:- {1,,3,4,7,9,9,12,56} So the min diff comes
    //in 3 -> 9 which is 6
    //Time complexity - O(nlogn) Space complexity - O(1)
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        long long mini = INT_MAX;
        sort(a.begin(),a.end());
        for(long long i = m-1;i<n;i++){
            mini = min(mini,a[i]-a[i-m+1]);
        }
        return mini;
        
    }   
};

int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}