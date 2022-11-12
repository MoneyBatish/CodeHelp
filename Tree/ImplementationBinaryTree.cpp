#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
class tree{
    public:
    Node *root=NULL;

    Node* BuildTree(Node *root)
    {
        int data;
        cin>>data;
        root=new Node(data);
        if(data==-1)
        {
            return NULL;
        }
        cout<<"Enter The Data for inserting in left of "<<data<<endl;
        root->left=BuildTree(root->left);
        cout<<"Enter The Data for inserting in right of "<<data<<endl;
        root->right=BuildTree(root->right);

        return root;
    }
};
int main()
{
    tree t;
    t.root=t.BuildTree(t.root);
}
