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

void BuildLevelTree(Node* &root)
{
    queue<Node *>q;
    cout<<"Enter The Root Node"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        cout<<"Enter The Left Node Of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1)
        {
            temp->left=new Node(leftData);
            q.push(temp->left);
        }

        int RightData;
        cin>>RightData;
        if(RightData!=-1)
        {
            temp->right=new Node(RightData);
            q.push(temp->right);
        }
    }
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }

        }
    }
}

int main()
{
    Node *root=NULL;
    BuildLevelTree(root);
    LevelOrderTraversal(root);
}