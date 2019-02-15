#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 20

ll fact[N];
set< vector<int> > S;

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i)
    fact[i] = i * fact[i - 1];
}

ll Compute(vector<int> v){
  if(S.find(v) != S.end()){
    return 0;
  }

  int m = 0;
  for(auto x : v)
    m += x;

  ll ans = fact[m];
  for(auto x : v)
    ans /= fact[x];

  ans = (m - v[0]) * ans / m;

  for(int i = 0; i < v.size(); ++i){
    if(v[i] <= 1){
      continue;
    }
    --v[i];
    ans += Compute(v);
    ++v[i];
  }

  S.insert(v);

  return ans;
}

int main(){
  ll n;

  cin >> n;

  Initialise();

  vector<int> v(10);
  while(n){
    ++v[(n % 10)];
    n /= 10;
  }

  cout << Compute(v) << '\n';

  return 0;
}
