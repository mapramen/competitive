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
#define N 100001

int f[N], cnt;
char s[N];

void Update(int i, int x){
  f[i] += x;
  
  if(f[i] == 1 && x == 1){
    ++cnt;
  }

  if(f[i] == 0 && x == -1){
    --cnt;
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int x = 0; x < m; ++x){
    int i;
    scanf("%d", &i);
    Update(i, 1);
    s[x] = '0' + (cnt == n);
    if(cnt == n){
      for(int i = 1; i <= n; ++i){
        Update(i, -1);
      }
    }
  }

  printf("%s\n", s);
  
  return 0;
}