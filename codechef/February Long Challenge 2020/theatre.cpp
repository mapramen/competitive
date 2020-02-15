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
#define B 4

int c[B][B];
char ch[2];
vector<int> X{0, 1, 2, 3}, Y{0, 1, 2, 3};

int GetCost(int i, int j, int k){
  return c[i][j] == 0 ? -100 : 25 * (k + 1) * c[i][j];
}

int Solve(){
  int n;

  scanf("%d", &n);

  for(int i = 0; i < B; ++i){
    for(int j = 0; j < B; ++j){
      c[i][j] = 0;
    }
  }

  while(n--){
    int i, j;
    scanf("%s%d", ch, &j);
    i = ch[0] - 'A', j = j / 3 - 1;
    ++c[i][j];
  }

  int ans = INT_MIN;
  do{
    do{
      int ansx = 0;
      for(int i = 0; i < B; ++i){
        ansx += GetCost(i, X[i], Y[i]);
      }
      ans = max(ans, ansx);
    } while(next_permutation(Y.begin(), Y.end()));
  } while(next_permutation(X.begin(), X.end()));
  
  return ans;
}

int main(){
  int t, ans = 0;
  
  scanf("%d", &t);
  while(t--){
    int ansx = Solve();
    printf("%d\n", ansx);
    ans += ansx;
  }
  printf("%d\n", ans);

  return 0;
}