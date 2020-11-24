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

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define B 26

char s[N];
int C[B];

void ResetBag(){
  for(int i = 0; i < B; ++i){
    C[i] = 0;
  }
}

void AddToBag(int n, int val){
  for(int i = 0; i < n; ++i){
    int k = s[i] - 'a';
    C[k] += val;
  }
}

void ReadString(int n, int val){
  scanf("%s", s);
  AddToBag(n, val);
}

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  ResetBag();
  ReadString(n, -1);
  ReadString(n, 1);

  for(int k = 0, x = 0; k < B; ++k){
    x += C[k];
    if(x > 0 || x % m != 0){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}