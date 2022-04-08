#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

class Leaderboard {
public:
	map<int, int> scoreM;
	map<int, list<int>> rankingM;


	Leaderboard() {

	}

	void addScore(int playerId, int score) {

		if (scoreM.find(playerId) == scoreM.end()) {
			scoreM[playerId] = score;
			rankingM[score].push_back(playerId);
		}
		else {
			int preScore = scoreM[playerId];
			int totalScore = preScore + score;
			scoreM[playerId] = totalScore;

			// remove playerId from rankingM
			rankingM[preScore].remove(playerId);
			// add playerId in proper location of rankingM
			rankingM[totalScore].push_back(playerId);
		}
	}

	int top(int K) {
		int ans = 0, kRemain = K;

		// reverse iteration from high to low
		std::map<int, list<int>>::reverse_iterator rit;
		for (rit = rankingM.rbegin(); rit != rankingM.rend(); ++rit) {
			int cnt = rit->second.size();
			if (kRemain > cnt) {
				kRemain -= cnt;
				ans += rit->first * cnt;
			}
			else if (kRemain == cnt) {
				kRemain -= cnt;
				ans += rit->first * cnt;
				break;
			}
			else {   // kRemain < cnt
				ans += rit->first * kRemain;
				break;
			}
		}
		return ans;
	}
	
	void reset(int playerId) {
		int prevScore = scoreM[playerId];
		scoreM.erase(playerId);
		rankingM[prevScore].remove(playerId);
	}
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */



int main() {
	char c;
	Leaderboard* obj = new Leaderboard();

#if 0
	//["Leaderboard", "addScore", "addScore", "addScore", "addScore", "addScore", "top", "reset", "reset", "addScore", "top"]
	//[[], [1, 73], [2, 56], [3, 39], [4, 51], [5, 4], [1], [1], [2], [2, 51], [3]]
	obj->addScore(1, 73);
	obj->addScore(2, 56);
	obj->addScore(3, 39);
	obj->addScore(4, 51);
	obj->addScore(5, 4);
	cout << obj->top(1) << endl;
	obj->reset(1);
	cout << obj->top(2) << endl;
	obj->addScore(1, 73);
	cout << obj->top(2) << endl;
	obj->addScore(1, 72);
	cout << obj->top(2) << endl;
#endif

#if 1
	//["Leaderboard", "addScore", "addScore", "addScore", "addScore", "addScore", "addScore", 
	//  "addScore", "addScore", "addScore", "addScore", "top", "reset", "reset", "addScore", 
	// "addScore", "top", "reset", "reset", "addScore", "reset"]
	//[[],              [1, 13],   [2, 93],    [3, 84],   [4, 6],      [5, 89],    [6, 31], 
	//  [7, 7],      [8, 1],     [9, 98],    [10, 42],  [5],   [1],      [2],     [3, 76], 
	// [4, 68],    [1],   [3],     [4],      [2, 70],    [2]]

	obj->addScore(1, 13);
	obj->addScore(2, 93);
	obj->addScore(3, 84);
	obj->addScore(4, 6);
	obj->addScore(5, 89);
	obj->addScore(6, 31);
	obj->addScore(7, 7);
	obj->addScore(8, 1);
	obj->addScore(9, 98);
	obj->addScore(10, 42);
	cout << obj->top(5) << endl;
	obj->reset(1);
	obj->reset(2);
	obj->addScore(3, 76);
	obj->addScore(4, 68);
	cout << obj->top(1) << endl;
//	obj->addScore(1, 73);
//	cout << obj->top(2) << endl;

#endif
//	obj->addScore(1, 73);
//	obj->addScore(1, 73);
//	int param_2 = obj->top(2);
//	obj->reset(2);

	cin >> c;
}
