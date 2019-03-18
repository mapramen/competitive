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
#define N 1000002

char s[N];
int suffixMin[N], suffixSum[N];

int main(){
  int n;

  scanf("%d%s", &n, s);

  for(int i = n; i > 0; --i){
    int x = s[i - 1] == '(' ? 1 : -1;
    suffixMin[i] = min(x, x + suffixMin[i + 1]);
    suffixSum[i] = x + suffixSum[i + 1];
  }

  int ans = 0;
  for(int i = 1, prefixSum = 0; i <= n && prefixSum >= 0; ++i){
    int x = s[i - 1] == '(' ? -1 : 1;
    int prefixSumX = prefixSum + x;
    if(prefixSumX >= 0 && suffixMin[i + 1] == suffixSum[i + 1] && prefixSumX + suffixSum[i + 1] == 0){
      ++ans;
    }
    prefixSum += (s[i - 1] == '(' ? 1 : -1);
  }

  printf("%d\n", ans);
  
  return 0;
}