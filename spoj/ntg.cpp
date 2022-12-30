#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define MOD 1000000007

vector<vector<int>> divisors(N);
int c[N], p[N], s[N];

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

void Initialize(int k){
  for(int i = 1; i < N; ++i){
    for(int j = i; j < N; j += i){
      divisors[j].push_back(i);
    }
  }

  for(int i = 1; i < N; ++i){
    vector<int>& D = divisors[i];
    p[i] = ModularExponentation(i, k);
    
    int ans = 0;
    for(int m = D.size(), x = m - 1; x > -1; --x){
      int cnt = i / D[x];
      for(int y = x + 1; y < m; ++y){
        if(D[y] % D[x] == 0){
          cnt -= c[y];
        }
      }

      ans = (ans + 1ll * cnt * p[D[x]]) % MOD;
      c[x] = cnt;
    }

    s[i] = (s[i - 1] + ans) % MOD;
  }
}

int Solve(){
  int l, r;
  scanf("%d%d", &l, &r);
  return (MOD + s[r] - s[l - 1]) % MOD;
}

int main(){
  int k;
  scanf("%d", &k);

  Initialize(k);

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}