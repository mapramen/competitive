#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

bool dp[N];

int main(){
  dp[0] = 1;

  for(int i = 0; i < N; ++i){
    if(i + 3 < N)
      dp[i + 3] |= dp[i];
    if(i + 7 < N)
      dp[i + 7] |= dp[i];
  }

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(dp[n])
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
