#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int d[N], c[N];

int main(){
  int n;

  scanf("%d", &n);
  ++c[d[1]];

  for(int i = 2; i <= n; ++i){
    int p;
    scanf("%d", &p);
    d[i] = 1 + d[p];
    ++c[d[i]];
  }

  int ans = 0;
  for(int i = 0; i < N; ++i)
    ans += (c[i] % 2);

  printf("%d\n", ans);

  return 0;
}
