#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

char s[10];

int main(){
  int n, bestBuy = 0, bestSell = 308983067, ans = 1;
  set<int> S{bestBuy, bestSell};

  scanf("%d", &n);
  while(n--){
    int x;
    scanf("%s%d", s, &x);

    if(s[2] == 'D'){
      S.insert(x);
    }
    else{
      if(x < bestBuy || bestSell < x){
        ans = 0;
        break;
      }

      if(bestBuy < x && x < bestSell){
        ans = (2 * ans) % MOD;
      }
      auto it = S.find(x);
      bestBuy = *prev(it, 1);
      bestSell = *next(it, 1);
      S.erase(x);
    }
  }

  int count = 0;
  for(auto it = S.find(bestBuy); *it != bestSell && ans != 0; ++it, ++count);

  ans = (1ll * count * ans) % MOD;

  printf("%d\n", ans);
  
  return 0;
}
