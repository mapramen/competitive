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

#define pii pair< int, int>
#define pll pair< ll, ll>
#define N 100001

vector< vector<int> > adj(N);
bool visited[N];
priority_queue< int, vector<int>, greater<int> > Q;

int main(){
  int n, m;
  vector<int> ans;

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  Q.push(1);
  visited[1] = true;

  while(!Q.empty()){
    int i = Q.top();
    Q.pop();

    ans.push_back(i);

    for(int j : adj[i]){
      if(visited[j]){
        continue;
      }
      Q.push(j);
      visited[j] = true;
    }
  }

  for(int i : ans){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}