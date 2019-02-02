#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1002

typedef struct node{
	int data;
	node* down;
	node* right;
}node;

node T[N][N];

node* GetHeadToCell(int n, int m){
	node *temp = &T[0][0];

	if(m == 0){
		for(int i = 0; i < n - 1; i++)
			temp = temp->down;
		return temp->down;
	}

	if(n == 0){
		for(int j = 0; j < m - 1; j++)
			temp = temp->right;
		return temp->right;
	}

	for(int i = 0; i < n - 1; i++)
		temp = temp->down;

	for(int j = 0; j < m - 1; j++)
		temp = temp->right;

	return temp->right->down;
}

void StitchDownBorder(node *mat1, node *mat2, int w){
	for(int j = 0; j < w; j++, mat1 = mat1->right, mat2 = mat2->right)
		mat1->down = mat2;
}

void StitchRightBorder(node *mat1, node *mat2, int h){
	for(int i = 0; i < h; i++, mat1 = mat1->down, mat2 = mat2->down)
		mat1->right = mat2;
}

void PrintMatrix(int n, int m){
	node *mat = T[0][0].right->down;

	for(int i = 1; i <= n; i++){
		node *curCell = mat;
		for(int j = 1; j <= m; j++){
			printf("%d ", curCell->data);
			curCell = curCell->right;
		}
		printf("\n");
		mat = mat->down;
	}
}

int main(){
	int n, m, q, i, j, k, a, b, c, d, h, w, x, y, z;
	node *submat[9], *mat[9];

	scanf("%d%d%d", &n, &m, &q);

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			scanf("%d", &T[i][j].data);

	for(i = 0; i <= n + 1; i++){
		for(j = 0; j <= m + 1; j++){
			if(i != n + 1)
				T[i][j].down = &T[i + 1][j];

			if(j != m + 1)
				T[i][j].right = &T[i][j + 1];
		}
	}

	k = 1;

	while(q--){
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &h, &w);

		submat[1] = GetHeadToCell(a, b);
		submat[2] = GetHeadToCell(a, b + w - 1);
		submat[3] = GetHeadToCell(a + h - 1, b);
		submat[4] = GetHeadToCell(a, b);
		submat[5] = GetHeadToCell(c, d);
		submat[6] = GetHeadToCell(c, d + w - 1);
		submat[7] = GetHeadToCell(c + h - 1, d);
		submat[8] = GetHeadToCell(c, d);

		mat[1] = GetHeadToCell(a - 1, b);
		mat[2] = GetHeadToCell(a, b + w);
		mat[3] = GetHeadToCell(a + h, b);
		mat[4] = GetHeadToCell(a, b - 1);
		mat[5] = GetHeadToCell(c - 1, d);
		mat[6] = GetHeadToCell(c, d + w);
		mat[7] = GetHeadToCell(c + h, d);
		mat[8] = GetHeadToCell(c, d - 1);

		StitchDownBorder(mat[5], submat[1], w);
		StitchDownBorder(submat[3], mat[7], w);
		StitchRightBorder(mat[8], submat[4], h);
		StitchRightBorder(submat[2], mat[6], h);
		
		StitchDownBorder(mat[1], submat[5], w);
		StitchDownBorder(submat[7], mat[3], w);
		StitchRightBorder(mat[4], submat[8], h);
		StitchRightBorder(submat[6], mat[2], h);
	}

	PrintMatrix(n,m);

	return 0;
}
