void inorder(Node* root,vector<int>&in)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
Node* NtoBst(Node* root,int s,int e,vector<int>&in)
{
    if(s>e)
    {
        return NULL;
    }
    int mid =(s+e)/2;
    Node*temp=new Node(in[mid]);
    temp->left=NtoBst(root,s,mid-1,in);
    temp->right=NtoBst(root,mid+1,e,in);
    
    return temp;
}
Node* buildBalancedTree(Node* root) {
    // Write your code here.
    vector<int>in;
    inorder(root,in);
    int n=in.size()-1;
    return NtoBst(root,0,n,in);
}