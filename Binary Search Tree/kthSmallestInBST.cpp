///   VECTOR APPROACH
void inorder(BinaryTreeNode<int>* root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here
    vector<int>ans;
    inorder(root,ans);
    
    if(k>ans.size())
    {
        return -1;
    }
    else{
        return ans[k-1];
    }
}