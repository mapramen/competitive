#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

typedef struct node
{
	int leftEnd;
	int rightEnd;
	int count;
	node* leftChild;
	node* rightChild;
}node;

vector< vector<int> > v(N);
int a[N];

//----------------------------------------- Persistent Segment Tree -----------------------------------------//
node *root[N];

node* CreateNode(int leftEnd, int rightEnd, int count){
	node *temp = new node;

	temp->leftEnd = leftEnd;
	temp->rightEnd = rightEnd;
	temp->count = count;

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

void TraverseSegmentTree(node* root){
	if(root != NULL){
		TraverseSegmentTree(root->leftChild);
		TraverseSegmentTree(root->rightChild);
		printf("%d %d\n", root->leftEnd, root->rightEnd);
	}
}

node* Insert(int i, node *parentNode){
	node *newNode;

	if(parentNode->leftEnd <= i && i <= parentNode->rightEnd){
		newNode = CreateNode(parentNode->leftEnd, parentNode->rightEnd, parentNode->count);

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
			currentNode->count += x;
		else{
			UpdateNode(currentNode->leftChild, i, x);
			UpdateNode(currentNode->rightChild, i, x);
			currentNode->count = (currentNode->leftChild)->count + (currentNode->rightChild)->count;
		}
	}
}

int Query(node *u, node *v, int k){
	if(k <= v->leftEnd)
		return 0;
	else{
		if(v->rightEnd < k){
			return v->count - u->count;
		}
		else{
			return Query(u->leftChild, v->leftChild, k) + Query(u->rightChild, v->rightChild, k);
		}
	}
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//

void PreProcess(int n, int k){
	for(int i = 1; i <= n; i++)
		v[a[i]].PB(i);

	for(int i = 1; i <= n; i++)
		a[i] = 0;

	for(int x = 1; x < N; x++){
		if(v[x].size() <= k)
			continue;

		for(int i = k; i < v[x].size(); i++)
			a[v[x][i]] = v[x][i - k];
	}

	root[0] = BuildSkeletonSegmentTree(0, n);

	for(int i = 1; i <= n; i++){
		root[i] = Insert(a[i], root[i - 1]);
		UpdateNode(root[i], a[i], 1);
	}
}

int main(){
	int n, k, q, ans = 0;

	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	PreProcess(n, k);

	scanf("%d", &q);
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		l = (l + ans) % n + 1;
		r = (r + ans) % n + 1;

		if(l > r)
			swap(l, r);

		ans = Query(root[l - 1], root[r], l);

		printf("%d\n", ans);
	}

	return 0;
}
