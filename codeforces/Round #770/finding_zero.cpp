#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

map<vector<int>,int> queries;

void Reset(){
  queries.clear();
}

int Query(int i, int j, int k){
  vector<int> v{i, j, k};
  sort(v.begin(), v.end());

  if(queries.count(v) != 0){
    return queries[v];
  }

  printf("? %d %d %d\n", i, j, k);
  fflush(stdout);

  int x;
  scanf("%d", &x);

  queries[v] = x;
  return x;
}

void PrintAns(int i, int j){
  printf("! %d %d\n", i, j);
  fflush(stdout);
}

tiii GetExtremes(int a, int b, int c, int d){
  vector<int> v{a, b, c, d};
  int dis = 0, x, y, z;

  for(int i = 0; i < 4; ++i){
    for(int j = i + 1; j < 4; ++j){
      vector<pii> t;
      for(int k = 0; k < 4; ++k){
        if(k == i || k == j){
          continue;
        }
        t.push_back({Query(v[i], v[j], v[k]), v[k]});
      }
      sort(t.begin(), t.end());

      if(t.front().first == t.back().first && t.front().first >= dis){
        dis = t.front().first;
        x = v[i], y = v[j], z = t.front().second;
      }
    }
  }

  return {x, y, z};
}

void Solve(){
  int n;
  scanf("%d", &n);
  
  Reset();

  int i = 1, j = 2, k = 0;
  for(int x = 3; x <= n; x += 2){
    tie(i, j, k) = GetExtremes(i, j, x, x == n ? k : x + 1);
  }

  PrintAns(i, j);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}