#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000051
#define B 26

string s;
int pi[N], T[N][B];

int ComputeFailure(int n, int i, char c){
  i = pi[i];

  if(i < n){
    return T[i][c - 'a'];
  }

  return s[i] == c ? i + 1 : ComputeFailure(n, i, c);
}

int main(){
  cin.tie(0);
	iostream::sync_with_stdio(false);
  cin >> s;

  int n = s.size();

  for(int i = 1; i <= n; ++i){
    T[i - 1][s[i - 1] - 'a'] = i;
  }

  for(int i = 1; i < n; ++i){
    int fi = pi[i];
    for(int k = 0; k < B; ++k){
      T[i][k] = T[fi][k];
    }
    
    int k = s[i] - 'a';
    T[i][k] = i + 1;
    pi[i + 1] = T[fi][k];
  }

  int q;
  cin >> q;

  while(q--){
    string t;
    cin >> t;
    s += t;

    for(int i = n + 1, m = s.size(); i <= m; ++i){
      pi[i] = ComputeFailure(n, i - 1, s[i - 1]);
      cout << pi[i] << ' ';
    }
    cout << '\n';

    for(int i = t.size(); i > 0; --i){
      s.pop_back();
    }
  }

  return 0;
}