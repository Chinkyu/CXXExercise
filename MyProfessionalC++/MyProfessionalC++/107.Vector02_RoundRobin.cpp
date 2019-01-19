#include <vector>
#include <iostream>

#include "107.Vector02_RoundRobin.h"

using namespace std;

template <typename T> RoundRobin<T>::RoundRobin(size_t numExpected)
{
	mElems.reserve(numExpected);
	mCurElem = end(mElems);
}

template <typename T> RoundRobin<T>::~RoundRobin()
{
	// do nothing
}

template <typename T> void RoundRobin<T>::add(const T& elem)
{
	int pos = (mCurElem == end(mElems) ? -1 : mCurElem - begin(mElems));

	// Add the element
	mElems.push_back(elem);

	mCurElem = (pos == -1 ? end(mElems) : begin(mElems) + pos);
}

template <typename T> void RoundRobin<T>::remove(const T& elem)
{
	for (auto it = begin(mElems); it != end(mElems); ++it) {
		if (*it == elem) {
			int newPos;

			// if current iterator is before or at the one we're removing,
			// the new position is the same as before
			if (mCurElem <= it) {
				newPos = mCurElem - begin(mElems);
			}
			else {
				newPos = mCurElem - begin(mElems) - 1;
			}
			mElems.erase(it);
			mCurElem = begin(mElems) + newPos;
			return;
		}
	}
}

template <typename T> T& RoundRobin<T>::getNext()
{
	if (mElems.empty()) {
		throw out_of_range("No elements in the list");
	}

	if (mCurElem == end(mElems)) {
		mCurElem = begin(mElems);
	}
	else {
		++mCurElem;
		if (mCurElem == end(mElems)) {
			mCurElem = begin(mElems);
		}
	}

	return *mCurElem;
}


class Process
{
public:
	string name;
	Process(string s) { name = s; }
	void doWorkDuringTimeSlice() {
		cout << "Processor : " << name.c_str() << " is Working" << endl;
	}
	bool operator==(const Process& rhs) {
		if (name == rhs.name) {
			return true;
		}
		else {
			return false;
		}
	}
};

// Simple round-robin based process scheduler
class Scheduler
{
public:
	Scheduler(const vector<Process> & processes);
	void scheduleTimeSlice();
	void removeProcess(const Process& process);
private:
	RoundRobin<Process> rr;
};

Scheduler::Scheduler(const vector<Process>& processes) {
	for (auto& process : processes) {
		rr.add(process);
	}
}

void Scheduler::scheduleTimeSlice()
{
	try {
		rr.getNext().doWorkDuringTimeSlice();
	}
	catch (const out_of_range&) {
		cerr << "No more processes to schedule." << endl;
	}
}

void Scheduler::removeProcess(const Process& process)
{
	rr.remove(process);
}

int main() {
	char c;

	vector<Process> processes = { Process("1"), Process("2"), Process("3") };
	Scheduler sched(processes);

	for (int i = 0; i < 40; ++i) {
		sched.scheduleTimeSlice();
	}
	sched.removeProcess(processes[1]);
	cout << "Removed second process" << endl;
	for (int i = 0; i < 40; ++i) {
		sched.scheduleTimeSlice();
	}

	cin >> c;

	return 0;
}
