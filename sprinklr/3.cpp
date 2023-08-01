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
int n;
vi v;
vector<vector<int>>dp;
vector<int>primes={2 , 3 , 5 ,7, 11,13,17,19,23,29};
int helper(int ind, int mask){
    if(ind>=n){
     if(mask ==0) return 0;
     return 1;
    }
    if(dp[ind][mask]!=-1){
    return dp[ind][mask];
    }
    int flag=0;
    int newmask = mask;
    for(int i=0;i<primes.size();i++){
        int it =primes[i];
        int x = v[ind];
        int cnt=0;
        while(x>1 && x %it==0){
             cnt++;
             x/=it;
        }
        if(cnt>1) {
            flag=1;
            break;
        }
        else if(cnt ==1 && mask & (1<<i)){
            flag= 1;
            break;
        }
       else if (cnt==1){
          newmask|=(1<<i);
       }
        
    }
     if(flag==1){
        return dp[ind][mask]=helper(ind+1, mask);
     }
      return dp[ind][mask]=helper(ind+1, newmask)+helper(ind+1,mask);
    
      
}
void solve()
{
    dp.clear();
    v.clear();
    cin>>n;
    v.resize(n);
    dp.resize(n,vector<int>(1<<11,-1));
    for(int i=0;i<n;i++){
        cin>>v[i];
        // cout<<v[i]<<endl;
    }
    cout<<helper(0,0)<<endl;
    
    
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
    
        
