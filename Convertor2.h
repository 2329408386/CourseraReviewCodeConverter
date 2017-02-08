//coding:utf-8
//filename:Convertor2.h
/*
Description: This file include one class, this class is to add approprite indents to a line and detele the unwanted lines.
Author:Li Chengpeng
Time:Feb 7,2017
*/

#ifndef CONVERTOR2_H
#define CONVERTOR2_H

#include "Convertor.h"
#include <vector>
#include <string>

class Convertor2
{
public:
	Convertor2(int ind = 0, Convertor con=Convertor(), std::string sec = "converted2.txt") :indent(ind), conv1(con), secConvertedFilename(sec){}

	//Store the changed strings from conv1.convertedFilename to changedStrings.
	void store2();	

	//Write strings in changedStrings to secConvertedFilename.
	void writeTo2();

	//Provide the entry for users to changed format of files.
	//Parameter: first: the origin files' name in a vector<string>, second: the changed files' names.
	friend void entry(const std::vector<std::string>&,const std::vector<std::string>&);

private:
	int indent;		//record the level of indents
	Convertor conv1;
	std::string secConvertedFilename;		//the ouput file name for second convertion.
	std::vector<std::string> changedStrings;		//Store the strings witch were changed at the second time
};


#endif