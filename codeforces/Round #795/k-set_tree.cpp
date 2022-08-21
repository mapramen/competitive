#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define MOD 1000000007

int fact[N], inv_fact[N];

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

void Initialize(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
  }

  inv_fact[N - 1] = ModularInverse(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    inv_fact[i] = (1ll * (i + 1) * inv_fact[i + 1]) % MOD;
  }
}

int nCr(int n, int r){
  if(n < 0 || r < 0 || n < r){
    return 0;
  }

  int q = (1ll * inv_fact[r] * inv_fact[n - r]) % MOD;
  return (1ll * fact[n] * q) % MOD;
}

vector<vector<int>> adj(N);
int n, k, subtree_size[N], c[N], dp_down[N], dp_up[N], total_cnt, total_ans = 0;

void DownDFS(int i, int p){
  subtree_size[i] = 1;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    DownDFS(j, i);
    
    subtree_size[i] += subtree_size[j];
    c[i] = (c[i] + c[j]) % MOD;
    dp_down[i] = (dp_down[i] + dp_down[j]) % MOD;
  }

  total_ans = (total_ans + dp_down[i]) % MOD;

  int cnt = (nCr(subtree_size[i], k) - c[i]) % MOD;
  dp_down[i] = (dp_down[i] + 1ll * cnt * subtree_size[i]) % MOD;
  c[i] = (c[i] + cnt) % MOD;
}

void UpDFS(int i, int p){
  int cnt = nCr(subtree_size[i] - 1, k), ans = dp_up[i];
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    cnt = (cnt + c[j]) % MOD;
    ans = (ans + dp_down[j]) % MOD;
  }

  for(int j: adj[i]){
    if(j == p){
      continue;
    }

    int c1 = (0ll + nCr(subtree_size[j] - 1, k) - (cnt - c[j])) % MOD;
    int c2 = nCr(subtree_size[j] - 1, k - 1);

    dp_up[j] = (0ll + ans - dp_down[j] + 1ll * c1 * (subtree_size[j] - 1)) % MOD;
    UpDFS(j, i);
  }

  total_ans = (total_ans + dp_up[i]) % MOD;
}

int main(){
  Initialize();

  scanf("%d%d", &n, &k);

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  total_cnt = nCr(n, k);

  DownDFS(1, 0);

  for(int i = 1; i <= n; ++i){
    int cnt = total_cnt - nCr(n - subtree_size[i], k);
    for(int j: adj[i]){
      if(subtree_size[j] > subtree_size[i]){
        continue;
      }
      cnt = (cnt - c[j]) % MOD;
    }
    total_ans = (total_ans + 1ll * cnt * n) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    subtree_size[i] = n - subtree_size[i] + 1;
  }

  c[1] = 0;
  UpDFS(1, 0);

  total_ans = (MOD + total_ans) % MOD;
  printf("%d\n", total_ans);

  return 0;
}