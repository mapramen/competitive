#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 301
#define M 45200

int n, m, a[N], wordsLength[N], c[M];
unsigned short T[M][N], dp[N][M];

void Initialise(){
  map< string, int > S;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int k = 0;
    string s;
    cin >> s;
    if(S.find(s) == S.end()){
      k = S.size() + 1;
      S[s] = k;
    }
    else{
      k = S[s];
    }
    a[i] = k;
    wordsLength[i] = s.size();
  }
}

int GetNextTrieNode(int i, int j){
  if(T[i][j] == 0){
    T[i][j] = ++m;
  }
  return T[i][j];
}

int main(){
  Initialise();

  for(int i = 1; i <= n; ++i){
    int currentTrieNode = 0, cost = 0;

    for(int j = i; j > 0; --j){
      cost += (wordsLength[j] - 1 + (j != i));
      currentTrieNode = GetNextTrieNode(currentTrieNode, a[j]);
      c[currentTrieNode] = cost;
      dp[i][currentTrieNode] = 1 + dp[j - 1][currentTrieNode];
    }

    for(int j = 1; j <= m; ++j){
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
  }

  int ans = 0;
  for(int j = 1; j <= m; ++j){
    if(dp[n][j] > 1){
      ans = max(ans, dp[n][j] * c[j]);
    }
  }

  ans = -ans;
  for(int i = 1; i <= n; ++i){
    ans += ((i != 1) + wordsLength[i]);
  }

  printf("%d\n", ans);

  return 0;
}
