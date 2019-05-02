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

int Query(vector<int> v){
  printf("next ");
  for(int i : v){
    printf("%d ", i);
  }
  printf("\n");
  fflush(stdout);
  int s;
  scanf("%d", &s);
  for(int i = 0; i < s; ++i){
    ll x;
    scanf("%lld", &x);
  }
  return s;
}

int main(){
  for(Query(vector<int>{0, 1}); Query(vector<int>{1}) > 2; Query(vector<int>{0, 1}));
  while(Query(vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) > 1);
  printf("done\n");
  fflush(stdout);
  return 0;
}