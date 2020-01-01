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
#define N 300

int Query(string s){
  cout << s << '\n';
  fflush(stdout);

  int x;
  cin >> x;
  return x;
}

int GetCharCount(char c){
  return N - Query(string(N, c));
}

int main(){
  int aCount = GetCharCount('a');
  
  if(aCount == N){
    return 0;
  }
  
  int bCount = GetCharCount('b');

  if(bCount == N){
    return 0;
  }

  if(bCount == 0){
    Query(string(aCount, 'a'));
    return 0;
  }

  if(aCount == 0){
    Query(string(bCount, 'b'));
    return 0;
  }

  int n = aCount + bCount;
  string s = string(n, 'a');

  for(int i = 0, x = bCount; i < n; ++i){
    s[i] = 'b';
    
    int y = Query(s);

    if(y == 0){
      break;
    }

    if(y < x){
      x = y;
      continue;
    }

    s[i] = 'a';
  }

  return 0;
}