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

bool IsPresent(vector<int> v, int x){
  int i = lower_bound(v.begin(), v.end(), x) - v.begin();
  return i < v.size() && v[i] == x;
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n;
    vector<int> v;

    scanf("%d", &n);
    while(n--){
      int x;
      scanf("%d", &x);
      v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    reverse(v.begin(), v.end());

    int ans = 0;

    vector<int> u;
    for(int x : v){
      bool isDivisor = false;
      for(int y : u){
        isDivisor |= (y % x == 0);
      }
      
      if(isDivisor){
        continue;
      }

      ans += x;
      u.push_back(x);
      if(u.size() == 3){
        break;
      }
    }

    reverse(v.begin(), v.end());
    int m = v.back();
    if(m % 30 == 0 && IsPresent(v, m / 2) && IsPresent(v, m / 3) && IsPresent(v, m / 5)){
      ans = max(ans, m / 2 + m / 3 + m / 5);
    }

    printf("%d\n", ans);
  }

  return 0;
}