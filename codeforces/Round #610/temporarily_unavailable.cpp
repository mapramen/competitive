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
  int t;
  cin >> t;
  while(t--){
    int a, b, c, r;
    cin >> a >> b >> c >> r;

    int l1 = min(a, b), r1 = max(a, b), l2 = c - r, r2 = c + r;

    cout << (r1 - l1) - max(0, min(r1, r2) - max(l1, l2)) << '\n';
  }
  return 0;
}