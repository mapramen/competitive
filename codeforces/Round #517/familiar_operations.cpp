#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define D 301
#define M 301

vector<int> divisors[D];
int leastPrimeDivisor[N], numberToIndex[N], dp[D][M], a[M], parent[M];
map< vector<int>, int > vectorToIndex;

void Initialise(){
  for(int i = 2; i < N; ++i){
    for(int j = i; j < N; j += i){
      if(leastPrimeDivisor[j] == 0){
        leastPrimeDivisor[j] = i;
      }
    }
  }

  a[0] = 1;
  for(int i = 1; i < N; ++i){
    vector<int> v;
    for(int x = i; x > 1; ){
      int k = 1;
      for(int p = leastPrimeDivisor[x]; x % p == 0; ++k, x /= p);
      v.PB(k);
    }

    sort(v.begin(), v.end());

    int k;
    if(vectorToIndex.count(v) == 0){
      k = vectorToIndex.size();
      vectorToIndex[v] = k;
    }
    else{
      numberToIndex[i] = vectorToIndex[v];
      continue;
    }

    numberToIndex[i] = k;

    if(v.size()){
      a[k] = v.back();
      v.pop_back();
      parent[k] = vectorToIndex[v];
    }
  }

  for(int i = 1; i < D; ++i){
    for(int j = i; j < D; j += i){
      divisors[j].PB(i);
    }
  }
}

void PreProcess(){
  int m = vectorToIndex.size();

  for(int j = 1; j < m; ++j){
    dp[1][j] = a[j] + dp[1][parent[j]];
  }

  for(int i = 2; i < D; ++i){
    for(int j = 0; j < m; ++j){
      int ans = INT_MAX, x = a[j], k = parent[j];
      for(auto d : divisors[i]){
        if(j == 0 && d == 1){
          continue;
        }
        ans = min(ans, abs(d - x) + dp[(i / d)][k]);
      }
      dp[i][j] = ans;
    }
  }
}

int main(){
  int t;

  scanf("%d", &t);

  Initialise();
  PreProcess();

  while(t--){
    int i, j, ans = INT_MAX;
    scanf("%d%d", &i, &j);
    i = numberToIndex[i], j = numberToIndex[j];
    for(int d = 1; d < D; ++d){
      ans = min(ans, dp[d][i] + dp[d][j]);
    }
    printf("%d\n", ans);
  }

  return 0;
}
