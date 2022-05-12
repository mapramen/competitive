#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  int g = 0;
  for(int i = 1; i < n; ++i){
    g = __gcd(g, a[i] - a[i - 1]);
  }

  int ans = 1 + (a.back() - a.front()) / g - n;

  printf("%d\n", ans);

  return 0;
}