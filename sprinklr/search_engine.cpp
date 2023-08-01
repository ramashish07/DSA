#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int fre=0;
    bool flag=false;

    bool contains_key(char ch){
        return links[ch-'a']!=NULL;
    }

    Node* get(char ch){
       return links[ch-'a'];
    }
    void set(char ch ,Node* node){
         links[ch-'a']=node;
    }

    void set_freq(int freq){
          fre+=freq;
    }
    int get_fre(){
        return fre;
    }

};
class Trie{
    public:
    Node* root; 
    Trie(){
        root = new Node();
    }

    void insert(string s,int freq){
        Node* node =root;
        for(int i=0;i<s.size();i++){
             if(!node->contains_key(s[i])){
                 node->set(s[i], new Node());
             }
             node = node->get(s[i]);
             node->set_freq(freq);
        }
        // node->set_freq(freq);
    }

    int prefixquery(string s){
        Node* node = root;
        for(int i=0;i<s.size();i++){
            if(!node->contains_key(s[i]))
              return 0;
            node= node->get(s[i]);
        }
        return node->get_fre();
    }

    void update(string s, int freq){
          Node* node =root;
        for(int i=0;i<s.size();i++){
             node = node->get(s[i]);
             node->set_freq(freq);
        }
        node->set_freq(freq);
    }
};
void solve(){
    int q;
    cin>>q;
    Trie trie;
    while (q--)
    {
        char c;
        cin>>c;
        if(c=='I'){
            string s;
            int freq;
            cin>>s;
            cin>>freq;
            trie.insert(s,freq);
        }
        else  if(c=='U'){
            string s;
            int f;
            cin>>s>>f;
            trie.update(s,f);
        }
        else{
            string s;
            cin>>s;
            cout<<trie.prefixquery(s)<<endl;
        }
    }
    

}
int main(){
     solve();
}