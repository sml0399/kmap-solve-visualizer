#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;


bool is_valid(string formula){
	string A="A";
	string a="a";
	string Z="Z";
	string z="z";
	string plus="+";
	string not_="'";
	for( int i = 0; i < formula.size(); i++ ){
		// FIX: indexing returns char, not std::string. Need to convert back to std::string if you really want to use compare.
		if( ( ( std::string(1, formula[i]).compare(A)) < 0 ) || ( ( std::string(1, formula[i]).compare(Z) > 0 ) && ( std::string(1, formula[i]).compare(a) < 0 ) ) || ( std::string(1, formula[i]).compare(z) > 0 ) ) && ( std::string(1, formula[i]).compare(not_) !=0 ) && ( std::string(1, formula[i]).compare(plus) != 0 ) ){
			return false;
		}
	}
	return true;
}

string get_eight_alpha(string formula){


	return "";
}

string convert_to_eight_alpha(string formula){




	return "";
}
/*
string to_SOP(string formula){



	return 
}


*/


int main(void){
	string formula = "";
	cout << "enter the formula" << endl;
	cin >> formula;
	if( !is_valid ){ cout << "error in the formula" << endl; return -1; }

	cout << formula << endl;
	return 0;




}
