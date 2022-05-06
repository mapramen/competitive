#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> Int2Vec(ll n){
  vector<int> v;
  for( ; n > 0; n /= 10){
    v.push_back(n % 10);
  }
  reverse(v.begin(), v.end());
  return v;
}

ll Calculate(ll n){
  if(n <= 0){
    return 0ll;
  }

  ll less_count = 0, less_sum = 0;
  ll equal_count = 1, equal_sum = 0;

  for(int x: Int2Vec(n)){
    ll new_less_count = 0, new_less_sum = 0;

    for(int d = 0; d <= 9; ++d){
      new_less_count += less_count, new_less_sum += less_sum + d * less_count;
    }

    for(int d = 0; d < x; ++d){
      new_less_count += equal_count, new_less_sum += equal_sum + d * equal_count;
    }

    equal_sum += x;
    less_count = new_less_count, less_sum = new_less_sum;
  }

  return less_sum + equal_sum;
}

ll Solve(){
  ll a, b;
  scanf("%lld%lld", &a, &b);
  return Calculate(b) - Calculate(a - 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}