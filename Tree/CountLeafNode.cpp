/////////////PREORDER TRAVERSAL ///////////////////
void PreOrder(BinaryTreeNode<int>* root,int &count)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        count++;
    }
    PreOrder(root->left,count);
    PreOrder(root->right,count); 
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int count=0;
    PreOrder(root,count);
    return count;
}
////////////INORDER TRAVERSAL//////////////////
void InOrder(BinaryTreeNode<int>* root,int &count)
{
    if(root==NULL)
    {
        return;
    }
    InOrder(root->left,count);
    if(root->left==NULL && root->right==NULL)
    {
        count++;
    }
    InOrder(root->right,count); 
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int count=0;
    InOrder(root,count);
    return count;
}
