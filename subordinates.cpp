#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N], b[N];

int main(){
  int n, s, i, j, k, x,y, z, ans;

  scanf("%d%d", &n, &s);

  for(i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(i = 1; i <= n; i++){
    if(i != s && a[i] != 0)
      b[a[i]]++;
  }

  for(b[0] = 1, x = 0, y = n - 1, i = 1, ans = n - 1; i < n; i++){
    x += (b[i] == 0);
    y -= b[i];
    if(x <= y)
        ans = min(ans, max(x, y - b[i + 1]));
  }

  ans += (a[s] != 0);

  printf("%d\n", ans);

  return 0;
}
