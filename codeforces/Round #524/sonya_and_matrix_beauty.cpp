#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 251
#define B 26
#define P 31
#define MOD 1000000007

int f[B], p[B], A[N][N][N], t[2 * N], a[2 * N], oddCount, hsh, inf = 2E9, ans = 0;
char s[N][N];

void Reset(){
  for(int i = 0; i < B; ++i){
    f[i] = 0;
  }
  oddCount = 0;
  hsh = 0;
}

int Add(char c){
  int i = max(0, c - 'a');
  ++f[i];
  oddCount += ((f[i] % 2 == 1) ? 1 : -1);
  hsh = (hsh + p[i]) % MOD;
  return (oddCount > 1) ? inf-- : hsh;
}

void FillStringMapping(int n, int m){
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      Reset();
      for(int k = j, l = 1; k <= m; ++k, ++l){
        A[l][k][i] = Add(s[i - 1][k - 1]);
      }
    }
  }
}

void PreProcess(int n, int m){
  p[0] = 1;
  for(int i = 1; i < B; ++i){
    p[i] = (1ll * P * p[i - 1]) % MOD;
  }
  FillStringMapping(n, m);
}

void ManacherAlgorithmOddLength(int n, int a[]){
  for(int i = 1; i <= n; ++i){
    t[i] = 1;
  }

  for(int i = 1; i <= n; ){
    int x = t[i] / 2 + 1;
    for( ; i - x > 0 && i + x <= n && a[i - x] == a[i + x]; ++x);
    --x;
    t[i] = 1 + 2 * x;
    int j, k;
    for(j = i + 1, k = i - 1; j <= i + x; ++j, --k){
      int y = t[k] / 2;
      t[j] = 1 + 2 * (min(j + y, i + x) - j);
      if(j + y == i + x){
        break;
      }
    }
    i = j;
  }
}

void ManacherAlgorithmEvenLength(int n, int s[]){
  a[1] = inf;
  for(int i = 1, j = 2; i <= n; ++i){
    a[j++] = s[i];
    a[j++] = inf;
  }
  ManacherAlgorithmOddLength(2 * n + 1, a);
}

void ManacherAlgorithm(int n, int a[]){
  ManacherAlgorithmOddLength(n, a);
  for(int i = 1; i <= n; ++i){
    if(a[i] < inf){
      ans += ((1 + t[i]) / 2);
    }
  }
  ManacherAlgorithmEvenLength(n, a);
  for(int i = 3; i < 2 * n + 1; i += 2){
    ans += ((t[i] - 1) / 4);
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  PreProcess(n, m);

  for(int l = 1; l <= m; ++l){
    for(int j = l; j <= m; ++j){
      ManacherAlgorithm(n, A[l][j]);
    }
  }

  printf("%d\n", ans);

  return 0;
}
