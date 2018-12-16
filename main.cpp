/**
 * Name: main.cpp
 * Developer: Jude McParland
 * Date: 12-15-18
 * Emai:judem6968@student.vvc.edu
 * Description: The main file of the Concordance program. 
 *  This calls all the Wordlist Memeber Class functions and reads the file "alice.txt" 
 *  as it was designed for. You can change this here and in Wordlist implementation file. 
 **/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <sstream>
#include "wordlist.h"

int main()
{
	std::ifstream input("alice.txt");
	if(input.fail())
		std::cout << "Error, cannot access alice.txt, has it gone down the rabbit hole?" << std::endl;
	else
		{
			std::cout << "File has been accessed! But no time to wait...Im late!" << std::endl;
		}
		
	Wordlist w;
	w.read_word(input);
	w.add_count();
	w.track_lines();
	std::cout << std::endl << "##### Concordance Started ##### " << std::endl;
	w.print_list();
	return 0;
}
