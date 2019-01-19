#pragma once

#include <vector>

// Class template RoundRobin
// Provides simple round-robin semantics for a list of elements.
template <typename T>
class RoundRobin
{
public:
	RoundRobin(size_t numExpected = 0);
	virtual ~RoundRobin();

	// prevent assignment and pass-by-value
	RoundRobin(const RoundRobin& src) = delete;
	RoundRobin& operator=(const RoundRobin& rhs) = delete;

	// append element to the end of the list
	void add(const T& elem);

	// remove the first element
	void remove(const T& elem);

	// return the next element in the list
	T& getNext();

private:
	std::vector<T> mElems;
	typename std::vector<T>::iterator mCurElem;  //:: typename  necessary??? 
};
