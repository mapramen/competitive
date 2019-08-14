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
#define B 3

vector<int> v{0, 1, 2, 0, 2, 1, 0};
int a[B], b[B];

int main(){
  int m = INT_MAX;

  for(int i = 0; i < B; ++i){
    cin >> a[i];
  }

  for(int i = 0; i < B; ++i){
    int c = 0;
    for(int x : v){
      c += (x == i);
    }
    m = min(m, a[i] / c);
  }

  for(int i = 0; i < B; ++i){
    int c = 0;
    for(int x : v){
      c += (x == i);
    }
    a[i] -= m * c;
  }

  int ans = 0;
  for(int i = 0, n = v.size(); i < n; ++i){
    for(int j = 0; j < B; ++j){
      b[j] = a[j];
    }

    int k = 0;
    for(int j = i; b[v[j]]; --b[v[j]], j = (j + 1) % n, ++k);

    ans = max(ans, k);
  }

  ans += v.size() * m;

  cout << ans << '\n';

  return 0;
}