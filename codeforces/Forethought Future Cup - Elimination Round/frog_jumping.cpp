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
#define N 200001

int c[N];
bool visited[N];

void Initialise(int a, int b){
  priority_queue<int, vector<int>, greater<int> > Q;
  Q.push(0);

  int x = 0, y = 0, n = a + b;
  while(!Q.empty()){
    int i = Q.top();
    Q.pop();

    if(i < 0 || i >= n || visited[i]){
      continue;
    }

    visited[i] = true;
    x = max(x, i);
    c[x] = ++y;

    Q.push(i - b);
    Q.push(i + a);
  }

  for(int i = 1; i < n; ++i){
    if(c[i] == 0){
      c[i] = c[i - 1];
    }
  }
}

ll Query(int n, int g){
  int b = n / g;
  ll ans = (1ll * g * b * (b + 1)) / 2;
  ans += 1ll * max(0, n - b * g + 1) * (b + 1);
  return ans;
}

int main(){
  int n, a, b;

  cin >> n >> a >> b;

  Initialise(a, b);

  ll ans = 0;
  for(int i = 0; i < min(n + 1, a + b); ++i){
    ans += c[i];
  }

  int g = __gcd(a, b);

  if(n >= a + b){
    ans += (Query(n, g) - Query(a + b - 1, g));
  }

  cout << ans << '\n';

  return 0;
}