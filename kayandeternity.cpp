#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector< pii > points, addPoints, removePoints;
vector<int> cnt, tempY, compressY, prevX;
vector< ll > ans;

int BinarySearchCompressedY(int i){
	int x = 0, y = tempY.size() - 1, z = 0, mid;

	while(x <= y){
		mid = x + (y - x) / 2;

		if(tempY[mid] <= i){
			z = compressY[mid];
			x = mid + 1;
		}
		else
			y = mid - 1;
	}

	return z;
}

void CompressYAndPreprocess(int k){
	for(int i = 0; i < points.size(); i++)
		tempY.PB(points[i].second);

	sort(tempY.begin(), tempY.end());

	int prevY = tempY[0] - k;
	int n = 0;

	for(int i = 0; i < tempY.size(); i++){
		for(prevY = max(prevY, tempY[i] - k + 1); prevY <= tempY[i]; prevY++, n++);

		compressY.PB(n - 1);
	}

	sort(points.begin(), points.end());

	int minX = points[0].first - k + 1;

	for(int i = 0; i < points.size(); i++){
		points[i].first -= minX;
		points[i].second = BinarySearchCompressedY(points[i].second);
		addPoints.PB(MP(points[i].first - k + 1, points[i].second - k + 1));
		removePoints.PB(MP(points[i].first + 1, points[i].second - k + 1));
	}

	cnt.resize(n);
	prevX.resize(n);
	ans.resize(points.size() + 1);
}

void Update(int y, int x, int k, int val){
	for(int currY = y; currY <= y + k - 1; currY++){
		ans[cnt[currY]] += (x - prevX[currY]);
		cnt[currY] += val;
		prevX[currY] = x;
	}
}

int main(){
	int n, i, j, k, x;

	scanf("%d%d", &n, &k);

	while(n--){
		scanf("%d%d", &i, &j);
		points.PB(MP(i,j));
	}

	CompressYAndPreprocess(k);

	for(i = j = 0; i < addPoints.size(); i++){
		for( ; removePoints[j] <= addPoints[i]; j++)
			Update(removePoints[j].second, removePoints[j].first, k, -1);

		Update(addPoints[i].second, addPoints[i].first, k, 1);
	}

	for( ; j < removePoints.size(); j++)
		Update(removePoints[j].second, removePoints[j].first, k, -1);

	for(i = 1; i < ans.size(); i++)
		printf("%I64d ", ans[i]);

	printf("\n");

	return 0;
}
