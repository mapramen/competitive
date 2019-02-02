#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 21

int peasantPref[N*N][N*N], fieldPref[N*N][N*N];
vector< vector< int > > peasantPrefList(N*N), fieldPrefList(N*N);
vector< pii > peasant, field;
bool isField[N][N];
int isFieldMatched[N*N], nextFieldIndex[N*N], currentField[N*N];

int main(){
	int n, m, k, s, i, j, x, y, d;

	scanf("%d%d%d%d", &n, &m, &k, &s);

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			isField[i][j] = 1;

	peasant.PB(MP(0,0));

	while(k--){
		scanf("%d%d", &i, &j);
		peasant.PB(MP(i,j));
		isField[i][j] = 0;
	}

	while(s--){
		scanf("%d%d", &i, &j);
		isField[i][j] = 0;
	}

	field.PB(MP(0,0));

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(isField[i][j])
				field.PB(MP(i,j));

	for(i = 1; i < peasant.size(); i++){
		vector< pii > temp;

		for(j = 1; j < field.size(); j++){
			d = abs(field[j].first - peasant[i].first) + abs(field[j].second - peasant[i].second);
			temp.PB(MP(d,j));
		}

		sort(temp.begin(), temp.end());

		for(j = 0; j < temp.size(); j++){
			peasantPrefList[i].PB(temp[j].second);
			peasantPref[i][temp[j].second] = j + 1;
		}
	}

	for(j = 1; j < field.size(); j++){
		vector< pair< int , pair< pii, int > > > temp;

		for(i = 1; i < peasant.size(); i++){
			d = abs(field[j].first - peasant[i].first) + abs(field[j].second - peasant[i].second);
			temp.PB(MP(d,MP(MP(-peasant[i].first, -peasant[i].second),i)));
		}

		sort(temp.begin(), temp.end());

		for(i = 0; i < temp.size(); i++){
			fieldPrefList[j].PB(temp[i].second.second);
			fieldPref[j][temp[i].second.second] = i + 1;
		}
	}

	for(i = 1; i < peasant.size(); i++){
		for(j = 0; j < peasantPrefList[i].size(); j++)
			printf("%d ", peasantPrefList[i][j]);
		printf("\n");
	}
	printf("\n");



	queue< int > q;

	for(i = 1; i < peasant.size(); i++){
		q.push(i);
		nextFieldIndex[i] = 1;
	}

	while(!q.empty()){
		i = q.front();
		q.pop();

		j = peasantPrefList[i][nextFieldIndex[i] - 1];

		cout << i << ' ' << j << '\n';

		if(isFieldMatched[j] == 0){
			isFieldMatched[j] = i;
			currentField[i] = j;
		}
		else{
			k = isFieldMatched[j];

			cout << k << ' ' << fieldPref[j][k] << ' ' << fieldPref[j][i] << '\n'; 

			if(fieldPref[j][k] > fieldPref[j][i]){
				isFieldMatched[j] = i;
				currentField[i] = j;
				q.push(k);
			}
			else
				q.push(i);
		}
		
		nextFieldIndex[i]++;
	}

	m = field.size();
	n = peasant.size();

	for(i = 1; i < n; i++)
		printf("%d ", currentField[i]);

	printf("\n");

	for(j = 0; j < m - 1; j++)
		for(i = 1; i < n; i++)
			if(currentField[i] == peasantPrefList[i][j])
				printf("%d ", i);

	printf("\n");

	return 0;
}
