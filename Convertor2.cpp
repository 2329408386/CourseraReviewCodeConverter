//coding:utf-8
//filename:Convertor2.cpp
/*
Descriptiong: This file include 2 methods' realiztion of class Convertor2
Author::Li Chengpeng
Time::Feb 7,2017
*/

#include "Convertor2.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Store the changed strings from conv1.convertedFilename to changedStrings.
void Convertor2::store2()
{
	//Get the first converted file name as the input file.
	string con1Filename = conv1.getConvertedFilename();		
	ifstream ifs(con1Filename);

	string line;
	//Read every line in con1Filename until the end of the file.
	while (getline(ifs, line))
	{
		string tempLine = line;
		int tempIntdent = indent;	//temperary record the indents.
		while (tempIntdent--)
			tempLine = "\t" + tempLine;

		//The the size of line, if its size is less than 2, it is impossible to has comments in this line.
		if (line.size() < 2)
		{
			if (line == "{")
				indent++;
			else if (line == "}")
				indent--;
			else
				;
		}
		
		//The situation when size is bigger or equal 2.
		else
		{
			//Delete the follow white lines if this line is a comment line.
			if (line[0] == '/'&&line[1] == '/')
			{
				string line2;
				do
				{
					getline(ifs, line2);
				} while (line2 == "");
				int mov = line2.size();
				ifs.seekg(-mov-2, ios::cur);
			}
		}		
				
		tempLine = tempLine + "\n";
		changedStrings.push_back(tempLine);
	}
}

//Write strings in changedStrings to secConvertedFilename.
void Convertor2::writeTo2()
{
	ofstream ofs(secConvertedFilename);
	for (vector<string>::iterator iter = changedStrings.begin(); iter != changedStrings.end(); iter++)
		ofs << *iter;
}

//Provide the entry for users to changed format of files.
//Parameter: first: the origin files' name in a vector<string>, second: the changed files' names.
void entry(const std::vector<std::string>& originFilename, const std::vector<std::string>& changedFilename)
{
	for (unsigned int i = 0; i < originFilename.size(); i++)
	{
		Convertor c(originFilename[i]);
		c.store();
		c.writeTo();

		Convertor2 c2(0,c,changedFilename[i]);
		c2.store2();
		c2.writeTo2();
		
	}
}