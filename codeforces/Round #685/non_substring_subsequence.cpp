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

string s;
int a[2][2];

bool Query(int i, int j){
  int x = s[i - 1] - '0', y = s[j - 1] - '0';
  return a[x][0] < i || j < a[y][1];
}

void Solve(){
  int n, q;

  scanf("%d%d", &n, &q);
  cin >> s;

  for(int k = 0; k < 2; ++k){
    a[k][0] = n + 1;
    a[k][1] = 0;
  }

  for(int i = 1; i <= n; ++i){
    int k = s[i - 1] - '0';
    a[k][0] = min(a[k][0], i);
    a[k][1] = max(a[k][1], i);
  }

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%s\n", Query(i, j) ? "YES" : "NO");
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}