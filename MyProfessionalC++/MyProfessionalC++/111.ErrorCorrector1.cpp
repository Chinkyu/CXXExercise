#include <iostream>
#include <ostream>
#include <queue>

using namespace std;

// sample error class with just a priority and a string error description.
class Error{
public:
	Error(int priority, const string& errMsg) : mPriority(priority), mError(errMsg) {}
	int getpriority() const { return mPriority; }
	const string& getErrorString() const { return mError; }
	friend bool operator<(const Error& lhs, const Error& rhs);
	friend ostream& operator<<(ostream& os, const Error& err);
private:
	int mPriority;
	string mError;
};

class ErrorCorrector {
public:
	void addError(const Error& error);
	Error getError();
private:
	priority_queue<Error> mErrors;
};


// XXXX : friends may make error when Error::operator<
bool operator<(const Error& lhs, const Error& rhs) {
	return (lhs.mPriority < rhs.mPriority);
}

ostream& operator<<(ostream& os, const Error& err) {
	os << err.mError.c_str() << " (priority " << err.mPriority << ")";
	return os;
}


void ErrorCorrector::addError(const Error& error) {
	mErrors.push(error);
}

Error ErrorCorrector::getError() {
	if (mErrors.empty()) {
		throw out_of_range("No more errors.");
	}

	// Save the top emelement.
	Error top = mErrors.top();
	// Remove the top emelement
	mErrors.pop();
	// Return the saved element.
	return top;
}

int main() {
	char c;

	ErrorCorrector ec;
	ec.addError(Error( 3, "Unable to read file"));
	ec.addError(Error( 1, "Incorrecto entry from user"));
	ec.addError(Error(10, "Unable to allocate memory!"));
	while (true) {
		try {
			Error e = ec.getError();
			cout << e << endl;
		}
		catch (const out_of_range&) {
			cout << "Finished processing errors" << endl;
			break;
		}
	}
	cin >> c;
}