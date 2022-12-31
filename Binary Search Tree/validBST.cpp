/// INORDER APPROACH 
void inorder(BinaryTreeNode<int> *root, vector<int> &ans){
    if(root == NULL){
        return ;
    }
    inorder(root -> left, ans);
    ans.push_back(root -> data);
    inorder(root -> right, ans);
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<int> ans;
    inorder(root, ans);
    
    if(is_sorted(ans.begin(), ans.end())){
        return true;
    }
    else{
        return false;
    }
}


///////MINIMUM AND MAXIMUM APPROACH
bool isBST(BinaryTreeNode<int>*root,int min,int max)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>=min && root->data<=max)
    {
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isBST(root,INT_MIN,INT_MAX);
}