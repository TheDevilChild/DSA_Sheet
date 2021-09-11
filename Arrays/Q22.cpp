
#include <bits/stdc++.h>
using namespace std;


class Solution {
    //Here we have to find factorial of big numbers but can't store them in basic data types. So 
    //we use arrays to store each digit.For every i from 2 to N we multiply i will all the numbers
    //present in the array and if the resulting number has more digits than one then we store %10 in
    //that place and take /10 as the carry to the next position.. In this way we save the factorial
    //in the reverse order... Eg:- 1 * 2 = 2*3 = 6*4 = (4,2)*5 = (0,2,1)
    //Time complexity - O(n^2) Space complexity - O(No of digits in factorial)
public:
    vector<int> factorial(int N){
        vector<int> v;
        v.push_back(1);
        for(int i = 2;i<=N;i++){
            int carry = 0;
            for(int j = 0;j<v.size();j++){
                int temp = v[j] * i + carry;
                v[j] = (temp)%10;
                carry = temp/10;
            }
            while(carry != 0){
                v.push_back(carry%10);
                carry = carry/10;
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends