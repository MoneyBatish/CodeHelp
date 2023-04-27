#define MOD 1000000007
#include<bits/stdc++.h>
long long int countDerangements(int n) {
    // Write your code here.
    long long int prev2=0;
    long long int prev1=1;
    for(int i=3;i<=n;i++){
        int curr=(i-1)*(prev2+prev1)%MOD;

        prev2=prev1;
        prev1=curr;
    }

    return prev1;
}