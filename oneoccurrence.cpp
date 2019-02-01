#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001

int a[N], b[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  pii ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Persistent Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
	node *temp = new node;

	temp->leftEnd = leftEnd;
	temp->rightEnd = rightEnd;

	return temp;
}

node* BuildSkeletonSegmentTree(int leftEnd, int rightEnd){
	node *temp = CreateNode(leftEnd, rightEnd);
  temp->ans = MP(N, 0);

	if(leftEnd != rightEnd){
		int mid = (leftEnd + rightEnd) / 2;
		temp->leftChild = BuildSkeletonSegmentTree(leftEnd, mid);
		temp->rightChild = BuildSkeletonSegmentTree(mid + 1, rightEnd);
	}
	else{
    temp->leftChild = temp->rightChild = NULL;
  }

	return temp;
}

node* Insert(node *parentNode, int i, int x, int v){
	node *newNode;

	if(parentNode->leftEnd <= i && i <= parentNode->rightEnd){
		newNode = CreateNode(parentNode->leftEnd, parentNode->rightEnd);

		if(parentNode->leftEnd != parentNode->rightEnd){
			newNode->leftChild = Insert(parentNode->leftChild, i, x, v);
			newNode->rightChild = Insert(parentNode->rightChild, i, x, v);
      newNode->ans = min(newNode->leftChild->ans, newNode->rightChild->ans);
		}
		else{
      newNode->ans = MP(x, v);
      newNode->leftChild = newNode->rightChild = NULL;
    }
	}
	else
		newNode = parentNode;

	return newNode;
}

pii Query(node *currentNode, int l, int r){
	if(r < currentNode->leftEnd || currentNode->rightEnd < l){
    return MP(N, 0);
  }
  else{
    if(l <= currentNode->leftEnd && currentNode->rightEnd <= r){
      return currentNode->ans;
    }
    else{
      return min(Query(currentNode->leftChild, l, r), Query(currentNode->rightChild, l, r));
    }
  }
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//

node *root[N];

void PreProcess(int n){
  root[0] = BuildSkeletonSegmentTree(1, n);

  for(int i = 1; i <= n; ++i){
    root[i] = root[i - 1];
    int v = a[i];
    root[i] = Insert(root[i], b[v], N, v);
    root[i] = Insert(root[i], i, b[v], v);
    b[v] = i;
  }
}

int main(){
  int n, q;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess(n);

  scanf("%d", &q);
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    pii ansp = Query(root[r], l, r);
    int ans = ansp.first < l ? ansp.second : 0;
    printf("%d\n", ans);
  }

  return 0;
}
