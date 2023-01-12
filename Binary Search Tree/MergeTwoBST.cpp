//APPROACH #1
void inorder(TreeNode<int>*root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
void sortedArray(vector<int>inorder1,vector<int>inorder2,vector<int>&ans){
    int i=0,j=0;
    while(i<inorder1.size() && j<inorder2.size())
    {
        if(inorder1[i]<inorder2[j]){
            ans.push_back(inorder1[i]);
            i++;
        }
        else{
            ans.push_back(inorder2[j]);
            j++;
        }
    }
    while(i<inorder1.size())
    {
        ans.push_back(inorder1[i]);
        i++;
    }
    while(j<inorder2.size())
    {
        ans.push_back(inorder2[j]);
        j++;
    }
}
TreeNode<int> *inorderToBST(vector<int>&ans,int s,int e){
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode<int>*root=new TreeNode<int>(ans[mid]);
    root->left=inorderToBST(ans,s,mid-1);
    root->right=inorderToBST(ans,mid+1,e);
    
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int>inorder1;
    vector<int>inorder2;
    inorder(root1,inorder1);
    inorder(root2,inorder2);
    vector<int>ans;
    sortedArray(inorder1,inorder2,ans);
    int s=0;
    int e=ans.size()-1;
    TreeNode<int>*root=inorderToBST(ans,s,e);
    return root;
}