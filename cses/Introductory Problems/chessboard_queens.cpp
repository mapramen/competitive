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
#define N 8

vector<set<int>> S(N);
int a[N];

void ReadInput(){
  for(int i = 0; i < N; ++i){
    for(int x = 0; x < N; ++x){
      S[i].insert(x);
    }

    string t;
    cin >> t;
    for(int j = 0; j < N; ++j){
      if(t[j] == '*'){
        S[i].erase(j);
      }
    }
  }
}

bool Check(int i){
  for(int j = 0; j < i; ++j){
    if(a[j] == a[i] || abs(i - j) == abs(a[i] - a[j])){
      return false;
    }
  }
  return true;
}

int DFS(int i){
  if(i == N){
    return 1;
  }

  int ans = 0;
  for(int x: S[i]){
    a[i] = x;
    if(Check(i)){
      ans += DFS(i + 1);
    }
  }

  return ans;
}

int main(){
  ReadInput();
  cout << DFS(0) << '\n';
  return 0;
}