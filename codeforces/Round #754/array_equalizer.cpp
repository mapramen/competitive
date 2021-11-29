#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

ll m[N], c[N], a[N], b[N];

void Update(int i, ll m, ll c){
  if(i >= N){
    return;
  }
  a[i] += m, b[i] += c;
}

void Update(int l, int r, ll m, ll c){
  l = max(0, l), r = min(N - 1, r);
  if(r < l){
    return;
  }

  Update(l, m, c);
  Update(r + 1, -m, -c);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    c[i] = x;
  }

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    c[i] = (i == 1 ? 0 : x) - c[i];
  }

  m[1] = 1;
  for(int i = 1; i <= n; ++i){
    ll mi = m[i], ci = c[i];
    for(int j = 2 * i; j <= n; j += i){
      m[j] -= mi, c[j] -= ci; 
    }

    if(mi == 0){
      ci = abs(ci);
    }

    if(mi < 0){
      mi = -mi, ci = -ci;
    }

    if(mi == 0){
      Update(INT_MIN, INT_MAX, 0ll, ci);
    }
    else{
      Update(INT_MIN, -ci, -1, -ci);
      Update(-ci, INT_MAX, 1, ci);
    }
  }

  for(int i = 1; i < N; ++i){
    a[i] += a[i - 1], b[i] += b[i - 1];
  }

  int q;
  scanf("%d", &q);
  while(q--){
    int i;
    scanf("%d", &i);
    printf("%lld\n", a[i] * i + b[i]);
  }

  return 0;
}