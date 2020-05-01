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

string Solve(){
  string s;
  cin >> s;

  bool hasZero = false, hasOne = false;
  for(char c : s){
    if(c == '0'){
      hasZero = true;
    }
    else{
      hasOne = true;
    }
  }

  string ans;

  if(hasZero == hasOne){
    for(int i = 0; i < s.size(); ++i){
      for(int x = 0; x < 2; ++x){
        ans.push_back('0' + x);
      }
    }
  }
  else{
    int x = hasZero ? 0 : 1;
    for(int i = 0; i < s.size(); ++i){
      ans.push_back('0' + x);
    }
  }

  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cout << Solve() << '\n';
  }
  return 0;
}