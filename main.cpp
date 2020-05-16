#include "md5.hpp"
#include <iostream>
#include <fstream>
#include <string>

/*------------------------------------------------
MD5 HASH generator.

Author: Helio Nunes Santos
Date: 05/13/2020
Version: 1.0
License: MIT

--------------------------------------------------*/

void show_help() {
	std::cout << "1- MD5HASH -s <string>\nTo generate a hash for a given string.\n";
	std::cout << "2- MD5HASH -f <filepath>\nTo generate a hash for a given file.\n";
	std::cout << "3- MD5HASH -h \nTo show this help.\n";
}

int main(int argc, char** argv) {	
	try {
		//Handle arguments
		if (argc != 3) {
			show_help();
		}
		else {
			if (!strcmp(argv[1], "-s")) {
				std::string str;
				if (argc == 3)
					str = argv[2];
					
				std::cout << MD5(str).get_string_hash() << "\n";
			}
			else if (!strcmp(argv[1], "-f")) {
				if (argc != 3)
					throw std::runtime_error("Missing filepath argument.");
				
				std::ifstream file(argv[2]);
				if (file.is_open())
					std::cout << MD5(file).get_string_hash() << "\n";
				else
					throw std::runtime_error("File could not be open. Check filepath or file/folder permissions.");
			}
			else {
				show_help();
			}
		}
	}
	catch (std::runtime_error &e) {
		std::cout << e.what() << "\n";
	}
} 