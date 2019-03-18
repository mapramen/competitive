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
  int n;
  stack<int> S;

  scanf("%d", &n);

  while(n--){
    int x;
    scanf("%d", &x);
    x %= 2;
    if(S.empty() || S.top() != x){
      S.push(x);
    }
    else{
      S.pop();
    }
  }

  printf("%s\n", S.size() < 2 ? "YES" : "NO");

  return 0;
}