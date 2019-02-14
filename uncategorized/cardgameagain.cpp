#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int loss = 0, a[N];
map<int,int> d;

void UpdateX(int p, int x){
  d[p] += x;
  if(x == -1 && d[p] == -1)
    loss--;
  if(x == 1 && d[p] == 0)
    loss++;
}

void PreProcess(int n){
  for(int i = 2; i <= n / i; i++){
    while(n % i == 0){
      UpdateX(i, -1);
      n /= i;
    }
  }

  if(n > 1)
    UpdateX(n, -1);
}

void Update(int n, int x){
  for(auto p : d){
    int k, kx;
    tie(k, kx) = p;
    while(n % k == 0){
      UpdateX(k, x);
      n /= k;
    }
  }
}

int main(){
  int n, k;
  ll ans = 0;

  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  PreProcess(k);
  for(int i = 1, j = 1; i <= n; i++){
    for( ; j <= n && loss < 0; j++)
      Update(a[j], 1);
    if(loss == 0)
      ans += (n - j + 2);
    Update(a[i], -1);
  }

  if(k == 1)
    ans = 1ll * n * (n + 1) / 2;

  printf("%lld\n", ans);

  return 0;
}
