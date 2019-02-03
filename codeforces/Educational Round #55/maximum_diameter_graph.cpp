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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501

vector< vector<int> > adj(N);
int m, diameter, maxDegree[N];
queue<int> leaves, nonLeaves;

void AddEdge(int i, int j){
	adj[i].push_back(j);
	adj[j].push_back(i);
	++m;
}

void PreProcessNonLeaves(){
	if(nonLeaves.empty()){
		return;
	}
	
	vector<int> v;
	while(true){
		if(v.size()){
			AddEdge(v.back(), nonLeaves.front());
			++diameter;
		}
		if(v.size() != nonLeaves.size() - 1){
			v.push_back(nonLeaves.front());
			nonLeaves.push(nonLeaves.front());
			nonLeaves.pop();
		}
		else{
			break;
		}
	}
}

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> maxDegree[i];
    if(maxDegree[i] == 1){
      leaves.push(i);
    }
    else{
      nonLeaves.push(i);
    }
  }

  PreProcessNonLeaves();

  diameter += min(2, (int)leaves.size());

  while(leaves.size() > 0 && !nonLeaves.empty()){
    int i = nonLeaves.front();
    nonLeaves.pop();
    if(adj[i].size() == maxDegree[i]){
      continue;
    }
    int j = leaves.front();
    leaves.pop();
    AddEdge(i, j);
    nonLeaves.push(i);
  }

  if(leaves.size()){
    printf("NO\n");
    return 0;
  }

  printf("YES %d\n%d\n", diameter, m);

  for(int i = 1; i <= n; ++i){
    for(auto j : adj[i]){
      if(j < i){
        printf("%d %d\n", j, i);
      }
    }
  }
    
  return 0;
}