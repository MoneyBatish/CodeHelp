#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;
    Heap()
    {
        arr[0]=-1;
        size=0;
    }
    void insert(int data)
    {
        size=size+1;
        int index=size;
        arr[index]=data;

        while(index>1)
        {
            int parent=index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }else{
                return;
            }
        }
    }
    void Heapify(int i)
    {
        int largest=i;
        int left=2*i;
        int right=2*i + 1;
        if(left<=size && arr[left]>arr[largest])
        {
            largest=left;
        }
        if(right<=size && arr[right]>arr[largest])
        {
            largest=right;
        }

        if(largest!=i)
        {
            swap(arr[largest],arr[i]);
            Heapify(largest);
        }
        else{
            return;
        }
    }
    void deleteFromHeap()
    {
        if(size==0)
        {
            cout<<"Delete Nahi Hunda"<<endl;
        }

        arr[1]=arr[size];
        size--;
        Heapify(1);
    }
    void printArray(){
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void printLVL()
    {
        queue<int>q;
        q.push(1);
        q.push(-1);
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            if(i==-1)
            {
                cout<<endl;
                if(!q.empty())
                {
                    q.push(-1);
                }
            }
            else{
                cout<<arr[i]<<" ";
                if(2*i<=size)
                {
                    q.push(2*i);
                }
                if(2*i+1<=size)
                {
                    q.push(2*i+1);
                }
            }
        }
    }
};
int main()
{
    Heap H;
    H.insert(60);
    H.insert(55);
    H.insert(70);
    H.insert(45);
    H.insert(34);
    H.deleteFromHeap();
    H.printLVL();
}