#include<bits/stdc++.h>
using namespace std;



int main(){

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];

    }
    int traverse = 0;
    int negative = 0;
    int temp = a[0];
    for (int i = 0; i < n;i++){
        if(a[traverse] <0){
            swap(a[negative], a[traverse]);
            negative += 2;
        }
        else{
            
        }
    }

    return 0;
}