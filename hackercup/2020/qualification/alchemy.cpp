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

char s[N];
vector<int> S;

bool Reduce(){
  if(S.size() < 3){
    return false;
  }

  int c = 0;
  for(int i = S.size() - 3, j = 0; j < 3; ++i, ++j){
    c += S[i];
  }

  if(c == 0 || c == 3){
    return false;
  }

  for(int j = 0; j < 3; ++j){
    S.pop_back();
  }

  S.push_back(c - 1);

  return true;
}

bool Solve(){
  int n;
  scanf("%d%s", &n, s);

  S.clear();

  for(int i = 0; i < n; ++i){
    S.push_back(s[i] == 'A');
    while(Reduce());
  }

  return S.size() == 1;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %c\n", k, Solve() ? 'Y' : 'N');
  }
  return 0;
}