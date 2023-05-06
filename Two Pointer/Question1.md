
# Question1 
Given a non-negative integer c, decide whether there're two integers a and b such that a^2 + b^2 = c.  
[Question Link](https://leetcode.com/problems/sum-of-square-numbers/)  
Approach:- clearly a and b will lie between 0 and ceil(sqrt(c)),Therefore simply apply two pointer in that range 
```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long   x= ceil(sqrt(c)*1.00);
        long long li=0,hi=x;
        while(li<=hi){
            long long n=1LL*li*li+1ll*hi*hi;
            if(n==c){
                return true;
            }
            else  if(c>n){
                li++;
            }
            else hi--;
        }
        return false;
        
    }
};
```


