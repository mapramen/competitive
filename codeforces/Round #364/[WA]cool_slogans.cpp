#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< pii, int >
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define PB push_back
#define MP make_pair
#define N 200001
#define LOGN 19

typedef struct node
{
	int leftEnd;
	int rightEnd;
	int ans;
	node* leftChild;
	node* rightChild;
}node;

char s[N];
int M;
pii a[N];

//-------------------------------------------- Suffix Array --------------------------------------------//
int SATable[LOGN][2*N], SArray[N], SAPosition[N], lcp[N];
piii L[N];

void BuildSuffixArray(int n){
	char c = 'z';
	M = 0;

	for(int i = 1; i < n; M++, i = (i << 1));

	for(int i = 1; i <= n; i++)
		c = min(c, s[i - 1]);

	c--;

	for(int i = 1; i <= n; i++)
		SATable[0][i] = s[i - 1] - c;

	for(int k = 1; k <= M; k++){
		for(int i = 1; i <= n; i++)
			L[i].first.first = SATable[k - 1][i], L[i].first.second = SATable[k - 1][i + (1 << (k - 1))], L[i].second = i;

		sort(L + 1, L + n + 1);

		for(int i = 1; i <= n; i++)
			SATable[k][L[i].second] = L[i].first == L[i - 1].first ? SATable[k][L[i - 1].second] : i;
	}

	for(int i = 1; i <= n; i++)
		SArray[SATable[M][i]] = i, SAPosition[i] = SATable[M][i];
}

int LCP(int i, int j, int n){
	int ans = 0, k;

	if(i == j)
		return n - i + 1;
	else
		for(k = M; k >= 0 && i <= n && j <= n; k--)
			if(SATable[k][i] == SATable[k][j])
				ans += (1 << k), i += (1 << k), j += (1 << k);

	return ans;
}
//-------------------------------------------- Suffix Array Ends --------------------------------------------//

node* CreateNode(int leftEnd, int rightEnd, int ans){
	node *temp = new node;
	
	temp->leftEnd = leftEnd;
	temp->rightEnd = rightEnd;
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
		printf("%d %d %d\n", root->leftEnd, root->rightEnd, root->ans);
	}
}

void UpdateNode(node *currentNode, int l, int r, int x){
	if(r < currentNode->leftEnd || currentNode->rightEnd < l)
		return ;
	else{
		l = max(l, currentNode->leftEnd);
		r = min(r, currentNode->rightEnd);

		if(l == currentNode->leftEnd && r == currentNode->rightEnd)
			currentNode->ans = max(currentNode->ans, x);
		else{
			currentNode->leftChild->ans = max(currentNode->leftChild->ans, currentNode->ans);
			currentNode->rightChild->ans = max(currentNode->rightChild->ans, currentNode->ans);

			UpdateNode(currentNode->leftChild, l, r, x);
			UpdateNode(currentNode->rightChild, l, r, x);
			currentNode->ans = max(currentNode->leftChild->ans, currentNode->rightChild->ans);
		}
	}
}

int QueryNode(node *currentNode, int i){
	if(i < currentNode->leftEnd || currentNode->rightEnd < i)
		return 0;
	else{
		if(i == currentNode->leftEnd && i == currentNode->rightEnd)
			return currentNode->ans;
		else{
			currentNode->leftChild->ans = max(currentNode->leftChild->ans, currentNode->ans);
			currentNode->rightChild->ans = max(currentNode->rightChild->ans, currentNode->ans);
			return max(QueryNode(currentNode->leftChild, i), QueryNode(currentNode->rightChild, i));
		}
	}
}

int main(){
	int n, i, j, k, x, y, ans = 0, ansx;
	node *root;

	scanf("%d", &n);
	scanf("%s", s);

	BuildSuffixArray(n);
	root = BuildSegmentTree(1,n);

	for(i = 1; i <= n; i++)
		printf("%d %d %s\n", i, SArray[i], s + SArray[i] - 1);

	for(i = 1; i <= n; i++)
		a[i] = MP(1, i);

	for(i = 1; i < n; i++){
		x = SArray[i], y = SArray[i + 1];

		if(x > y)
			swap(x, y);

		k = LCP(x, y, n);
		a[x] = max(a[x], MP(k, y));
	}

	for(i = 1; i <= n; i++){
		ansx = 1 + QueryNode(root, i);

		int l = a[i].second, r = a[i].second + a[i].first - 1;
		UpdateNode(root, l, r, ansx);

		ans = max(ans, ansx);
		printf("%d %d %d %d %d\n", i, l, r, ansx, ans);
	}

	printf("%d\n", ans);
}