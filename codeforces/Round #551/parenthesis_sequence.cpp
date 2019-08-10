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

int main(){
  int n;
  string s;

  cin >> n >> s;

  int m = n / 2;
  for(char c : s){
    m -= (c == '(');
  }

  for(int i = 0; i < n && m > 0; ++i){
    if(s[i] == '?'){
      s[i] = '(';
      --m;
    }
  }

  for(int i = 0; i < n; ++i){
    if(s[i] == '?'){
      s[i] = ')';
    }
  }

  m = 0;
  for(int i = 0; i < n; ++i){
    m += (s[i] == '(' ? 1 : -1);
    if(m < 0 || (m == 0 && i < n - 1)){
      cout << ":(\n";
      return 0;
    }
  }

  if(m == 0){
    cout << s << '\n';
  }
  else{
    cout << ":(\n";
  }
  return 0;
}