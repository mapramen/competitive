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
#define N 500001

vector<int> C;
int a[N], b[N], c[N], d[N];

void AddToCompressed(int x){
  C.push_back(max(0, x));
}

int GetCompressedValue(int x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

void Initialise(){
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());
}

void Reset(){
  for(int i = 0; i < C.size(); ++i){
    c[i] = 0;
    d[i] = 0;
  }
  C.clear();
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n, T, x, y;

    scanf("%d%d%d%d", &n, &T, &x, &y);
    
    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n; ++i){
      scanf("%d", &b[i]);
    }

    AddToCompressed(-1);
    AddToCompressed(T);

    for(int i = 1; i <= n; ++i){
      AddToCompressed(b[i] - 1);
      AddToCompressed(b[i]);
    }

    Initialise();

    for(int i = 1; i <= n; ++i){
      int ci = GetCompressedValue(b[i]);
      c[ci] += (a[i] == 0);
      d[ci] += a[i];
    }

    for(int i = 1; i < C.size(); ++i){
      c[i] += c[i - 1];
      d[i] += d[i - 1];
    }
    
    int totalC = c[C.size() - 1], totalD = d[C.size() - 1];

    int ans = 0;
    for(int i = 1; i < C.size(); ++i){
      ll s = (1ll * x * c[i] + 1ll * y * d[i]);

      if(s > C[i]){
        continue;
      }

      int sx = C[i] - s;
      int cx = min(totalC - c[i], sx / x);
      sx -= cx * x;
      int dx = min(totalD - d[i], sx / y);

      int ansx = c[i] + d[i] + cx + dx;
      ans = max(ans, ansx);
    }

    printf("%d\n", ans);
    Reset();
  }

  return 0;
}