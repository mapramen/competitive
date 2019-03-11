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
#define B 26

char s[N];
int c[B];

int main(){
  int n, k;
  
  scanf("%d%d%s", &n, &k, s);
  
  for(int i = 0; i < n; ){
    int j = i;
    for( ; j < n && s[j] == s[i]; ++j);
    int x = s[i] - 'a';
    c[x] += ((j - i) / k);
    i = j;
  }

  int ans = 0;
  for(int i = 0; i < B; ++i){
    ans = max(ans, c[i]);
  }

  printf("%d\n", ans);
  
  return 0;
}