bool hasPathSum(TreeNode* root, int targetSum,int sum=0) {
        if(root==NULL)
        {
            return false;
        }
        if(root->left==NULL && root->right==NULL)
        {
            sum+=root->val;
            return sum==targetSum;
        }
        sum+=root->val;
        bool leftAns=hasPathSum(root->left,targetSum,sum);
        bool rightAns=hasPathSum(root->right,targetSum,sum);
        return leftAns||rightAns;
    }