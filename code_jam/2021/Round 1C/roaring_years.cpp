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

bool IsMinNumber(string a, string b){
  if(a.size() < b.size()){
    return true;
  }

  if(b.size() < a.size()){
    return false;
  }

  return a < b;
}

string GetRoaringYear(int n, int l){
  string ans;
  for(int i = 0; i < l; ++i){
    for(char c: to_string(n + i)){
      ans.push_back(c);
    }
  }
  return ans;
}

string BinarySearch(int l, string s){
  int x = 1, y = 2e9, ans = y;

  while(x <= y){
    int mid = x + (y - x) / 2;
    string t = GetRoaringYear(mid, l);
    if(IsMinNumber(s, t)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return GetRoaringYear(ans, l);
}

string Solve(){
  ll n;
  scanf("%lld", &n);

  string s = to_string(n);
  string ans = GetRoaringYear(1, s.size() + 1);

  for(int l = 2; l <= s.size(); ++l){
    string ansx = BinarySearch(l, s);
    if(IsMinNumber(ansx, ans)){
      ans = ansx;
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %s\n", k, Solve().c_str());
  }
  return 0;
}