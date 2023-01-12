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


//APPROACH #2
void ConvertBSTtoDLL(TreeNode<int>*root,TreeNode<int>* &head)
{
    if(root==NULL)
    {
        return;
    }
    ConvertBSTtoDLL(root->right,head);
    
    root->right=head;
    
    if(head!=NULL)
    {
        head->left=root;
    }
    head=root;
    ConvertBSTtoDLL(root->left,head);
}
TreeNode<int> *mergeTwoDLL(TreeNode<int> *head1,TreeNode<int> *head2){
    TreeNode<int>*head=NULL;
    TreeNode<int>*tail=NULL;
    while(head1 != NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            if(head==NULL)
            {
                head=head1;
                tail=head;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;          
            }
        }
        else{
            if(head==NULL)
            {
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right; 
            }
        }
    }
    while(head1 != NULL)
    {
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;  
    }
    while(head2!=NULL)
    {
      tail->right=head2;
      head2->left=tail;
      tail=head2;
      head2=head2->right;   
    }
    return head;
}
int countNodes(TreeNode<int> *root)
{
    int count=0;
    while(root!=NULL)
    {
        count++;
        root=root->right;
    }
    return count;
}
TreeNode<int> *DLLtoBST(TreeNode<int> *&head,int n)
{
    if(n<=0 || head==NULL)
    {
        return NULL;
    }
    TreeNode<int> *left=DLLtoBST(head,n/2);
    TreeNode<int> *root=head;
    root->left=left;
    head=head->right;
    root->right=DLLtoBST(head,n-n/2-1);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    TreeNode<int>*head1=NULL;
    ConvertBSTtoDLL(root1,head1);
    head1->left=NULL;
    
    TreeNode<int>*head2=NULL;
    ConvertBSTtoDLL(root2,head2);
    head2->left=NULL;
    
    TreeNode<int>*head=mergeTwoDLL(head1,head2);
    
    TreeNode<int>*root=DLLtoBST(head,countNodes(head));
    return root;
}