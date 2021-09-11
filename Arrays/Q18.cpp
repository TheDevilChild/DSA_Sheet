#include<bits/stdc++.h>
using namespace std;

//Approach 1
class Solution{   
public:
    //Here we use a map and count the freq of every number occuring in the array and then we loop over
    //them one by one.. If k - current number is present in the map we multiply their freq and add
    //it to the final count and also make the count of k- current numbers freq as 0 to avoid doubling
    //as otherwise we would have calculated for k - current number also.
    //Edge case is if we get a number which is 2*number = k. In this case we would add freq(freq-1)/2
    //Time complexity - O(n) Space complexity - O(n)
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int> m;
        for(int i = 0;i<n;i++){
            m[arr[i]]++;
        }
        int count = 0;
        for(auto x:m){
            if(x.first*2==k){
                count += x.second * (x.second - 1)/2;
            }
            else if(m.count(k-x.first)>0){
                count +=x.second*m[k-x.first];
                m[k-x.first] = 0;
            }
        }
        return count;
    }
};

//Approach 2
class Solution{   
public:
    //Here we instead of kepping the freq of all the numbers occuring we traverse the array and keep
    //the freq of k-arr[i] freq..Eg:- k - 6 array -1 5 7 1 5.. We will start from 1 and as there is 
    //no 1 present(meaning we have not encountered a 5 to make a pair with 1) will just make m[5]= 1.
    //Then we move to 5 and as freq of 5 is 1 we add it to the count(this means that there was 1 of 1
    //before 5 that would make a pair with 5 to make 6) and also do m[1]= 1 so that if we encounter any
    //more 1 further ahead we would know that there is a 5 present before to make a pair..In this way 
    //we would avoid taking the pairs 2 times also.
    //Time complexity - O(n) Space complexity - O(n)
    int getPairsCount(int arr[], int n, int k) {
            int ans = 0;
            unordered_map<int, int> m;
            for(int i = 0; i < n; i++) {
                if(m.count(arr[i])) {
                    ans += m[arr[i]];
                }
                m[k-arr[i]] ++;
            }
            return ans;
        }
};

int main(){

     int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
        
    }

    return 0;
}


