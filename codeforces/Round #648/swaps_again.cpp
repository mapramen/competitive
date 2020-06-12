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
#define N 501

int a[N], b[N];

void ReadArray(int n, int a[]){
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
}

vector<pii> ArrayCharacteristic(int n, int a[]){
  vector<pii> v;
  for(int i = 1, j = n; i < j; ++i, --j){
    if(a[i] > a[j]){
      swap(a[i], a[j]);
    }
    v.push_back({a[i], a[j]});
  }
  sort(v.begin(), v.end());
  return v;
}

int Solve(){
  int n;

  scanf("%d", &n);
  ReadArray(n, a);
  ReadArray(n, b);

  if(n % 2 == 1 && a[(n + 1) / 2] != b[(n + 1) / 2]){
    return false;
  }

  return ArrayCharacteristic(n, a) == ArrayCharacteristic(n, b);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Yes" : "No");
  }
  return 0;
}