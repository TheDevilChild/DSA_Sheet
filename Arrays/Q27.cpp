#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

//Here we put all the elements of the array in a set and then traverse the other set
//and check if all of its elements are present or not in the above array.If yes then its
//a subset of the above array else no 
//Time complexity - O(n) Space complexity - O(n)
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_set<int> s;
    for(int i = 0;i<n;i++){
        s.insert(a1[i]);
    }
    for(int i = 0;i<m;i++){
        if(s.find(a2[i])==s.end()){
            return "No";
        }
    }
    return "Yes";
}