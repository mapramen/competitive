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

void Solve(){
  int n;
  string s;

  scanf("%d", &n);
  cin >> s;

  string ans = s;
  int ansk = 1;

  for(int k = 2; k <= n; ++k){
    string a = string(s, 0, k - 1), b = string(s, k - 1);

    if((n - k + 1) % 2 == 1){
      reverse(a.begin(), a.end());
    }

    string t = b + a;
    
    if(ans.empty() || t < ans){
      ans = t, ansk = k;
    }
  }

  printf("%s\n%d\n", ans.c_str(), ansk);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}