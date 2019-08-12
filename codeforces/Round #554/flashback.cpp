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
#include <list>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 100001

vector< vector<int> > edgeNos(N);
int b[N], c[N], edgeXORs[N];
bool isEdgeVisited[N];
vector<int> C;

void ReadInputArray(int n, int a[]){
	for(int i = 1; i < n; ++i){
		scanf("%d", &a[i]);
		C.push_back(a[i]);
	}
}

int inline GetCompressedValue(int x){
	return lower_bound(C.begin(), C.end(), x) - C.begin();
}

bool FormGraph(int n){
	for(int x = 1; x < n; ++x){
		if(b[x] > c[x]){
			return false;
		}

		int i = GetCompressedValue(b[x]), j = GetCompressedValue(c[x]);
		edgeNos[i].push_back(x);
		edgeNos[j].push_back(x);
		edgeXORs[x] = (i ^ j);

		printf("Added Edge edgeNo = %d i = %d j = %d edgeXor = %d\n", x, i, j, edgeXORs[x]);
	}
	return true;
}

int GetEulerPathStart(){
	int oddDegreeCount = 0, oddDegreeVertex;
	
	for(int i = 0; i < C.size() && oddDegreeCount < 3; ++i){
		if(edgeNos[i].size() % 2){
			++oddDegreeCount, oddDegreeVertex = i;
		}
	}

	if(oddDegreeCount > 2){
		return -1;
	}

	return oddDegreeCount ? oddDegreeVertex : 0;
}

list<int> EulerDFS(int i){
	list<int> path;
	// printf("EulerDFS %d\n", i);
	while(!edgeNos[i].empty()){
		int edgeNo = edgeNos[i].back();
		edgeNos[i].pop_back();

		if(isEdgeVisited[edgeNo]){
			continue;
		}

		isEdgeVisited[edgeNo] = true;
		int j = (edgeXORs[edgeNo] ^ i);

		path.push_back(edgeNo);
		auto pathx = EulerDFS(j);
		path.splice(path.end(), pathx);

		printf("i = %d j = %d edgeNo = %d\n", C[i], C[j], edgeNo);
	}

	return path;
}

int main(){
  int n;
  scanf("%d", &n);

  ReadInputArray(n, b);
	ReadInputArray(n, c);

	sort(C.begin(), C.end());
	C.erase(unique(C.begin(), C.end()), C.end());

	if(C.size() > n){
		printf("-1\n");
		return 0;
	}

	if(!FormGraph(n)){
		printf("-1\n");
		return 0;
	}

	int startVertex = GetEulerPathStart();

	if(startVertex < 0){
		printf("-1\n");
		return 0;
	}

	auto eulerPath = EulerDFS(startVertex);

	if(eulerPath.size() != n - 1){
		printf("-1\n");
		return 0;
	}

	int i = startVertex;
	// printf("%d ",C[i]);
	for(auto it = eulerPath.begin(); it != eulerPath.end(); ++it){
		i = (edgeXORs[*it] ^ i);
		printf("edgeNo = %d edgeXor = %d i = %d j = %d\n", *it, edgeXORs[*it], edgeXORs[*it] ^ i, i);
		// printf("%d ", C[i]);
	}
	printf("\n");

  return 0;
}