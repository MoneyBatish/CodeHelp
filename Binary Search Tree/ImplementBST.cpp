#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void MorrisTraversal(Node *root)
{
    Node *curr;
    Node *pre;

    if(root==NULL)
    {
        return;
    }

    curr=root;
    while(curr!=NULL){
        if(curr->left==NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            pre=curr->left;
            while(pre->right!=NULL && pre->right!=curr)
            {
                pre=pre->right;
            }

            if(pre->right==NULL)
            {
                pre->right=curr;
                curr=curr->left;
            }
            else{
                pre->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}
void levelOrderTraversal(Node *root)
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

Node *insertIntoTree(Node *root,int data)
{
    if(root==NULL)
    {
        root=new Node(data);
        return root;
    }
    if(data>root->data)
    {
        root->right=insertIntoTree(root->right,data);
    }
    else{
        root->left=insertIntoTree(root->left,data);
    }
    return root;
}
Node * minValue(Node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
Node * deleteNode(Node *root ,int data)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==data)
    {
        //0 Child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //1 child

        //left child
        if(root->left!=NULL && root->right==NULL)
        {
            Node *temp=root->left;
            delete root;
            return temp;
        }

        //right child
        //left child
        if(root->left==NULL && root->right!=NULL)
        {
            Node *temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left != NULL && root->right !=NULL)
        {
            int mini=minValue(root->right)->data;
            root->data=mini;
            root->right=deleteNode(root->right,mini);
        }
    }
    else if(root->data>data)
    {
        root->left=deleteNode(root->left,data);
    }
    else{
        root->right=deleteNode(root->right,data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=insertIntoTree(root,data);
        cin>>data;
    }
}
int main()
{
    Node *root=NULL;
    cout<<"Enter data in Binary Search Tree"<<endl;

    takeInput(root);
    levelOrderTraversal(root);
    //MorrisTraversal(root);
    int del;
    cin>>del;
    deleteNode(root,del);
    levelOrderTraversal(root);
}
