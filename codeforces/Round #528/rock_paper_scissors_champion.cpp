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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define B 3

int n, T[B][N];
set<int> M[B];
char s[N], ch[B];

void Update(int T[], int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int T[], int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int Query(int T[], int i, int j){
  return i <= j ? Query(T, j) - Query(T, i - 1) : 0;
}

int GetMapping(char c){
  if(c == 'R'){
    return 0;
  }
  else if(c == 'P'){
    return 1;
  }
  else{
    return 2;
  }
}

void Add(int i, char c){
  s[i - 1] = c;
  int j = GetMapping(c);
  M[j].insert(i);
  Update(T[j], i, 1);
}

void Remove(int i){
  int j = GetMapping(s[i - 1]);
  M[j].erase(i);
  Update(T[j], i, -1);
}

void Update(int i, char c){
  Remove(i);
  Add(i, c);
}

int Query(int i){
  int j = (i + B - 1) % B, k = (i + 1) % B;

  if(M[k].empty()){
    return 0;
  }

  if(M[j].empty()){
    return (int)M[i].size();
  }

  int x1 = *M[k].begin(), y1 = *M[j].begin();
  int x2 = *M[k].rbegin(), y2 = *M[j].rbegin();

  int ans = Query(T[i], x1, y1) + Query(T[i], y2, x2);

  return ans;
}

int Query(){
  int ans = 0;
  for(int i = 0; i < B; ++i){
    ans += Query(i);
  }
  return ans;
}

void PrintAns(){
  printf("%d\n", n - Query());
}

void PreProcess(){
  for(int i = 1; i <= n; ++i){
    Add(i, s[i - 1]);
  }
  PrintAns();
}

int main(){
  int q;

  scanf("%d%d%s", &n, &q, s);
  PreProcess();

  while(q--){
    int i;
    scanf("%d%s", &i, ch);
    Update(i, ch[0]);
    PrintAns();
  }

  return 0;
}