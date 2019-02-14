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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2000

int a[N];

int main(){
  int n;

  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }

  cout << n + 1 << '\n';

  for(int i = n - 1, s = 0; i > -1; --i){
    a[i] += s;
    int x = n * ((a[i] + n - 1) / n) + i - a[i];
    cout << 1 << ' ' << i + 1 << ' ' << x << '\n';
    s += x;
  }

  cout << 2 << ' ' << n << ' ' << n << '\n';
  
  return 0;
}