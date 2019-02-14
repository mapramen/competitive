#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int h[N], d[N], a[N], b[N];
ll T[N], C[N];

void Update(ll T[], int i, int val){
  for( ; i != 0 && i < N; i += (i & -i))
    T[i] += val;
}

ll Query(ll T[], int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

void Update(int i, int k, int val){
  Update(C, i, k);
  Update(T, i, k * val);
}

ll Query(int c){
  int x = 1, y = N - 1, z = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Query(C, mid) <= c)
      z = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return Query(T, z);
}

void PreProcess(int n){
  vector< pii > v;

  for(int i = 1; i <= n; ++i){
    a[i] = max(0, h[i] - d[i]);
    v.PB(MP(a[i], i));
  }

  sort(v.begin(), v.end());

  for(int i = 1; i <= n; ++i)
    b[i] = v.size() - (lower_bound(v.begin(), v.end(), MP(a[i], i)) - v.begin());

  for(int i = 1; i <= n; ++i)
    Update(b[i], 1, a[i]);
}

int main(){
  int n, k, m;
  ll baseAns = 0, ans = 0;

  scanf("%d%d%d", &n, &k, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &h[i], &d[i]);
    baseAns += d[i];
  }

  PreProcess(n);

  ans = baseAns + Query(m);

  if(k > 0 && m > 0){
    for(int i = 1; i <= n; ++i){
      Update(b[i], -1, a[i]);
      ll ansx = h[i];
      for(int x = k; x > 0; --x)
        ansx *= 2;
      ansx += (baseAns - d[i] + Query(m - 1));
      ans = max(ans, ansx);
      Update(b[i], 1, a[i]);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
