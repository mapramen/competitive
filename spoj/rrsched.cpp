#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50001

int a[N], idxs[N], T[N];
ll ans[N];

void Update(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);
  
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  iota(idxs + 1, idxs + n + 1, 1);
  sort(idxs + 1, idxs + n + 1, [](int i, int j) { return make_pair(a[i], i) < make_pair(a[j], j); });

  for(int i = 1; i <= n; ++i){
    Update(i, 1);
  }

  ll base_time = 0, parts_completed = 0;
  for(int i = 1; i <= n; ++i){
    int j = i;
    for( ; j <= n && a[idxs[j]] == a[idxs[i]]; ++j);
    --j;

    for(int k = j; k >= i; --k){
      ans[idxs[k]] = base_time + 1ll * (n - i + 1) * (a[idxs[k]] - parts_completed - 1) + Query(idxs[k]);
      Update(idxs[k], -1);
    }

    base_time += 1ll * (n - i + 1) * (a[idxs[i]] - parts_completed);
    parts_completed = a[idxs[i]];

    i = j;
  }

  for(int i = 1; i <= n; ++i){
    printf("%lld\n", ans[i]);
  }

  return 0;
}