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
#define N 51

int c[N];

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    int x;
    cin >> x;
    ++c[x];
  }

  int m = n / 2;
  for(int i = 1; i < N; ++i){
    if(c[i] == 0){
      continue;
    }
    cout << ((c[i] <= m) ? "Alice" : "Bob") << '\n';
    return 0;
  }

}