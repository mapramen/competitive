#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

map< string, int > week;
int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Insert_Day_In_Week(char *s){
	week.insert(MP(string(s), week.size()));
}

void Initialize(){
	Insert_Day_In_Week("monday");
	Insert_Day_In_Week("tuesday");
	Insert_Day_In_Week("wednesday");
	Insert_Day_In_Week("thursday");
	Insert_Day_In_Week("friday");
	Insert_Day_In_Week("saturday");
	Insert_Day_In_Week("sunday");
}

int main(){
	string day1, day2;
	int n1, n2;

	Initialize();

	cin >> day1;
	cin >> day2;

	n1 = week[day1];
	n2 = week[day2];

	for(int i = 0; i < 11; i++){
		if((n1 + days_in_month[i]) % 7 == n2){
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");

	return 0;
}
