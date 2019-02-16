#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001

char s[N], t[N];

int main(){
  int n, k;

  scanf("%d%d", &n, &k);
  scanf("%s%s", s, t);

  int i = 1;
  for( ; i <= n && s[i - 1] == t[i - 1]; ++i);

  ll ans = i - 1;
  for(int x = 0, y = 0; i <= n; ++i){
    x = 2 * x + (s[i - 1] - 'a');
    y = 2 * y + (t[i - 1] - 'a');
    
    int z = y - x + 1;
    if(k <= z || i == n){
      k = min(k, z);
      ans += (1ll * k * (n - i + 1));
      break;
    }
    else{
      ans += z;
    }
  }

  printf("%lld\n", ans);

  return 0;
}