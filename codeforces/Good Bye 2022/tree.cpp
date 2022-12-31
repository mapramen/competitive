#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001
#define MOD 998244353
#define INV2 499122177

vector<vector<int>> adj(N);
int parent[N], p[N], a[N];
vector<pii> edges;

int ModularExponentation(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

void DFS(int i, int p){
  parent[i] = p;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    a[i] += a[j];
  }
}

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int x = 1; x <= k; ++x){
    int i;
    scanf("%d", &i);
    a[i] = 1, p[i] = 1;
  }

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
    edges.push_back({i, j});
  }

  DFS(1, 0);

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans = (ans + 1ll * a[i] * (k - a[i])) % MOD;
  }

  for(auto [i, j]: edges){
    if(j == parent[i]){
      swap(i, j);
    }

    int pij = 1ll * p[i] * (MOD + 1 - p[j]) % MOD;
    int pji = 1ll * p[j] * (MOD + 1 - p[i]) % MOD;

    int ansx = 0;
    ansx = (MOD + ansx - 1ll * pij * a[j] % MOD * (k - a[j]) % MOD) % MOD;
    ansx = (MOD + ansx - 1ll * pji * a[j] % MOD * (k - a[j]) % MOD) % MOD;

    ansx = (ansx + 1ll * pij * (k - a[j] - 1) % MOD * (a[j] + 1)) % MOD;
    ansx = (ansx + 1ll * pji * (a[j] - 1) % MOD * (k - a[j] + 1)) % MOD;

    ansx = 1ll * ansx * INV2 % MOD;
    ans = (ans + ansx) % MOD;

    p[i] = p[j] = 1ll * (p[i] + p[j]) * INV2 % MOD;
  }

  ans = (1ll * ans * ModularInverse((1ll * k * (k - 1) / 2) % MOD)) % MOD;

  printf("%d\n", ans);

  return 0;
}