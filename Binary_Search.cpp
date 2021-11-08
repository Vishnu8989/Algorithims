#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int count;                           // to count iteration
void insertionSort(int arr[], int n) // see other file for explanation
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (arr[j] > temp && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
// this search takes sorted array and searches for element by comparing the middle element and dividing array in 2 parts accordingly for further searches
void binarySearch(int d[], int l, int r, int x) // sorted array , start point , endpoint - 1 , target element
{
    count++;
    // Condition to stop as l>r mean not found we have covered whole array
    if (l <= r)
    {
        cout << "From " << l << " to " << r << endl;
        int mid = (l + r) / 2; // finding mid index
        if (d[mid] == x)       // checking middle element here
        {
            printf("Found at %d after %d iterations\n", mid, count);
            return;
        }
        else if (d[mid] > x) // if mid element is greater that we need to search first half of array
        {
            r = mid - 1; // end point updated for next call
        }
        else // if mid element is less than target then we need to search later half of array
        {
            l = mid + 1; // updating the start point for next array
        }
        binarySearch(d, l, r, x); // since l<r we search more coz we know there are nore element left unsearched
    }
    else
    {
        cout << "Element not found";
    }
}
int main()
{
    system("cls");
    srand(time(NULL));
    int a;
    cout << "Enter array size : ";
    cin >> a;
    int d[a];
    for (int i = 0; i < a; i++)
    {
        // printf("Arr[%d] : ", i);
        // cin >> d[i];
        d[i] = rand() % (5 * a); // Auto input
    }
    insertionSort(d, a); // Sorting as Binary Search takes sorted array
    for (int i = 0; i < a; i++)
    {
        printf("\nArr[%d] : %d", i, d[i]);
    }
    int target = 0;
    cout << "\nEnter Element to search : ";
    cin >> target;
    binarySearch(d, 0, a - 1, target); // our array pointer,0 as our array start from zero ,
    //  a-1 as we need to search element till a-1 as a is out of range , target element
}