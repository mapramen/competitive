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
    int a, b;
    cin >> a >> b;
    int c = abs(a - b), ans = 0;
    for(int i = 1; c > 0 || c % 2 != 0; c -= i, ++i, ++ans);
    cout << ans << '\n';
  }
  return 0;
}