#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 55
#define MOD 998244353

int c[N][N], p[N][N], A[N][N + 1];

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

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i < N; ++i){
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }

  for(int i = 0; i < N; ++i){
    for(int j = 0, x = 1; j < N; ++j, x = (1ll * i * x) % MOD){
      p[i][j] = x;
    }
  }

  for(int m = 1; m < N; ++m){
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
      for(int k = 1; k <= m; ++k){
        int cntk = 0;
        for(int x = 0; x < i; ++x){
          for(int y = x + 1; y <= n - i; ++y){
            int cntxy = (1ll * c[i - 1][x] * c[n - i][y]) % MOD;
            cntxy = (1ll * cntxy * p[k - 1][x]) % MOD;
            cntxy = (1ll * cntxy * p[m + 1 - k][i - 1 - x]) % MOD;
            cntxy = (1ll * cntxy * p[m - k][y]) % MOD;
            cntxy = (1ll * cntxy * p[k][n - i - y]) % MOD;

            cntk = (cntk + cntxy) % MOD;
          }
        }
        cnt = (cnt + 1ll * k * cntk) % MOD;
      }
    }
    A[m - 1][N] = cnt;
  }

  for(int i = 1; i < N; ++i){
    for(int j = 0; j < N; ++j){
      A[i - 1][j] = p[i][j];
    }
  }

  for(int i = 0; i < N; ++i){
    int pivot = i;
    for( ; pivot < N && A[pivot][i] == 0; ++pivot);
    if(pivot == N){
      break;
    }

    swap(A[i], A[pivot]);

    for(int j = i, x = ModularInverse(A[i][i]); j <= N; ++j){
      A[i][j] = (1ll * x * A[i][j]) % MOD;
    }

    for(int k = 1; k < N; ++k){
      if(k == i){
        continue;
      }

      for(int j = i, x = A[k][i]; j <= N; ++j){
        A[k][j] = (A[k][j] - 1ll * x * A[i][j]) % MOD;
        A[k][j] = (MOD + A[k][j]) % MOD;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < N; ++i){
    if(A[i][i] == 0){
      continue;
    }
    ans = (ans + 1ll * A[i][N] * ModularExponentation(m, i)) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}