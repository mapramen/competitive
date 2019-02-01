#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

ll a[N];

void Update(int i, int j, int x){
  a[i] += x;
  a[j] -= x;
}

int main(){
  int n, k;
  queue< pii > Q;

  scanf("%d%d", &n, &k);

  Q.push(MP(0, n));
  --k;

  while(!Q.empty() && k > 0){
    int l, r;
    tie(l, r) = Q.front();
    Q.pop();

    if(l + 1 == r || k == 0)
      continue;

    k -= 2;

    int mid = (l + r) / 2;
    int k1 = l, k2 = r + l - mid;
    Update(l, mid, k2 - k1);
    Update(mid, r, l - mid);

    Q.push(MP(l, mid));
    Q.push(MP(mid, r));
  }

  if(k != 0){
    printf("-1\n");
    return 0;
  }

  for(int i = 1; i <= n; ++i)
    a[i] += a[i - 1];

  for(int i = 0; i < n; ++i)
    printf("%lld ", a[i] + i + 1);
  printf("\n");

  return 0;
}
