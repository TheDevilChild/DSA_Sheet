#include<bits/stdc++.h>
using namespace std;

//Approach 1
class Solution {
public:
    //Here we count the freq of all the numbers and return the one having freq greater than 1
    //Time complexity - O(n) Space complexity - O(n)
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x:nums){
            m[x]++;
        }
        for(auto x:m){
            if(x.second>1){
                return x.first;
            }
        }
        return 0;
    }
};

//Approach 2
class Solution {
public:
    //In this we traverse the array and for every value we go to that index and add size of array
    //to it as we know all the numbers in the array are less than the size of array..So the number
    //with atleast 2 frequency will have a value greater than 2 * size of array at its index
    //Eg:- If we have 2 twice in the array then index 1 after the whole traversal will have the
    //maximum value also this value will be greater than 2*size so we will output index + 1
    //Time complexity - O(n) Space complexity - O(1)
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            nums[nums[i]%n-1] +=n;
            if(nums[i]>2*n){
                return i+1;
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i]>2*n){
                return i+1;
            }
        }
        return 0;
    }
};

int main(){


    return 0;
}