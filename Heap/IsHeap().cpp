int countNodes(struct Node* root)
  {
      if(root==NULL)
      {
          return 0;
      }
      
      int ans=1+countNodes(root->left) +countNodes(root->right);
      return ans;
  }
  bool isCBT(struct Node* root, int i ,int count)
  {
      if(root==NULL)
      {
          return true;
      }
      
      if(i >=count)
      {
          return false;
      }
      bool left=isCBT(root->left,2*i+1,count);
      bool right=isCBT(root->right,2*i+2,count);
      
      return (left && right);
  }
  bool isMAXheap(struct Node* root)
  {
      if((root->left == NULL) &&(root->right==NULL))
      {
          return true;
      }
      
      if(root->right==NULL)
      {
          return root->data>root->left->data;
      }
      
      bool left=isMAXheap(root->left);
      bool right=isMAXheap(root->right);
      if(left && right && (root->data>root->left->data) && (root->data>root->right->data))
      {
          return true;
      }
      else{
          return false;
      }
  }
    bool isHeap(struct Node* tree) {
        // code here
        int count=countNodes(tree);
        int index=0;
        if(isCBT(tree,index,count) && isMAXheap(tree))
        {
            return true;
        }
        else{
            return false;
        }
    }