// { Driver Code Starts
//Initial Template for C

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C
//**********************************************************************************************************
//Approch 1 - Simple Counting Method Time complexity - O(n)
    // void sort012(int a[], int n)
    // {
    //     int zero = 0;
    //     int one = 0;
    //     int two = 0;
    //     int i;
    //     for (i = 0; i < n; i++)
    //     {
    //         if (a[i] == 0)
    //             zero++;
    //         else if (a[i] == 1)
    //             one++;
    //         else
    //             two++;
    //     }
    //     i = 0;
    //     for (; zero > 0; i++, zero--)
    //         a[i] = 0;
    //     for (; one > 0; i++, one--)
    //         a[i] = 1;
    //     for (; two > 0; i++, two--)
    //         a[i] = 2;
    // }
//******************************************************************************************************
//Approach 2 - The one have zero one unknown two zones within the array
//There will be three pointers 1st pointing at the next index after last zero at the current point
//the next pointer will be pointing at the first unkonwn which is next element after the last known 1
//and the third will be pointing 1 before the first 2 that is at the last unknown
//if the unkonwn is zero we replace it will the 1st pointer and increment 1st and 2nd pointer
//if it is one we simply increment the second pointer
//if it is two we swap it with 3rd pointer and decrease the third pointer but we don't increment
//the second pointer because in this case the swaped element that comes back can be anything and
//thus it also required analysis while in case of zero we always know that the swapped element is 1
void sort012(int a[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[low++], a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid], a[high--]);
            break;
        }
    }
}
//***********************************************************************************************
// { Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends