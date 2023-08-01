#include<bits/stdc++.h>
using namespace std; 

int Find(vector < int > & v, int n) {

  vector < int > bit(32, 0);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < 32; j++)
      if ((v[i] >> j) & 1)
        bit[j]++;

  long long ans = 0;

  int M = 1e9 + 7;
  for (int i = 0; i < n / 2; i++) {

    long long val = 0;

    for (int j = 0; j < 32; j++) {
      if (bit[j]) {
        val = (val | (1 << j));
        bit[j]--;
      }
    }

    ans += (val * val);
    ans %= M;

  }

  return ans;

}

main(){
	int N ; 
	cin >> N ; 
	
	vector<int> arr(N + 1) ; 
	
	for(int i = 0; i < N; ++i)cin >> arr[i] ; 
	
	cout << Find(arr, N) ; 
}