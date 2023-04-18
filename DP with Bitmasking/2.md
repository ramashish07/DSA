
# Question 2 Assign SPOJ
[Problem Link ](https://www.spoj.com/problems/ASSIGN/)

### Approach 1  DP with Bitmasking but TLE:

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
int dp[21][1<<21];
int helper(int ind , int mask ,vector<vector<int>>&v){
  if(ind==v.size()) return 1;
  if(dp[ind][mask]!=-1) return dp[ind][mask];
  int ans=0;
  for(int i=0;i<v.size();i++){
      if((mask & (1<<i)) && v[ind][i]==1) {
        ans+= helper(ind+1,mask^(1<<i),v);
      } 
  }
   return dp[ind][mask]=ans;

}
void solve()
{
    int n ;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<helper(0,(1<<n)-1,v)<<endl;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
    #endif
    fast;
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    // google
     solve();
    }   
}
    
        
```
Time Complexity =O( n*n *2^n) 

### Approach 2 :Accepted;

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
int dp[1<<21];
int helper( int mask ,vector<vector<int>>&v){
  int k =__builtin_popcount(mask);
  if(k==v.size()) return 1;
  if(dp[mask]!=-1) return dp[mask];
  int ans=0;
  for(int i=0;i<v.size();i++){
      if(!(mask & (1<<i)) && v[k][i]==1) {
        ans+= helper(mask^(1<<i),v);
      } 
  }
   return dp[mask]=ans;

}
void solve()
{
    int n ;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<helper(0,v)<<endl;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
    #endif
    fast;
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    // google
     solve();
    }   
}
    
Time Complexity = O(n*2^n)
