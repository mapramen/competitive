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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
set<int> S;

int Query(char c, int x){
  printf("%c %d\n", c, x);
  fflush(stdout);
  int y;
  scanf("%d", &y);
  return y;
}

int BinarySearch(){
  int x = 0, y = 1E9, ans = y;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Query('>', mid)){
      x = mid + 1;
    }
    else{
      ans = mid, y = mid - 1;
    }
  }
  return ans;
}

int GetRandIndex(int n){
  while(true){
    int x = uniform_int_distribution<int>(1, n)(rng);
    if(S.count(x) == 0){
      S.insert(x);
      return x;
    }
  }
}

int main(){
  int n;

  scanf("%d", &n);

  int m = BinarySearch();

  vector<int> v{m};
  for(int i = 0; i < min(n, 30); ++i){
    v.push_back(Query('?', GetRandIndex(n)));
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  int d = 0;
  for(int x = v.size() - 1; x > 0; --x){
    d = gcd(d, v[x] - v[x - 1]);
  }

  int a = m - (n - 1) * d;

  printf("! %d %d\n", a, d);
  fflush(stdout);

  return 0;
}