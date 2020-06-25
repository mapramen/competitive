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
#define B 3

int GetMex(int n){
  return n % (B + 1);
}

bool Solve(){
  int n;
  scanf("%d", &n);

  int ans = 0;
  while(n--){
    int x;
    scanf("%d", &x);
    ans ^= GetMex(x);
  }

  return ans != 0;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "first" : "second");
  }
  return 0;
}