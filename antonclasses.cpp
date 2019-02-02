#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, m, min1 = INT_MAX, max1 = INT_MIN, min2 = INT_MAX, max2 = INT_MIN, ans = 0;

  scanf("%d", &n);
  while(n--){
    int l, r;
    scanf("%d%d", &l, &r);
    min1 = min(min1, r);
    max1 = max(max1, l);
  }

  scanf("%d", &m);
  while(m--){
    int l, r;
    scanf("%d%d", &l, &r);
    min2 = min(min2, r);
    max2 = max(max2, l);
  }

  ans = max(ans, max(max2 - min1, max1 - min2));

  printf("%d\n", ans);
  
  return 0;
}
