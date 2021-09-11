// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int pt1 = 0, pt2 = 0, changer = 0;
        int comp;
        if(arr1[n-1]>arr2[m-1])
            comp = arr1[n - 1] + 1;
        else
            comp = arr2[m - 1] + 1;
        while (pt1 < n && pt2 < m)
        {
            if(arr1[pt1]%comp<arr2[pt2]%comp){
                if(changer<n){
                    arr1[changer] = arr1[changer] + comp * (arr1[pt1] % comp);
                }
                else{
                    arr2[changer-n] = arr2[changer-n] + comp * (arr1[pt1] % comp);
                }
                changer++;
                pt1++;
            }
            else{
                if (changer < n)
                {
                    arr1[changer] = arr1[changer] + comp * (arr2[pt2] % comp);
                }
                else
                {
                    arr2[changer-n] = arr2[changer-n] + comp * (arr2[pt2] % comp);
                }
                changer++;
                pt2++;
            }
        }
        while(pt1<n){
            if(changer<n){
                arr1[changer] = arr1[changer] + comp * (arr1[pt1++] % comp);
            }
            else{
                arr2[changer - n] = arr2[changer - n] + comp * (arr1[pt1++] % comp);
            }
            changer++;
        }
        while (pt2 < m)
        {
            if (changer < n)
            {
                arr1[changer] = arr1[changer] + comp * (arr2[pt2++] % comp);
            }
            else
            {
                arr2[changer - n] = arr2[changer - n] + comp * (arr2[pt2++] % comp);
            }
            changer++;
        }
        for (int i = 0; i < n;i++){
            arr1[i] = arr1[i] / comp;
        }

        for (int j = 0; j < m; j++)
        {
            arr2[j] = arr2[j] / comp;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends