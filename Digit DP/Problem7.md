
# Question 7
[Problem Link ](https://leetcode.com/problems/count-numbers-with-unique-digits/)

### Approach   Digit dp 
```cpp
class Solution {
public:
    int dp[11][2][2][1<<11];
    int solve(int pos,string s,int tight,int hasrepeated,int mask){
         if(pos==s.size()){
             if(hasrepeated) return 0;
             else return 1;
         }
         
         if(dp[pos][tight][hasrepeated][mask]!=-1) return dp[pos][tight][hasrepeated][mask];

         int ub=tight?s[pos]-'0':9;

         int ans=0;

         for(int i=0;i<=ub;i++){
             if(i==0 && mask==0) ans+=solve(pos+1,s,tight && (ub==i),0,mask);
             else if((1<<i) & mask) ans+=solve(pos+1,s,tight && (ub==i),1,mask);
             else ans+=solve(pos+1,s,tight && (ub==i),hasrepeated,mask|(1<<i));
         }
         return dp[pos][tight][hasrepeated][mask]=ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        int x =pow(10,n)-1;
        cout<<x<<endl;
        string s=to_string(x);
        memset(dp,-1,sizeof(dp));
        return solve(0,s,1,0,0);

    }
};
```
