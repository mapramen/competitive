#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int x = 0, y = n - 1;
  ll sx = a[x], sy = a[y];
  int ans = 0;

  while(x < y){
    if(sx > sy){
      sy += a[y - 1];
      --y;
      continue;
    }

    if(sx < sy){
      sx += a[x + 1];
      ++x;
      continue;
    }

    ans = max(ans, x + 1 + n - y);

    sx += a[x + 1], sy += a[y - 1];
    ++x, --y;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}