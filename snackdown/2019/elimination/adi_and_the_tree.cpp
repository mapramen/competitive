#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 250001

typedef struct node
{
	int leftEnd;
	int rightEnd;
  int lazyValue;
	int ans;
	node* leftChild;
	node* rightChild;
}node;

vector< vector<int> > adj(N);
int parent[N], subtreeSize[N];

//------------------------------------------------ HLD ------------------------------------------------//
int totalChains = 1, chainSize[N], chainHead[N], chainNo[N], chainPosition[N];
node *root[N];

void HLD(int i){ //initialize first vertex with chainNo[i] = chainPosition[i] = 1, chainHead[1] = i;
	chainSize[chainNo[i]]++;
	int heavyChild = 0;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(parent[k] == i && subtreeSize[k] > subtreeSize[heavyChild])
			heavyChild = k;
	}

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(parent[k] == i){
			if(k == heavyChild){
				chainNo[k] = chainNo[i];
				chainPosition[k] = chainPosition[i] + 1;
			}
			else{
				chainNo[k] = ++totalChains;
				chainPosition[k] = 1;
				chainHead[totalChains] = k;
			}
			HLD(k);
		}
	}
}

node* CreateNode(int leftEnd, int rightEnd, int ans){
	node *temp = new node;

	temp->leftEnd = leftEnd;
	temp->rightEnd = rightEnd;
  temp->lazyValue = 0;
	temp->ans = ans;

	return temp;
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
	node *temp = CreateNode(leftEnd, rightEnd, 0);

	if(leftEnd != rightEnd){
		int mid = (leftEnd + rightEnd) / 2;
		temp->leftChild = BuildSegmentTree(leftEnd, mid);
		temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
	}
	else
		temp->leftChild = temp->rightChild = NULL;

	return temp;
}

void TraverseSegmentTree(node* root){
	if(root != NULL){
		TraverseSegmentTree(root->leftChild);
		TraverseSegmentTree(root->rightChild);
		printf("%d %d\n", root->leftEnd, root->rightEnd);
	}
}

void FlipNodeData(node *currentNode){
  currentNode->lazyValue ^= 1;
  currentNode->ans = (currentNode->rightEnd - currentNode->leftEnd + 1) - currentNode->ans;
}

int UpdateNode(node *currentNode, int l, int r){
	if(r < currentNode->leftEnd || currentNode->rightEnd < l){
		return 0;
	}
	else{
		if(l <= currentNode->leftEnd && currentNode->rightEnd <= r){
      int ans = currentNode->ans;
      FlipNodeData(currentNode);
      return currentNode->ans - ans;
    }
		else{
      if(currentNode->lazyValue){
        FlipNodeData(currentNode->leftChild);
        FlipNodeData(currentNode->rightChild);
        currentNode->lazyValue = 0;
      }
			int ans = UpdateNode(currentNode->leftChild, l, r) + UpdateNode(currentNode->rightChild, l, r);
      currentNode->ans = currentNode->leftChild->ans + currentNode->rightChild->ans;
      return ans;
		}
	}
}

void BuildSegmentTrees(int n){
  chainNo[1] = chainPosition[1] = 1;
  chainHead[1] = 1;
  HLD(1);

	for(int chain = 1; chain <= totalChains; chain++)
		root[chain] = BuildSegmentTree(1, chainSize[chain]);
}
//----------------------------------------------- HLD Ends -----------------------------------------------//

void DFS(int i){
  for(auto k : adj[i]){
    if(k == parent[i]){
      continue;
    }
    parent[k] = i;
    DFS(k);
    subtreeSize[i] += subtreeSize[k];
  }
	++subtreeSize[i];
}

int Query(int v, int u = 1){
	int ans = 0;

	while(chainNo[v] != chainNo[u]){
		ans += UpdateNode(root[chainNo[v]], 1, chainPosition[v]);
		v = parent[chainHead[chainNo[v]]];
	}

	if(u != v)
		ans += UpdateNode(root[chainNo[u]], chainPosition[u] + 1, chainPosition[v]);

	return ans;
}

int main(){
  int n, q;

  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1);
  BuildSegmentTrees(n);

  scanf("%d", &q);

  ll ans = 0;
  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    ans += (Query(i) + Query(j));
    printf("%lld\n", ans);
  }

  return 0;
}
