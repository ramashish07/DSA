
# Question 3
[Problem Link ](https://leetcode.com/problems/numbers-with-repeated-digits/)

### Approach   Digit dp 

```cpp
class Solution {
public:
    int dp[11][2][2][1<<11];
    // dp with bitmasking + digit dp 
    int solve(int pos,string s, int tight, int hasrepeated, int mask){
         if(pos==s.size()) {
            if(hasrepeated) return 1;
            return 0;
         }
         if(dp[pos][tight][hasrepeated][mask]!=-1) return dp[pos][tight][hasrepeated][mask];
         int ub=tight?s[pos]-'0':9;
         int ans=0;
         for(int i=0;i<=ub;i++){
            if(i==0 && mask==0) ans+=solve(pos+1,s,tight &&(ub==i),0,mask);
            else if((1<<i)&mask)
            ans+=solve(pos+1,s,tight && (ub==i),1,mask);
            else{
             ans+=solve(pos+1,s,tight && (ub==i),hasrepeated,mask|(1<<i));
           }
         }
         return dp[pos][tight][hasrepeated][mask]=ans;
    }
    int numDupDigitsAtMostN(int n) {
        memset(dp,-1,sizeof(dp));
        string s=to_string(n);
        return solve(0,s,1,0,0);
    }
};
```
