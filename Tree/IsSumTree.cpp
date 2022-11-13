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

///////////////APPROACH 2///////////

pair<bool,int>isSumTreeFast(Node* root)
    {
         // Your code here
         if(root==NULL)
         {
             pair<bool,int>p=make_pair(true,0);
             return p;
         }
         if(root->left==NULL && root->right==NULL)
         {
             pair<bool,int>p=make_pair(true,root->data);
             return p;
         }
         
         pair<bool,int>leftAns=isSumTreeFast(root->left);
         pair<bool,int>rightAns=isSumTreeFast(root->right);
         
         bool isLeft=leftAns.first;
         bool isRight=rightAns.first;
         
         int leftSum=leftAns.second;
         int rightSum=rightAns.second;
         
         bool cond=leftSum+rightSum==root->data;
         
         pair<bool,int>ans;
         ans.second=leftSum+rightSum+root->data;
         if(isLeft && isRight && cond)
         {
             ans.first=true;
         }
         else{
             ans.first=false;
         }
         return ans;
    }
    bool isSumTree(Node *root)
    {
        return isSumTreeFast(root).first;
    }