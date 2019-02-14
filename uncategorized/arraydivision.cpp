#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

ll a[N];

int main(){
  int n;
  ll m = 0, sx;
  set<ll> s;
  bool ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%lld", &a[i]);
    m += a[i];
  }

  if(m % 2 == 0){
    m /= 2;
    sx = 0;
    for(int i = 1; i <= n && ans == 0; i++){
      sx += a[i];
      s.insert(a[i]);
      ans = ((i > 1) && (sx == m || s.find(sx - m) != s.end()));
    }

    for(int i = 1; 2 * i <= n; i++)
      swap(a[i], a[n - i + 1]);

    s.clear();
    sx = 0;
    for(int i = 1; i <= n && ans == 0; i++){
      sx += a[i];
      s.insert(a[i]);
      ans = ((i > 1) && (sx == m || s.find(sx - m) != s.end()));
    }
  }

  if(ans == 0)
    printf("NO\n");
  else
    printf("YES\n");

  return 0;
}
