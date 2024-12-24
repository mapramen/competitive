#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

unordered_map<string, int> ReadInputWires() {
	unordered_map<string, int> wires;
	for (string line; getline(cin, line);) {
		if (line.empty()) {
			break;
		}

		string wire = line.substr(0, 3);
		int value = stoi(line.substr(5));

		wires[wire] = value;
	}
	return wires;
}

vector<tuple<string, string, string, string>> ReadGates() {
	vector<tuple<string, string, string, string>> gates;
	for (string line; getline(cin, line);) {
		istringstream iss(line);
		string input1, operation, input2, arrow, output;
		iss >> input1 >> operation >> input2 >> arrow >> output;

		if (input1 > input2) {
			swap(input1, input2);
		}

		gates.push_back({input1, input2, operation, output});
	}
	sort(gates.begin(), gates.end());
	return gates;
}

int main() {
	unordered_map<string, int> gate_values = ReadInputWires();
	vector<tuple<string, string, string, string>> gates = ReadGates();

	// for (auto [input1, input2, operation, output] : gates) {
	// 	cout << input1 << " " << operation << " " << input2 << " -> " << output << endl;
	// }

	for (int k = 0; k < gates.size(); ++k) {
		for (const auto [input1, input2, operation, output] : gates) {
			int input1_value = gate_values.count(input1) ? gate_values[input1] : 0;
			int input2_value = gate_values.count(input2) ? gate_values[input2] : 0;

			if (operation == "AND") {
				gate_values[output] = input1_value & input2_value;
			} else if (operation == "OR") {
				gate_values[output] = input1_value | input2_value;
			} else if (operation == "XOR") {
				gate_values[output] = input1_value ^ input2_value;
			} else {
				assert(false);
			}
		}
	}

	vector<pair<string, int>> result;
	for (auto [key, value] : gate_values) {
		if (key.front() == 'z') {
			result.push_back({key, value});
		}
	}

	sort(result.begin(), result.end());
	reverse(result.begin(), result.end());

	ll ans = 0;
	for (const auto [_, value] : result) {
		ans = 2 * ans + value;
	}

	cout << ans << endl;

	return 0;
}