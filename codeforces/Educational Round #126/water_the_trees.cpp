#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(vector<int> a, ll t, int parity){
  ll even = t / 2, odd = t - even;

  for(int& x: a){
    if(x % 2 != parity){
      ++x, --odd;
    }
  }

  if(odd < 0){
    return false;
  }

  even += odd / 2;

  int m = *max_element(a.begin(), a.end());
  for(int x: a){
    even -= ((m - x) / 2);
  }

  return even >= 0;
}

bool Check(vector<int> a, ll t){
  return Check(a, t, 0) || Check(a, t, 1);
}

ll BinarySearch(vector<int> a){
  ll x = 0, y = 1E18, ans = y;

  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(a, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return ans;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int &x: a){
    scanf("%d", &x);
  }

  return BinarySearch(a);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}