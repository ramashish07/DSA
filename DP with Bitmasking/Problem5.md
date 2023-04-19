
# Question  leetcode 464
[Problem Link ](https://leetcode.com/problems/can-i-win/description/)

### Approach   DP with Bitmasking 

```cpp
class Solution {
public:
    int dp[1<<22];
    int n;
    int t ;
    bool solve( int mask, int score){
        if(score>=t) return true;
        if(dp[mask]!=-1) return dp[mask];
        for(int i=0;i<n;i++ ){
              if(mask &(1<<i)) continue;
              if(score+i+1>=t || solve(mask^(1<<i),score+i+1)==false)
              return dp[mask]=true;
            
        }
        return dp[mask]=false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
          memset(dp,-1,sizeof(dp));
           n=maxChoosableInteger;
           t =desiredTotal;
          if((n*(n+1)/2<t) ) return false;
          return solve(0,0);
          
        
    }
};
```
