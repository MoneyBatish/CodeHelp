void inorder(BinaryTreeNode* root,vector<int>&in)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
BinaryTreeNode *PreHeap(BinaryTreeNode* root,vector<int>&in,int &i)
{
    if(root==NULL)
    {
        return NULL;
    }
    root->data=in[i++];
    BinaryTreeNode *left=PreHeap(root->left,in,i);
    BinaryTreeNode *right=PreHeap(root->right,in,i);
    
    return root;
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
    vector<int>in;
    inorder(root,in);
    int i=0;
    BinaryTreeNode *ans=PreHeap(root,in,i);
    return ans;
}