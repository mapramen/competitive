#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define TOTAL_FRAMES 10

int ReadPin() {
	int x;
	scanf("%d", &x);
	return x;
}

int Solve() {
	int ans = 0;

	for (int frames = 1, last_frame_strike = false, last_frame_spare = false, second_last_frame_strike = false; frames <= TOTAL_FRAMES; ++frames) {
		int first_pin = ReadPin();
		ans += first_pin;

		if (second_last_frame_strike && last_frame_strike) {
			ans += first_pin;
		}

		if (last_frame_strike || last_frame_spare) {
			ans += first_pin;
		}

		if (first_pin == 10 && frames != TOTAL_FRAMES) {
			second_last_frame_strike = last_frame_strike;
			last_frame_strike = true;
			last_frame_spare = false;
			continue;
		}

		int second_pin = ReadPin();
		ans += second_pin;

		if (last_frame_strike) {
			ans += second_pin;
		}

		if (frames != TOTAL_FRAMES || (first_pin != 10 && first_pin + second_pin != 10)) {
			last_frame_strike = false;
			last_frame_spare = first_pin + second_pin == 10;
			second_last_frame_strike = false;
			continue;
		}

		int third_pin = ReadPin();
		ans += third_pin;
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}