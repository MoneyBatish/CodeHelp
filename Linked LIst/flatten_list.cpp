Node *merge(Node *down,Node *right)
{
    if(down==NULL)
        return right;
    if(right==NULL)
        return down;
    Node *ans=new Node(-1);
    Node *temp=ans;
    while(down!=NULL && right!=NULL)
    {
        if(down->data<right->data)
        {
            temp->child=down;
            temp=down;
            down=down->child;
        }
        else{
            temp->child=right;
            temp=right;
            right=right->child;
        }
    }
    if(down!=NULL)
    {
        temp->child=down;
        temp=down;
        down=down->child;
    }
    if(right!=NULL)
    {
         temp->child=right;
         temp=right;
         right=right->child;
    }
    return ans->child;
}
Node* flattenLinkedList(Node* head) 
{
    // Write your code here
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *down=head;
    Node*right=head->next;
    down->next=NULL;
    right=flattenLinkedList(right);
    return merge(down,right);
}

