#include <bits/stdc++.h> 
void heapify(vector<int> &arr,int n, int i)
{
    int smaller = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;
    if(leftIndex < n && arr[smaller] > arr[leftIndex])
    {
        smaller = leftIndex;
    }
    if(rightIndex < n && arr[smaller] > arr[rightIndex])
    {
        smaller = rightIndex;
    }

    if (smaller != i)
    {
        swap(arr[i], arr[smaller]);
        heapify(arr, n, smaller);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    return arr;
}