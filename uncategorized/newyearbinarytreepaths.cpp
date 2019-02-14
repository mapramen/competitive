#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define L 51
#define B 2

ll dp[L][2 * L][B][B];

int GetDepth(ll s){
  int depth = 0;
  for( ; s > 1; s /= 2)
    depth++;
  return depth;
}

ll Solve(int l1, int l2, int totalPopCount, ll s){
  int l = max(max(l1, l2), GetDepth(s));
  ll ans;

  dp[0][0][0][0] = 1;
  for(int k = 0; k <= l; k++){
    int targetBit = ((s & (1ll << k)) > 0);
    for(int currentPopCount = 0; currentPopCount <= totalPopCount; currentPopCount++){
      for(int same = 0; same < B; same++){
        for(int carry = 0; carry < B; carry++){
          if(dp[k][currentPopCount][same][carry])
            printf("%d %d %d %d %lld\n", k, currentPopCount, same, carry, dp[k][currentPopCount][same][carry]);

          for(int i = 0; i < B; i++){
            for(int j = 0; j < B; j++){
              if((k > l1 && i == 1) || (k > l2 && j == 1) || (k == l1 && i == 0) || (k == l2 && j == 0))
                continue;

              int currentBit = (carry + i + j) % 2;
              int newPopCount = currentPopCount + i + j;
              int newSame = (same | (i != j));
              int newCarry = (carry + i + j) / 2;

              if(currentBit == targetBit && newPopCount <= totalPopCount){
                // printf("New: %d %d %d %d %d\n", i, j, k + 1, newPopCount, newCarry);
                dp[k + 1][newPopCount][newSame][newCarry] += dp[k][currentPopCount][same][carry];
              }
            }
          }
        }
      }
    }
  }

  ans = dp[l + 1][totalPopCount][1][0];

  for(int k = 0; k <= l + 1; k++)
    for(int currentPopCount = 0; currentPopCount <= totalPopCount; currentPopCount++)
      for(int same = 0; same < B; same++)
        for(int carry = 0; carry < B; carry++)
          dp[k][currentPopCount][same][carry] = 0;

  if(l1 != 0 && l2 != 0)
    ans /= 2;

  return ans;
}

int main(){
  ll s, ans = 1;

  cin >> s;
  int maxDepth = GetDepth(s);

  for(int l1 = 0; l1 <= maxDepth; l1++){
    for(int l2 = 0; l2 <= l1; l2++){
      ll v = (1ll << (l1 + 1)) + (1ll << (l2 + 1)) - 3;
      ll lca = s / v;
      int lcaDepth = GetDepth(lca), depth1 = lcaDepth + l1, depth2 = lcaDepth + l2;

      if(lca == 0 || (depth1 + 2 <= maxDepth && depth2 + 2 <= maxDepth) || depth1 > maxDepth || depth2 > maxDepth)
        continue;

      for(int popCount = 0; popCount <= l1 + l2 + 2; popCount++){
        ll newS = s - (lca - 1) * v + popCount + 1;
        if(newS % 2)
          continue;

        newS /= 2;
        ll ansx = Solve(l1, l2, popCount, newS);
        ans += ansx;

        printf("Solve %d %d %lld %lld %d %lld %lld %lld\n\n", l1, l2, v, lca, popCount, newS, ansx, ans);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
