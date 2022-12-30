Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node *ans=NULL;
        
        while(root!=NULL)
        {
            if(root->data>=x->data){
                
                root=root->left;
            }
            else{
                ans=root;
                root=root->right;
            }
        }
        return ans;
    }