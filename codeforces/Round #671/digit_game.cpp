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
  int n;
  string s;
  bool oddPlaceHasOdd = false, evenPlaceHasEven = false;

  scanf("%d", &n);
  cin >> s;

  for(int i = 1; i <= n; ++i){
    int x = s[i - 1] - '0';

    if(i % 2 == 1){
      oddPlaceHasOdd = oddPlaceHasOdd || (x % 2 == 1);
    }
    else{
      evenPlaceHasEven = evenPlaceHasEven || (x % 2 == 0);
    }
  }

  return (n % 2 == 1 && oddPlaceHasOdd) || (n % 2 == 0 && !evenPlaceHasEven) ? 1 : 2;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}