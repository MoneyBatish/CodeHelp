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
    void LevelOrderTraversal()
    {
        queue<Node*>q;
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
    void ReversalOrderTraversal()
    {
        queue<Node*>q;
        stack<Node*>s;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            s.push(temp);
            
            if(temp==NULL)
            {
                if(!q.empty())
                {
                   q.push(NULL);
                }
            }
            else{
            if(temp->right)
            {
                q.push(temp->right);
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            
            }
        }
        while(!s.empty())
        {
            Node *temp=s.top();
            s.pop();
            if(temp==NULL)
            {
                cout<<endl;
            }
            else{
                cout<<temp->data<<" ";
            }
        }
    }
    void InOrder(Node *root){
        if(root==NULL)
        {
            return;
        }
        InOrder(root->left);
        cout<<root->data<<" ";
        InOrder(root->right);
    }
    void PreOrder(Node *root){
        if(root==NULL)
        {
            return;
        }
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
    void PostOrder(Node *root){
        if(root==NULL)
        {
            return;
        }
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";
    }
};
int main()
{
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    tree t;
    t.root=t.BuildTree(t.root);
    t.LevelOrderTraversal();
    t.ReversalOrderTraversal();
    cout<<endl;
    t.InOrder(t.root);
    cout<<endl;
    t.PreOrder(t.root);
    cout<<endl;
    t.PostOrder(t.root);
    cout<<endl;
}
