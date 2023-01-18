  void inorder(Node* root,vector<int>&in)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
void maxHeap(Node* root,vector<int>&in,int &i)
{
    if(root==NULL)
    {
        return;
    }
    root->data=in[i--];
    maxHeap(root->right,in,i);
    maxHeap(root->left,in,i);
}
void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
    vector<int>in;
    inorder(root,in);
    int lastindex=in.size()-1;
    maxHeap(root,in,lastindex);
    }
};