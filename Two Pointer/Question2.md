
# Question2
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 
[Question Link](https://leetcode.com/problems/valid-palindrome-ii/)  
Approach:-
- Take left pointer as i=0, and right pointer to be j=n-1 
- if s[i]== s[j] then simply do i++ , and j--;
- if s[i]!=s[j] , we can remove either s[i] or s[j] , if we remove s[i] than the string from i+1 to j must be a palindrome in order to return true or we if we remove j then the string from i to j-1
must me a palindrome, as we can remove atmost one character

```cpp
class Solution {
public:
    bool check(string s ){
         int i=0,j=s.size()-1;
         while(i<=j){
              if(s[i]==s[j]){
                  i++;
                  j--;
              }
              else return false;
         }
         return true;
    }
    bool validPalindrome(string s) {
           int n=s.size();
           int lo=0,hi=n-1;
           int cnt=0;
           while(lo<hi){
                if (s[lo]!=s[hi]){
                    if(check(s.substr(lo+1,hi-lo))|| check(s.substr(lo,hi-lo))) return true;
                    return false;
                }
                else{
                lo++;
                hi--;
                }
           }
           return true;
    }
};
```


