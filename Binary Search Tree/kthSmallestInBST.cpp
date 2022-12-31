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


// Iterative Approach
int solve(TreeNode<int>*root,int &i,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    int left=solve(root->left,i,k);
    if(left != -1){
        return left;
    }
    i++;
    if(i==k)
    {
        return root->data;
    }
    
    return solve(root->right,i,k);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int i=0;
   int ans=solve(root,i,k);
    return ans;
}