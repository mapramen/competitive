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

char ch[2];

int main(){
  int q, a = 0, b = 0;
  scanf("%d", &q);
  while(q--){
    int x, y;
    scanf("%s%d%d", ch, &x, &y);
    if(x > y){
      swap(x, y);
    }
    if(ch[0] == '+'){
      a = max(a, x);
      b = max(b, y);
    }
    else{
      if(a <= x && b <= y){
        printf("YES\n");
      }
      else{
        printf("NO\n");
      }
    }
  }
  return 0;
}