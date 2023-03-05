/*#approah 1
   Time Complexity = N2 log(n)
   Space Complexity = N2
*/

#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	vector<int>ans;
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=arr[j];
			ans.push_back(sum);
		}
	}
	sort(ans.begin(),ans.end());
	return ans[ans.size()-k];
}