#include<iostream>
using namespace std;
class stack{
    public:
    int size;
    int *arr;
    int top;

    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int data){
        if(top<size-1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top==-1)
        {
            cout<<"Stack Is Empty"<<endl;
        }
        else{
            arr[top]--;
            top--;
        }
    }

    void peek(){
        if(top==-1)
        {
            cout<<"Stack Is Empty"<<endl;
        }
        else{
            cout<<arr[top]<<endl;
        }
    }
    bool IsEmpty(){
        if(top==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
};
int main()
{
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.peek();
    cout<<s.IsEmpty();
}