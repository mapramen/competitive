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

set<int> S;

int Solve(){
  int n;
  scanf("%d", &n);

  while(n--){
    int x;
    scanf("%d", &x);
    if(S.count(x) > 0){
      S.insert(x + 1);
    }
    else{
      S.insert(x);
    }
  }

  int ans = S.size();
  S.clear();

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}