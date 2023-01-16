#include<iostream>
using namespace std;
void Heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=i*2;
    int right=i*2 + 1;
    if(left<=n && arr[largest]<arr[left])
    {
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right])
    {
        largest=right;
    }

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        Heapify(arr,n,largest);
    }
}
void HeapSort(int arr[],int n)
{
    int t=n;
    while(t>1)
    {
        swap(arr[1],arr[t]);
        t--;

        Heapify(arr,t,1);
    }
}
void BuildHeap(int arr[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        Heapify(arr,n,i);
    }
}
int main()
{
    int arr[9]={-1,35,75,45,68,45,78,98,25};
    int n=8;
    BuildHeap(arr,n);
    HeapSort(arr,n);
    
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


}