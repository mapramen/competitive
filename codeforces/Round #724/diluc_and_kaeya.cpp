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
#define N 500001

char s[N];
map<pii,int> M;

void Solve(){
  int n;
  scanf("%d%s", &n, s);

  M.clear();
  int d = 0, k = 0;
  for(int i = 0; i < n; ++i){
    d += (s[i] == 'D');
    k += (s[i] == 'K');

    int g = gcd(d, k);
    pii p = {d / g, k / g};

    printf("%d ", ++M[p]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}