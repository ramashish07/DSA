
# Question 2 Leetcode 1434
[Problem Link ](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/)

### Approach   DP with Bitmasking 

```cpp
class Solution {
public:
    vector<int>hats2p[41];
    int dp[41][1<<11];
    int n;
    const int mod=1e9+7;
    int solve(int hat, int mask ){
         int k =__builtin_popcount(mask);
         if(k==n) return 1;
         if(hat>40) return 0;
         if(dp[hat][mask]!=-1) return dp[hat][mask];
         int ans=solve(hat+1,mask);
         for(int p:hats2p[hat]){
             if(!(mask &(1<<p))){
               ans=(ans+solve(hat+1,mask^(1<<p)))%mod;
             }
         }
         return dp[hat][mask]=ans;
    }
    int numberWays(vector<vector<int>>& hats) {
         memset(dp,-1,sizeof(dp));
         n=hats.size();
         for(int i=0;i<hats.size();i++){
               for(auto it : hats[i]){
                   hats2p[it].push_back(i);
               }
        }
        return solve(1,0);

    }
}
```
Time Complexity = O(41*2^11*11)
