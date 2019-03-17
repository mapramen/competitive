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

char ch[2], s[10];

bool Query(int x, int y){
  printf("? %d %d\n", x, y);
  fflush(stdout);
  scanf("%s", ch);
  return ch[0] == 'y';
}

void PrintAns(int x){
  printf("! %d\n", x);
  fflush(stdout);
}

int main(){
  while(true){
    scanf("%s", s);
    if(s[0] == 'e'){
      break;
    }

    int x = 1, y = 2;
    while(Query(x, y)){
      x *= 2, y *= 2;
    }

    if(x == 1){
      if(!Query(0, 1)){
        PrintAns(1);
      }
      else{
        PrintAns(2);
      }
      continue;
    }

    if(!Query(0, y)){
      PrintAns(y);
      continue;
    }

    int l = x + 1, r = y - 1, ans;
    while(l <= r){
      int mid = l + (r - l) / 2;
      if(Query(mid, x)){
        ans = mid, r = mid - 1;
      }
      else{
        l = mid + 1;
      }
    }

    PrintAns(ans);
  }

  return 0;
}