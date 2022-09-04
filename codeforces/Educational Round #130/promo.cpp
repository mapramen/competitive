#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

ll s[N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &s[i]);
  }
  
  sort(s + 1, s + n + 1);
  for(int i = 1; i <= n; ++i){
    s[i] += s[i - 1];
  }

  while(q--){
    int x, y;
    scanf("%d%d", &x, &y);
    x = n - x;
    printf("%lld\n", s[x + y] - s[x]);
  }
  
  return 0;
}