void dia(Node * root,int col,map<int,vector<int>>&m)
{
    if(root==NULL)
    {
        return;
    }
    
    m[col].push_back(root->data);
    dia(root->left,col+1,m);
    dia(root->right,col,m);
}

vector<int> diagonal(Node *root)
{
   // your code here
   vector<int>ans;
   if(root==NULL)
   {
       return ans;
   }
   
   map<int,vector<int>>m;
   dia(root,0,m);
   
   for(auto i:m)
   {
       for(j:i.second)
       {
           ans.push_back(j);
       }
   }
   return ans;
}