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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int a[N];

int main(){
  int n, t, ans = INT_MAX;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }
  for(int tx = 1; tx <= 100; ++tx){
    int ansx = 0;
    for(int i = 1; i <= n; ++i){
      int ansxx = INT_MAX;
      for(int txx = max(1, tx - 1); txx <= tx + 1; ++txx){
        ansxx = min(ansxx, abs(txx - a[i]));
      }
      ansx += ansxx;
    }
    if(ansx < ans){
      ans = ansx, t = tx;
    }
  }
  cout << t << ' ' << ans << '\n';
  return 0;
}