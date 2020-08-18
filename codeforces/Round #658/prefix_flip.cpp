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

vector<int> GetPathToRoot(string s){
  vector<int> ans;

  if(s.empty()){
    return ans;
  }

  s.push_back('1');
  for(int i = 0, n = s.size() - 1; i < n; ++i){
    if(s[i] != s[i + 1]){
      ans.push_back(i + 1);
    }
  }

  return ans;
}

void Solve(){
  int n;
  string a, b;

  cin >> n >> a >> b;

  vector<int> A = GetPathToRoot(a), B = GetPathToRoot(b);
  reverse(B.begin(), B.end());
  
  vector<int> ans(A);
  ans.insert(ans.end(), B.begin(), B.end());

  printf("%lu ", ans.size());
  for(int i: ans){
    printf("%d ", i);
  }
  printf("\n");
}

int main(){
  int t;
  cin >> t;
  while(t--){
    Solve();
  }
  return 0;
}