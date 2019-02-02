#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 20
#define N 1000001
#define MOD 1000000007

vector< vector<int> > primeDivisors(N);
int dp[B][N];

void PreProcessing(){
  for(int i = 2; i < N; i++)
    if(primeDivisors[i].size() == 0){
      for(int j = i; j < N; j += i)
        primeDivisors[j].PB(i);
    }

  for(int j = 0; j < N; j++)
    dp[0][j] = 1;

  for(int i = 1; i < B; i++){
    dp[i][0] = 2;
    for(int j = 1; j < N; j++)
      dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
  }
}

int main(){
  int q, n, r, x;
  ll ans;

  PreProcessing();

  scanf("%d", &q);

  while(q--){
    scanf("%d%d", &r, &n);
    x = n;
    ans = 1;

    for(auto p : primeDivisors[x]){
      int k = 0;
      while(n % p == 0)
        n /= p, k++;
      ans = (ans * dp[k][r]) % MOD;
    }

    printf("%lld\n", ans);
  }

  return 0;
}
