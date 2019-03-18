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

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  vector<int> v;
  for(int x = 1, m = n; m ; m /= 2, x *= 2){
    if(m % 2){
      v.push_back(x);
    }
  }

  if(k < v.size() || k > n){
    printf("NO\n");
    return 0;
  }

  vector<int> ans;
  sort(v.begin(), v.end(), greater<int>());

  while(v.size() + ans.size() < k){
    int x = v.back();
    v.pop_back();

    if(x == 1){
      ans.push_back(1);
    }
    else{
      v.push_back(x / 2);
      v.push_back(x / 2);
    }
  }

  while(!v.empty()){
    ans.push_back(v.back());
    v.pop_back();
  }

  printf("YES\n");
  for(int i : ans){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}