
# Question  leetcode 698
[Problem Link ](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/)

### Approach   DP with Bitmasking 

```cpp
class Solution {
public:
    int dp[(1<<16)+1];
    int solve(int mask, int sum , int k,vector<int>&nums, int target){
          if(k==1) return 1;
          int ans=0;
          if(dp[mask]!=-1) return dp[mask];
          for(int i=0;i<nums.size();i++){
              if((1<<i)&mask) continue;
              if(sum+nums[i]>target) break;
              if(sum+nums[i]==target) {
               mask^=(1<<i);
              ans= max(ans,solve(mask,0,k-1,nums,target));
              mask^=(1<<i);
              }
              else {
                  mask^=(1<<i);
                  ans=max(ans,solve(mask,sum+nums[i],k,nums,target));
                  mask^=(1<<i);
              }
              if(ans==1) break;
              
          }
          return  dp[mask]=ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // we can do that via dp with bit masking 
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k) return  false;
        sort(nums.begin(),nums.end());
        return solve(0,0,k,nums,sum/k);

    }
};
```
