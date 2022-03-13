#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define L 19

ll p[L], c[L];

void Initialise(){
  ll x = 1;
  for(int i = 1; i < L; ++i, x *= 10){
    c[i] = i * 9 * x;
  }

  x = 1;
  for(int i = 0; i < L; ++i, x *= 10){
    p[i] = x;
  }
}

vector<int> GetDigits(ll m){
  vector<int> v;
  for( ; m > 0; m /= 10){
    v.push_back(m % 10);
  }
  reverse(v.begin(), v.end());
  return v;
}

ll GetDigitsCount(ll m){
  vector<int> v = GetDigits(m);
  reverse(v.begin(), v.end());

  ll ans = 0;

  for(int n = 1; n < v.size(); ++n){
    ans += c[n];
  }

  int i = 0;
  while(!v.empty()){
    int d = v.back();
    v.pop_back();

    int n = v.size();

    for(int dx = i == 0; dx < d; ++dx){
      ans += (n + 1) * p[n];
    }

    ans += (m % p[n] + 1);
    ++i;
  }

  return ans;
}

ll BinarySearch(ll k){
  ll x = 0, y = 1E17, ans = 0;

  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(GetDigitsCount(mid) < k){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }

  return ans;
}

int Solve(){
  ll k;
  scanf("%lld", &k);

  ll n = BinarySearch(k);
  k -= GetDigitsCount(n);
  ++n;

  vector<int> v = GetDigits(n);
  return v[k - 1];
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}