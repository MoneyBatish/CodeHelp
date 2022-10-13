node *MID(node *head)
{
    node *slow=head;
    node *fast=slow->next;
    
    while(fast->next!=NULL)
    {
        fast=fast->next;
        if(fast->next!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;        
    }
    return slow;
}
node *merge(node *left,node*right)
{
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
    }
    node *ans=new node(-1);
    node *temp=ans;
    
    while(left!=NULL && right!=NULL)
    {
        if(left->data<right->data)
        {
            temp->next=left;
            temp=left;
            left=left->next;
        }else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    return ans->next;
}
node* mergeSort(node *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    node *mid=MID(head);
    node *left=head;
    node *right=mid->next;
    mid->next=NULL;
    
    left=mergeSort(left);
    right=mergeSort(right);
    
    node *ans=merge(left,right);
    return ans;
}