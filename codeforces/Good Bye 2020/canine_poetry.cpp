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
  string s;
  cin >> s;

  int n = s.size(), ans = 0;
  for(int i = 0; i < n; ++i){
    int c = 0;
    for(int j = i - 2; j < i; ++j){
      if(j >= 0){
        c += (s[j] == s[i]);
      }
    }

    if(c == 0){
      continue;
    }

    for(char x = 'a'; x <= 'z'; ++x){
      s[i] = x;
      c = 0;
      for(int j = i - 2; j <= i + 2; ++j){
        if(j >= 0 && j < n){
          c += s[j] == x;
        }
      }
      if(c == 1){
        break;
      }
    }
    
    ++ans;
  }

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