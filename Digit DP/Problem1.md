
# Question 1
[Problem Link ](https://www.spoj.com/problems/GONE/)

### Approach   Digit dp 

```cpp
/*
(¯`·¯`·.¸¸.·´¯·´¯)
( \            / )
 ( ) Pandey07 ( ) 
  (/          \)  
   (.·´¯`·.¸¸.) 
*/
#include<bits/stdc++.h>
using namespace std;
#define ff    first 
#define ss    second 
#define int   long long
#define pb    push_back
#define all(v) v.begin(),v.end()
#define mp    make_pair 
#define pii   pair <int ,int >
#define vi    vector <int >
#define mii   map<int ,int >
#define pqb   priority_queue <int>
#define pqs   priority_queue<int ,vi, greater <int >>
#define setbits (x)   __builtin_popcoutll(x)
#define zrobits(X)   __builtin_ctzll(x)
#define mod   1000000007
#define endl "\n"
#define dump() {cout<<"NO"<<endl;return;}
#define ok(){cout<<"YES"<<endl;return;}
#define w(X)     int x ; cin>>x; while(x--)
#define f(i,a ,n ) for (int i =a ; i< n ; i++)
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define google {cout<<"Case #"<<i<<": ";}
//--------------------------------------------------Debugger------------------------------------------------//
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "<<x<<endl;
#else
#define debug(x)
#endif
//-----------------------------------------------Solution----------------------------------------------------//
map<int,int>m;
int dp[10][2][80];
bool isprime(int n){
    for(int i=2;i*i<=n;i++){
         if(n%i==0) return false;
    }
    return true;
}
int helper(int pos,string s ,int sum, int tight){
    if(pos==s.size()){
        if(m.find(sum)!=m.end()) return 1;
        return 0;
    }

   if (dp[pos][tight][sum]!=-1) return dp[pos][tight][sum];
   int ub=tight?s[pos]-'0':9;
   int ans=0;
   for(int i=0;i<=ub;i++){
    ans+=helper(pos+1,s,sum+i,tight && (ub==i));
   }
   return dp[pos][tight][sum]=ans;
    
}
void solve()
{
  int l,r;
  cin>>l>>r;
  l--;
  string b=to_string(r);
  string a=to_string(l);
  memset(dp,-1,sizeof(dp));
  int ans1=helper(0,a,0,1);
  memset(dp,-1,sizeof(dp));
  int ans2=helper(0,b,0,1);
  cout<<ans2-ans1<<endl;

    
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
    #endif
    fast;
    int t=1;
    cin>>t;
    for(int i=2;i<=100;i++){
        if(isprime(i)) m[i]++;
    }
    for(int i=1;i<=t;i++)
    {
    // google
     solve();
    }   
}
```
Time Complexity = O(10*2*80*10)
