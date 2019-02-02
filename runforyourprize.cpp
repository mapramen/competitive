#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000000

int main(){
  int n, ans = N, p = 1;

  scanf("%d", &n);
  while(n--){
    int c;
    scanf("%d", &c);
    ans = min(ans, max(p - 1, N - c));
    p = c;
  }

  ans = min(ans, p - 1);

  printf("%d\n", ans);

  return 0;
}
