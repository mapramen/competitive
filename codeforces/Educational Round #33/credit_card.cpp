#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N], b[N], c[N];

int main(){
  int n, d, ans = 0;

  scanf("%d%d", &n, &d);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; ++i){
    b[i] = a[i] + b[i - 1];
    c[i] = max(0, d - b[i]);
  }

  for(int i = n - 1; i > 0; --i)
    c[i] = min(c[i], c[i + 1]);

  int excess = 0;
  for(int i = 1; i <= n; ++i){
    if((a[i] == 0 && c[i] + b[i] < 0) || c[i] + b[i] > d){
      ans = -1;
      break;
    }

    if(a[i] != 0)
      continue;

    if(excess + b[i] < 0){
      ++ans;
      excess = c[i];
    }
  }

  printf("%d\n", ans);

  return 0;
}
