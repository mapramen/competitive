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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 15

int a[N];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  for(int mask = 0; mask < (1 << n); ++mask){
    int s = 0;
    for(int i = 0; i < n; ++i){
      int k = (mask & (1 << i));
      k = k > 0 ? 1 : -1;
      s += k * a[i];
    }
    if(s % 360 == 0){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}