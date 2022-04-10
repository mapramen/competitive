#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define edge tuple<int,int,int>
#define N 200001
#define MOD 998244353

vector<vector<edge>> adj(N);
vector<map<int,int>> M(N);
int least_prime_divisor[N], dp[N];

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

void Initialise(){
  for(int i = 2; i < N; ++i){
    for(int j = i; j < N; j += i){
      if(least_prime_divisor[j] == 0){
        least_prime_divisor[j] = i;
      }
    }
  }
}

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    M[i].clear();
  }
}

void AddToLCM(map<int,int>& m, int x){
  for(int y = x; y != 1; ){
    int p = least_prime_divisor[y];
    ++m[p];
    y /= p;
  }
}

int CalculateLCM(){
  int ans = 1;
  for(auto [k, v]: M[1]){
    while(v--){
      ans = (1ll * k * ans) % MOD;
    }
  }
  return ans;
}

int DFS(int i, int p, int ia, int ib){
  int heavyChild = i, ans = 1;
  for(auto [j, ja, jb]: adj[i]){
    if(j == p){
      continue;
    }

    ans = (ans + DFS(j, i, ja, jb)) % MOD;
    if(M[j].size() > M[heavyChild].size()){
      heavyChild = j;
    }
  }

  swap(M[i], M[heavyChild]);
  map<int,int>& m = M[i];

  for(auto [j, ja, jb]: adj[i]){
    if(j == p || j == heavyChild){
      continue;
    }

    for(auto [k, v]: M[j]){
      m[k] = max(m[k], v);
    }
  }

  ans = (1ll * ModularInverse(ia) * ans) % MOD;
  AddToLCM(m, ia);

  while(ib != 1){
    int x = least_prime_divisor[ib];
    m[x] = max(0, m[x] - 1);
    ans = (1ll * x * ans) % MOD;
    ib /= x;
  }

  return ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int e = 1; e < n; ++e){
    int i, j, a, b;
    scanf("%d%d%d%d", &i, &j, &a, &b);

    int g = __gcd(a, b);
    a /= g, b /= g;

    adj[i].push_back({j, a, b});
    adj[j].push_back({i, b, a});
  }

  int ans = DFS(1, 0, 1, 1);

  ans = (1ll * CalculateLCM() * ans) % MOD;
  return ans;
}

int main(){
  Initialise();
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}