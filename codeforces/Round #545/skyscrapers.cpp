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

int a[N][N], b[N][N], c[N][N], R[N], C[N];

void RemoveDuplicates(vector<int> &v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

void PreProcess(int n, int m, int b[][N], int R[]){
  for(int i = 1; i <= n; ++i){
    vector<int> v;
    for(int j = 1; j <= m; ++j){
      v.push_back(a[i][j]);
    }
    RemoveDuplicates(v);

    for(int j = 1; j <= m; ++j){
      b[i][j] = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin() + 1;
    }

    R[i] = v.size();
  }
}

void Transpose(int a[][N]){
  for(int i = 1; i < N; ++i){
    for(int j = i + 1; j < N; ++j){
      swap(a[i][j], a[j][i]);
    }
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  PreProcess(n, m, b, R);
  Transpose(a);
  PreProcess(m, n, c, C);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      int x = max(b[i][j], c[j][i]) + max(R[i] - b[i][j], C[j] - c[j][i]);
      a[i][j] = x;
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}