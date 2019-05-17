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
  cin >> n;
  int ans = 0;
  n -= 2;
  for(int k = 1; k <= n; ++k){
    ans += (k + 1) * (k + 2);
  }
  cout << ans << '\n';
  return 0;
}