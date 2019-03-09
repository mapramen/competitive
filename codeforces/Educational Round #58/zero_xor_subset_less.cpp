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
#define B 29

int main(){
  int n;
  vector< pii > v;

  scanf("%d", &n);
  
  int p = 0;
  while(n--){
    int a;
    scanf("%d", &a);
    p ^= a;

    for(pii q : v){
      int x, k;
      tie(k, x) = q;

      if((a & (1 << k)) > 0){
        a ^= x;
      }
    }

    if(a == 0){
      continue;
    }

    int k = B;
    for( ; k > -1 && (a & (1 << k)) == 0; --k);

    v.push_back(make_pair(k, a));
  }

  int ans = (p == 0) ? -1 : v.size();

  printf("%d\n", ans);
  
  return 0;
}