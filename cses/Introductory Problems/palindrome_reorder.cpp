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
#define B 26

int c[B];

int main(){
  string s;
  cin >> s;

  for(auto ch: s){
    int i = ch - 'A';
    ++c[i];
  }

  for(int i = 0, x = 0; i < B; ++i){
    x += (c[i] % 2);

    if(x > 1){
      printf("NO SOLUTION\n");
      return 0;
    }
  }

  string s1, s2;
  for(int i = 0; i < B; ++i){
    if(c[i] % 2 == 1){
      continue;
    }

    for(int x = c[i]; x > 0; --x){
      if(x % 2 == 1){
        s1.push_back('A' + i);
      }
      else{
        s2.push_back('A' + i);
      }
    }
  }

  for(int i = 0; i < B; ++i){
    if(c[i] % 2 == 0){
      continue;
    }

    for(int x = c[i]; x > 0; --x){
      if(x % 2 == 1){
        s1.push_back('A' + i);
      }
      else{
        s2.push_back('A' + i);
      }
    }
  }

  reverse(s2.begin(), s2.end());

  cout << (s1 + s2) << '\n';
  
  return 0;
}