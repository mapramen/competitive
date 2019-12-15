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
#define B 26

int c[B];

int main(){
  int n;
  
  cin >> n;
  while(n--){
    string s;
    cin >> s;
    ++c[s.front() - 'a'];
  }

  int ans = 0;
  for(int i = 0; i < B; ++i){
    int x = c[i];
    if(x % 2 == 0){
      ans += (x * (x - 2) / 4);
    }
    else{
      x /= 2;
      ans += x * x;
    }
  }

  cout << ans << '\n';

  return 0;
}