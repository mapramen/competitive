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
  string s;
  ll ans = 0;

  cin >> n >> s;
  for(int i = 1; i <= n; ++i){
    int x = s[i - 1] - '0';
    if(x % 2 == 0){
      ans += i;
    }
  }

  cout << ans << '\n';
  
  return 0;
}