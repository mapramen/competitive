#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101
#define B 26

vector<int> adj[N][B], revAdj[N], v;
int outDegree[N], dp[N][N][B][2];
char s[2];

int main(){
  int n, m;
  queue<int> Q;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d%s", &i, &j, s);
    int k = s[0] - 'a';
    adj[i][k].PB(j);
    revAdj[j].PB(i);
    ++outDegree[i];
  }

  for(int i = 1; i <= n; ++i){
    if(outDegree[i] == 0)
      Q.push(i);
  }

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    v.PB(i);
    for(auto k : revAdj[i]){
      --outDegree[k];
      if(outDegree[k] == 0)
        Q.push(k);
    }
  }

  for(auto i : v){
    for(auto j : v){
      for(int k = B - 1, ans = 0; k > -1; --k){
        int ansx = 1;
        for(auto x : adj[i][k])
          ansx &= dp[x][j][k][1];
        ans |= (1 - ansx);
        dp[i][j][k][0] = ans;
      }

      for(int k = B - 1, ans = 0; k > -1; --k){
        int ansx = 1;
        for(auto y : adj[j][k])
          ansx &= dp[i][y][k][0];
        ans |= (1 - ansx);
        dp[i][j][k][1] = ans;
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      putchar('A' + 1 - dp[i][j][0][0]);
    }
    putchar('\n');
  }

  return 0;
}
