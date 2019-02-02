#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int c[2 * N];

int main(){
  int n, m, k, ans = 0;
  stack<int> S;

  scanf("%d%d%d", &n, &m, &k);

  while(n--){
    int i;
    scanf("%d", &i);
    ++c[i];
  }

  for(int i = 1, j = 1, s = 0; i < N; ++i){
    for(j = max(i, j); j - i + 1 <= m; ++j){
      s += c[j];
      while(s >= k){
        --s;
        --c[j];
        ++ans;
      }
    }
    s -= c[i];
  }

  printf("%d\n", ans);

  return 0;
}
