bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL)
        {
            return true;
        }
        if(r1!=NULL && r2==NULL)
        {
            return false;
        }
        if(r1==NULL && r2!=NULL)
        {
            return false;
        }
        
        bool left=isIdentical(r1->left,r2->left);
        bool right=isIdentical(r1->right,r2->right);
        
        bool data=r1->data==r2->data;
        if(left && right && data)
        {
            return true;
        }
        else{
            return false;
        }
    }