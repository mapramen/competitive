#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int Get_Rectangle_Count(int x1, int y1, int x2, int y2){
	int ans;

	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);

	scanf("%d", &ans);
	return ans;
}

int Get_X_End(int x1, int y1, int x2, int y2, int cnt, bool is_right_end){
	int mid, x, xl = x1, xr = x2;

	while(xl <= xr){
		mid = xl + (xr - xl) / 2;

		if(is_right_end){
			if(Get_Rectangle_Count(x1, y1, mid, y2) >= cnt){
				x = mid;
				xr = mid - 1;
			}
			else
				xl = mid + 1;
		}
		else{
			if(Get_Rectangle_Count(mid, y1, x2, y2) >= cnt){
				x = mid;
				xl = mid + 1;
			}
			else
				xr = mid - 1;
		}
	}

	return x;
}

int Get_Y_End(int x1, int y1, int x2, int y2, int cnt, bool is_upper_end){
	int mid, y, yl = y1, yr = y2;

	while(yl <= yr){
		mid = yl + (yr - yl) / 2;

		if(is_upper_end){
			if(Get_Rectangle_Count(x1, y1, x2, mid) >= cnt){
				y = mid;
				yr = mid - 1;
			}
			else
				yl = mid + 1;
		}
		else{
			if(Get_Rectangle_Count(x1, mid, x2, y2) >= cnt){
				y = mid;
				yl = mid + 1;
			}
			else
				yr = mid - 1;
		}
	}

	return y;
}

int main(){
	int n, i, j, k, x1, y1, x2, y2, r1, r2, r3, r4, c1, c2, c3, c4;

	cin >> n;

	x1 = y1 = 1;
	x2 = y2 = n;

	x1 = Get_X_End(x1, y1, x2, y2, 2, 0);
	x2 = Get_X_End(x1, y1, x2, y2, 2, 1);

	y1 = Get_Y_End(x1, y1, x2, y2, 2, 0);
	y2 = Get_Y_End(x1, y1, x2, y2, 2, 1);

	r1 = r3 = x1;
	r2 = r4 = x2;

	c1 = c3 = y1;
	c2 = c4 = y2;

	r2 = Get_X_End(r1, c1, r2, c2, 1, 1);
	r3 = Get_X_End(r3, c3, r4, c4, 1, 0);

	if(r1 < r3 && r2 < r4 && r2 >= r3 && Get_Rectangle_Count(r3, y1, r2, y2) == 1){
		swap(r3, r4);
		swap(r2, r3);
		swap(r3, r4);
	}

	if(r1 == r3 && r2 == r4)
		c2--, c3++;

	c2 = Get_Y_End(r1, c1, r2, c2, 1, 1);
	c1 = Get_Y_End(r1, c1, r2, c2, 1, 0);

	c3 = Get_Y_End(r3, c3, r4, c4, 1, 0);
	c4 = Get_Y_End(r3, c3, r4, c4, 1, 1);

	printf("! %d %d %d %d %d %d %d %d", r1, c1, r2, c2, r3, c3, r4, c4);
	cout << endl;
	fflush(stdout);

	return 0;
}