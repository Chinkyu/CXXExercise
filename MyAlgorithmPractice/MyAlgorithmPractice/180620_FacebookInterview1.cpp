Welcome to Facebook!

This is just a simple shared plaintext pad, with no execution capabilities.

When you know what language you'd like to use for your interview,
simply choose it from the dropdown in the top bar.

Enjoy your interview!

Given a mapping from digits to list of letters and a string of digits of arbitrary length, determine all possible ways to replace the digits with corresponding letters from the map.

Mapping = {
	'1' ¡æ['A', 'B', 'C'], <= fix : 3
	'2' ¡æ['D', 'E', 'F'],
	...
	'0' ¡æ['X', 'Y', 'Z'],
}
Input String = ¡°12¡± <= arbitrary..
Expected Output = [¡°AD¡±, ¡°AE¡±, ¡°AF¡±, ¡°BD¡±, ¡°BE¡±, ¡°BF¡±, ¡°CD¡±, ¡°CE¡±, ¡°CF¡±]

// time complexity
O(3 ^ n);  n == strlen(input string);


//////////////////////////////////////////////////////////////////////////////
// assume... 
extern char * mapping[];
extern char * input_str; // <- can be used in global or class varialbe.. 

#define MAX_LEN 3
						 //#define MAX_RESULT 100;

using namespace std;

//char result[MAX_RESULT];
string result;

void iteration(int idx, int input_str_len) { // XXXX : remove input_str_len
											 //  int len = strlen(s);

	if (idx >= input_str_len) {  // end condition  >- i
								 // print result 
		for (int j = 0; j < input_str_len; j++) {
			cout << result[i];
		}
		cout << endl;  // <- 
		return;
	}

	int input_str_idx = input_str[idx] - '0;

		for (int i = 0; i < MAX_LEN; ++i) {
			result[idx] = mapping[input_str_idx[i];
			//cout << mapping[input_str_idx][i];                     
			iteration(idx + 1, input_str_len);
		}

}


// for small input_string -

int main() {
	int len = strnlen(input_str); // <-

	iteration(0, len);

}

////////////////////////////////////////////////////////////////////////////////