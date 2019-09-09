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

int a[B];

int main(){
  int t;
  cin >> t;
  
  while(t--){
    string s;
    cin >> s;

    for(int i = 0; i < B; ++i){
      a[i] = 0;
    }

    for(char c : s){
      ++a[c - 'a'];
    }

    s.clear();

    vector<int> v;
    for(int j = 0; j < 2 && v.empty(); ++j){
      int x = -1, y = -1;
      
      for(int i = B - 1; i > -1; --i){
        if(i % 2 == j && a[i]){
          x = i;
        }
      }

      for(int i = 0; i < B; ++i){
        if(i % 2 != j && a[i]){
          y = i;
        }
      }

      if(x == -1 || y == -1 || abs(x - y) > 1){
        v.push_back(j);
        v.push_back(1 - j);
      }
    }

    for(int j : v){
      for(int i = B; i > -1; --i){
        if(i % 2 != j){
          continue;
        }
        int k = a[i];
        while(k--){
          s.push_back('a' + i);
        }
      }
    }

    bool valid = !s.empty();
    for(int i = 1; i < s.size() && valid; ++i){
      valid = (abs(s[i] - s[i - 1]) != 1);
    }

    if(valid){
      cout << s << '\n';
    }
    else{
      cout << "No answer\n";
    }
  }

  return 0;
}