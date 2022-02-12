#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int d[N];

void Initialise(){
  queue<int> Q;

  for(int i = 1; i < N; ++i){
    d[i] = INT_MAX;
  }

  d[1] = 0;
  Q.push(1);

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(int x = 1; x <= i; ++x){
      int j = i + (i / x);
      if(d[j] != INT_MAX){
        continue;
      }
      d[j] = 1 + d[i];
      Q.push(j);
    }
  }
}

vector<int> ReadArray(int n){
  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  return a;
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  k = min(k, 12 * n);
  vector<int> B = ReadArray(n);
  vector<int> C = ReadArray(n);

  vector<int> dp(k + 1);
  for(int i = 0; i < n; ++i){
    int x = d[B[i]], c = C[i];
    for(int y = k; y >= x; --y){
      dp[y] = max(dp[y], dp[y - x] + c);
    }
  }

  return *max_element(dp.begin(), dp.end());
}

int main(){
  int t;
  scanf("%d", &t);

  Initialise();

  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}