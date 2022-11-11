int maxDepth(TreeNode<int> *root) {
    // Write your code here.
    if(root==NULL)
    {
        return -1;
    }
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    int ans=max(left,right)+1;
    return ans;
}