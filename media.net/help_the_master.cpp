#include<bits/stdc++.h>
#include <thread>
#include <mutex>
using namespace std;

vector<vector<bool>> visited;
vector<int> comp(1e6+1);
long long mod=7985896514;

long long find(int x) {
    long long ans=0ll;
    for (int y=2*x;y<=1e6;y+=x) {
        if (comp[y] && comp[y]!=comp[x]) ans=(ans+y)%mod;
    }
    return ans;
}

void dfs(int i, int j, vector<vector<int>>& a, int id) {
    visited[i][j]=true;
    comp[a[i][j]]=id;
    if (i-1>=0 && !visited[i-1][j] && a[i-1][j]!=-1) dfs(i-1,j,a,id);
    if (i+1<a.size() && !visited[i+1][j] && a[i+1][j]!=-1) dfs(i+1,j,a,id);
    if (j-1>=0 && !visited[i][j-1] && a[i][j-1]!=-1) dfs(i,j-1,a,id);
    if (j+1<a.size() && !visited[i][j+1] && a[i][j+1]!=-1) dfs(i,j+1,a,id);
}

long long solve(vector<vector<int>> &a)
{
    int n = a.size();
    int negs=0;
	for (int i=0;i<n;i++) {
	    for (int j=0;j<n;j++) {
	        if (a[i][j]==-1) negs++;
	    }
	}
	visited.resize(n, vector<bool>(n));
	int id=1;
	for (int i=0;i<n;i++) {
	    for (int j=0;j<n;j++) {
	        if (!visited[i][j] && a[i][j]!= -1) {
	            dfs(i,j,a,id);
	            id++;
	        }
	    }
	}
	long long ans=0ll;
	for (int i=0;i<n;i++) {
	    for (int j=0;j<n;j++) {
	        if (a[i][j]>0) {
	            long long cntrb=find(a[i][j]);
    	        ans=(ans+cntrb)%mod;
	        }
	    }
	}
	ans-=negs;
	ans%=mod;
	ans+=mod;
	ans%=mod;
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i=0;i<n;i++) {
	    for (int j=0;j<n;j++) {
	        cin >> a[i][j];
	    }
	}

	cout << solve(a) << '\n';
	return 0;
}