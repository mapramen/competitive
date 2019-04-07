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
#define B 26

void Query(string &s){
  cout << '?' << ' ' << s << '\n';
  fflush(stdout);
  cin >> s;
}

int main(){
  string t;
  cin >> t;

  int n = t.size();
  vector<int> v(n);

  for(int k = 2; k > -1; --k){
    string s;
    for(int i = 0; i < n; ++i){
      int x = i;
      for(int y = k; y > 0; --y){
        x /= B;
      }
      s.push_back('a' + (x % B));
    }
    Query(s);

    for(int i = 0; i < n; ++i){
      v[i] = B * v[i] + (s[i] - 'a');
    }
  }

  string s = t;
  for(int i = 0; i < n; ++i){
    s[v[i]] = t[i];
  }

  cout << '!' << ' ' << s << '\n';
  fflush(stdout);

  return 0;
}