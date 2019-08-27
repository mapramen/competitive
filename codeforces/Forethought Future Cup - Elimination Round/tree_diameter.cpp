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

int Query(int i, vector<int> &v){
  printf("1 %lu %d ", v.size(), i);
  for(int j : v){
    printf("%d ", j);
  }
  printf("\n");
  fflush(stdout);

  int d;
  scanf("%d", &d);

  return d;
}

int BinarySearch(int n){
  vector<int> v;
  for(int i = 2; i <= n; ++i){
    v.push_back(i);
  }

  int d = Query(1, v);

  while(v.size() > 1){
    int m = v.size() / 2;
    vector<int> u(v.begin(), v.begin() + m);

    int dx = Query(1, u);

    if(dx >= d){
      v = u;
    }
    else{
      v = vector<int>(v.begin() + m, v.end());
    }
  }

  return v.back();
}

int QueryAns(int n, int i){
  vector<int> v;
  for(int j = 1; j <= n; ++j){
    if(j != i){
      v.push_back(j);
    }
  }

  return Query(i, v);
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    int i = BinarySearch(n);
    printf("-1 %d\n", QueryAns(n, i));
    fflush(stdout);
  }

  return 0;
}