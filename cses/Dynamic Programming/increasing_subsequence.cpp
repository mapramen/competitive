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

int main(){
  int n;
  vector<int> v;

  scanf("%d", &n);
  while(n--){
    int x;
    scanf("%d", &x);

    if(v.empty() || v.back() < x){
      v.push_back(x);
      continue;
    }

    int i = lower_bound(v.begin(), v.end(), x) - v.begin();
    v[i] = x;
  }

  printf("%lu\n", v.size());
  
  return 0;
}