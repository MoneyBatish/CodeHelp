int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int>PQ;
        for(int i=0;i<k;i++)
        {
            PQ.push(arr[i]);
        }
        
        for(int i=k;i<=r;i++)
        {
            if(arr[i]<PQ.top())
            {
             PQ.pop();
              PQ.push(arr[i]);  
            }
        }
        
        return PQ.top();
    }