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

int a[N];

int main(){
  int t;

  cin >> t;
  while(t--){
    int n;
    
    cin >> n;
    for(int i = 1; i <= n; ++i){
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    for(int i = n; i > 0; --i){
      cout << a[i] << ' ';
    }
    cout << '\n';
  }  
  return 0;
}