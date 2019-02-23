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
#define B 26
#define N 1000001

int n, m, c[B], invC[B];
char s[N], a[N], b[N];

bool Search(int i = 0, bool isBigger = false, bool isSmaller = false){
  if(i == n || (isBigger && isSmaller)){
    return true;
  }

  int k = s[i] - 'a', x = a[i] - 'a', y = b[i] - 'a';
  int l = c[k] < 0 ? (isBigger ? 0 : x) : c[k];
  int r = c[k] < 0 ? (isSmaller ? m - 1 : y) : c[k];
  int z = c[k];

  for(int j = l; j <= r; ++j){
    if(invC[j] != -1 && invC[j] != k){
      continue;
    }

    c[k] = j;
    invC[j] = k;
    
    if(!isBigger && j < x){
      continue;
    }
    
    if(!isSmaller && y < j){
      continue;
    }
    
    if(Search(i + 1, isBigger || (x < j), isSmaller || (j < y))){
      return true;
    }

    invC[j] = -1;
  }

  c[k] = z;
  if(c[k] >= 0){
    invC[z] = k;
  }

  return false;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d%s%s%s", &m, s, a, b);
    n = strlen(s);
    for(int i = 0; i < m; ++i){
      c[i] = -1, invC[i] = -1;
    }
    if(!Search()){
      printf("NO\n");
    }
    else{
      printf("YES\n");
      
      vector<int> v;
      
      for(int i = 0; i < m; ++i){
        if(invC[i] < 0){
          v.push_back(i);
        }
      }
      
      for(int i = 0; i < m; ++i){
        if(c[i] < 0){
          c[i] = v.back();
          v.pop_back();
        }
      }

      for(int i = 0; i < m; ++i){
        printf("%c", 'a' + c[i]);
      }
      printf("\n");
    }
  }
  return 0;
}