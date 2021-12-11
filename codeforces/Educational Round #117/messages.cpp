#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdi pair<double,int>
#define tdiv tuple<double,int,vector<int>>
#define N 200001
#define M 21

vector<vector<int>> V(N), S(N);
priority_queue<pdi, vector<pdi>, greater<pdi>> Q;

tdiv Calculate(int t){
  for(int i = 1; i < N; ++i){
    int n = V[i].size() - 1;
    int j = lower_bound(V[i].begin(), V[i].end(), t) - V[i].begin() - 1;
    Q.push({n - j + 1.0 * S[i][j] / t, i});

    if(Q.size() > t){
      Q.pop();
    }
  }

  double ans = 0;
  vector<int> v;

  for( ; !Q.empty(); Q.pop()){
    auto [ansx, i] = Q.top();
    ans += ansx;
    v.push_back(i);
  }

  return {ans, t, v};
}

int main(){
  int n;
  scanf("%d", &n);

  while(n--){
    int m, k;
    scanf("%d%d", &m, &k);
    V[m].push_back(k);
  }

  for(int i = 1; i < N; ++i){
    V[i].push_back(0);

    sort(V[i].begin(), V[i].end());
    S[i].resize(V[i].size());

    for(int j = 1; j < V[i].size(); ++j){
      S[i][j] = S[i][j - 1] + V[i][j];
    }
  }

  tdiv ans = {0.0, 0, vector<int>()};
  for(int t = 1; t < M; ++t){
    ans = max(ans, Calculate(t));
  }

  auto [ansVal, anst, ansv] = ans;

  printf("%d\n", anst);
  for(int i: ansv){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}