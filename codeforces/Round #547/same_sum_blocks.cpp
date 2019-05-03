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
#define N 1501

vector< vector< pii > > v;
int a[N];
vector<int> c;

void NonOverlappingIntervals(vector< pii > &v){
  vector< pii > u;
  for(pii p : v){
    u.push_back(make_pair(p.second, p.first));
  }
  sort(u.begin(), u.end());
  v.clear();

  for(int i = 0; i < u.size(); ){
    v.push_back(make_pair(u[i].second, u[i].first));

    int r = u[i].first;
    for( ; i < u.size() && u[i].second <= r; ++i);
  }
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = i, s = 0; j <= n; ++j){
      s += a[j];
      c.push_back(s);
    }
  }

  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  v.resize(c.size());

  for(int i = 1; i <= n; ++i){
    for(int j = i, s = 0; j <= n; ++j){
      s += a[j];
      int k = lower_bound(c.begin(), c.end(), s) - c.begin();
      v[k].push_back(make_pair(i, j));
    }
  }

  vector< pii > ans;
  for(int i = 0; i < v.size(); ++i){
    NonOverlappingIntervals(v[i]);
    if(v[i].size() > ans.size()){
      ans = v[i];
    }
  }

  cout << ans.size() << '\n';
  for(pii p : ans){
    cout << p.first << ' ' << p.second << '\n';
  }

  return 0;
}