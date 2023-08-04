#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivotindex = start + count;

    // swap(arr[pivotindex],arr[start]);
    int temp = arr[pivotindex];
    arr[pivotindex] = arr[start];
    arr[start] = temp;

    // making left and right part of pivotindex correct
    int i = start;
    int j = end;
    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
        {
            // swap(arr[i],arr[j]);
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return pivotindex;
}
void quickSort(int arr[], int start, int end)
{
    // base case :- start and end are indexes
    if (start < end)
    {
        int p = partition(arr, start, end);
        // left part sorting
        quickSort(arr, start, p - 1);
        // right part sorting
        quickSort(arr, p + 1, end);
    }
}
int main()
{
    int arr[] = {1000, 45, 67, 22, 11, 90, 43, 34, 111, 37, 78};
    int len = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}