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
#define N 1001

char s[N];

int main(){
  scanf("%s", s);

  const int n = strlen(s);
  vector<int> v;
  for(int i = 0, j = n - 1; i < j && i < n && j > -1; ++i, --j){
    if(s[i] != '('){
      ++j;
      continue;
    }

    if(s[j] != ')'){
      --i;
      continue;
    }

    v.push_back(i + 1);
    v.push_back(j + 1);
  }

  sort(v.begin(), v.end());

  if(v.empty()){
    printf("0\n");
    return 0;
  }

  printf("1\n%lu\n", v.size());
  for(int x : v){
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}