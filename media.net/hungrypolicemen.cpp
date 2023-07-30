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
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++){
        int a , b , c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    priority_queue<pair<int,int>>pq;
    vector<int>v(n+1,-1);
    int k;
    cin>>k;
    for(int  i=0;i<k;i++){
        int x, y;
        cin>>x>>y;
        v[x]=y;
        pq.push({y,x});
    }
    while(pq.size()){
        int sat = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int child =it.first;
            int len = it.second;
            if(sat-len>v[child]){
                v[child]=sat-len;
                pq.push({v[child],child});
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(v[i]>=0) cnt++;
    }
    cout<<cnt<<endl;


    
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
    #endif
    fast;
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
    // google
     solve();
    }   
}
    
        
