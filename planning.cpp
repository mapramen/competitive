#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

int c[N], ans[N];

int main(){
  int n, k;
  priority_queue< pii > Q;
  ll cost = 0, costx = 0;

  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &c[i]);

  for(int t = 1; t <= n + k; ++t){
    if(t <= n){
      Q.push(MP(c[t], t));
      costx += c[t];
    }
    if(t > k){
      ans[Q.top().second] = t;
      costx -= Q.top().first;
      Q.pop();
    }
    cost += costx;
  }

  printf("%lld\n", cost);
  for(int i = 1; i <= n; ++i)
    printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
