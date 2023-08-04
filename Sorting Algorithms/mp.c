#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int i, j, k;
    int L[n1];int R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[start + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    i = j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        k++;
        i++;
    }
}
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        mergeSort(arr, 0, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}
int main()
{
    int arr[] = {100, 99, 98, 97, 96, 95, 94};
    int len = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, len - 1);

    for (int l = 0; l < len; l++)
    {
        printf("%d ", arr[l]);
    }
    return 0;
}