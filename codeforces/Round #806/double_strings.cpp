#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int n;
  scanf("%d", &n);

  set<string> S;
  vector<string> v(n);
  for(int i = 0; i < n; ++i){
    cin >> v[i];
    S.insert(v[i]);
  }

  string ans;
  for(int i = 0; i < n; ++i){
    bool found = false;
    for(int m = v[i].size(), j = 1; j < m; ++j){
      string s = string(v[i], 0, j), t = string(v[i], j);
      found = found || S.count(s) != 0 && S.count(t) != 0;
    }
    ans.push_back(found ? '1' : '0');
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}