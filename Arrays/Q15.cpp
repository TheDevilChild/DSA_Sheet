#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n = nums.size()-1;
       //first we will traverse the array in the reverse order and find the consequtive elements
       //that are (smaller,larger). Eg :- 1 3 5 4 2 we will go till (3,5). Now as we have traversed 
       //the array in the reverse direction we for certain know that from 5 to 2 we have the maximum
       //permutation so for the next permutation we sort the array from 5 to 2 .. Now we have 1 3 2 4 5
       //Now we will find the element just greater than 3 and swap 3 with that element .. 1 4 2 3 5-->Ans
       //Edge case is the one in which the whole array is the last permutation. Eg:- 5 4 3 2 1....In 
       //this case we just reverse the array as the next permutation will be lexiographically the smallest one.
       //Time complexity - O(nlogn) Space complexity - O(1) 
        for(int i = n;i>0;i--){
            if(nums[i]>nums[i-1]){
                sort(nums.begin()+i,nums.end());
                int j;
                for(j = i;i<n;j++){
                    if(nums[j]>nums[i-1]){
                        break;
                    }
                }
                swap(nums[i-1],nums[j]);
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
int main(){

}