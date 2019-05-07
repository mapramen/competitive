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
#define N 101

int l[N], r[N];

int main(){
  int n, k;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> l[i] >> r[i];
  }
  cin >> k;
  int ans = 1;
  for( ; ans <= n && r[ans] < k; ++ans);
  ans = (n - ans + 1);
  cout << ans << '\n';
  return 0;
}