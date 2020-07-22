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

vector<int> ReadInput(){
  string s;
  cin >> s;

  vector<int> v(B);
  for(char c: s){
    ++v[c - 'A'];
  }
  return v;
}

int main(){
  vector<int> v = ReadInput();

  string s;
  for(int prv = -1; ; ){
    int n = 0, m = 0, mi;
    for(int i = 0; i < B; ++i){
      n += v[i];
      if(v[i] > m){
        m = v[i], mi = i;
      }
    }

    if(n == 0){
      break;
    }

    if(2 * m > n + 1){
      s = "-1";
      break;
    }

    int i = 0;
    if(2 * m == n + 1){
      i = mi;
    }
    else{
      for( ; i < B && (v[i] == 0 || i == prv); ++i);
    }

    s.push_back('A' + i);
    --v[i];
    prv = i;
  }

  cout << s << '\n';

  return 0;
}