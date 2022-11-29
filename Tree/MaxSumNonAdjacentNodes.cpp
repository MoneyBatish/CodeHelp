pair<int,int> solve(Node *root)
    {
        if(root==NULL)
        {
            return make_pair(0,0);
        }
        
        pair<int,int>leftAns=solve(root->left);
        pair<int,int>rightAns=solve(root->right);
        
        pair<int,int>ans;
        
        ans.first=root->data+leftAns.second+rightAns.second;
        ans.second=max(leftAns.first,leftAns.second)+max(rightAns.first,rightAns.second);
        return ans;
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int>ans=solve(root);
        return max(ans.first,ans.second);
    }