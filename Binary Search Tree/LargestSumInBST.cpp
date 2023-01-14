class Info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
Info solve(TreeNode<int>*root,int &ans)
{
    if(root==NULL)
    {
        return {INT_MIN,INT_MAX,true,0};
    }
    
    Info Left=solve(root->left,ans);
    Info Right=solve(root->right,ans);
    
    Info currNode;
    currNode.maxi=max(root->data,Right.maxi);
    currNode.mini=min(root->data,Left.mini);
    currNode.size=Left.size+Right.size+1;
    
    if(Left.isBST && Right.isBST && ((root->data>Left.maxi) && (root->data<Right.mini)))
    {
        currNode.isBST=true;
    }
    else{
        currNode.isBST=false;
    }
    if(currNode.isBST)
    {
        ans=max(ans,currNode.size);
    }
    return currNode;
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxSize=0;
    Info temp=solve(root,maxSize);
    return maxSize;
}