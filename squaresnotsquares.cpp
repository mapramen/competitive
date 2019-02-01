#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int LowerSquareRoot(int n){
  int x = sqrt(n) - 2;
  x = max(0, x);
  while(x * x <= n)
    ++x;
  --x;
  return x;
}

bool IsSquare(int n){
  int x = LowerSquareRoot(n);
  return (x * x == n);
}

int SquareCost(int n){
  int x = LowerSquareRoot(n);
  int ans = min(n - x * x, (x + 1) * (x + 1) - n);
  return ans;
}

int NonSquareCost(int n){
  if(n < 2)
    return 2 - n;
  else
    return IsSquare(n);
}

ll GetCost(vector<int>& a, int n){
  ll ans = 0;
  for(int i = 0; i < n; ++i)
    ans += a[i];
  return ans;
}

int main(){
  int n;
  vector<int> a, b;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    int ca = SquareCost(x), cb = NonSquareCost(x);
    if(ca == 0)
      a.PB(cb);
    else
      b.PB(ca);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans;
  if(a.size() > b.size())
    ans = GetCost(a, (a.size() - b.size()) / 2);
  else
    ans = GetCost(b, (b.size() - a.size()) / 2);

  printf("%lld\n", ans);

  return 0;
}
