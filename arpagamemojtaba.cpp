#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 30

map< int, int > dp;

void RemoveDuplicates(vector<int>& v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

int Grundy(int n){
  if(dp.find(n) != dp.end())
    return dp[n];

  vector<int> v;
  for(int i = 1; i < B; ++i){
    int m = ((n >> i) | (n & ((1 << i) - 1)));
    if(m != n)
      v.PB(Grundy(m));
  }

  RemoveDuplicates(v);

  int ans = 0;
  for( ; ans < v.size() && v[ans] == ans; ++ans);

  dp[n] = ans;
  return ans;
}

int main(){
  int n, ans = 0;
  vector<int> a, primes;

  cin >> n;
  while(n--){
    int i;
    cin >> i;
    if(i > 1)
      a.PB(i);
  }

  RemoveDuplicates(a);

  for(auto x : a){
    int y = x;
    for(int i = 2; i * i <= y; ++i){
      if(y % i == 0)
        primes.PB(i);
      while(y % i == 0)
        y /= i;
    }

    if(y > 1)
      primes.PB(y);
  }

  RemoveDuplicates(primes);

  dp[1] = 0;
  for(auto p : primes){
    int mask = 0;
    for(auto y : a){
      int x = y, k = 0;
      while(x % p == 0){
        ++k;
        x /= p;
      }
      mask |= (1 << k);
    }
    int ansx = Grundy(mask);
    ans ^= ansx;
  }

  if(ans == 0)
    cout << "Arpa\n";
  else
    cout << "Mojtaba\n";

  return 0;
}
