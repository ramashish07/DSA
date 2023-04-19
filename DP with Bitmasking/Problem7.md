
# Question  leetcode 
[Problem Link ](https://leetcode.com/problems/shortest-path-visiting-all-nodes/submissions/934975142/)

### Approach   DP with Bitmasking 

```cpp
class Solution {
public:
    int dp[12][25][1<<12];
    int solve(int node,int steps, int mask,vector<vector<int>>&graph,int n){
         if(steps>2*n) return 2*n;
         if(mask==(1<<n)-1) return 0;
         if(dp[node][steps][mask]!=-1) return dp[node][steps][mask];
         int ans=INT_MAX;
         for(auto child:graph[node]){
             ans=min(ans,1+solve(child,steps+1,mask|(1<<child),graph,n));
         }
         return dp[node][steps][mask]=ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        memset(dp,-1,sizeof(dp));
        int n=graph.size();
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,solve(i,0,1<<i,graph,n));
        }
        return ans;
    }
};
```
