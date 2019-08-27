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

  int n = s.size(), x = 0;
  for(char c : s){
    x += (c == 'a');
  }

  int ans = min(n, 2 * x - 1);

  cout << ans << '\n';
  
  return 0;
}