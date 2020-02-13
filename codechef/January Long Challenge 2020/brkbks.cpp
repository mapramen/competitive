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
    int s, w1, w2, w3;
    cin >> s >> w1 >> w2 >> w3;

    int ans = 3;

    if(w1 + w2 + w3 <= s){
      ans = 1;
    }
    else if(w1 + w2 <= s || w2 + w3 <= s){
      ans = 2;
    }

    cout << ans << '\n';
  }
  
  return 0;
}