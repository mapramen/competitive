#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int main(){
	int n, i, daysRest = 0, daysGym = 0, daysContest = 0, tempRest, tempGym, tempContest, ans = N;

	scanf("%d", &n);

	while(n--){
		scanf("%d", &i);
		if(i == 0){
			tempRest = min(daysRest, min(daysGym, daysContest)) + 1;
			tempGym = N;
			tempContest = N;
		}
		else if(i == 1){
			tempRest = min(daysRest, min(daysGym, daysContest)) + 1;
			tempContest = min(daysRest, daysGym);
			tempGym = N;
		}
		else if(i == 2){
			tempRest = min(daysRest, min(daysGym, daysContest)) + 1;
			tempGym = min(daysRest, daysContest);
			tempContest = N;
		}
		else{
			tempRest = min(daysRest, min(daysGym, daysContest)) + 1;
			tempGym = min(daysRest, daysContest);
			tempContest = min(daysRest, daysGym);
		}

		daysRest = tempRest;
		daysGym = tempGym;
		daysContest = tempContest;
	}

	ans = min(ans, min(daysRest, min(daysGym, daysContest)));

	printf("%d\n", ans);

	return 0;
}
