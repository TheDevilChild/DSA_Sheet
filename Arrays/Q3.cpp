// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    //In this we will make a max priority queue and add first k numbers into it. Then from k+1 to 
    //n we will check if the current number is smaller than the top of the queue(which is the max
    //number in the queue till now we will pop that number and push this one.. In this way after the 
    //traversal we will get the k minimum numbers in the array and the top of that queue would be the
    //kth one.
    //Time complexity -  O(nlogk) Space complexity - O(k)

    // r : ending index of the array i.e size-1
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> q;
        for(int i = 0;i<r+1;i++){
            if(i<k){
                q.push(arr[i]);
            }
            else{
                if(arr[i]<q.top()){
                    q.pop();
                    q.push(arr[i]);
                }
            }
        }
        return q.top();
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends