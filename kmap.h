/*kmap.h*/
#ifndef MIN_KMAP_SOLVER_H_
#define MIN_KMAP_SOLVER_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

bool is_valid(std::string formula);
std::vector<char> get_eight_alpha(std::string formula);
std::string convert_to_regular_alpha(std::string formula, std::vector<char> characters);
std::string convert_to_original_alpha(std::string formula, std::vector<char> characters);
std::string formula_expansion(std::string formula);
std::string to_SOP(std::string formula);
std::string preprocess(std::string formula);

#endif
