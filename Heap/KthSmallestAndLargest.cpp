#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
// Write your code here.
   vector<int> v;
   sort(arr.begin(),arr.end());
   int a=arr[k-1];
   int b=arr[n-k];
   v.push_back(a);
   v.push_back(b);
   return v;
   
}