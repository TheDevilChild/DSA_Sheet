// C++ program of the above
// approach

#include <bits/stdc++.h>
using namespace std;

// Function to shift all the negative elements on left side
//The two pointer approach - Here we take 2 pointers low and high
//low is pointing at the the first unknown element or the element just after the last 
//negative element in the current situation
//high is pointing at the last unknown or the element just before the first positive number
//if we find a negative number simply increment low
//if we find a positive number swap it with high position element decrement high but don't increment
//low as the number that we get can be anything so it requires analysis
//Time complexity - O(n) Space complexity - O(1)
void shiftall(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    while(low <=high){
        if(arr[low]<0){
            low++;
        }
        else{
            swap(arr[low], arr[high--]);
        }
    }
}

// Function to print the array
void display(int arr[], int right)
{

    // Loop to iterate over the element
    // of the given array
    for (int i = 0; i <= right; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver Code
int main()
{
    int arr[] = {-12, 11, -13, -5,
                 6, -7, 5, -3, 11};
    int arr_size = sizeof(arr) /
                   sizeof(arr[0]);

    // Function Call
    shiftall(arr,  arr_size );
    display(arr, arr_size - 1);
    return 0;
}

