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

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

int main(){
  string s;
  cin >> s;

  ll c1 = 0, c2 = 0, s0 = 0, s1 = 0, s2 = 0;
  for(char t: s){
    int d = t - '0';
    
    c2 = (c2 + c1) % MOD;
    s2 = (s2 + s1) % MOD;
    s2 = (10 * s2 + c2 * d) % MOD; 

    s1 = (s1 + s0) % MOD;
    c1 = (c1 + 1) % MOD;

    s0 = (10 * s0 + d) % MOD;
  }

  cout << (s1 + s2) % MOD << '\n';

  return 0;
}