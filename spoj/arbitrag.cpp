#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  map<string,int> city_to_index;
  for(int i = 0; i < n; ++i){
    string city;
    cin >> city;
    city_to_index[city] = i;
  }

  vector<vector<double>> dp(n, vector<double>(n));
  for(int i = 0; i < n; ++i){
    dp[i][i] = 1;
  }

  int m;
  scanf("%d", &m);

  while(m--){
    string city1, city2;
    double r;
    cin >> city1 >> r >> city2;
    dp[city_to_index[city1]][city_to_index[city2]] = r;
  }

  for(int k = 0; k < n; ++k){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        dp[i][j] = max(dp[i][j], dp[i][k] * dp[k][j]);
      }
    }
  }

  for(int i = 0; i < n; ++i){
    if(dp[i][i] > 1){
      return true;
    }
  }

  return false;
}

int main(){
  for(int k = 1; ; ++k){
    printf("Case %d: %s\n", k, Solve() ? "Yes" : "No");
  }
  return 0;
}