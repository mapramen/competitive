#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Query(int m, vector<int> v){
  string s(m, '0');
  for(int i: v){
    s[i] = '1';
  }
  printf("? %s\n", s.c_str());
  fflush(stdout);

  int x;
  scanf("%d", &x);

  return x;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<pii> edges;
  for(int i = 0; i < m; ++i){
    edges.push_back({Query(m, vector<int>{i}), i});
  }
  sort(edges.begin(), edges.end());

  vector<int> v;
  int ans = 0;
  for(auto [w, i]: edges){
    v.push_back(i);
    if(Query(m, v) != ans + w){
      v.pop_back();
      continue;
    }
    ans += w;
  }

  printf("! %d\n", ans);

  return 0;
}