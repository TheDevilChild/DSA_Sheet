// { Driver Code Starts
// Initial Template for C

#include <stdio.h>

struct pair
{
    long long int min;
    long long int max;
};

struct pair getMinMax(long long int arr[], long long int n);

int main()
{
    long long int t, n, a[100002], i;
    struct pair minmax;

    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);

        for (i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        minmax = getMinMax(a, n);
        printf("%lld %lld\n", minmax.min, minmax.max);
    }
    return 0;
} // } Driver Code Ends

// User function Template for C

//Approach 1 - Linear search
//We are going to make 2 variables min and max and store the max and min elements by constantly
//them with the current element and changing their value as we search linearly
//Time complexity - O(n)

//Approach 2 - Binary search type appraoch using recursion (Tournament Method)
//We divide the array into 2 parts and find their max and min and compare them with the other half array's
//min and max
//Time complexity - O(n)

//Approach 3 - Compare in pairs
//if n is odd - set the first element as max and min if n is even - set the max
//of first 2 as max and the other as min Then for the rest of the even elements remaining make pairs of 2
//In those pairs find the max and min and then compare them with the overall max and min variables we are having
//Time complexity - O(n)
struct pair getMinMax(long long int arr[], long long int n)
{
    struct pair minmax;
    int i;
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else
        {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }
        i = 2;
    }
    else
    {
        minmax.min = minmax.max = arr[0];
        i = 1;
    }
    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            minmax.max = (minmax.max > arr[i]) ? minmax.max : arr[i];
            minmax.min = (minmax.min < arr[i + 1]) ? minmax.min : arr[i + 1];
        }
        else
        {
            minmax.max = (minmax.max > arr[i + 1]) ? minmax.max : arr[i + 1];
            minmax.min = (minmax.min < arr[i]) ? minmax.min : arr[i];
        }
        i += 2;
    }
    return minmax;
}