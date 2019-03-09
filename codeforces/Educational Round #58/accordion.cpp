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
#define N 500001

char s[N];
int a[5];

int main(){
  scanf("%s", s);

  a[2] = INT_MIN;
  for(int i = 0; s[i] != '\0'; ++i){
    char c = s[i];

    if(c == '['){
      a[0] = 1;
    }
    else if(c == ':'){
      if(a[0]){
        a[1] = 2;
      }
      if(a[2] >= 0){
        a[3] = max(a[3], 1 + a[2]);
      }
    }
    else if(c == '|'){
      if(a[2]){
        ++a[2];
      }
      if(a[1]){
        a[2] = max(a[2], 1 + a[1]);
      }
    }
    else if(c == ']'){
      if(a[3] > 0){
        a[4] = max(a[4], 1 + a[3]);
      }
    }

    if(a[1]){
      a[2] = max(a[2], 2);
    }
  }

  int ans = a[4] > 0 ? a[4] : -1;

  printf("%d\n", ans);

  return 0;
}