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
#define N 100001
#define M N

int A[N], B[N], C[N], cnt;

ll TakeInput(int A[]){
  ll ans = 0;
  string s;
  cin >> s;
  for(int i = 1, j = 1; i <= s.size(); ++i, j = -j){
    A[i] = s[i - 1] - '0';
    ans += j * A[i];
  }
  return ans;
}

void PrintOperation(int i, int x){
  if(cnt >= M){
    return ;
  }

  if((x == 1 && A[i + 1] == 9) || (x == -1 && A[i + 1] == 0)){
    PrintOperation(i + 1, -x);
    PrintOperation(i, x);
    return ;
  }

  if(++cnt >= M){
    return ;
  }

  A[i] += x, A[i + 1] += x;
  printf("%d %d\n", i, x);
}

int main(){
  int n;

  cin >> n;
  
  if(TakeInput(A) != TakeInput(B)){
    printf("-1\n");
    return 0;
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    C[i] += A[i];
    int x = B[i] - C[i];
    ans += abs(x);
    if(i < n){
      C[i + 1] += x;
    }
  }

  printf("%lld\n", ans);
  for(int i = 1; i < n && cnt < M; ){
    if(A[i] == B[i]){
      ++i;
      continue;
    }

    if(A[i] < B[i]){
      PrintOperation(i, 1);
    }
    else{
      PrintOperation(i, -1);
    }
  }

  return 0;
}