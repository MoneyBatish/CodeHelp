long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>PQ;
        
        for(int i=0;i<n;i++)
        {
            PQ.push(arr[i]);
        }
        
        long long cost =0;
        while(PQ.size()>1)
        {
            long long a=PQ.top();
            PQ.pop();
            long long b=PQ.top();
            PQ.pop();
            
            long long sum=a+b;
            cost+=sum;
            
            PQ.push(sum);
        }
        return cost;
    }