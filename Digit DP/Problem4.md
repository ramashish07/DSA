
# Question 4
[Problem Link ](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/)

### Approach   Digit dp 

```cpp
class Solution {
public:
    int dp[11][2];
    vector<string>dgt;
    int solve(int pos, string s , int tight ){
        if(pos==s.size()) return 1;
        if(dp[pos][tight]!=-1) return dp[pos][tight];
        int ub=tight?s[pos]-'0':9;
        int ans=0;
        for(int i=0;i<dgt.size() && stoi(dgt[i])<=ub;i++){
           ans+=solve(pos+1,s,tight && ub==stoi(dgt[i]));
        }
        return dp[pos][tight]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        dgt=digits;
        string s=to_string(n);
        string temp="9";
        int ans=0;
        for(int i=1;i<s.size();i++){
            memset(dp,-1,sizeof(dp));
            ans+=solve(0,temp,1);
            temp+="9";
        }
        memset(dp,-1,sizeof(dp));
        ans+=solve(0,s,1);
        return ans;
       
    }
};
```
