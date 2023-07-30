#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve (){
    ll wt;
    cin>>wt;
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll sum =accumulate(v.begin(),v.end(),0);
    if(sum<wt){
        cout<<-1<<endl;
        return;
    }
    vector<ll>bt(70,0);
    vector<ll>btt(70,0);

    for(ll i=0;i<n;i++){
        for(ll j=0;j<40;j++){
             if ((1LL<<j) & v[i]){
                bt[j]++;
                break;
             }
        }
    }
   int ans=0;
    for(ll i=0;i<63;i++){
         if(wt & (1LL<<i)){
            for(int j=i;j>=0;j--){
                while(bt[j]>0 && (1LL << j)<=(wt-(1LL<<i))){
                     bt[j]--;
                     bt[j-1]+=2;
                     ans++;
                }
            }
         }
    }
    cout<<ans<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}