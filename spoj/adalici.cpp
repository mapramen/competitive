#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define qt tuple<int,int,int>
#define N 200000
#define LYCHEE_MOD 100003

vector<vector<int>> adj(N);
vector<vector<qt>> queries(N);
vector<vector<pii>> updates(N);
int seed, A, B, path[N];

void ReadSeed(){
  scanf("%d%d%d", &seed, &A, &B);
}

int GetRandomInt(){
  int ans = seed;
  seed = (1ll * A * seed + B) % 1000000007;
  return ans;
}

void DFS(int i, int d){
  path[d] = i;
  
  for(int j: adj[i]){
    DFS(j, d + 1);
  }

  for(qt& query: queries[i]){
    int k = get<0>(query), l = get<1>(query) % (d + 1), x = get<2>(query) % LYCHEE_MOD;
    updates[path[d - l]].push_back({k, x});
  }
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  ReadSeed();

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
  }

  for(int i = 0; i < n; ++i){
    updates[i].push_back({-1, GetRandomInt() % LYCHEE_MOD});
  }

  for(int k = 0; k < q; ++k){
    int i = GetRandomInt() % n;
    queries[i].push_back({k, GetRandomInt(), GetRandomInt()});
  }

  DFS(0, 0);

  ll ans = 0;
  for(int i = 0; i < n; ++i){
    ll s = 0;
    int max_k = INT_MIN, m = 0;
    
    for(pii& update: updates[i]){
      int k, x;
      tie(k, x) = update;

      if(k > max_k){
        max_k = k, m = x;
      }

      s += x;
    }

    s -= m;
    ans += i * s;
  }

  printf("%lld\n", ans);

  return 0;
}