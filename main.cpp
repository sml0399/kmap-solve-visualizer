/*main.cpp*/

#include "kmap.h"

using namespace std;

int main(void) {
	string formula = "";
	vector<char> char_set = {};
	
	cout << "Enter the formula: ";
	getline(cin, formula);

	formula = preprocess(formula);
	// cout << formula << endl;

	if (!is_valid(formula)) {
		cerr << "Error in the formula" << endl;
		return -1;
	}

	try {
		char_set = get_eight_alpha(formula);
	} catch (const char* msg) {
		return -1;
	}

	for (char c : char_set)
		cout << c << endl;

	string regular_formula = convert_to_regular_alpha(formula, char_set);
	cout << regular_formula << endl;

/*	regular_formula=formula_expansion(regular_formula);
	string solution=to_SOP(regular_formula);  

	solution=convert_to_original_alpha(solution, characters);
	cout << solution << endl;*/
	return 0;
}