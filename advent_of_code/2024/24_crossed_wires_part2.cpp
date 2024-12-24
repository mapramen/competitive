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

map<tuple<string, string, string>, string> ReadGates() {
	map<tuple<string, string, string>, string> gates;
	for (string line; getline(cin, line);) {
		istringstream iss(line);
		string input1, operation, input2, arrow, output;
		iss >> input1 >> operation >> input2 >> arrow >> output;

		if (input1 > input2) {
			swap(input1, input2);
		}

		gates[{operation, input1, input2}] = output;
	}
	return gates;
}

string GetGateName(char x, int number) {
	ostringstream oss;
	oss << setw(2) << setfill('0') << number;
	return x + oss.str();
}

string GetGate(const map<tuple<string, string, string>, string>& actual_gates, const string operation, string input1, string input2) {
	if (input1 > input2) {
		swap(input1, input2);
	}

	auto it = actual_gates.find({operation, input1, input2});
	if (it != actual_gates.end()) {
		// cout << "Found gate for " << input1 << " " << operation << " " << input2 << " = " << it->second << endl;
		return it->second;
	}

	// cout << "Gate not found for " << input1 << " " << operation << " " << input2 << endl;
	return "";
}

string GetUpdatedGateName(const string& gate1, const string& gate2, const string& gate) {
	if (gate == gate1) {
		return gate2;
	}

	if (gate == gate2) {
		return gate1;
	}

	return gate;
}

map<tuple<string, string, string>, string> GetUpdatedGates(const map<tuple<string, string, string>, string>& actual_gates, const string gate1, const string gate2) {
	map<tuple<string, string, string>, string> updated_gates;

	for (const auto& [key, output] : actual_gates) {
		const auto [operation, input1, input2] = key;
		string new_output = GetUpdatedGateName(gate1, gate2, output);
		updated_gates[{operation, input1, input2}] = new_output;
	}

	return updated_gates;
}

vector<string> mismatches;

bool Check(const int n, map<tuple<string, string, string>, string>& actual_gates, bool should_update) {
	unordered_set<string> result_gates;
	for (int i = 0; i < n; ++i) {
		result_gates.insert(GetGateName('z', i));
	}

	string c = GetGate(actual_gates, "AND", "x00", "y00");
	string z00 = GetGate(actual_gates, "XOR", "x00", "y00");
	string z00_expected = GetGateName('z', 0);

	if (z00 != z00_expected) {
		if (!should_update) {
			return false;
		}
		// cout << "Mismatch at 0 " << z00 << " " << z00_expected << endl;
		actual_gates = GetUpdatedGates(actual_gates, z00, z00_expected);
		mismatches.push_back(z00);
		mismatches.push_back(z00_expected);
		return Check(n, actual_gates, should_update);
	}

	for (int i = 1; i < n; ++i) {
		const string a = GetGateName('x', i);
		const string b = GetGateName('y', i);

		string d = GetGate(actual_gates, "XOR", a, b);
		if (d == "") {
			return false;
		}

		string z = GetGate(actual_gates, "XOR", c, d);
		if (z == "") {
			return false;
		}

		string z_expected = GetGateName('z', i);

		if (z != z_expected) {
			// sleep(1);
			if (!should_update) {
				return false;
			}
			// cout << "Mismatch at " << i << " " << z << " " << z_expected << endl;
			actual_gates = GetUpdatedGates(actual_gates, z, z_expected);
			mismatches.push_back(z);
			mismatches.push_back(z_expected);
			return Check(n, actual_gates, should_update);
		}

		string e = GetGate(actual_gates, "AND", a, b);
		if (e == "") {
			return false;
		}

		string f = GetGate(actual_gates, "AND", c, d);
		if (f == "") {
			return false;
		}

		c = GetGate(actual_gates, "OR", e, f);
	}

	return true;
}

void PrintMismatches() {
	sort(mismatches.begin(), mismatches.end());
	for (int i = 0; i < mismatches.size(); ++i) {
		if (i != 0) {
			cout << ",";
		}
		cout << mismatches[i];
	}
	cout << endl;
}

int main() {
	unordered_map<string, int> gate_values = ReadInputWires();
	map<tuple<string, string, string>, string> actual_gates = ReadGates();

	bool is_valid = Check(45, actual_gates, true);

	if (!is_valid) {
		vector<string> gate_names;
		for (auto [_, output] : actual_gates) {
			gate_names.push_back(output);
		}

		sort(gate_names.begin(), gate_names.end());

		for (const string& gate1 : gate_names) {
			for (const string& gate2 : gate_names) {
				map<tuple<string, string, string>, string> updated_gates = GetUpdatedGates(actual_gates, gate1, gate2);

				if (gate2 <= gate1) {
					continue;
				}

				// printf("Checking %s %s\n", gate1.c_str(), gate2.c_str());
				if (Check(45, updated_gates, false)) {
					// cout << "Found " << gate1 << " " << gate2 << endl;
					mismatches.push_back(gate1);
					mismatches.push_back(gate2);
					PrintMismatches();
					return 0;
				}
			}
		}
	}

	return 0;
}