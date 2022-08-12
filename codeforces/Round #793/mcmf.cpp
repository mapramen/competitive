#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define M (2 * N)
#define MOD 1000000007

int a[N], b[N], ans[N + 1], T1[M], T2[M];
vector<ll> C;

void Reset(){
  for(int i = 0; i < M; ++i){
    T1[i] = 0, T2[i] = 0;
  }
  C.clear();
}

void Update(int T[M], int i, int x){
  for( ; i < M; i += (i & -i)){
    T[i] = (T[i] + x) % MOD;
  }
}

int Query(int T[M], int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans = (ans + T[i]) % MOD;
  }
  return ans;
}

int GetCompressedValue(ll x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

void Compute(int n){
  Reset();

  ll s = 0;
  for(int i = n; i != 0; --i){
    s += b[i];
    C.push_back(s);
  }
  C.push_back(LLONG_MIN);
  C.push_back(LLONG_MAX);
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  s = 0;
  for(int i = n; i != 0; --i){
    s += b[i];

    int cx = GetCompressedValue(s - b[i] + 1), cy = GetCompressedValue(s);
    if(b[i] > 0){
      Update(T2, 1, (1ll * b[i] * a[i]) % MOD);
      
      Update(T1, cx, (-2ll * a[i]) % MOD);
      Update(T2, cx, (2ll * ((s - b[i]) % MOD) * a[i]) % MOD);

      Update(T1, cy, (2ll * a[i]) % MOD);
      Update(T2, cy, (-2ll * (s % MOD) * a[i]) % MOD);
    }

    int A = Query(T1, cy), B = Query(T2, cy);
    ans[i] = (ans[i] + (1ll * A * (s % MOD)) % MOD + B) % MOD;
    ans[i] = (MOD + ans[i]) % MOD;
  }
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  Compute(n);

  for(int i = 1; i <= n; ++i){
    b[i] = -b[i];
  }

  Compute(n);

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d\n", (MOD + ans[i] - ans[j + 1]) % MOD);
  }

  return 0;
}