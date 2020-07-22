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

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int preOrder[N], inOrder[N], postOrder[N], inOrderPosition[N];

void PreProcess(int n){
  for(int i = 1; i <= n; ++i){
    inOrderPosition[inOrder[i]] = i;
  }
}

void Solve(int length, int lpre, int lin, int lpost){
  if(length <= 0){
    return;
  }

  postOrder[lpost + length - 1] = preOrder[lpre];

  int i = inOrderPosition[preOrder[lpre]];
  int lsize = i - lin;

  Solve(lsize, lpre + 1, lin, lpost);
  Solve(length - lsize - 1, lpre + lsize + 1, i + 1, lpost + lsize);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &preOrder[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &inOrder[i]);
  }

  PreProcess(n);
  Solve(n, 1, 1, 1);

  for(int i = 1; i <= n; ++i){
    printf("%d ", postOrder[i]);
  }
  printf("\n");

  return 0;
}