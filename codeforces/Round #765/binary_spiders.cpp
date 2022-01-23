#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001
#define B 30
#define M (N * (B + 1))

int T[M][2], C[M], nxt = 0;

void Reset(){
  for( ; nxt != -1; --nxt){
    C[nxt] = 0;
    T[nxt][0] = 0, T[nxt][1] = 0;
  }
  nxt = 0;
}

void Add(int x, int val){
  int i = 0;
  for(int k = B - 1; k != -1; --k){
    int j = (x & (1 << k)) != 0;
    if(T[i][j] == 0){
      T[i][j] = ++nxt;
    }
    i = T[i][j];
    C[i] = val;
  }
}

int Query(int x, int m){
  int i = 0;
  for(int k = B - 1; k != -1; --k){
    int xb = (x & (1 << k)) != 0;
    int mb = (m & (1 << k)) != 0;
    
    if(mb == 1){
      if(T[i][1 - xb] == 0){
        return 0;
      }
    }
    else{
      if(T[i][1 - xb] != 0){
        return C[T[i][1 - xb]];
      }

      if(T[i][xb] == 0){
        return 0;
      }
    }

    i = T[i][(mb ^ xb)];
  }

  return C[i];
}

pair<vector<pii>,vector<pii>> SplitByKthBit(vector<pii>& v, int k){
  vector<pii> zeros, ones;
  for(auto [x, i]: v){
    if((x & (1 << k)) != 0){
      ones.push_back({x, i});
    }
    else{
      zeros.push_back({x, i});
    }
  }
  return {zeros, ones};
}

void Solve(vector<pii>& v, int m, vector<int>& ans){
  if(v.empty()){
    return;
  }

  Reset();

  bool found = false;
  for(auto [x, i]: v){
    int j = Query(x, m);
    if(j != 0){
      ans.push_back(i);
      ans.push_back(j);
      found = true;
      break;
    }
    Add(x, i);
  }

  if(!found){
    ans.push_back(v.front().second);
  }
}

void Solve(int k, vector<pii>& v, int m, vector<int>& ans){
  if(v.empty()){
    return;
  }

  if(k == -1 || (m & (1 << k)) != 0){
    Solve(v, m, ans);
    return;
  }

  auto [zeros, ones] = SplitByKthBit(v, k);
  Solve(k - 1, zeros, m, ans);
  Solve(k - 1, ones, m, ans);
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(m == 0){
    printf("%d\n", n);
    for(int i = 1; i <= n; ++i){
      printf("%d ", i);
    }
    printf("\n");
    return 0;
  }

  vector<pii> v(n);
  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    v[i] = {x, i + 1};
  }

  vector<int> ans;
  Solve(30, v, m, ans);

  if(ans.size() < 2){
    printf("-1\n");
    return 0;
  }

  printf("%lu\n", ans.size());
  for(int i: ans){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}