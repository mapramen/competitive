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

string GetValuedString(string s, int x){
  replace(s.begin(), s.end(), 'x', (char)('0' + x));
  replace(s.begin(), s.end(), 'X', (char)('0' + 1 - x));
  return s;
}

template <typename T> T ExtractTop(stack<T>& S){
  T x = S.top();
  S.pop();
  return x;
}

bool Evaluate(string s){
  stack<int> values;
  stack<char> operations;

  for(auto c : s){
    if(c == '('){
      continue;
    }

    if(c == ')'){
      int x = ExtractTop(values), y = ExtractTop(values), z;
      char op = ExtractTop(operations);

      if(op == '|'){
        z = x | y;
      }
      else if(op == '&'){
        z = x & y;
      }
      else{
        z = x ^ y;
      }

      values.push(z);
      
      continue;
    }

    if(c == '0' || c == '1'){
      values.push(c - '0');
    }
    else{
      operations.push(c);
    }
  }

  // cout << "Evaluate " << s << ' ' << values.top() << '\n';

  return values.top();
}

bool Solve(){
  string s;
  cin >> s;
  string s1 = GetValuedString(s, 0), s2 = GetValuedString(s, 1);
  return Evaluate(s1) != Evaluate(s2);
}

int main(){
  int t;
  cin >> t;
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}