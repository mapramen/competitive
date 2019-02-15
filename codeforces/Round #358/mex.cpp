#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, m, i, j, ans;

  scanf("%d%d", &n, &m);
  ans = n;

  while(m--){
    scanf("%d%d", &i, &j);
    ans = min(ans, j - i + 1);
  }

  printf("%d\n", ans);

  for(i = 0; i < n; i++)
    printf("%d ", i % ans);
  printf("\n");

  return 0;
}
