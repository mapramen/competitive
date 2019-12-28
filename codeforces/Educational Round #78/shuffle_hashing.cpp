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

int main(){
  int t;
  cin >> t;
  while(t--){
    string p, s;
    vector<int> c(B);

    cin >> p >> s;

    for(auto x : p){
      ++c[x - 'a'];
    }

    bool valid = false;

    const int n = s.size(), m = p.size();
    for(int i = 0; i < n && !valid; ++i){
      --c[s[i] - 'a'];
      
      if(i >= m){
        ++c[s[i - m] - 'a'];
      }

      valid = true;
      for(int x : c){
        valid = valid && (x == 0);
      }
    }

    cout << (valid ? "YES" : "NO") << '\n';
  }
  return 0;
}