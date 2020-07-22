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
#define N 200002

vector<vector<int>> lists(N);
int numberToListNumber[N], towerToListNumber[N];

int Initialise(int n, int m){
  for(int i = 1; i <= m; ++i){
    towerToListNumber[i] = i;
  }

  for(int i = 1; i <= n; ++i){
    lists[numberToListNumber[i]].push_back(i);
  }

  int ans = 0;
  for(int i = 2; i <= n; ++i){
    ans += (numberToListNumber[i] != numberToListNumber[i - 1]);
  }

  return ans;
}

int MoveListContents(int i, int j){
  int ans = 0;

  for(int x: lists[i]){
    if(numberToListNumber[x - 1] == j){
      ++ans;
    }
    if(numberToListNumber[x + 1] == j){
      ++ans;
    }
  }

  for(int x: lists[i]){
    lists[j].push_back(x);
    numberToListNumber[x] = j;
  }

  lists[i].clear();

  return ans;
}

int Merge(int i, int j){
  if(i == j){
    return 0;
  }

  int li = towerToListNumber[i], lj = towerToListNumber[j];

  if(lists[li].size() < lists[lj].size()){
    towerToListNumber[i] = lj, towerToListNumber[j] = li;
    swap(li, lj);
  }

  return MoveListContents(lj, li);
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  
  for(int i = 1; i <= n; ++i){
    scanf("%d", &numberToListNumber[i]);
  }

  int ans = Initialise(n, m);
  printf("%d\n", ans);

  while(--m){
    int i, j;
    scanf("%d%d", &i, &j);
    ans -= Merge(i, j);
    printf("%d\n", ans);
  }

  return 0;
}