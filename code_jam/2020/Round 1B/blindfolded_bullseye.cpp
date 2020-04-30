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

const int inf = 1E9;
vector< pii > candidatePoints;
bool found;

void Initialise(){
  for(int dx = -1; dx < 2; ++dx){
    for(int dy = -1; dy < 2; ++dy){
      candidatePoints.push_back(make_pair((dx * inf) / 2, (dy * inf) / 2));
    }
  }
}

int Query(int x, int y, bool swapAxes){
  if(found == true){
    return -1;
  }

  if(swapAxes){
    swap(x, y);
  }
  cout << x << ' ' << y << '\n';
  fflush(stdout);

  string s;
  cin >> s;

  if(s == "CENTER"){
    found = true;
    return 0;
  }

  if(s == "HIT"){
    return 1;
  }

  return -1;
}

int QueryLeftEnd(int x, int y, bool swapAxes){
  int l = -inf, r = y, ans = r;

  while(l <= r){
    int mid = l + (r - l) / 2;
    if(Query(x, mid, swapAxes) >= 0){
      ans = mid, r = mid - 1;
    }
    else{
      l = mid + 1;
    }
  }

  return ans;
}

int QueryRightEnd(int x, int y, bool swapAxes){
  int l = y, r = inf, ans = l;

  while(l <= r){
    int mid = l + (r - l) / 2;
    if(Query(x, mid, swapAxes) >= 0){
      ans = mid, l = mid + 1;
    }
    else{
      r = mid - 1;
    }
  }

  return ans;
}

int QueryCenter(int x, int y, bool swapAxes){
  return (QueryLeftEnd(x, y, swapAxes) + QueryRightEnd(x, y, swapAxes)) / 2;
}

void Solve(){
  int x, y;

  found = false;
  for(auto p : candidatePoints){
    if(Query(p.first, p.second, false) >= 0){
      tie(x, y) = p;
      break;
    }
  }

  y = QueryCenter(x, y, false);
  x = QueryCenter(y, x, true);

  if(!found){
    assert(Query(x, y, false) == 0);
  }
}

int main(){
  int t, a, b;
  cin >> t >> a >> b;

  Initialise();

  while(t--){
    Solve();
  }
  
  return 0;
}