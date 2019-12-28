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

bool FindAndPrintAns(string s, int c){
  vector<int> a, ans;

  for(char x : s){
    a.push_back(x == 'B');
  }

  for(int i = 0; i + 1 < a.size(); ++i){
    if(a[i] != c){
      a[i] ^= 1;
      a[i + 1] ^= 1;
      ans.push_back(i + 1);
    }
  }

  if(a.back() != c){
    return false;
  }

  printf("%lu\n", ans.size());
  for(int x : ans){
    printf("%d ", x);
  }
  printf("\n");

  return true;
}

int main(){
  int n;
  string s;

  cin >> n >> s;

  if(!FindAndPrintAns(s, 1) && !FindAndPrintAns(s, 0)){
    printf("-1\n");
  }

  return 0;
}