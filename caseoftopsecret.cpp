#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int peg_position[N], peg_no[N];
vector<int> peg_coordinate;
vector< pii > pegs;

int main(){
	int n, m, q, i, j, k, l, curr_peg, next_peg, is_right, prev_jump_len, curr_jump_len;

	scanf("%d%d", &n, &m);

	for(i = 1; i <= n; i++){
		scanf("%d", &j);
		pegs.PB(MP(j, i));
	}

	sort(pegs.begin(), pegs.end());

	for(i = 0; i < pegs.size(); i++){
		peg_coordinate.PB(pegs[i].first);
		peg_no[i] = pegs[i].second;
		peg_position[peg_no[i]] = i;
	}

	while(m--){
		scanf("%d%d", &curr_peg, &l);
		curr_peg = peg_position[curr_peg];
		prev_jump_len = peg_coordinate[n - 1] - peg_coordinate[0] + 1;
		is_right = 1;

		while(1){
			if(is_right){
				next_peg = lower_bound(peg_coordinate.begin(), peg_coordinate.end(), min(l + peg_coordinate[curr_peg], peg_coordinate[n - 1])) - peg_coordinate.begin();

				if(peg_coordinate[next_peg] - peg_coordinate[curr_peg] > l)
					next_peg--;

				curr_jump_len = peg_coordinate[next_peg] - peg_coordinate[curr_peg];
			}
			else{
				next_peg = lower_bound(peg_coordinate.begin(), peg_coordinate.end(), max(peg_coordinate[curr_peg] - l, peg_coordinate[0])) - peg_coordinate.begin();
				curr_jump_len = peg_coordinate[curr_peg] - peg_coordinate[next_peg];
			}

			// printf("Current Peg: %d \tNext Peg: %d\t Jump Length: %d\n", curr_peg, next_peg, curr_jump_len);

			if(curr_jump_len == 0)
				if(prev_jump_len == 0)
					break;
				else
					is_right = 1 - is_right;
			else
				if(curr_jump_len != prev_jump_len){
					l -= curr_jump_len;
					curr_peg = next_peg;
					is_right = 1 - is_right;
				}
				else{
					k = l / curr_jump_len;
					l = l % curr_jump_len;

					if(k % 2){
						curr_peg = next_peg;
						is_right = 1 - is_right;
					}
				}

			prev_jump_len = curr_jump_len;
		}

		printf("%d\n", peg_no[curr_peg]);
	}

	return 0;
}
