#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300005

int a[N], fib[N], MOD;
char type[2];

int Initialise(int n){
  fib[1] = 1, fib[2] = 1;
  for(int i = 3; i < N; ++i){
    fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    a[i] = (MOD + a[i]) % MOD;
  }

  for(int i = n; i != 1; --i){
    a[i] = (a[i] - a[i - 1] - a[i - 2]) % MOD;
  }

  int unequal_count = 0;
  for(int i = n; i != 0; --i){
    unequal_count += (a[i] != 0);
  }

  return unequal_count;
}

void Update(int i, int m, int x){
  a[i] = (a[i] + x * fib[m]) % MOD;
}

int IsUnequal(int n, int i){
  return i > n ? 0 : a[i] != 0;
}

int GetUnequalCount(int n, int l, int r){
  return IsUnequal(n, l) + IsUnequal(n, r + 1) + IsUnequal(n, r + 2);
}

int main(){
  int n, q;
  scanf("%d%d%d", &n, &q, &MOD);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    a[i] -= x;
  }

  int unequal_count = Initialise(n);

  while(q--){
    int l, r;
    scanf("%s%d%d", type, &l, &r);

    bool equal = true;
    int x = type[0] == 'A' ? 1 : -1, m = r - l + 1;

    unequal_count -= GetUnequalCount(n, l, r);

    Update(l, 1, x);
    Update(r + 1, m + 1, -x);
    Update(r + 2, m, -x);

    unequal_count += GetUnequalCount(n, l, r);

    printf("%s\n", unequal_count == 0 ? "YES" : "NO");
  }

  return 0;
}