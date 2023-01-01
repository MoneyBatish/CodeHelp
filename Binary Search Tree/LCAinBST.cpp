/// RECURSION APPROACH
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(root==NULL)
    {
      return NULL;  
    }
    
    if(root->data>P->data && root->data>Q->data)
    {
        return LCAinaBST(root->left,P,Q);
    }
    if(root->data<P->data && root->data<Q->data)
    {
        return LCAinaBST(root->right,P,Q);
    }
    return root;
}  

/// ITERATIVE APPROACH
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL)
        {
            if(root->val>p->val && root->val>q->val){
                root=root->left;
            }
            else if(root->val<p->val && root->val<q->val){
                root=root->right;
            }
            else{
                return root;
            }
        }
        return NULL;
    }