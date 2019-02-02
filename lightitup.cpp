#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100002

int a[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  a[n + 1] = m;

  int ans = 0, x = 0, y = 0;
  for(int i = n; i > -1; --i){
    int ans1 = 0;

    if(a[i + 1] - a[i] > 1){
      ans1 = a[i + 1] - a[i] - 1 + x - y;
    }

    x += (a[i + 1] - a[i]);
    if(i % 2 == 0){
      y += (a[i + 1] - a[i]);
    }

    int ans2 = y;
    ans = max(ans, ans1 - ans2);
  }

  ans += y;

  printf("%d\n", ans);

  return 0;
}
