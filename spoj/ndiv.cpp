#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001

int c[N];

int main(){
  int n, a, b;
  scanf("%d%d%d", &a, &b, &n);

  for(int i = 1; i * i <= b; ++i){
    int k = max(i, a / i);
    for(int j = k * i; j <= b; j += i, ++k){
      if(j < a){
        continue;
      }
      c[j - a] += (1 + (k != i));
    }
  }

  int ans = 0;
  for(int x = 0; x < N; ++x){
    ans += (c[x] == n);
  }

  printf("%d\n", ans);

  return 0;
}