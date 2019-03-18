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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];

int main(){
  int n;
  stack<int> S;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int m = 0;
  for(int i = 1; i <= n; ++i){
    m = max(m, a[i]);
  }

  bool valid = true;
  for(int i = 1; i <= n && valid; ++i){
    int x = a[i];
    
    if(x == m){
      valid = S.empty();
      continue;
    }

    if(S.empty() || S.top() > x){
      S.push(x);
    }
    else if(S.top() == x){
      S.pop();
    }
    else{
      valid = false;
    }
  }

  printf("%s\n", S.empty() ? "YES" : "NO");

  return 0;
}