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
#define B 11

int main(){
  int n;
  string s;

  cin >> n >> s;

  int n1 = n - B, n2 = n1 / 2;
  n1 -= n2;

  for(int i = 0; i < n && n2; ++i){
    if(s[i] == '8'){
      s[i] = '\0';
      --n2;
    }
  }

  for(int i = n - 1; i > -1 && n2; --i){
    if(s[i] != '\0'){
      s[i] = '\0';
      --n2;
    }
  }

  for(int i = 0; i < n; ++i){
    if(s[i] == '\0'){
      continue;
    }
    if(s[i] == '8' && n1 >= 0){
      printf("YES\n");
      return 0;
    }
    --n1;
  }

  printf("NO\n");

  return 0;
}