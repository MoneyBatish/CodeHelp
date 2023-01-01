/// Love Babbar Approach
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int pred=-1;
    int succ=-1;
    BinaryTreeNode<int>* temp=root;
    while(temp->data!=key)
    {
        if(temp->data>key)
        {
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }
    BinaryTreeNode<int>*leftTree=temp->left;
    while(leftTree!=NULL)
    {
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    BinaryTreeNode<int>*rightTree=temp->right;
    while(rightTree!=NULL)
    {
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    
    pair<int,int>ans=make_pair(pred,succ);
    return ans;
}