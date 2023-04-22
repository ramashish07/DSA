
# Question 6
[Problem Link ](https://leetcode.com/problems/number-of-digit-one/)

### Approach   Digit dp 

```cpp
class Solution {
public:
    int dp[11][11][2];
    int solve(int pos,string s,int tight,int count){
         if(pos==s.size()) {
            return count;
         }
         if(dp[pos][count][tight]!=-1) return dp[pos][count][tight];
         int ub=tight?s[pos]-'0':9;
         int ans=0;
         for(int i=0;i<=ub;i++){
              if(i==1) ans+=solve(pos+1,s,tight&&(ub==i),count+1);
              else ans+=solve(pos+1,s,tight && (ub==i),count);
         }
         return dp[pos][count][tight]=ans;
     }
    int countDigitOne(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,s,1,0);
    }
};
```
