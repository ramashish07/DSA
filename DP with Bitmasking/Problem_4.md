
# Question  leetcode 1595
[Problem Link ](https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/)

### Approach   DP with Bitmasking 

```cpp
class Solution {
public:
    int dp[13][1<<13];
    vector<vector<int>>Cost;
    int n;
    int m;
    int solve(int ind, int mask2, vector<int>&min_in_col){ 
        int k=__builtin_popcount(mask2);
        if(ind==n) {
            int sum=0;
            for(int j=0;j<m;j++){
                 if(!(mask2 &(1<<j))){
                     sum+=min_in_col[j];
                 }
            }
            return sum;
        }
        if(dp[ind][mask2]!=-1) return dp[ind][mask2];
        int ans=1e9;
        for(int j=0;j<m;j++){
            ans=min(ans,Cost[ind][j]+solve(ind+1,mask2|(1<<j),min_in_col));
        }
        return dp[ind][mask2]=ans;

    }
    int connectTwoGroups(vector<vector<int>>& cost) {
     Cost=cost;
     n=cost.size();
     m=cost[0].size();
     memset(dp,-1,sizeof(dp));
     vector<int>min_in_col(m);
     for(int j=0;j<m;j++){
         int mini=1e9;
         for(int i=0;i<n;i++){
           mini=min(mini,cost[i][j]);
         }
         min_in_col[j]=mini;
     }
    return  solve(0,0,min_in_col);
    }
};
```
