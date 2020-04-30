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

string Solve(string s){
  string ans;

  int x = 0;
  for(auto c : s){
    int k = c - '0';

    for( ; x < k; ++x){
      ans.push_back('(');
    }

    for( ; x > k; --x){
      ans.push_back(')');
    }

    ans.push_back(c);
  }

  for( ; x > 0; --x){
    ans.push_back(')');
  }

  return ans;
}

int main(){
  int t;
  cin >> t;
  for(int k = 1; k <= t; ++k){
    string s;
    cin >> s;
    cout << "Case #" << k << ": " << Solve(s) << "\n";
  }
  return 0;
}