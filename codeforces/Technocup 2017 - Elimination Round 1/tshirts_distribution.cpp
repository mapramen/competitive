#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

map< string, int > string_map;
string inv_string[7];
int cnt[7], ans[N], tshirt_assigned;
queue<int> ones[7], twos[7];

void Insert_Shirt(char *s){
	string shirt_string = string(s);
	string_map.insert(MP(shirt_string, string_map.size()));
	inv_string[string_map[shirt_string]] = shirt_string;
}

void Initialise(){
	Insert_Shirt("");
	Insert_Shirt("S");
	Insert_Shirt("M");
	Insert_Shirt("L");
	Insert_Shirt("XL");
	Insert_Shirt("XXL");
	Insert_Shirt("XXXL");
}

void Empty_Queue(queue<int>& q, int i){
	while(!q.empty() && cnt[i] > 0){
		ans[q.front()] = i;
		q.pop();
		cnt[i]--;
		tshirt_assigned++;
	}
}

int main(){
	int n, i, j, k;

	Initialise();

	for(i = 1; i <= 6; i++)
		cin >> cnt[i];

	cin >> n;

	for(i = 1; i <= n; i++){
		string s;
		cin >> s;

		for(j = 1; j <= 6; j++)
			if(s == inv_string[j])
				ones[j].push(i);

		for(j = 1; j <= 5; j++)
			if(s == inv_string[j] + string(",") + inv_string[j + 1])
				twos[j].push(i);
	}

	for(i = 1; i <= 6; i++){
		if(i != 1)
			Empty_Queue(twos[i - 1], i);

		Empty_Queue(ones[i], i);
		Empty_Queue(twos[i], i);
	}

	if(tshirt_assigned < n){
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for(i = 1; i <= n; i++)
		cout << inv_string[ans[i]] << '\n';

	return 0;
}
