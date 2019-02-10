#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define LOGN 18

const int inf = 100000000;
vector< vector<int> > adj(N), v(N);
int timer, a[N], d[N], start[N], finish[N], invStart[N], L[LOGN][N], T[LOGN][N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  int ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Persistent Segment Tree -----------------------------------------//
node *root[N];

node* CreateNode(int leftEnd, int rightEnd, int count){
	node *temp = new node;

	temp->leftEnd = leftEnd;
	temp->rightEnd = rightEnd;
	temp->ans = count;

	return temp;
}

node* BuildSkeletonSegmentTree(int leftEnd, int rightEnd){
	node *temp = CreateNode(leftEnd, rightEnd, 0);

	if(leftEnd != rightEnd){
		int mid = (leftEnd + rightEnd) / 2;
		temp->leftChild = BuildSkeletonSegmentTree(leftEnd, mid);
		temp->rightChild = BuildSkeletonSegmentTree(mid + 1, rightEnd);
	}
	else
		temp->leftChild = temp->rightChild = NULL;

	return temp;
}

node* Insert(int i, node *parentNode){
	node *newNode;

	if(parentNode->leftEnd <= i && i <= parentNode->rightEnd){
		newNode = CreateNode(parentNode->leftEnd, parentNode->rightEnd, parentNode->ans);

		if(parentNode->leftEnd != parentNode->rightEnd){
			newNode->leftChild = Insert(i, parentNode->leftChild);
			newNode->rightChild = Insert(i, parentNode->rightChild);
		}
		else
			newNode->leftChild = newNode->rightChild = NULL;
	}
	else
		newNode = parentNode;

	return newNode;
}

void UpdateNode(node *currentNode, int i, int x){
	if(i < currentNode->leftEnd || currentNode->rightEnd < i){
		return;
	}
	else{
		if(i == currentNode->leftEnd && i == currentNode->rightEnd)
			currentNode->ans += x;
		else{
			UpdateNode(currentNode->leftChild, i, x);
			UpdateNode(currentNode->rightChild, i, x);
			currentNode->ans = (currentNode->leftChild)->ans + (currentNode->rightChild)->ans;
		}
	}
}

int Query(node *u, node *v, int l, int r){
	if(r < l || r < u->leftEnd || u->rightEnd < l)
		return 0;
	else{
    if(l <= u->leftEnd && u->rightEnd <= r){
      return v->ans - u->ans;
    }
    else{
      return Query(u->leftChild, v->leftChild, l, r) + Query(u->rightChild, v->rightChild, l, r);
    }
	}
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//

void BuildLCASparseTable(int n){
  for(int k = 1; k < LOGN; ++k)
    for(int i = 1; i <= n; ++i)
      L[k][i] = L[k - 1][L[k - 1][i]];
}

bool IsAncestor(int u, int v){
  return (start[u] <= start[v] && finish[v] <= finish[u]);
}

int KthAncestor(int i, int k){
  for(int j = LOGN - 1; k > 0 && j > -1; --j){
    if((1 << j) <= k){
      i = L[j][i];
      k -= (1 << j);
    }
  }
  return i;
}

int ChildWithNode(int i, int j){
  return KthAncestor(j, d[j] - d[i] - 1);
}

int LCA(int i, int j){
  if(d[i] > d[j]){
    swap(i, j);
  }

  j = KthAncestor(j, d[j] - d[i]);

  if(i == j)
    return i;
  else{
    for(int k = LOGN - 1; L[0][i] != L[0][j] && k > -1; k--){
      if(L[k][i] != L[k][j])
        i = L[k][i], j = L[k][j];
    }
    return L[0][i];
  }
}

void DFS(int i, int p = 0){
  d[i] = 1 + d[p];
  L[0][i] = p;
  start[i] = ++timer;
  invStart[start[i]] = i;

  for(auto k : adj[i])
    DFS(k, i);

  finish[i] = timer;
}

void OneBusDFS(int i, int p = 0){
  for(auto k : adj[i]){
    OneBusDFS(k, i);
    a[start[i]] = min(a[start[i]], a[start[k]]);
  }
  T[0][i] = invStart[a[start[i]]];
}

void PreProcess(int n){
  OneBusDFS(1);

  for(int k = 1; k < LOGN; ++k)
    for(int i = 1; i <= n; ++i)
      T[k][i] = T[k - 1][T[k - 1][i]];

  root[0] = BuildSkeletonSegmentTree(1, n);
  for(int i = 1; i <= n; ++i){
    root[i] = root[i - 1];
    for(auto x : v[i]){
      root[i] = Insert(x, root[i]);
      UpdateNode(root[i], x, 1);
    }
  }
}

void AddBus(int i, int j){
  if(start[i] > start[j]){
    swap(i, j);
  }

  int k = LCA(i, j);
  a[start[i]] = min(start[k], a[start[i]]);
  a[start[j]] = min(start[k], a[start[j]]);

  if(k != i){
    v[start[i]].PB(start[j]);
  }
}

int NumberOfBuses(int& i, int k){
  int ans = 0;

  for(int j = LOGN - 1; j > -1; --j){
    if(d[T[j][i]] > d[k]){
      i = T[j][i];
      ans += (1 << j);
    }
  }

  if(d[T[0][i]] <= d[k]){
    ++ans;
  }
  else
    ans = inf;

  return ans;
}

int Query(int i, int j){
  if(start[i] > start[j]){
    swap(i, j);
  }

  int ans = 0;
  if(IsAncestor(i, j)){
    ans = NumberOfBuses(j, i);
  }
  else{
    int k = LCA(i, j);
    ans = NumberOfBuses(i, k) + NumberOfBuses(j, k);
    ans -= (Query(root[start[i] - 1], root[finish[i]], start[j], finish[j]) > 0);
  }

  if(ans >= inf)
    ans = -1;

  return ans;
}

int main(){
  int n, m, q;

  scanf("%d", &n);
  for(int i = 2; i <= n; ++i){
    int p;
    scanf("%d", &p);
    adj[p].PB(i);
  }

  DFS(1);
  BuildLCASparseTable(n);

  for(int i = 1; i <= n; ++i)
    a[i] = i;

  scanf("%d", &m);
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    AddBus(i, j);
  }

  PreProcess(n);

  scanf("%d", &q);
  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d\n", Query(i, j));
  }

  return 0;
}
