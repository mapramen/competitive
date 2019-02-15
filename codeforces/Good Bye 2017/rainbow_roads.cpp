#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

int a[N];
char s[2], c[N];
ll r1 = INT_MIN, r2 = INT_MIN, b1 = INT_MIN, b2 = INT_MIN, g1 = INT_MIN, g2 = INT_MIN, rx = 0, bx = 0, ans = 0, minRB = LLONG_MAX;

void UpdateR(int x){
  if(r2 == INT_MIN)
    r1 = r2 = x;
  else{
    rx = max(rx, x - r2);
    r2 = x;
  }
}

void UpdateB(int x){
  if(b2 == INT_MIN)
    b1 = b2 = x;
  else{
    bx = max(bx, x - b2);
    b2 = x;
  }
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    scanf("%s", s);
    c[i] = s[0];
  }

  int i = 1;
  for( ; i <= n && c[i] != 'G'; ++i){
    if(c[i] == 'R')
      UpdateR(a[i]);
    else
      UpdateB(a[i]);
    minRB = min(minRB, abs(b2 - r2));
  }

  ans += (r2 - r1);
  ans += (b2 - b1);

  if(i == n + 1){
    printf("%lld\n", ans);
    return 0;
  }

  g2 = a[i];

  if(r2 != INT_MIN)
    ans += (g2 - r2);

  if(b2 != INT_MIN)
    ans += (g2 - b2);

  ++i;
  r1 = r2 = b1 = b2 = INT_MIN;
  rx = 0, bx = 0;
  for(; i <= n; ++i){
    if(c[i] == 'R'){
      UpdateR(a[i]);
    }
    else if(c[i] == 'B'){
      UpdateB(a[i]);
    }
    else{
      g1 = g2, g2 = a[i];
      if(r2 == INT_MIN)
        rx = g2 - g1;
      else
        rx = max(rx, max(r1 - g1, g2 - r2));

      if(b2 == INT_MIN)
        bx = g2 - g1;
      else
        bx = max(bx, max(b1 - g1, g2 - b2));

      ans += min(3 * (g2 - g1) - rx - bx, 2 * (g2 - g1));

      r1 = r2 = b1 = b2 = INT_MIN;
      rx = 0, bx = 0;
    }
  }

  if(r2 > g2)
    ans += (r2 - g2);

  if(b2 > g2)
    ans += (b2 - g2);

  printf("%lld\n", ans);

  return 0;
}
