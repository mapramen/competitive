#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< pii, int >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

typedef struct node
{
	int leftEnd;
	int rightEnd;
	int ans;
	node* leftChild;
	node* rightChild;
}node;

int a[2*N];
piii queries[N];

//------------------- Coordinate Compress -------------------//
vector< int > compressedValues;

int CompressCoordinate(int a[], int n){
	vector<int> temp;

	for(int i = 1; i <= n; i++)
		temp.PB(a[i]);

	sort(temp.begin(), temp.end());

	compressedValues.PB(0);
	compressedValues.PB(temp[0]);

	for(int i = 1; i < temp.size(); i++)
		if(temp[i] != temp[i - 1])
			compressedValues.PB(temp[i]);

	return compressedValues.size() - 1;
}

int GetCompressedValue(int a){
	return lower_bound(compressedValues.begin(), compressedValues.end(), a) - compressedValues.begin();
}

int GetOriginalValue(int a){
	return compressedValues[a];
}
//----------------- Coordinate Compress Ends -----------------//

//-------------------------------------- Segment Tree --------------------------------------//
node* CreateNode(int leftEnd, int rightEnd, int ans){
	node *temp = new node;
	
	temp->leftEnd = leftEnd;
	temp->rightEnd = rightEnd;
	temp->ans = ans;

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

void UpdateNode(node *currentNode, int l, int r, int x){
	if(r < currentNode->leftEnd || currentNode->rightEnd < l){
		return;
	}
	else{
		l = max(l, currentNode->leftEnd);
		r = min(r, currentNode->rightEnd);

		if(l == currentNode->leftEnd && r == currentNode->rightEnd)
			currentNode->ans = max(x, currentNode->ans);
		else{
			UpdateNode(currentNode->leftChild, l, r, x);
			UpdateNode(currentNode->rightChild, l, r, x);
		}
	}
}

int QueryNode(node *currentNode, int l, int r, int x){
	if(r < currentNode->leftEnd || currentNode->rightEnd < l){
		currentNode->ans = max(currentNode->ans, x);
		return 0;
	}
	else{
		l = max(l, currentNode->leftEnd);
		r = min(r, currentNode->rightEnd);

		if(l == currentNode->leftEnd && r == currentNode->rightEnd)
			return currentNode->ans = max(x, currentNode->ans);
		else
			return max(QueryNode(currentNode->leftChild, l, r, max(x, currentNode->ans)), QueryNode(currentNode->rightChild, l, r, max(x, currentNode->ans)));
	}
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
	int n, m, q, i, j, k, x, y, z, t, x1, y1, x2, y2, ans;
	set<int> b;
	char s[2];
	node *root1, *root2;

	scanf("%d%d", &n, &q);

	for(i = 1, j = 1; i <= q; i++){
		scanf("%d%d", &queries[i].first.first, &queries[i].first.second);
		scanf("%s", s);
		queries[i].second = (s[0] == 'U');
		a[j++] = queries[i].first.first;
		a[j++] = queries[i].first.second;
	}

	a[j] = n + 1;

	m = CompressCoordinate(a, 2*q + 1);

	root1 = BuildSkeletonSegmentTree(0, m);
	root2 = BuildSkeletonSegmentTree(0, m);

	for(x = 1; x <= q; x++){
		i = GetCompressedValue(queries[x].first.first);
		j = GetCompressedValue(queries[x].first.second);
		t = queries[x].second;

		if(t == 1){
			k = QueryNode(root1, j, j, 0);
			x1 = GetCompressedValue(n + 1 - GetOriginalValue(j));
			x2 = GetCompressedValue(n + 1 - GetOriginalValue(k));
			UpdateNode(root2, x1, x2, i);
			ans = GetOriginalValue(j) - GetOriginalValue(k);
		}
		else{
			k = QueryNode(root2, i, i, 0);
			y1 = GetCompressedValue(n + 1 - GetOriginalValue(i));
			y2 = GetCompressedValue(n + 1 - GetOriginalValue(k));
			UpdateNode(root1, y1, y2, j);
			ans = GetOriginalValue(i) - GetOriginalValue(k);
		}

		if(b.find(i) != b.end())
			ans = 0;
		else
			b.insert(i);

		printf("%d\n", ans);
	}

	return 0;
}
