int findCelebrity(int n) {
 	// Write your code here.
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        s.push(i);
    }
    while(s.size()!=1)
    {
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(knows(a,b))
        {
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int celebrity=s.top();
    int zeroCount=0;
    for(int i=0;i<n;i++)
    {
        if(M[celebrity][i]==0)
        {
            zeroCount++;
        }
    }
    if(zeroCount!=n)
    {
        return -1;
    }
    int oneCount=0;
    for(int i=0;i<n;i++)
    {
        if(M[i][celebrity]==1)
        {
            oneCount++;
        }
    }
    if(oneCount!=n-1)
    {
        return -1;
    }
    return celebrity;
}