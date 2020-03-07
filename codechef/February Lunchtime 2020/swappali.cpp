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

char s[N];

int Solve(){
  int n, ans = 0;

  scanf("%d%s", &n, s);

  for(int i = 0, j = n - 1, canSwapAtLeftEnd = 1, canSwapAtRightEnd = 1; i < j; ++i, --j){
    if(s[i] == s[j]){
      canSwapAtLeftEnd = 1, canSwapAtRightEnd = 1;
      continue;
    }

    if(j == i + 1){
      return -1;
    }

    if(canSwapAtLeftEnd == 1 && s[i + 1] == s[j]){
      ++ans;
      swap(s[i], s[i + 1]);
      canSwapAtLeftEnd = 0, canSwapAtRightEnd = 1;
    }
    else if(canSwapAtRightEnd == 1 && s[i] == s[j - 1]){
      ++ans;
      swap(s[j - 1], s[j]);
      canSwapAtLeftEnd = 1, canSwapAtRightEnd = 0;
    }
    else{
      return -1;
    }
  }

  return ans;
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int ans = Solve();

    if(ans < 0){
      printf("NO\n");
    }
    else{
      printf("YES\n%d\n", ans);
    }
  }

  return 0;
}