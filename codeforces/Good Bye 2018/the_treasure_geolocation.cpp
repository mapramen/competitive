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

int main(){
  int n;
  set< pii > S;
  vector< pii > v;

  cin >> n;
  for(int i = 0; i < n; ++i){
    int x, y;
    cin >> x >> y;
    S.insert(make_pair(x, y));
  }

  for(int i = 0; i < n; ++i){
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }

  for(auto p : v){
    int sx, sy, c = 0;
    tie(sx, sy) = *S.begin();

    int Tx = sx + p.first, Ty = sy + p.second;

    for(int i = 0; i < n; ++i){
      int tx = Tx - v[i].first, ty = Ty - v[i].second;
      if(S.count(make_pair(tx, ty)) == 0){
        break;
      }
      ++c;
    }

    if(c == n){
      cout << Tx << ' ' << Ty << '\n';
      break;
    }
  }

  return 0;
}