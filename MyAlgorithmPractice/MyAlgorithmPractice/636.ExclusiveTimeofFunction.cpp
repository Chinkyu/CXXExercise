class Solution {
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		vector<int> result(n, 0);
		char action[6];
		int fid;
		stack<pair<int, int>> s; // fid, previous end time
		for (const auto& log : logs) {
			int time;
			sscanf(log.c_str(), "%d:%[a-z]:%d", &fid, action, &time);
			if (action[0] == 's') { // start
				if (!s.empty()) {
					result[s.top().first] += time - s.top().second;
				}
				s.push({ fid, time });
			}
			else { // end
				result[s.top().first] += time - s.top().second + 1;
				s.pop();
				if (!s.empty()) {
					s.top().second = time + 1; // update previous end time
				}
			}
		}

		return result;
	}
};