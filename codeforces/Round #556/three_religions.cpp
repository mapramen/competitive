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
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 100001
#define M 251
#define B 26

char s[N], ch[2];
int n, T[N][B], dp[M][M][M];
string S[3];

void PreProcess(){
  for(int j = 0; j < B; ++j){
    T[n][j] = n;
  }

  for(int i = n - 1; i > -1; --i){
    for(int j = 0; j < B; ++j){
      T[i][j] = T[i + 1][j];
    }
    T[i][s[i] - 'a'] = i;
  }

  dp[0][0][0] = -1;
}

int inline GetCost(int i, int j, int k, char c){
  if(i < 0 || j < 0 || k < 0 || dp[i][j][k] == n){
    return n;
  }

  int x = min(n, 1 + dp[i][j][k]);
  return T[x][c - 'a'];
}

void inline Update(int i, int j, int k){
  int &val = dp[i][j][k];
  val = n;

  val = min(val, GetCost(i - 1, j, k, S[0][i - 1]));
  val = min(val, GetCost(i, j - 1, k, S[1][j - 1]));
  val = min(val, GetCost(i, j, k - 1, S[2][k - 1]));
}

void inline UpdateFirst(){
  int n = S[1].size(), m = S[2].size(), k = S[0].size();
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      Update(k, i, j);
    }
  }
}

void inline UpdateSecond(){
  int n = S[0].size(), m = S[2].size(), k = S[1].size();
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      Update(i, k, j);
    }
  }
}

void inline UpdateThird(){
  int n = S[0].size(), m = S[1].size(), k = S[2].size();
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      Update(i, j, k);
    }
  }
}

void inline Update(int k){
  if(k == 1){
    UpdateFirst();
  }
  else if(k == 2){
    UpdateSecond();
  }
  else{
    UpdateThird();
  }
}

bool inline Query(){
  return dp[S[0].size()][S[1].size()][S[2].size()] < n;
}

int main(){
  int q;

  scanf("%d%d%s", &n, &q, s);
  PreProcess();

  while(q--){
    int k;
    scanf("%s%d", ch, &k);
    
    if(ch[0] == '+'){
      scanf("%s", ch);
      S[k - 1].push_back(ch[0]);
      Update(k);
    }
    else{
      S[k - 1].pop_back();
    }

    printf("%s\n", Query() ? "YES" : "NO");
  }

  return 0;
}