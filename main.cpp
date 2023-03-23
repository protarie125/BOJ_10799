#include <iostream>
#include <stack>
#include <string>

using namespace std;

using sc = stack<char>;

class solution {
public:
	explicit solution(const string& str)
		: str_{ str } {
	}

private:
	string str_{};
	int ans_{ 0 };

public:
	void solve() {
		const auto& n = str_.length();

		auto st = sc{};
		auto prev = char{ 0 };
		for (auto i = decltype(n){ 0 }; i < n; ++i) {
			const auto& now = str_[i];

			if (')' == now) {
				st.pop();

				if ('(' == prev) {
					ans_ += st.size();
				}
				else {
					++ans_;
				}
			}
			else {
				st.push(now);
			}

			prev = now;
		}
	}

	const int& getAns() const noexcept {
		return ans_;
	}
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string str; cin >> str;
	auto solver = solution{ str };
	solver.solve();
	cout << solver.getAns();

	return 0;
}