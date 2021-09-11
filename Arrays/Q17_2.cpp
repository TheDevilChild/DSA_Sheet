#include<bits/stdc++.h>
using namespace std;

//Approach 1
class Solution {
public:
    //In this approach what we simply do is that if the next days price is greater than todays price we 
    //buy today and sell tomorrow...In this case we use the fact that we can buy and sell on the same 
    //day.. So in case of 1 5 7 we buy 1 sell 5 then buy 5 again and then sell 7
    //Time complexity - O(n) Space complexity - O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for(int i=0; i<n-1; i++)
        {
            if(prices[i]<prices[i+1])
                profit += prices[i+1]- prices[i];
            
        }
        return profit;
    }
};

//Approach 2
class Solution {
public:
    //In this one we can perform multiple transactions on the array just not at the same time that is
    //we can't buy multiple stocks at the same time but can buy sell buy sell multiple times
    //So we start with i = 0 and compare price of i and i+1.. If price of i+1 is higher than i then
    //it is not worth selling the stock on ith day..Otherwise we sell the stock add the profit and
    //move start to i+1.. Eg:- 1 5 3 2 5 .. here we buy at 1 sell at 5 but now we are at 3 and 3 is less
    //than 2 so we add profit 0 and move to 2..
    //Edge case is the one where the last element is greater than last - 1 element and the last stock 
    //transaction never happens.. For this after the loop we have added the profit of last - start..
    //As in non-edge cases if start was not larger than last-1 we would have sold the stock on last-1
    //and start would have been on last also so we would basically add profit 0 thus not changing the profit
    //Time complexity - O(n) Space complexity - O(1)
    int maxProfit(vector<int>& prices) {
        int start = 0;
        int profit = 0;
        for(int i = 0; i<prices.size()-1;i++){
            if(prices[i]>prices[i+1]){
                profit += prices[i]-prices[start];
                start= i+1;
            } 
        }
        profit += prices[prices.size()-1]-prices[start];
        return profit;
    }
};



int main(){


    return 0;
}