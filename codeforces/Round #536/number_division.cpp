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

#define pii pair< int, int>
#define pll pair< ll, ll>
#define M 10001

int freq[M];

int main(){
  int n;

  scanf("%d", &n);
  while(n--){
    int i;
    scanf("%d", &i);
    ++freq[i];
  }

  ll ans = 0;
  for(int i = 1, j = M - 1; i <= j; ){
    for( ; i < M && freq[i] == 0; ++i);
    for( ; j > 0 && freq[j] == 0; --j);
    
    if(i > j){
      break;
    }

    int k = i + j;
    ans += k * k;
    --freq[i], --freq[j];
  }

  printf("%lld\n", ans);
  
  return 0;
}