#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define LOGN 16

int a[N], p[N], invp[N], T[N];

void Update(int n, int i, int x){
  for( ; i <= n; i += (i & -i)){
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

int QueryGEIndex(int n, int x){
  int pos = 0;
  for(int k = LOGN, sum = 0; k != -1; --k){
    if(pos + (1 << k) <= n && sum + T[pos + (1 << k)] < x){
      pos += (1 << k);
      sum += T[pos];
    }
  }
  return pos + 1;
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  iota(invp + 1, invp + n + 1, 1);
  sort(invp + 1, invp + n + 1, [](int i, int j) { return a[i] < a[j]; });
  sort(a + 1, a + n + 1);

  for(int i = 1; i <= n; ++i){
    p[invp[i]] = i;
    Update(n, i, a[i] - a[i - 1]);
  }

  while(q--){
    int t, x;
    scanf("%d%d", &t, &x);

    if(t == 1){
      int y = invp[QueryGEIndex(n, Query(p[x]) + 1) - 1];

      swap(invp[p[x]], invp[p[y]]);
      swap(p[x], p[y]);

      Update(n, p[x], 1);
      Update(n, p[x] + 1, -1);
    }
    else if(t == 2){
      printf("%d\n", n - QueryGEIndex(n, x) + 1);
    }
    else{
      Update(n, QueryGEIndex(n, x), -1);
    }
  }

  return 0;
}