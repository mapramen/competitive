#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, L, a, ans = 0, x = 0, y, l;

  scanf("%d%d%d", &n, &L, &a);
  while(n--){
    scanf("%d%d", &y, &l);
    ans += ((y - x) / a);
    x = y + l;
  }

  ans += ((L - x) / a);

  printf("%d\n", ans);
  
  return 0;
}
