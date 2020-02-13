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
#define N 100001

int a[N];

int main(){
  int n, q;

  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%s\n", ((a[l] < a[l + 1]) ^ (a[r - 1] < a[r])) ? "YES" : "NO");
  }
  
  return 0;
}