#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int c[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ++c[x];
  }

  int ans = 0;
  for(int i = N - 1, s = 0, k = c[i]; i > 0; s += k, --i, k += c[i]){
    if(k == n){
      ans += (s > 0);
      break;
    }
    if(s + k > m){
      ++ans;
      s = 0;
    }
  }

  printf("%d\n", ans);

  return 0;
}
