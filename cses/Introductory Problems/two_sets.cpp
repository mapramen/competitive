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

void Print(vector<int> &v){
  printf("%lu\n", v.size());
  for(auto x: v){
    printf("%d ", x);
  }
  printf("\n");
}

int main(){
  ll n;

  scanf("%lld", &n);

  ll s = n * (n + 1) / 2;

  if(s % 2 == 1){
    printf("NO\n");
    return 0;
  }

  s /= 2;

  vector<int> v1, v2;

  for(int i = 1; i <= s; s -= i, ++i){
    v1.push_back(i);
  }

  for(int i = v1.back() + 1; i <= n; ++i){
    v2.push_back(i);
  }

  if(s > 0){
    swap(v1[v2.front() - s - 1], v2.front());
  }

  printf("YES\n");
  Print(v1);
  Print(v2);

  return 0;
}