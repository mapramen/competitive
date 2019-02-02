#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 11
#define N (1 << B)

int c[N], d[N];

int main(){
  int n, k, x, minAns = INT_MAX, maxAns = INT_MIN;

  scanf("%d%d%d", &n, &k, &x);

  for(int i = 1; i <= n; i++){
    int j;
    scanf("%d", &j);
    c[j]++;
  }

  while(k--){
    for(int i = 0; i < N; i++)
      d[i] = 0;

    for(int i = 0, t = 0; i < N; t += c[i], i++){
      int odds = (c[i] + 1) / 2, evens = c[i] - odds;

      if(t % 2)
        swap(evens, odds);

      d[(i ^ x)] += odds;
      d[i] += evens;
    }

    for(int i = 0; i < N; i++)
      c[i] = d[i];
  }

  for(int i = 0; i < N; i++){
    if(c[i]){
      minAns = min(minAns, i);
      maxAns = max(maxAns, i);
    }
  }

  printf("%d %d\n", maxAns, minAns);

  return 0;
}
