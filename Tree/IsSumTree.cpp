///////////////APPROACH #1////////////
int sum(Node *root)
    {
        if(root==NULL)
         {
             return 0;
         }
         if(root->left==NULL && root->right==NULL)
         {
             return root->data;
         }
         
         int left=sum(root->left);
         int right=sum(root->right);
         
         return left+right+root->data;
         
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         if(root==NULL)
         {
             return true;
         }
         if(root->left==NULL && root->right==NULL)
         {
             return true;
         }
         
         bool left=isSumTree(root->left);
         bool right=isSumTree(root->right);
         
         bool cond=sum(root->left)+sum(root->right)==root->data;
         
         if(left && right && cond)
         {
             return true;
         }
         else{
             return false;
         }
    }