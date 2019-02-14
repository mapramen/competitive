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
#define N 100001

int a[N];

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  sort(a + 1, a + n + 1);

  for(int i = n; i > 1; --i){
    a[i] -= a[i - 1];
  }

  for(int i = 1; k > 0 && i <= n; ++i){
    if(a[i] == 0){
      continue;
    }
    printf("%d\n", a[i]);
    --k;
  }

  for( ; k; --k){
    printf("0\n");
  }

  return 0;
}