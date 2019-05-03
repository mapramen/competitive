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
#define N 200001

vector< vector<int> > edgeNumbers(N);
int edgeXors[N], c[N], edgeColors[N];

void DFS(int i, int parent, int parentEdgeColor, int totalColors){
  bool colorSame = edgeNumbers[i].size() > totalColors;
  int currentColor = 1;

  for(int x : edgeNumbers[i]){
    int j = (i ^ edgeXors[x]);
    if(j == parent){
      continue;
    }
    currentColor += (currentColor == parentEdgeColor);
    int edgeColor = colorSame ? max(1, parentEdgeColor) : currentColor++;
    DFS(j, i, edgeColor, totalColors);
    edgeColors[x] = edgeColor;
  }
}

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    edgeNumbers[i].push_back(x);
    edgeNumbers[j].push_back(x);
    edgeXors[x] = (i ^ j);
  }

  for(int i = 1; i <= n; ++i){
    ++c[edgeNumbers[i].size()];
  }

  for(int i = n - 1; i > 0; --i){
    c[i] += c[i + 1];
  }

  int ans = 1;
  for( ; k < c[ans]; ++ans);
  --ans;

  DFS(1, 0, 0, ans);

  printf("%d\n", ans);
  for(int x = 1; x < n; ++x){
    printf("%d ", edgeColors[x]);
  }
  printf("\n");

  return 0;
}