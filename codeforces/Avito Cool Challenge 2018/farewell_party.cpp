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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > c(N);
int ans[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int j;
    scanf("%d", &j);
    c[j].push_back(i);
  }

  int x = 1;
  for(int i = 0; i < n; ++i){
    if(c[i].size() == 0){
      continue;
    }

    int m = i + c[i].size() - n, g = n - i;
    if(m < 0 || m % g != 0 || m + g != c[i].size()){
      printf("Impossible\n");
      return 0;
    }
    
    for(int j = 0; j < c[i].size(); ++x){
      for(int k = 0; k < g; ++k, ++j){
        ans[c[i][j]] = x;
      }
    }
  }

  printf("Possible\n");
  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}