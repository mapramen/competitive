#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];

int main(){
  int n, m = INT_MAX;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    m = min(m, a[i]);
  }

  int ans = n + 1;
  for(int i = 1, j = -n; i <= n; ++i){
    if(a[i] == m){
      ans = min(ans, i - j);
      j = i;
    }
  }

  printf("%d\n", ans);

  return 0;
}
