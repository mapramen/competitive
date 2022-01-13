#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

map<string,tiii> M;

void AddPhoneNumber(string s, int i, int len){
  int n = s.size();
  for(int l = 0, r = len - 1; r < n; ++l, ++r){
    M[string(s, l, len)] = {l + 1, r + 1, i};
  }
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  M.clear();
  for(int i = 1; i <= n; ++i){
    string s;
    cin >> s;
    AddPhoneNumber(s, i, 2);
    AddPhoneNumber(s, i, 3);
  }

  string t;
  cin >> t;
  vector<int> dp(m + 1, -1), parent(m + 1, -1);

  dp[0] = 0, parent[0] = 0;
  for(int r = 1; r <= m; ++r){
    for(int k = 2, l = r - k + 1; k <= 3 && l >= 1; ++k, --l){
      if(parent[l - 1] != -1 && M.count(string(t, l - 1, k)) != 0){
        dp[r] = 1 + dp[l - 1], parent[r] = l;
      }
    }
  }

  vector<tiii> v;
  for(int r = m; r != 0; --r){
    int l = parent[r];
    if(l == -1){
      v.clear();
      break;
    }

    v.push_back(M[{string(t, l - 1, r - l + 1)}]);
    r = l;
  }

  if(v.empty()){
    printf("-1\n");
    return;
  }

  reverse(v.begin(), v.end());
  printf("%lu\n", v.size());
  for(auto [l, r, i]: v){
    printf("%d %d %d\n", l, r, i);
  }
  v.clear();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}