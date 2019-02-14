#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define MOD 1000000007

typedef struct node
{
	int leftEnd;
	int rightEnd;
	int count;
	node* leftChild;
	node* rightChild;
}node;

int a[N];
ll fact[N], invfact[N];

ll ModExp(int a, int n){
	ll x = a, y = 1;

	while(n > 0){
		if(n % 2)
			y = (x * y) % MOD;

		x = (x * x) % MOD;
		n /= 2;
	}

	return y;
}

ll Inverse(int a){
	return ModExp(a, MOD - 2);
}

void PreCompute(){
	fact[0] = invfact[0] = 1;

	for(int i = 1; i < N; i++){
		fact[i] = (i * fact[i - 1]) % MOD;
		invfact[i] = (Inverse(i) * invfact[i - 1]) % MOD;
	}
}

ll nCr(int n, int r){
	return (fact[n] * ((invfact[r] * invfact[n - r]) % MOD)) % MOD;
}

//------------------- Coordinate Compress -------------------//
vector< int > compressedValues;

int CompressCoordinate(int a[], int n){
	vector<int> temp;

	for(int i = 1; i <= n; i++)
		temp.PB(a[i]);

	sort(temp.begin(), temp.end());

	compressedValues.PB(temp[0] - 1);
	compressedValues.PB(temp[0]);

	for(int i = 1; i < temp.size(); i++)
		if(temp[i] != temp[i - 1])
			compressedValues.PB(temp[i]);

	return compressedValues.size() - 1;
}

int GetCompressedValue(int a){
	int x = 0, y = compressedValues.size() - 1, z = 0, mid;

	while(x <= y){
		mid = x + (y - x) / 2;

		if(compressedValues[mid] <= a){
			z = mid;
			x = mid + 1;
		}
		else
			y = mid - 1;
	}

	return z;
}

int GetOriginalValue(int a){
	return compressedValues[a];
}
//----------------- Coordinate Compress Ends -----------------//

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

ll Query(node *u, node *v, int k){
	if(u->leftEnd == u->rightEnd){
		// printf("%d %d %d %d\n", u->leftEnd, u->rightEnd, u->count - v->count, k);
		return nCr(u->count - v->count, k);
	}
	else{
		int count = u->leftChild->count - v->leftChild->count;

		if(count >= k)
			return Query(u->leftChild, v->leftChild, k);
		else
			return Query(u->rightChild, v->rightChild, k - count);
	}
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//

int main(){
	int n, m, q, i, j, k, ans;

	PreCompute();

	scanf("%d%d", &n, &q);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	m = CompressCoordinate(a, n);

	root[0] = BuildSkeletonSegmentTree(1, m);

	for(i = 1; i <= n; i++){
		a[i] = GetCompressedValue(a[i]);
		root[i] = Insert(a[i], root[i - 1]);
		UpdateNode(root[i], a[i], 1);
	}

	while(q--){
		scanf("%d%d%d", &i, &j, &k);
		ans = Query(root[j], root[i - 1], k);
		printf("%d\n", ans);
	}

	return 0;
}
