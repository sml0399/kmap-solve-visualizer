#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

using namespace std;


bool is_valid(string formula){ /*check whether input form is valid. Only alphabets, +, ' are allowed*/
	for( int i = 0; i < formula.length(); i++ ){
		const char * character=&formula[i];
		// FIX: indexing returns char, not std::string. Need to convert back to std::string if you really want to use compare.
		if(( (strncmp(character,"A",1) < 0 ) || ( ( strncmp(character,"Z",1) > 0 ) && ( strncmp(character,"a",1) < 0 ) ) || ( strncmp(character,"z",1) > 0 ) ) && ( strncmp(character,"'",1) !=0 ) && ( strncmp(character,"+",1) != 0 ) ){
			return false;
		}
	}
	return true;
}

vector<char> get_eight_alpha(string formula){/*get alphabets in the input form. Allowed upto 8 alphabets.*/
	vector<char> characters={};
	

	return characters;
}

string convert_to_regular_alpha(string formula){ /*convert user inputs using fixed alphabets(a,b,c,d,e,f,g,h)*/




	return "";
}
/*
string to_SOP(string formula){



	return ;
}


*/


int main(void){ /*temporary main. This part will be removed after other functionalities are implemented*/
	string formula = "";
	cout << "Enter the formula: ";
	cin >> formula;
	if( !is_valid(formula) ){ cout << "Error in the formula" << endl; return -1; }

	cout << formula << endl;
	return 0;




}
