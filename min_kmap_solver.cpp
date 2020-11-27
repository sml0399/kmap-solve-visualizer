#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

using namespace std;


bool is_valid(string formula){
	for( int i = 0; i < formula.length(); i++ ){
		const char * character=&formula[i];
		// FIX: indexing returns char, not std::string. Need to convert back to std::string if you really want to use compare.
		if(( (strncmp(character,"A",1) < 0 ) || ( ( strncmp(character,"Z",1) > 0 ) && ( strncmp(character,"a",1) < 0 ) ) || ( strncmp(character,"z",1) > 0 ) ) && ( strncmp(character,"'",1) !=0 ) && ( strncmp(character,"+",1) != 0 ) ){
			return false;
		}
	}
	return true;
}

vector<char> get_eight_alpha(string formula){
	vector<char> characters={};
	

	return characters;
}

string convert_to_eight_alpha(string formula){




	return "";
}
/*
string to_SOP(string formula){



	return ;
}


*/


int main(void){
	string formula = "";
	cout << "Enter the formula: ";
	cin >> formula;
	if( !is_valid(formula) ){ cout << "Error in the formula" << endl; return -1; }

	cout << formula << endl;
	return 0;




}
