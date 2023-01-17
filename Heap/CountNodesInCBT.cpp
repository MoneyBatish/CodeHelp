int countNodes(TreeNode<int> *root)
{
    //    Write your code here.
    if(root==NULL)
    {
        return 0;
    }
    int ans=1 + countNodes(root->left) + countNodes(root->right);
}