#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>a,vector<int>b){
        if(a[0] == b[0]){
            return (a[1]<b[1]);
        }
        return (a[0]<b[0]);
}
//We start by sorting the array in ascending order where [1,3] will come before [1,6]
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),comp);
        //Then we take 2 integer pointers start and end and we start traversing the vector
        int start = 0;
        int end = 1;
        while(end<intervals.size()){
            // If the first of the current end is smaller or equal to the last of the previous one 
            //then we place the max of index 1 of both end and end-1 in end for next calculations and move 
            //end to the next value
            // we do this max so as to avoid the condition where the previous one was engulfing the end one whole
            //eg [1,10], [2,3], [4.5] ---> [1,10],[2,10],[4,5] ---> [1,10],[2,10],[4,10]
            if(intervals[end][0]<=intervals[end-1][1]){
            intervals[end][1] = max(intervals[end][1], intervals[end - 1][1]);
            end++;
            }
            //When the 0th of end is greater than the 1st of end-1 then we can make a vector for start and end -1
            //and then move start to end and end to next
            else{
                vector<int> a;
                a.push_back(intervals[start][0]);
                a.push_back(max(intervals[end-1][1],intervals[start][1]));
                ans.push_back(a);
                start = end;
                end++;
            }
        }
        //For the last iteration end will go out of bounds and the last start to end vector will never be 
        //pushed into this vector so this is handling that condition where we are pushing start to size-1 
        //as that would be the last element of the vector
        vector<int>a;
        a.push_back(intervals[start][0]);
        a.push_back(max(intervals[end-1][1],intervals[start][1]));
        ans.push_back(a);
        return ans;
        
    }
};

int main(){


    return 0;
}