#include "kmap.h"

using namespace std;

bool is_valid(string formula) {
	/* input: string typed formula, output: boolean. Return True when formula has no problem				*/
	/* check whether input form is valid. Only alphabets, +, ', paranthesis are allowed					*/
	/* tests whether formula contains only valid characters									*/
	/* checks paranthesis matching												*/
	for (size_t i = 0; i < formula.length(); i++) {
		if ((formula[i] >= 'A') && (formula[i] <= 'Z'))
			// Large Alpha
			continue;
		else if ((formula[i] >= 'a') && (formula[i] <= 'z'))
			// Small Alpha
			continue;
		else if ((formula[i] == '+') || (formula[i] == '\'') || (formula[i] == '(') || (formula[i] == ')'))
			// Special chars
			continue;
		else {
			cerr << "only alphabets, +, ', paranthesis '(' and ')' are allowed" << endl;
			return false;
		}
	}

	/*parenthesis matching test*/
	int parenthesis_counter=0;
	for (size_t i = 0; i < formula.length(); ++i) {
		if (formula[i] == '(')
			parenthesis_counter++;
		else if (formula[i] == ')')
			parenthesis_counter--;

		if (parenthesis_counter < 0) {
			cerr << "parenthesis of your formula does not match" << endl;
			return false;
		}
	}
	if (parenthesis_counter != 0) {
		cerr << "parenthesis of your formula does not match" << endl;
		return false;
	}

	return true;
}

vector<char> get_eight_alpha(string formula) {
	/* input: string typed formula, output: vector carrying chars.(eight alphabets used in the formula of user input)	*/
	/* get alphabets in the input form. Allowed upto 8 alphabets.								*/
	vector<char> char_set = {};
	for (size_t i = 0; i < formula.length(); i++) {
		if (isalpha(formula[i])) {
			bool new_alphabet = true;
			for (char c : char_set) {
				if (formula[i] == c){
					new_alphabet = false;
					break;
				}
			}
			if (new_alphabet)
				char_set.push_back(formula[i]);
		}
	}

	if ((char_set.size() > 8) || (char_set.size() < 1))
	{
		cerr << "Error in the formula. We allow eight different alphabet characters at maximum and requires at least one alphabet" << endl;
		throw "Character Set Number Error";
	}

	return char_set;
}

string convert_to_regular_alpha(string formula, vector<char> characters){
	/* input: vector carrying chars, string typed formula. output: string typed formula					*/
	/* convert user inputs to formula with fixed alphabets(a,b,c,d,e,f,g,h)							*/
	for (size_t i = 0; i < characters.size(); i++)
		replace(formula.begin(), formula.end(), characters[i], (char)(i + '0'));
	for (size_t i = 0; i < 8; i++)
		replace(formula.begin(), formula.end(), (char)(i + '0'), (char)(i + 'a'));
	return formula;
}

string convert_to_original_alpha(string formula, vector<char> characters){
	/* input: string typed formula, vector carrying chars(eight alphabet info).						*/
	/* convert result to user defined alphabets										*/
	string result="";
	for( size_t i = 0; i < formula.length(); i++ ){
		const char * character=&formula[i];
		bool not_added=true;
		for(size_t j=0;j<8;j++){
			if(('a'+j-*character)==0){
				result.push_back(characters[j]);
				not_added=false;
				break;
			}
		}
		if(not_added){result.push_back(*character);}

	}


	return result;
}

string formula_expansion(string formula){
	/*input: string typed formula, output: string typed formula that expanded the input formula*/
	/*TODO: implement formula_expansion*/

	return formula;
}

string to_SOP(string formula){
	/*input: string typed formula, output: string typed formula that satisfies minimum SOP*/
	/*TODO: implement to_SOP function*/


	return formula;
}

string preprocess(string formula){
	/* input: string typed formula, output: string typed preprocessed formula						*/
	/* preprocess: remove space character from user input									*/
	string::iterator end_pos = remove(formula.begin(), formula.end(), ' ');
	formula.erase(end_pos, formula.end());
	return formula;
}
