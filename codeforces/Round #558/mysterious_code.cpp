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
#define N 1001
#define M 51

char s[M], t[M], a[N];
int fs[M], ft[M], dp[N][M][M];

int ComputeFailure(char s[], int f[], int i, char c){
  for( ; i > 0 && s[i] != c; i = f[i]);
  return i + (s[i] == c);
}

int ComputeFailureS(int i, int c){
  return ComputeFailure(s, fs, i, c);
}

int ComputeFailureT(int i, int c){
  return ComputeFailure(t, ft, i, c);
}

void InitialiseFailure(char s[], int f[]){
  for(int i = 1; s[i] != '\0'; ++i){
    f[i + 1] = ComputeFailure(s, f, f[i], s[i]);
  }
}

void PreProcess(){
  InitialiseFailure(s, fs);
  InitialiseFailure(t, ft);
}

int main(){
  scanf("%s%s%s", a, s, t);

  PreProcess();

  int n = strlen(a), sLength = strlen(s), tLength = strlen(t);
  for(int i = 0; i <= n; ++i){
    for(int x = 0; x < sLength; ++x){
      for(int y = 0; y < tLength; ++y){
        dp[i][x][y] = INT_MIN;
      }
    }
  }

  dp[0][0][0] = 0;

  for(int i = 0; i < n; ++i){
    char cs = a[i] == '*' ? 'a' : a[i];
    char ct = a[i] == '*' ? 'z' : a[i];

    for(int x = 0; x < sLength; ++x){
      for(int y = 0; y < tLength; ++y){
        if(dp[i][x][y] == INT_MIN){
          continue;
        }

        for(char c = cs; c <= ct; ++c){
          int val = dp[i][x][y];
          int nx = ComputeFailureS(x, c), ny = ComputeFailureT(y, c);
          
          if(nx == sLength){
            ++val;
            nx = fs[nx];
          }

          if(ny == tLength){
            --val;
            ny = ft[ny];
          }

          dp[i + 1][nx][ny] = max(dp[i + 1][nx][ny], val);
        }
      }
    }
  }

  int ans = INT_MIN;
  for(int x = 0; x < sLength; ++x){
    for(int y = 0; y < tLength; ++y){
      ans = max(ans, dp[n][x][y]);
    }
  }

  printf("%d\n", ans);

  return 0;
}