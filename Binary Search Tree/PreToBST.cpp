BinaryTreeNode<int>*PreToBst(vector<int> &pre,int min,int max,int &i)
{
    if(i>=pre.size())
    {
        return NULL;
    }
    if(pre[i]<min || pre[i]>max){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(pre[i++]);
    root->left=PreToBst(pre,min,root->data,i);
    root->right=PreToBst(pre,root->data,max,i);
    
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int i=0;
    int mini=INT_MIN;
    int max=INT_MAX;
    return PreToBst(preorder,mini,max,i);
}