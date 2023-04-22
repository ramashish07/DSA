
# Question 5
[Problem Link ](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)

### Approach   Digit dp 

```cpp
class Solution {
public:
    int dp[33][2][2];
    int solve(int pos,string s,int tight,int prev){
        if(pos==s.size()) return 1;
        if(dp[pos][tight][prev]!=-1) return dp[pos][tight][prev];
        int ans=0;
        if(tight) {
            ans+=solve(pos+1,s,s[pos]=='0',0);
            if(s[pos]=='1' && prev==0)
            ans+=solve(pos+1,s,1,1);
        }
        else {
            ans+=solve(pos+1,s,0,0);
            if(prev==0)
            ans+=solve(pos+1,s,0,1);
        }
        return dp[pos][tight][prev]=ans;

    }
    int findIntegers(int n) {
      memset(dp,-1,sizeof(dp));
      string s;
      while(n){
        if(n %2) s.push_back('1');
        else s.push_back('0');
        n=n>>1;
      }
      reverse(s.begin(),s.end());
      // cout<<s<<endl;
      return solve(0,s,1,0);
        
    }
};
```
