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

  int ans = 0;
  for(int i = 0, j = 0, n = s.size(); i < n; i = j){
    for(j = i; j < n && s[j] == s[i]; ++j);
    ans = max(ans, j - i);
  }

  printf("%d\n", ans);
  
  return 0;
}