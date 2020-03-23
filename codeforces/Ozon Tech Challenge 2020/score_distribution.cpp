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
#define N 5001
#define M 1000000000

int a[N];

int main(){
  int n, m;

  cin >> n >> m;

  int i = 1, s = 0;
  for( ; i <= n && s < m; ++i){
    a[i] = i;
    s += ((i - 1) / 2);
  }

  if(s < m){
    cout << "-1\n";
    return 0;
  }

  if(s != m){
    --i;
    s -= ((i - 1) / 2);
    a[i] = a[i - 1] + a[i - 2 * (m - s)];
  }

  if(a[i] == 0){
    --i;
  }

  for(int j = n, k = 0; j > i; --j, ++k){
    a[j] = M - k * n;
  }

  for(int j = 1; j <= n; ++j){
    cout << a[j] << ' ';
  }
  cout << '\n';

  return 0;
}