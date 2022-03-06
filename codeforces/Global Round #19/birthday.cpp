#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

vector<int> C;
priority_queue<tiii> Q;

int Power2(int n){
  int m = 1;
  while(m < n){
    m <<= 1;
  }
  return m;
}

void Reset(int n){
  C.clear();
  C.resize(Power2(n) + 1);
}

void Push(int p, int i, int x){
  Q.push({Power2(i), p, i});
  C[i] += x;
}

void Solve(){
  int n;
  scanf("%d", &n);

  if(n == 2){
    printf("-1\n");
    return;
  }

  Reset(n);

  vector<pii> ans;

  for(int i = 1; i <= n; ++i){
    Push(0, i, 1);
  }

  while(!Q.empty()){
    auto [_, p, i] = Q.top();
    --p;

    Q.pop();

    if((i & (i - 1)) == 0 || C[i] == 0){
      continue;
    }

    int j = Power2(i) - i;

    if(C[j] == 0){
      Push(p, i, 0);
      continue;
    }

    if(i < j){
      swap(i, j);
    }

    int z = min(C[i], C[j]);

    C[i] -= z, C[j] -= z;
    Push(p, i + j, z), Push(p, i - j, z);

    while(z--){
      ans.push_back({i, j});
    }
  }

  vector<int> v;

  int m = Power2(n);

  for(int i = 1; i <= m; ++i){
    while(C[i]--){
      v.push_back(i);
    }
  }

  for(int i = 1; i < v.size(); ++i){
    if(v[i] == v[i - 1]){
      ans.push_back({v[i], v[i]});
      v[i] *= 2, v[i - 1] = 0;
      break;
    }
  }

  for(int& x: v){
    if(x == 0){
      continue;
    }

    while(x < m){
      ans.push_back({0, x});
      ans.push_back({x, x});
      x *= 2;
    }
  }

  ans.push_back({0, m});

  printf("%lu\n", ans.size());
  for(auto [x, y]: ans){
    printf("%d %d\n", x, y);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}