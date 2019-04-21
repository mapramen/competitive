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
#define N 5001
#define B 26

vector<int> M[B];
int n, A[N][N], dp[N];
string s;

void PreProcess(){
  queue< pair< vector<int>, int > > Q;

  vector<int> v;
  for(int i = 0; i < n; ++i){
    v.push_back(i);
  }
  Q.push(make_pair(v, 1));

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= i; ++j){
      A[i][j] = i;
    }
  }

  while(!Q.empty()){
    int l;
    tie(v, l) = Q.front();
    Q.pop();

    for(int i : v){
      if(i >= n){
        continue;
      }
      M[s[i] - 'a'].push_back(i + 1);
    }

    for(int j = 0; j < B; M[j].clear(), ++j){
      if(M[j].size() < 2){
        continue;
      }

      for(int i : M[j]){
        A[i][l] = M[j].front();
      }
      Q.push(make_pair(M[j], l + 1));
    }
  }
}

int main(){
  int a, b;

  cin >> n >> a >> b >> s;

  PreProcess();

  for(int i = 1; i <= n; ++i){
    dp[i] = a + dp[i - 1];
    for(int j = i, l = 1; j > 0; --j, ++l){
      if(A[i][l] < j){
        dp[i] = min(dp[i], dp[j - 1] + b);
      }
    }
  }

  printf("%d\n", dp[n]);

  return 0;
}