#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n + 1), c(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    ++c[a[i]];
  }

  int l = n, x = 1, y = n;
  for(int i = 1, j = 1, s = 0; i <= n; ++i){
    for( ; j <= n && 2 * s - n < k; ++j){
      s += c[j];
    }

    if(2 * s - n >= k && j - i < l){
      l = j - i, x = i, y = j - 1;
    }

    s -= c[i];
  }

  printf("%d %d\n", x, y);

  for(int i = 1, j = 1, s = 0, kx = 1; i <= n; ++i){
    s += (x <= a[i] && a[i] <= y ? 1 : -1);

    if(s != kx){
      continue;
    }
    
    printf("%d %d\n", j, kx == k ? n : i);
    
    if(kx == k){
      break;
    }

    j = i + 1, ++kx;
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}