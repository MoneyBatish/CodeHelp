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
    H.printLVL();
}