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
#define N 1001

int a[N];

bool Check(int n, int m){
  vector<int> v;
  for(int i = 1; i <= n; ++i){
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end(), greater<int>());

  for(int i = 0; i < n && m >= 0; i += 2){
    m -= v[i];
  }

  return m >= 0;
}

int BinarySearch(int n, int m){
  int x = 0, y = n, ans = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(mid, m)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }
  return ans;
}

int main(){
  int n, m;

  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  cout << BinarySearch(n, m) << '\n';

  return 0;
}