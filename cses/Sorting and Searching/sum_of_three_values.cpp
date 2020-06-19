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

  map<int,int> M;
  for(int i = 1; i <= n; ++i){
    for(int j = i - 1; j > 1; --j){
      auto it = M.find(s - a[i] - a[j]);
      if(it != M.end() && it->second < j){
        cout << it->second << ' ' << j << ' ' << i << '\n';
        return 0;
      }
    }
    
    if(M.count(a[i]) == 0){
      M[a[i]] = i;
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}