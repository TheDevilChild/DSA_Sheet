#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //In this que we start from the first index and traverse the array.If the difference of the prices
    //on ith day and start day(which is the min priced day till this day) is greater than profit we update
    //profit to this difference otherwise we check that if the price on ith day is less than that on the 
    //start day so we update start to i
    //Time complexity - O(n) Space complexity - O(1)
    int maxProfit(vector<int>& prices) {
        int start = 0;
        int profit = 0;
        for(int i = 1; i<prices.size();i++){
            if(prices[i]-prices[start]>profit){
                profit = prices[i]-prices[start];
            }
            else if(prices[i]<prices[start]){
                start = i;
            }
        }
        return profit;
    }
};

int main(){


    return 0;
}