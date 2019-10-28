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
#define N 6

vector<int> v{4, 8, 15, 16, 23, 42};
int a[N + 1], ans[N + 1];

int Query(int i, int j){
  printf("? %d %d\n", i, j);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}

void Fill(int s){
  for(int i = s; i <= s + 1; ++i){
    a[i] = Query(i, i + 1);
  }

  for(int i : v){
    for(int j : v){
      for(int k : v){
        if(i == j || j == k || i == k){
          continue;
        }
        if(i * j == a[s] && j * k == a[s + 1]){
          ans[s] = i, ans[s + 1] = j, ans[s + 2] = k;
          return ;
        }
      }
    }
  }
}

void PrintAns(){
  printf("! ");
  for(int i = 1; i <= N; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");
  fflush(stdout);
}

int main(){
  Fill(1);
  Fill(N / 2 + 1);

  PrintAns();

  return 0;
}