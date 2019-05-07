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
#define N 501

int A[N][N], B[N][N];

int main(){
  int n, m;
  cin >> n >> m;
  
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      cin >> A[i][j];
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      cin >> B[i][j];
    }
  }

  for(int k = 0; k <= n + m - 2; ++k){
    vector<int> u, v;
    for(int i = 1; i <= n; ++i){
      int j = k + 2 - i;
      if(j <= 0 || j > m){
        continue;
      }
      u.push_back(A[i][j]);
      v.push_back(B[i][j]);
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    if(u != v){
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
  return 0;
}