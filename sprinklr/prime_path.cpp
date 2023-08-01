#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<ll>par;
vector<ll>size;
vector<vector<ll>>tree;

ll find(ll node){
    if(node == par[node]) return node;
    return par[node] = find(par[node]);
}

void merge(int u , int v ){
    int x = find(u);
    int y = find (v);
    if(x==y) return ;
    if(size[x]<size[y]) swap(x,y);
    par[y]=x;
    size[x]+=size[y];
}
void solve(){
    ll n ;
    cin>>n;
    tree.clear();
    par.clear();
    size.clear();
    tree.resize(n+1);
    par.resize(n+1);
    size.resize(n+1,1);
    for(ll i=1;i<=n;i++){
        par[i]=i;
    }
    vector<ll>primes;
    vector<ll>isprime(n+2,1);
    isprime[0]=0;
    isprime[1]=0;
    for(ll i=2;i*i<=n;i++){
         if(isprime[i]){
            primes.push_back(i);
            for(ll j =i*i;j<=n;j+=i){
                isprime[j]=0;
            }
         }
    }

    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        if(isprime[u] && isprime[v]){
            continue;
        }
        else if (isprime[u]){
            tree[u].push_back(v);
        }
        else if (isprime[v]){
            tree[v].push_back(u);
        }
        else {
            merge(u,v);
        }
    }
    ll ans=0;
    for(ll i=0;i<primes.size();i++){
        ll in =1LL;
        for(auto child:tree[primes[i]]){
            in+=size[find(child)];
        }

        for(auto child:tree[primes[i]]){
            ans+=(1LL*size[find(child)]*(in-size[find(child)]));
            in-=size[find(child)];
        }

    }
    cout<<ans<<endl;


}
int main(){
    solve();
}
