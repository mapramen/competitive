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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int degree[N];

int main(){
  int n, s;

  scanf("%d%d", &n, &s);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    ++degree[i];
    ++degree[j];
  }

  int m = 0;
  for(int i = 1; i <= n; ++i){
    m += (degree[i] == 1);
  }

  double ans = 2 * s;
  ans /= m;

  printf("%.15lf\n", ans);
  
  return 0;
}