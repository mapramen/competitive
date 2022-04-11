#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 4
#define N 10000
#define M 102

vector<vector<int>> adj(N);
int dp[M][N];

vector<int> Int2Vec(int n){
  vector<int> v(B);
  for(int i = B - 1; i != -1; --i, n /= 10){
    v[i] = n % 10;
  }
  return v;
}

int Vec2Int(vector<int>& v){
  int ans = 0;
  for(int d: v){
    ans = 10 * ans + d;
  }
  return ans;
}

vector<int> GetMoves(int n){
  vector<int> v = Int2Vec(n);
  
  vector<int> ans;
  for(int i = 0; i < B; ++i){
    v[i] = (v[i] + 1) % 10;
    ans.push_back(Vec2Int(v));
    v[i] = (v[i] + 9) % 10;
  }

  return ans;
}

void Initialise(){
  for(int i = 0; i < N; ++i){
    adj[i] = GetMoves(i);
  }
}

bool Calculate(int m, int n){
  if(m == 0){
    return false;
  }

  for(int i = 0; i < N; ++i){
    dp[m + 1][i] = i;
  }

  for(int k = m; k > 0; --k){
    bool isMin = k % 2 == 0;
    for(int i = 0; i < N; ++i){
      int ans = isMin ? INT_MAX : INT_MIN;
      for(int j: adj[i]){
        if(isMin){
          ans = min(ans, dp[k + 1][j]);
        }
        else{
          ans = max(ans, dp[k + 1][j]);
        }
      }
      dp[k][i] = ans;
    }
  }

  return dp[1][n] > n;
}

bool Solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  return Calculate(k, n);
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Ada" : "Vinit");
  }
  
  return 0;
}