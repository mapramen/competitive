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
#define N 31
#define M 54

ll a[N];
bool c[M];

string Solve(){
  int n, k;

  cin >> n >> k;

  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  for(int i = 0; i < M; ++i){
    c[i] = false;
  }

  for(int i = 1; i <= n; ++i){
    ll x = a[i];
    for(int j = 0; x > 0; x /= k, ++j){
      int y = x % k;
      if(y == 0){
        continue;
      }

      if(y > 1 || c[j] == true){
        return "NO";
      }
      
      c[j] = true;
    }
  }

  return "YES";
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cout << Solve() << '\n';
  }
  return 0;
}