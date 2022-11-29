int find(int in[],int ele,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==ele)
            {
                return i;
            }
        }
        return -1;
    }
    Node *solve(int in[],int pre[],int &index,int inStart,int inEnd,int n)
    {
        if(index>n || inStart>inEnd)
        {
            return NULL;
        }
        
        int ele=pre[index++];
        Node *temp=new Node(ele);
        int position=find(in,ele,n);
        temp->left=solve(in,pre,index,inStart,position-1,n);
        temp->right=solve(in,pre,index,position+1,inEnd,n);
        
        return temp;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preIndex=0;
        Node *ans=solve(in,pre,preIndex,0,n-1,n);
        return ans;
    }

///////////#2 Approach////////////

int createmap(int in[],map<int,int>&map,int n)
    {
        for(int i=0;i<n;i++)
        {
            map[in[i]]=i;
        }
    }
    Node *solve(int in[],int pre[],int &index,int inStart,int inEnd,int n,map<int,int>&map)
    {
        if(index>n || inStart>inEnd)
        {
            return NULL;
        }
        
        int ele=pre[index++];
        Node *temp=new Node(ele);
        int position=map[ele];
        temp->left=solve(in,pre,index,inStart,position-1,n,map);
        temp->right=solve(in,pre,index,position+1,inEnd,n,map);
        
        return temp;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preIndex=0;
        map<int,int>map;
        createmap(in,map,n);
        Node *ans=solve(in,pre,preIndex,0,n-1,n,map);
        return ans;
    }