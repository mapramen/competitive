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

#define pii pair< int, int >
#define pll pair< ll, ll >

int c[3];
vector<int> v;

bool PushToAns(int i){
  if(c[i] <= 0){
    return false;
  }
  v.push_back(i);
  --c[i];
  return true;
}

int main(){
  int n;

  scanf("%d", &n);
  while(n--){
    int x;
    scanf("%d", &x);
    ++c[x];
  }

  PushToAns(2);
  PushToAns(1);

  while(PushToAns(2));
  while(PushToAns(1));

  for(int x : v){
    printf("%d ", x);
  }
  printf("\n");
  
  return 0;
}