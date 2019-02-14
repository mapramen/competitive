#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501

int a[N];

int floor(int n, int k){
  if(k == 0)
    return INT_MAX;
  else
    return n / k;
}

int ceil(int n, int k){
  if(k == 0)
    return INT_MAX;
  else
    return (n + k - 1) / k;
}

bool Check(int n, int d){
  return (ceil(n, d + 1) <= floor(n, d));
}

ll GetAns(int n, int d){
  bool valid = 1;
  ll ans = 0;
  for(int i = 1; i <= n && valid == 1; i++){
    valid = Check(a[i], d);
    ans += ceil(a[i], d + 1);
  }
  if(valid == 0)
    ans = LLONG_MAX;
  return ans;
}

int main(){
  int n, s;
  ll ans = LLONG_MAX;

  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> a[i];

  sort(a + 1, a + n + 1);

  for(s = 0; s * s <= a[1]; s++);
  s--;

  for(int d = 0; d <= s; d++)
    ans = min(ans, GetAns(n, d));

  for(int k = 1; k <= s; k++){
    int dMin = max(0, ceil(a[1], k) - 1), dMax = floor(a[1], k);
    for(int d = dMin; d <= dMax; d++)
      ans = min(ans, GetAns(n, d));
  }

  cout << ans << '\n';
  
  return 0;
}
