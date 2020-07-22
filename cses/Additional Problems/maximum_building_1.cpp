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
#define N 1001
 
char s[N][N];
int a[N];
stack<int> S, P;
 
int Update(int i, int x){
  int j = i, ans = 0;
 
  while(!S.empty() && S.top() >= x){
    j = P.top();
    ans = max(ans, (i - j) * S.top());
    S.pop(), P.pop();
  }
  S.push(x), P.push(j);
 
  return ans;
}
 
int MaximumRectangleArea(int n){
  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans = max(ans, Update(i, a[i]));
  }
  ans = max(ans, Update(n + 1, 0));
  S.pop(), P.pop();
 
  return ans;
}
 
int main(){
  int n, m;
 
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }
 
  int ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 1; j <= m; ++j){
      if(s[i][j - 1] == '*'){
        a[j] = 0;
      }
      else{
        ++a[j];
      }
    }
    ans = max(ans, MaximumRectangleArea(m));
  }
 
  printf("%d\n", ans);
 
  return 0;
}