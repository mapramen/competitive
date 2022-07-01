#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001
#define B 3

vector<vector<int>> adj(N);
int min_dp[B][N], max_dp[B][N];

int FormGraph(string& s, int &nxt){
  int i = nxt + 1;
  int c = s[nxt] - '0';
  
  ++nxt;
  adj[i].clear();

  while(c--){
    adj[i].push_back(FormGraph(s, nxt));
  }

  return i;
}

void DFS(int i){
  for(int j: adj[i]){
    DFS(j);
  }

  for(int color = 0; color < B; ++color){
    min_dp[color][i] = INT_MAX, max_dp[color][i] = INT_MIN;
  }

  for(int color = 0; color < B; ++color){
    int min_ans = color == 0, max_ans = color == 0;
    
    int child_color = color;
    for(int j: adj[i]){
      child_color = (child_color + 1) % B;
      min_ans += min_dp[child_color][j];
      max_ans += max_dp[child_color][j];
    }

    min_dp[color][i] = min(min_dp[color][i], min_ans);
    max_dp[color][i] = max(max_dp[color][i], max_ans);
  }

  for(int color = 0; color < B; ++color){
    int min_ans = color == 0, max_ans = color == 0;
    
    int child_color = color;
    for(int j: adj[i]){
      child_color = (child_color + B - 1) % B;
      min_ans += min_dp[child_color][j];
      max_ans += max_dp[child_color][j];
    }

    min_dp[color][i] = min(min_dp[color][i], min_ans);
    max_dp[color][i] = max(max_dp[color][i], max_ans);
  }
}

void Solve(){
  string s;
  cin >> s;

  int nxt = 0;
  FormGraph(s, nxt);

  DFS(1);

  int max_ans = 0, min_ans = INT_MAX;
  for(int color = 0; color < B; ++color){
    max_ans = max(max_ans, max_dp[color][1]);
    min_ans = min(min_ans, min_dp[color][1]);
  }

  printf("%d %d\n", max_ans, min_ans);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}