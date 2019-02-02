#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

ll v[N], t[N], s[N], a[N + 1], b[N];

int BinarySearch(int n, int i, ll v){
  int x = i - 1, y = n, z = x;
  v += s[i - 1];
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(s[mid] <= v)
      z = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i)
    scanf("%lld", &v[i]);

  for(int i = 1; i <= n; ++i)
    scanf("%lld", &t[i]);

  for(int i = 1; i <= n; ++i)
    s[i] = t[i] + s[i - 1];

  for(int i = 1; i <= n; ++i){
    int j = BinarySearch(n, i, v[i]);
    ++a[i];
    --a[j + 1];
    b[j + 1] += (v[i] - s[j] + s[i - 1]);
  }

  for(int i = 1; i <= n; ++i)
    a[i] += a[i - 1];

  for(int i = 1; i <= n; ++i)
    printf("%lld ", a[i] * t[i] + b[i]);
  printf("\n");

  return 0;
}
