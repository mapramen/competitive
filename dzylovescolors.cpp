#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int n, blockSize, totalBlocks;
vector< int > color, blockColor;
vector< ll > colorfulness, blockColorfulness, lazyBlockColorfulness;
vector< bool > isBlockDirty;

void MakeBlockDirty(int currBlock){
	if(isBlockDirty[currBlock] == 0){
		int i = (currBlock - 1) * blockSize + 1;
		int j = currBlock * blockSize;

		for( ; i <= j; i++){
			colorfulness[i] += lazyBlockColorfulness[currBlock];
			color[i] = blockColor[currBlock];
		}

		lazyBlockColorfulness[currBlock] = 0;
		isBlockDirty[currBlock] = 1;
	}
}

void UpdateInBlock(int l, int r, int x, int currBlock){
	for( ; l <= r; l++){
		int y = abs(x - color[l]);
		colorfulness[l] += y;
		blockColorfulness[currBlock] += y;
		color[l] = x;
	}
}

void Update(int l, int r, int x){
	int leftBlock = (l - 1)/blockSize + 1;
	int rightBlock = (r - 1)/blockSize + 1;

	for(int currBlock = leftBlock + 1; currBlock < rightBlock; currBlock++){
		if(isBlockDirty[currBlock]){
			int i = (currBlock - 1) * blockSize + 1;
			int j = currBlock * blockSize;
			
			UpdateInBlock(i, j, x, currBlock);

			blockColor[currBlock] = x;
			isBlockDirty[currBlock] = 0;
		}
		else{
			int y = abs(x - blockColor[currBlock]);
			lazyBlockColorfulness[currBlock] += y;
			blockColorfulness[currBlock] += (1LL*y*blockSize);
			blockColor[currBlock] = x;
		}
	}

	MakeBlockDirty(leftBlock);
	MakeBlockDirty(rightBlock);

	if(leftBlock != rightBlock){
		UpdateInBlock(l, leftBlock * blockSize, x, leftBlock);
		UpdateInBlock((rightBlock - 1) * blockSize + 1, r, x, rightBlock);
	}
	else
		UpdateInBlock(l, r, x, leftBlock);
}

ll QueryInBlock(int l, int r, int currBlock){
	ll ans = 0;

	for( ; l <= r; l++)
		ans += (colorfulness[l] + lazyBlockColorfulness[currBlock]);

	return ans;
}

ll Query(int l, int r){
	ll ans = 0;
	int leftBlock = (l - 1)/blockSize + 1;
	int rightBlock = (r - 1)/blockSize + 1;

	for(int currBlock = leftBlock + 1; currBlock < rightBlock; currBlock++)
		ans += blockColorfulness[currBlock];

	if(leftBlock != rightBlock){
		ans += QueryInBlock(l, leftBlock * blockSize, leftBlock);
		ans += QueryInBlock((rightBlock - 1) * blockSize + 1, r, rightBlock);
	}
	else
		ans += QueryInBlock(l, r, leftBlock);

	return ans;
}

int main(){
	int q, k, x, l, r;

	scanf("%d%d", &n, &q);

	blockSize = (int)sqrt(n + 1);
	totalBlocks = (n / blockSize) + (n % blockSize != 0);

	color.resize(n + 1);
	colorfulness.resize(n + 1);
	blockColor.resize(totalBlocks + 1);
	blockColorfulness.resize(totalBlocks + 1);
	lazyBlockColorfulness.resize(totalBlocks + 1);
	isBlockDirty.resize(totalBlocks + 1);

	for(l = 1; l <= n; l++)
		color[l] = l;

	for(l = 1; l <= totalBlocks; l++)
		isBlockDirty[l] = 1;

	while(q--){
		scanf("%d", &k);

		if(k == 1){
			scanf("%d%d%d", &l, &r, &x);
			Update(l, r, x);
		}
		else{
			scanf("%d%d", &l, &r);
			printf("%I64d\n", Query(l, r));
		}
	}

	return 0;
}
