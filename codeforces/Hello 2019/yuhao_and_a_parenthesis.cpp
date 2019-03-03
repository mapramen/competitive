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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001

char s[N];
int a[N], b[N];

int main(){
  int n, zeros = 0;

  scanf("%d", &n);
  while(n--){
    scanf("%s", s);

    int p = 0, q = INT_MAX;
    for(int i = 0; s[i] != '\0'; ++i){
      p += ((s[i] == '(') ? 1 : -1);
      q = min(q, p);
    }

    if(p > 0){
      if(q < 0){
        continue;
      }
      ++a[p];
    }
    else if(p < 0){
      if(q < p){
        continue;
      }
      ++b[-p];
    }
    else{
      if(q < 0){
        continue;
      }
      ++zeros;
    }
  }

  int ans = zeros / 2;
  for(int i = 1; i < N; ++i){
    ans += min(a[i], b[i]);
  }

  printf("%d\n", ans);
  
  return 0;
}