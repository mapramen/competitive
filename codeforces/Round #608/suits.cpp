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
  int a, b, c, d, e, f;

  cin >> a >> b >> c >> d >> e >> f;

  int ans = 0;
  for(int x = 0; x <= min(a, d); ++x){
    int y = max(0, min(b, min(c, d - x)));
    int ansx = e * x + f * y;
    ans = max(ans, ansx);
  }

  printf("%d\n", ans);

  return 0;
}