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
#define N 100001

ll a[N];
char s[N];

ll Compute(vector<int> &v, ll &x, int c){
  if(v.empty() || x == 0){
    return 0ll;
  }

  ll ans = 0;
  ++c;

  while(!v.empty() && x > 0){
    int i = v.back();
    if(a[i] <= x){
      ans += c * a[i];
      x -= a[i];
      a[i] = 0;
      v.pop_back();
    }
    else{
      ans += c * x;
      a[i] -= x;
      x = 0;
    }
  }

  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  scanf("%s", s);

  ll ans = 0;
  vector<int> grasses, waters;
  bool waterFound = false;
  
  for(int i = 1; i <= n; ++i){
    char c = s[i - 1];
    
    if(c == 'G'){
      grasses.push_back(i);
      continue;
    }
    
    if(c == 'W'){
      waters.push_back(i);
      waterFound = true;
      continue;
    }

    ans += Compute(waters, a[i], 3);
    ans += Compute(grasses, a[i], 5);

    if(waterFound){
      ans += 4 * a[i];
    }
    else{
      ans += 6 * a[i];
    }

    a[i] = 0;
  }

  waters.clear();
  grasses.clear();

  for(int i = 1; i <= n; ++i){
    char c = s[i - 1];
    if(c == 'L'){
      continue;
    }

    if(c == 'W'){
      waters.push_back(i);
      continue;
    }
    
    ans += Compute(waters, a[i], 3);
    ans += 3 * a[i];
    a[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    char c = s[i - 1];
    if(c == 'W'){
      ans += 2 * a[i];
      a[i] = 0;
    }
  }

  printf("%lld\n", ans);

  return 0;
}