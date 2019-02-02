#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, a, b, c, ans = 0;

  scanf("%d%d%d%d", &a, &b, &c, &n);
  while(n--){
    scanf("%d", &a);
    ans += ((b < a) && (a < c));
  }

  printf("%d\n", ans);
  
  return 0;
}
