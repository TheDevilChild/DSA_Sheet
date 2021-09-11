#include<bits/stdc++.h>
using namespace std;

//Approach 1
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


//Approach 2 NOTE: No idea why it works :)(GFG - https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-stock-at-most-twice-set-2/?ref=rp)
//Maximum Profit for the First Transaction 
//Find the minimum price we have to pay from our pocket (buy1) to get 1st stock which is the price of the stock on that day or on any previous day.
//Find the maximum profit by selling the 1st stock which on the current day.
//Maximum profit for the second Transaction 
//The minimum price we have to pay from our pocket to buy second stocks will be
//buy2 = price[i] - profit1, 
// Profit 1 is the profit from 
// selling the first stock
//Find the maximum profit (profit2) by selling the 2nd stock.
//Eg:- 2, 30, 15, 10, 1, 25, 80
/*
buy1 2
profit1 0
buy2 2
profit2 0
----------------
buy1 2
profit1 28
buy2 2
profit2 28
----------------
buy1 2
profit1 28
buy2 -13
profit2 28
----------------
buy1 2
profit1 28
buy2 -18
profit2 28
----------------
buy1 1
profit1 28
buy2 -27
profit2 28
----------------
buy1 1
profit1 28
buy2 -27
profit2 52
----------------
buy1 1
profit1 79
buy2 -27
profit2 107
----------------
*/
//Time complexity - O(n) Space complexity - O(1)
int maxProfit(int price[], int n)
{
 
    // buy1 - Money lent to buy 1 stock
    // profit1 - Profit after selling
    // the 1st stock buyed.
    // buy2 - Money lent to buy 2 stocks
    // including profit of selling 1st stock
    // profit2 - Profit after selling 2 stocks
    int buy1, profit1, buy2, profit2;
 
    // Set initial buying values to
    // INT_MAX as we want to minimize it
    buy1 = buy2 = INT_MAX;
 
    // Set initial selling values to
    // zero as we want to maximize it
    profit1 = profit2 = 0;
 
    for (int i = 0; i < n; i++) {
 
        // Money lent to buy the stock
        // should be minimum as possible.
        // buy1 tracks the minimum possible
        // stock to buy from 0 to i-1.
        buy1 = min(buy1, price[i]);
 
        // Profit after selling a stock
        // should be maximum as possible.
        // profit1 tracks maximum possible
        // profit we can make from 0 to i-1.
        profit1 = max(profit1, price[i] - buy1);
 
        // Now for buying the 2nd stock,
        // we will integrate profit made
        // from selling the 1st stock
        buy2 = min(buy2, price[i] - profit1);
 
        // Profit after selling a 2 stocks
        // should be maximum as possible.
        // profit2 tracks maximum possible
        // profit we can make from 0 to i-1.
        profit2 = max(profit2, price[i] - buy2);
    }
 
    return profit2;
}
 

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