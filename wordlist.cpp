/**
 * Name: wordlist.cpp
 * Developer: Jude McParland
 * Date: 12-15-18
 * Email: judem6968@student.vvc.edu
 * Description: This file provides the implementation for the word list. 
 * 	This actually does the work of the concordance generator.
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

// This constructers and following member fxns deal with std::vector<Wordlist> linecnt vector.

Wordlist::Wordlist()
{
	wrd = "";
}

Wordlist::Wordlist(std::string w, int ln)
{
	wrd = w;
	line.push_back(ln);
}

std::string Wordlist::get_wrd()
{
	return wrd;
}

void Wordlist::add_line(int ln)
{
	line.push_back(ln);
}

std::vector<int> Wordlist::get_lines()
{
	return line;
}

// Concordance Fxns.
//The following function reads all the words

void Wordlist::read_word(std::ifstream &str)
{
	while(!str.eof())
		{
			std::string word;
			str >> word;

		   	//	I used these following member functions of std::string / std:: library as it was the 
			//	only thing that I could get to work with my iplementation. 
			//
	 		//	It seemed like a basic function because it just searched the starting character of 
 			//	a string for punctuation and erased it and for every character left behind, it transformed 
 			//	it to lowercase per index. This is what I got as a result of research to help me because I was stuck here. :( 
			
			word.erase(std::remove_if(word.begin(),word.end(), ::ispunct) , word.end());
			std::transform(word.begin(),word.end(), word.begin(),::tolower);
			
			add_to_list(word);
			wordchecklist.push_back(word);
		}
}


//This function adds the unique words to a vector list.

void Wordlist::add_to_list(std::string w)
{
	if(!(find(wordlist.begin(),wordlist.end(),w) != wordlist.end()))
		{
			wordlist.push_back(w);
		}
}


//This detects how many times a word occurs in the file and adds it to a list.

void Wordlist::add_count()
{	
	int count = 0;
	for(int i=0;i<wordlist.size();i++)
		{
					for(int j=0;j<wordchecklist.size();j++)
					{
						if(wordchecklist[j] == wordlist[i])
							count++;
					}
					
					wordcount.push_back(count);
					count = 0;
		}

}

//This tracks the lines the occurances of a words occurs on.

void Wordlist::track_lines()
{
	std::string ln;
	std::ifstream str("alice.txt");

	int lnum = 0;
	while(!str.eof())
	{
		getline(str,ln);
		ln.erase(std::remove_if(ln.begin(),ln.end(), ::ispunct) , ln.end());
		std::transform(ln.begin(),ln.end(), ln.begin(),::tolower);
		lnum++;
		std::istringstream stream(ln);
		while(!stream.eof())
			{
				std::string word;
				stream >> word;
				for(int i=0;i<wordlist.size();i++)
				{
					if(wordlist[i] == word && word != " " && word != "" )
						{

							if(linecnt.size() == 0)
								{
									linecnt.push_back(Wordlist(wordlist[i],lnum));
									
								}
							else 
								{
									for(int m=0;m<linecnt.size();m++)
									{
										std::vector<int> linetest = linecnt[m].get_lines(); //Tests if line reported.
										if(linecnt[m].get_wrd() == wordlist[i])
											{
												linecnt[m].add_line(lnum);
												break;
											}	
										else if(m == linecnt.size()-1)
											{
												linecnt.push_back(Wordlist(wordlist[i],lnum));
												break;
											}	
									}
								}
						
						}
				}
			}
	}
	
str.close();
}

//This prints the concondrance list.

void Wordlist::print_list()
{
	std::cout << std::endl;
	for(int i=0;i<wordlist.size()-1;i++)
		{
		//	std::cout << wordlist[i] << " : " << wordcount[i] << " : ";
			std::cout << "Word: " << "'"<<  linecnt[i].get_wrd() << "' : " << wordcount[i] << " : ";
			std::vector<int> lines = linecnt[i].get_lines();
			for(int z=0;z<lines.size();z++)
				{
					if(wordcount[i] >= 2) //If there are at least 2 instances of the word, we need commas for line #'s
						if(z == lines.size()-1) //Last line # doesn't need comma.
							std::cout << " " << lines[z];
						else
							std::cout << " " << lines[z] << ", "; 
					else
						std::cout << " " << lines[z];
				}

			std::cout << std::endl;
		}
	std::cout << std::endl;
}

