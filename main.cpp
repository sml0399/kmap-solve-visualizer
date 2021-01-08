/*main.cpp*/

#include "kmap.h"

using namespace std;

int main(void) {
	string formula = "";
	vector<char> characters={};
	cout << "Enter the formula: ";
	getline(cin,formula);
	formula=preprocess(formula);
	if( !is_valid(formula) ){ cerr << "Error in the formula" << endl; return -1; }
	characters=get_eight_alpha(formula);
	if((characters.size()>8)||(characters.size()<1)){cerr<< "Error in the formula. We allow eight different alphabet characters at maximum and requires at least one alphabet"<<endl;return -1;}
	string regular_formula=convert_to_regular_alpha(formula, characters);

/*	regular_formula=formula_expansion(regular_formula);
	string solution=to_SOP(regular_formula);  

	solution=convert_to_original_alpha(solution, characters);
	cout << solution << endl;*/
	return 0;
}