#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //In this que we require at max 2 stock tracsactions which can't be overlapping i.e. we 
    //can't have 2 stocks bought at the same time so we divide the array into 2 disjoint parts
    //and find the max transaction possible in first part and the second part and add them to get
    //the net profit. To achieve this we use DP. We traverse from start to end and store max profit
    //till ith index in an array and we traverse from end to start and store max profit from ith to last
    //in another array and then we traverse both the arrays and find max of sum of 2 disjoint transactions.
    //Time complexity - O(n) Space complexity - O(n)
    int maxProfit(vector<int>& prices) {
        int start = 0;
        int profit = 0;
        vector<int> proUp;
        for(int i = 0; i<prices.size();i++){
            if(prices[i]-prices[start]>profit){
                profit = prices[i]-prices[start];
            }
            else if(prices[i]<prices[start]){
                start = i;
            }
            proUp.push_back(profit);
        }
        vector<int>proDown;
        profit = 0;
        int max = prices.size()-1;
        for(int i = prices.size()-1;i>=0;i--){
            if(prices[max]-prices[i]>profit){
                profit = prices[max]-prices[i];
            }
            else if(prices[i]>prices[max]){
                max = i;
            }
            proDown.push_back(profit);
        }
        max = 0;
        for(int i = 0;i<prices.size();i++){
            if(proUp[i]+proDown[prices.size()-1-i]>max){
                max = proUp[i]+proDown[prices.size()-1-i];
            }
        }
        return max;
    }
};

int32_t main()
{

    int t = 1;
    while (t--)
    {
        vector<int> a = {7, 6, 4, 3, 1};
        Solution s;
        cout << s.maxProfit(a);
    }

    return 0;
}