#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 20
#define N 100001

int n, a[N], C[(1 << (B + 1))];

void ResetCnt(){
  for(int x = 0; x < (1 << (B + 1)); ++x)
    C[x] = 0;
}

void Add(int x){
  for(int i = 0, k = B - 1; k > -1; --k){
    int j = ((x & (1 << k)) > 0);
    i = (i << 1) + j + 1;
    ++C[i];
  }
}

int Query(int x, int y){
  int ans = 0;
  for(int i = 0, k = B - 1; k > -1; --k){
    int j1 = ((x & (1 << k)) > 0);
    int j2 = ((y & (1 << k)) > 0);

    if(j2)
      ans += C[(i << 1) + (1 ^ j1 ^ j2) + 1];

    i = (i << 1) + (j1 ^ j2) + 1;
  }
  return ans;
}

bool Check(int m, ll c){
  ll d = 0;
  ResetCnt();
  Add(0);
  // printf("Check: %d %lld\n", m, c);
  for(int i = 1; i <= n; ++i){
    // printf("%d %d %d\n", i, a[i], Query(a[i], m));
    d += Query(a[i], m);
    c -= Query(a[i], m);
    Add(a[i]);
  }
  // printf("%d %lld\n\n", m, d);
  return (c > 0);
}

int BinarySearch(ll c){
  int x = 0, y = (1 << B) - 1, z = 0;
  while(x <= y){
    int mid = (x + y) / 2;
    if(Check(mid, c))
      z = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  ll c;
  scanf("%d%lld", &n, &c);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; ++i)
    a[i] ^= a[i - 1];

  c = 1ll * n * (n + 1) / 2 - c + 1;

  printf("%d\n", BinarySearch(c));

  return 0;
}
