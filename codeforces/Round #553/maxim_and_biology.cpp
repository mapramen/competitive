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
  int n, ans = INT_MAX;
  string s, t = "ACTG";

  cin >> n >> s;
  for(int i = 0, m = t.size(); i + m <= n; ++i){
    int ansx = 0;
    for(int j = 0; j < m; ++j){
      int c = (B + s[i + j] - t[j]) % B;
      ansx += min(c, B - c);
    }
    ans = min(ans, ansx);
  }

  cout << ans << '\n';

  return 0;
}