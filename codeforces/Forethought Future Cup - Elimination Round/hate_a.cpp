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
  string s;

  cin >> s;

  int m = s.size(), a = 0;
  for(char c : s){
    a += (c == 'a');
  }

  int n = max(1, (m + a) / 2);

  string t;
  for(int i = 0; i < n; ++i){
    if(s[i] != 'a'){
      t.push_back(s[i]);
    }
  }

  if(t == string(s, n)){
    cout << string(s, 0, n) << "\n";
  }
  else{
    cout << ":(\n";
  }
  
  return 0;
}