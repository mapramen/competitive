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

int Solve(){
  string s;
  cin >> s;

  int a = 0, b = 0, ans = 0;
  for(char c: s){
    if(c == '('){
      ++a;
    }
    else if(c == ')'){
      if(a != 0){
        --a, ++ans;
      }
    }
    else if(c == '['){
      ++b;
    }
    else{
      if(b != 0){
        --b, ++ans;
      }
    }
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