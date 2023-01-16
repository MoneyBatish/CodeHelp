#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int>MaxHeap;
    MaxHeap.push(3);
    MaxHeap.push(5);
    MaxHeap.push(10);
    MaxHeap.push(7);
    MaxHeap.push(6);
    cout<<"MaxHeap Size = "<<MaxHeap.size()<<endl;
    MaxHeap.pop();
    cout<<"MaxHeap Top Element = "<<MaxHeap.top()<<endl;

    priority_queue<int,vector<int>,greater<int>>MinHeap;
    MinHeap.push(3);
    MinHeap.push(5);
    MinHeap.push(10);
    MinHeap.push(7);
    cout<<"MinHeap Size = "<<MinHeap.size()<<endl;
    MinHeap.pop();
    cout<<"MinHeap Top Element = "<<MinHeap.top()<<endl;

}