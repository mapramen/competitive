#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<vector<int>> a;
vector<int> dp;

void Reset(){
  a.clear();
  dp.clear();
}

void AddBlocks(vector<int> v){
  sort(v.begin(), v.end());
  do{
    a.push_back(v);
  } while(next_permutation(v.begin(), v.end()));
}

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  Reset();

  while(n--){
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    AddBlocks({x, y, z});
  }

  sort(a.begin(), a.end());

  n = a.size();
  dp.resize(n);

  for(int i = 0; i < n; ++i){
    vector<int>& x = a[i];

    int ans = 0;
    for(int j = 0; j < i; ++j){
      vector<int>& y = a[j];
      if(y[0] < x[0] && y[1] < x[1]){
        ans = max(ans, dp[j]);
      }
    }

    dp[i] = ans + x[2];
  }

  return *max_element(dp.begin(), dp.end());
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}