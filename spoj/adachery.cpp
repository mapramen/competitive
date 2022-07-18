#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

vector<vector<int>> adj(N);
int degrees[N];
unordered_set<ll, custom_hash> S;

ll GetEdgeHash(int n, int i, int j){
  return 1ll * (n + 1) * i + j;
}

void AddEdge(int n, int i, int j){
  ++degrees[i];
  adj[i].push_back(j);
  S.insert(GetEdgeHash(n, i, j));
}

pii GetDegreePair(int i){
  return {degrees[i], i};
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;
    AddEdge(n, i, j), AddEdge(n, j, i);
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    int d = degrees[i];
    ans += 1ll * d * (d - 1) / 2;
  }

  for(int i = 1; i <= n; ++i){
    vector<int>& v = adj[i];
    sort(v.begin(), v.end(), [](int x, int y) { return GetDegreePair(x) > GetDegreePair(y); });

    vector<int> u;
    for(int j: v){
      if(GetDegreePair(j) < GetDegreePair(i)){
        break;
      }

      for(int k: u){
        ans -= 3 * (S.count(GetEdgeHash(n, j, k)) != 0);
      }

      u.push_back(j);
    }
  }

  printf("%lld\n", ans);

  return 0;
}