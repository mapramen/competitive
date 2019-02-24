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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int Solve(int ang){
  for(int n = 3; n <= 360; ++n){
    for(int i = 1; 2 * i <= n; ++i){
      int x = 360 * i;
      if(x % (2 * n) != 0){
        continue;
      }
      x /= (2 * n);
      if(x == ang || (i > 1 && x + ang == 180)){
        return n;
      }
    }
  }
  return -1;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int ang, found = 0;
    cin >> ang;
    cout << Solve(ang) << '\n';
  }
  return 0;
}