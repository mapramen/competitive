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
#define tiii tuple<int,int,int>
#define N 200001

int allotedRoom[N];
vector<tiii> v;

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int l, r;
    scanf("%d%d", &l, &r);
    v.push_back({l, 1, i});
    v.push_back({r, 2, i});
  }
  sort(v.begin(), v.end());

  int ans = 0;
  queue<int> Q;

  for(auto t: v){
    int l, x, i;
    tie(l, x, i) = t;

    if(x == 2){
      Q.push(allotedRoom[i]);
      continue;
    }

    if(Q.empty()){
      Q.push(++ans);
    }

    allotedRoom[i] = Q.front();
    Q.pop();
  }

  printf("%d\n", ans);
  for(int i = 1; i <= n; ++i){
    printf("%d ", allotedRoom[i]);
  }
  printf("\n");

  return 0;
}