#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

int d[N];
priority_queue< pii > Q;
bool v[N];

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  int m = n + 1;
  for(int i = 1; i <= n && m > n; ++i){
    for(int j = i + i; j <= n; j += i)
      ++d[j];
    d[i] += d[i - 1];
    v[i] = 1;
    if(k <= d[i]){
      m = i;
      break;
    }
  }

  if(m > n){
    printf("No\n");
    return 0;
  }

  for(int i = m; i + i > m; --i)
    Q.push(MP(d[i] - d[i - 1], i));

  int s = m;
  k = d[m] - k;
  while(!Q.empty() && k != 0){
    int x, i;
    tie(x, i) = Q.top();
    Q.pop();
    if(x <= k){
      k -= x;
      v[i] = 0;
      --s;
    }
  }

  printf("Yes\n%d\n", s);
  for(int i = 1; i <= m; ++i){
    if(v[i])
      printf("%d ", i);
  }
  printf("\n");

  return 0;
}
