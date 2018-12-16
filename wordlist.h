/**
 * Name: wordlist.h
 * Developer: Jude McParland
 * Date: 12-15-18
 * Email: judem6968@student.vvc.edu
 * Description: The header file for the Wordlist class. This class reads from the 
 * 	file and utilizes vectors to add and check against themsevvles to provide the 
 * 	information of how many instances of a specific word occurs in the file "alice.txt"
 * 	(onfigurable in wordlist implementation file) as well as the line numbers they occur on.
**/

#ifndef WORDLIST_H
#define WORDLIST_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <sstream>

class Wordlist
{
	std::vector<std::string> wordlist;
	std::vector<std::string> wordchecklist;
	std::vector<Wordlist> linecnt;
	std::vector<int> line;
	std::vector<int> wordcount;

	std::string wrd;
	
	public:
	Wordlist();
	Wordlist(std::string w, int ln);
	void read_word(std::ifstream &str);
	void add_to_list(std::string w);

	void track_lines();
	std::string get_wrd();
	void add_line(int ln);
	std::vector<int> get_lines();

	void add_count();
	
	void print_list();

};

#endif
