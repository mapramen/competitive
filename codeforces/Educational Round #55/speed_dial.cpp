#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501
#define M 11

vector< vector<int> > adj(N), ancestors(N);
int m, cnt[N], d[N], dp[N][N][M], s[N][N][M], temp[M], inf = 1E9;

int NextTrieIndex(map< pair<int,char>, int> &trie, int i, char c){
  auto p = make_pair(i, c);
  if(trie.find(p) == trie.end()){
    int nxt = trie.size();
    trie[p] = nxt;
  }
  return trie[p];
}

void TakeInputsAndPreProcess(){
  int n;
  cin >> n >> m;
  map< pair<int,char>, int > trie;
  trie[make_pair(0, '\0')] = 0;
  
  while(n--){
    string s;
    int k;
    cin >> s >> k;
    int i = 0;
    for(auto c : s){
      i = NextTrieIndex(trie, i, c);
    }
    cnt[i] += k;
  }

  for(auto p : trie){
    int i = p.first.first, j = p.second;
    if(i == j){
      continue;
    }
    adj[i].push_back(j);
  }
}

void DFS(int i, int parent){
  if(parent >= 0){
    d[i] = 1 + d[parent];
    for(auto j : ancestors[parent]){
      ancestors[i].push_back(j);
    }
  }

  ancestors[i].push_back(i);

  for(auto p : ancestors[i]){
    for(int k = 1; k <= m; ++k){
      s[i][p][k] = inf;
    }
    s[i][p][0] = 0;
  }

  if(adj[i].empty()){
    for(int k = 0; k <= m; ++k){
      s[i][i][k] = 0;
    }
  }

  for(auto j : adj[i]){
    DFS(j, i);
    for(auto p : ancestors[i]){
      for(int k = 0; k <= m; ++k){
        temp[k] = inf;
      }
      for(int k1 = 0; k1 <= m; ++k1){
        for(int k2 = 0, k = k1; k1 + k2 <= m; ++k2, ++k){
          temp[k] = min(temp[k], s[i][p][k1] + dp[j][p][k2]);
        }
      }
      for(int k = 0; k <= m; ++k){
        s[i][p][k] = temp[k];
      }
    }
  }

  for(auto p : ancestors[i]){
    int ansx = cnt[i] * (d[i] - d[p]);
    dp[i][p][0] = s[i][p][0] + ansx;
    for(int k = 1; k <= m; ++k){
      dp[i][p][k] = min(s[i][p][k] + ansx, s[i][i][k - 1]);
    }
  }
}

int main(){
  TakeInputsAndPreProcess();

  DFS(0, -1);

  cout << dp[0][0][m] << '\n';

  return 0;
}