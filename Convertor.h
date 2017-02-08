//coding:utf-8; 
//filename: Convertor.h
/*
Description: This  file include a class declaration. this is class is to convert a file with ununiformed information to be uniformed. 
Author:Li ChengPeng
Time: Feb 6,2017
*/

#ifndef CONVERTOR_H
#define CONVERTOR_H

#include <string>
#include <vector>

class Convertor
{
public:
	//!Default constructor
	//!Convertor(){ isQuo = false; originFilename = "origin.txt"; convertedFilename = "converted.txt"; }
	
	//Parameter: ori:the original name of the file; con: the converted file's name
	Convertor(std::string ori = "origin.txt", std::string con = "converted.txt") :originFilename(ori), convertedFilename(con){ isQuo = false; }

	//store the useful chars came from the original file,including the inserted chars to usefulChars.
	void store();
	
	//write the data in usefulChars to the converted file.
	void writeTo();

	std::string getConvertedFilename(){ return convertedFilename; }

private:
	std::string originFilename;		//Store the name of original file
	std::string convertedFilename;		//Store the name of converted file
	std::vector<char> usefulChars;		//Store the useful chars
	bool isQuo;		//Use to judge if a char is between a couple of quotations

};

#endif