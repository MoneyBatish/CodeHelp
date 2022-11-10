#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
	// Write your code here.
    long long sum=0;
    for(int i=0;i<=n-k;i++)
    {
        int mini=arr[i];
        int maxi=arr[i];
        for(int j=i+1;j<i+k;j++)
        {
            mini=min(mini,arr[j]);
            maxi=max(maxi,arr[j]);
        }
        sum+=maxi+mini;
    }
    return sum;
}

//////////////////OR///////////////

#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
	// Write your code here.
    deque<int>maxi,mini;
    for(int i=0;i<k;i++)
    {
       while(!maxi.empty() && arr[maxi.back()]<=arr[i])
       {
           maxi.pop_back();
       }
       while(!mini.empty() && arr[mini.back()]>=arr[i])
       {
           mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    long long sum=arr[maxi.front()]+arr[mini.front()];
    for(int i=k;i<n;i++)
    {
        while(!maxi.empty() && i-maxi.front()>=k)
        {
            maxi.pop_front();
        }
        while(!mini.empty() && i-mini.front()>=k)
        {
            mini.pop_front();
        }
        
        while(!maxi.empty() && arr[maxi.back()]<=arr[i])
       {
           maxi.pop_back();
       }
       while(!mini.empty() && arr[mini.back()]>=arr[i])
       {
           mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        
        sum+=arr[maxi.front()]+arr[mini.front()];
    }
    return sum;
}
