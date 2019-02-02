#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define M 1000001
#define MOD 1000000007

vector<int> v[M];
int dp[N];

void Initialise(int n){
  for(int i = 1; i < M; ++i){
    for(int j = i, k = 1; j < M && k <= n; j += i, ++k){
      v[j].PB(k);
    }
  }
}

int main(){
  int n;

  scanf("%d", &n);

  Initialise(n);

  dp[0] = 1;
  while(n--){
    int x;
    scanf("%d", &x);
    for(auto i : v[x]){
      dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }
  }

  int ans = 0;
  for(int i = 1; i < N; ++i){
    ans = (ans + dp[i]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}
