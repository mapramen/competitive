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
#define N 201

char s[N][N];
vector<pii> v;

void CheckAndPush(int x, int y, char c){
  if(s[x - 1][y - 1] != c){
    v.push_back({x, y});
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  for(char x = '0'; x < '2'; ++x){
    char y = '0' + (x == '0');
    
    v.clear();
    CheckAndPush(1, 2, x);
    CheckAndPush(2, 1, x);
    CheckAndPush(n - 1, n, y);
    CheckAndPush(n, n - 1, y);
    
    if(v.size() <= 2){
      break;
    }
  }

  printf("%lu\n", v.size());
  for(auto p: v){
    printf("%d %d\n", p.first, p.second);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}