#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

set<int> good_numbers, beautiful_numbers;
map<int,int> dp;

void CheckAndAddGoodNumber(int d, int x){
  if(x % d == 0){
    good_numbers.insert(x);
  }
  dp[x] = 0;
}

bool Solve(){
  int n, d;
  scanf("%d%d", &n, &d);

  good_numbers.clear(), beautiful_numbers.clear(), dp.clear();

  for(int x = 1; x * x <= n; ++x){
    if(n % x != 0){
      continue;
    }
    CheckAndAddGoodNumber(d, x);
    CheckAndAddGoodNumber(d, n / x);
  }

  for(int x: good_numbers){
    bool is_beautiful = true;
    
    for(int y: good_numbers){
      if(y > x || !is_beautiful){
        break;
      }
      if(x % y == 0){
        is_beautiful = good_numbers.count(x / y) == 0;
      }
    }

    if(is_beautiful){
      beautiful_numbers.insert(x);
    }
  }

  dp[1] = 1;
  for(int y: beautiful_numbers){
    for(auto& np: dp){
      if(np.second >= 2){
        continue;
      }

      int x = np.first;
      if(x < y || x % y != 0){
        continue;
      }
      
      np.second = min(2, np.second + dp[x / y]);
    }
  }

  return dp[n] >= 2;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}