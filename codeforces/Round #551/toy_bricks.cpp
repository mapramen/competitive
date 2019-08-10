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
#define N 101

vector< vector<int> > A(N), B(N);
int r[N], c[N], a[N][N], b[N][N];

int main(){
  int n, m, h;
  
  cin >> n >> m >> h;
  
  for(int j = 1; j <= m; ++j){
    int x;
    cin >> x;
    B[x].push_back(j);
    c[j] = x;
  }

  for(int i = 1; i <= n; ++i){
    int x;
    cin >> x;
    A[x].push_back(i);
    r[i] = x;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      cin >> a[i][j];
    }
  }

  for(int x = h; x > 0; --x){
    for(int i : A[x]){
      bool valid = false;
      
      for(int j = 1; j <= m && !valid; ++j){
        valid = (b[i][j] == x);
      }

      for(int j = 1; j <= m && !valid; ++j){
        if(a[i][j] == 1 && c[j] >= x){
          b[i][j] = x;
          a[i][j] = 0;
          valid = true;
        }
      }
    }

    for(int j : B[x]){
      bool valid = false;
      
      for(int i = 1; i <= n && !valid; ++i){
        valid = (b[i][j] == x);
      }

      for(int i = 1; i <= n && !valid; ++i){
        if(a[i][j] == 1 && r[i] >= x){
          b[i][j] = x;
          a[i][j] = 0;
          valid = true;
        }
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      cout << max(b[i][j], a[i][j]) << ' ';
    }
    cout << '\n';
  }

  return 0;
}