//////////APNI APPROACH//////////
vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>ans;
    	queue<Node*>q;
    	q.push(root);
    	stack<Node*>s;
    	bool leftToRight=true;
    	while(!q.empty())
    	{
    	    if(leftToRight)
    	    {
    	        int size=q.size();
    	        for(int i=0;i<size;i++)
    	        {
    	            Node* val=q.front();
    	            q.pop();
    	            ans.push_back(val->data);
    	            if(val->left)
    	            {
    	                q.push(val->left);
    	            }
    	            if(val->right)
    	            {
    	                q.push(val->right);
    	            }
    	        }
    	        leftToRight=false;
    	    }
    	    else{
    	        int size=q.size();
    	        for(int i=0;i<size;i++)
    	        {
    	            Node* val=q.front();
    	            q.pop();
    	            s.push(val);
    	            if(val->left)
    	            {
    	                q.push(val->left);
    	            }
    	            if(val->right)
    	            {
    	                q.push(val->right);
    	            }
    	        }
    	        while(!s.empty())
    	        {
    	            Node* val=s.top();
    	            s.pop();
    	            ans.push_back(val->data);
    	        }
    	        leftToRight=true;
    	    }
    	    
    	}
    	return ans;
    }

////////////LOVE BABBAR APPROACH////////

vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>ans;
    	queue<Node*>q;
    	q.push(root);
    	bool leftToRight=true;
    	while(!q.empty())
    	{
    	    int size=q.size();
    	    vector<int>temp(size);
    	    for(int i=0;i<size;i++)
    	    {
    	        Node* val=q.front();
    	        q.pop();
    	        int index=leftToRight?i:size-i-1;
    	        temp[index]=val->data;
    	        if(val->left)
    	        {
    	            q.push(val->left);
    	        }
    	        if(val->right)
    	        {
    	            q.push(val->right);   
    	        }
    	    }
    	    for(auto i:temp)
    	    {
    	        ans.push_back(i);
    	    }
    	    leftToRight=!leftToRight;
    	}
    	return ans;
    }