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

int a[N];

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  for(int i = 2; i <= n; ++i){
    if(a[i - 1] + a[i] == 5){
      cout << "Infinite\n";
      return 0;
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    if(a[i] == 1){
      continue;
    }
    ans += (((i > 1) + (i < n)) * (1 + a[i]));
  }

  for(int i = 3; i <= n; ++i){
    ans -= (a[i] == 2 && a[i - 2] == 3);
  }

  cout << "Finite\n";
  cout << ans << '\n';

  return 0;
}