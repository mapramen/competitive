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
#define N 1000001

int f[N];
string s;

int ComputeFailure(int i, char c){
  for( ; i != 0 && s[i] != c; i = f[i]);
  return i + (s[i] == c);
}

int main(){
  cin >> s;

  int n = s.size();
  
  for(int i = 2; i <= n; ++i){
    f[i] = ComputeFailure(f[i - 1], s[i - 1]);
  }

  vector<int> ans;
  for(int i = f[n]; i != 0; i = f[i]){
    ans.push_back(i);
  }
  reverse(ans.begin(), ans.end());

  for(int x: ans){
    printf("%d ", x);
  }
  printf("\n");
  
  return 0;
}