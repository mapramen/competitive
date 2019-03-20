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
char s[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  scanf("%s", s);

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    int j;
    vector<int> v;
    for(j = i; j <= n && s[j - 1] == s[i - 1]; ++j){
      v.push_back(a[j]);
    }

    if(v.size() > m){
      sort(v.begin(), v.end(), greater<int>());
      v.resize(m);
    }

    for(int x : v){
      ans += x;
    }

    i = j - 1;
  }

  printf("%lld\n", ans);
  
  return 0;
}