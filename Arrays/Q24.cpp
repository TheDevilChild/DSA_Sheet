
#include <bits/stdc++.h>
using namespace std;

class Solution{
    //We would push all the numbers into a set and then we would traverse the array and check if the
    //number previous to the current number is present or not.If present don't do anything but if not
    //that means this is the number from where a continuous subsequence will start.So increase the number
    //and check if this number is present in set or not and count the number of continuous present
    //And finally store the max continuous in a variable
    //Time complexity - O(n) Space complexity - O(n)
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
      unordered_set<int> s;
      for(int i = 0;i<N;i++){
          s.insert(arr[i]);
      }
      int count= 0;
      for(int i = 0;i<N;i++){
          if(s.find(arr[i]-1)==s.end()){
                int j = arr[i];
                while(s.find(j)!=s.end())
                    j++;
                count = max(count,j-arr[i]);
          }
      }
      return count;
      
    }
};


int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}