string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int>count;
		    queue<int>q;
		    string ans="";
		    for(int i=0;i<A.length();i++)
		    {
		        char ch=A[i];
		        count[ch]++;
		        q.push(ch);
		        while(!q.empty())
		        {
		            if(count[q.front()]>1)
		            {
		                q.pop();
		            }
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty())
		        {
		            ans.push_back('#');
		        }
		    }
		    return ans;
}

//////////////OR//////////////////

#include <bits/stdc++.h> 
char firstNonRepeatingCharacter(string str) {

  // Write your code here
    unordered_map<char,int>count;
    queue<char>q;
    string ans="";
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        count[ch]++;
        q.push(ch);
        while(!q.empty())
        {
            if(count[q.front()]>1)
            {
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty())
        {
            ans.push_back(str[0]);
        }
    }
    return ans[ans.length()-1];
}