#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;


bool is_valid(string formula){ 
	/* input: string typed formula, output: boolean. Return True when formula has no problem				*/
	/* check whether input form is valid. Only alphabets, +, ', paranthesis are allowed					*/
	/* tests whether formula contains only valid characters									*/
	/* checks paranthesis matching												*/
	

	for( size_t i = 0; i < formula.length(); i++ ){
		const char * character=&formula[i];
		if(( (strncmp(character,"A",1) < 0 ) || 
			( ( strncmp(character,"Z",1) > 0 ) && ( strncmp(character,"a",1) < 0 ) ) || 
			( strncmp(character,"z",1) > 0 ) ) && 
			( strncmp(character,"'",1) !=0 ) && ( strncmp(character,"+",1) != 0 ) && ( strncmp(character,"(",1) !=0 ) && ( strncmp(character,")",1) !=0 )){
			cerr<<"we only allow alphabets, +, ', paranthesis '(' and ')' "<<endl;
			return false;
		}
	}
	
	/*paranthesis matching test*/
	int paranthesis_counter=0;
	for( size_t i = 0; i < formula.length(); i++ ){
		const char * character=&formula[i];
		if( strncmp(character,"(",1) ==0 ){paranthesis_counter++;}
		else if( strncmp(character,")",1) ==0 ){paranthesis_counter--;}
		if(paranthesis_counter<0){cerr<<"paranthesis of your formula does not match"<<endl;return false;}
	}
	if(paranthesis_counter!=0){cerr<<"paranthesis of your formula does not match"<<endl;return false;}



	return true;
}

vector<char> get_eight_alpha(string formula){
	/* input: string typed formula, output: vector carrying chars.(eight alphabets used in the formula of user input)	*/
	/* get alphabets in the input form. Allowed upto 8 alphabets.								*/
	vector<char> characters={};
	for( size_t i = 0; i < formula.length(); i++ ){
		const char * character=&formula[i];		
		if( ( ( strncmp(character,"A",1) >= 0 ) && ( strncmp(character,"Z",1) <= 0 ) ) || ( ( strncmp(character,"a",1) >= 0 ) && ( strncmp(character,"z",1) <= 0 ) ) ){
			bool new_alphabet=true;
			for(size_t j=0;j<characters.size();j++){
				if((characters[j] - *character)==0){
					new_alphabet=false;
					break;
				}				
			}
			if(new_alphabet){characters.push_back(*character);}
		}
	}
	return characters;
}

string convert_to_regular_alpha(string formula, vector<char> characters){ 
	/* input: vector carrying chars, string typed formula. output: string typed formula					*/
	/* convert user inputs to formula with fixed alphabets(a,b,c,d,e,f,g,h)							*/
	string result="";
	for( size_t i = 0; i < formula.length(); i++ ){
		const char * character=&formula[i];		
		bool not_added=true;
		for(size_t j=0;j<characters.size();j++){
			if((characters[j]-(*character))==0){
				result.push_back('a'+j);
				not_added=false;
				break;
			}
		}
		if(not_added){result.push_back(*character);}

	}


	return result;
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
	string result="abc";


	return result;
}

string to_SOP(string formula){
	string result="abc";


	return result;
}

string preprocess(string formula){
	/* input: string typed formula, output: string typed preprocessed formula						*/
	/* preprocess: remove space character from user input									*/
	string::iterator end_pos =remove(formula.begin(), formula.end(), ' ');
	formula.erase(end_pos, formula.end());
	return formula;
}



int main(void){ /*temporary main. This part will be removed after other functionalities are implemented*/
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
