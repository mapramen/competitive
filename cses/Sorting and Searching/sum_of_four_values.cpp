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
#define N 5001
 
int a[N];
 
int main(){
  int n, s;
 
  cin >> n >> s;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }
 
  map<int,pii> M;
  for(int i = 1; i <= n; ++i){
    if(a[i] < s){
      for(int j = i - 1; j > 2; --j){
        int x = a[i] + a[j];
        if(x >= s){
          continue;
        }

        auto it = M.find(s - x);
        if(it != M.end() && it->second.second < j){
          cout << it->second.first << ' ' << it->second.second << ' ' << j << ' ' << i << '\n';
          return 0;
        }
      }
    }
 
    for(int j = 1; j < i; ++j){
      int x = a[i] + a[j];
      if(x < s && M.count(x) == 0){
        M[x] = {j, i};
      }
    }
  }
 
  cout << "IMPOSSIBLE\n";
 
  return 0;
}