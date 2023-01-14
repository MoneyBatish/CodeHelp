#include<iostream>
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

    void print(){
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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
    H.print();
}