// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
  public:
    //In this que we start sorting the array using merge sort and count the number of swaps in the 
    //following way:- Lets take an example.. 2 4 1 5 3 we call merge sort recursively and reach 2 arrays
    //1st 2 2nd 4. Here we can see that the sorted array would become 2,4 which was already sorted and 
    //doesn't require any swap for making it sorted which can be seen by the fact that the element in the
    //first array was never less than the element in the second array.. Now we merge 2,4 and 1..Now we see
    //that 1 is smaller than 2.. so we add the number of elements in the 1st array from that point onwards
    //into count(2)..Now we have 1,2 4 array on one side.. On the other side we have 5 and 3.We can see
    // 3 is smaller than 5 so we add 1(remaining elemnents in upper array) to count(3).. Now we have
    //1,2,4 and 3,5 now while merging we will encounter that 3 is less than 4 so we will add 1 to count(4)
    //Now the sorting process is complete and the count is 4
    //Time complexity - O(nlogn) Space complexity - O(n)
    void mergeSort(long long a[], long long si, long long ei,long long& count)
    {
        //base case
        if (si >= ei)
            return;
    
        //recursive call
        long long mid = si + (ei - si) / 2;
        mergeSort(a, si, mid,count);
        mergeSort(a, mid + 1, ei,count);
    
        //small calculations
        long long arr[ei - si + 1];
        long long i = si;
        long long j = mid + 1;
        long long k = 0;
        while (i <= mid && j <= ei)
        {
            if (a[i] > a[j])
            {
                arr[k++] = a[j++];
                count += mid - i + 1;
            }
            else if (a[i] <= a[j])
            {
                arr[k++] = a[i++];
            }
        }
        while (i <= mid)
            arr[k++] = a[i++];
    
        while (j <= ei)
            arr[k++] = a[j++];
    
        for (long long it = 0; it<k; it++)
        {
            a[it + si] = arr[it];
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long count = 0;
        mergeSort(arr,0,N-1,count);
        return count;
    }
   

};


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends