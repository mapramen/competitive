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

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n;
    vector<int> players, villians;

    scanf("%d", &n);

    for(int i = 1, x; i <= n; ++i){
      scanf("%d", &x);
      villians.push_back(x);
    }

    for(int i = 1, x; i <= n; ++i){
      scanf("%d", &x);
      players.push_back(x);
    }

    sort(villians.begin(), villians.end());
    sort(players.begin(), players.end());

    bool win = true;
    for(int i = 0; i < n && win == true; ++i){
      win = players[i] > villians[i];
    }

    printf("%s\n", win ? "WIN" : "LOSE");
  }

  return 0;
}