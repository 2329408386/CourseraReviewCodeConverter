//codiing:utf-8;
//filename:Convertor.cpp
/*
Description: This file include the concrete realization of class "Convertor".
Author:Li Chengpeng
Time£» Feb 2,2017
*/

#include "Convertor.h"
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

//store the useful chars came from the original file,including the inserted chars to usefulChars.
void Convertor::store()
{
	usefulChars.clear();
	ifstream ifs(originFilename);
	ifs >> noskipws;
	char c;

	//input every char in originFilename to c until the end of the file
	while (ifs >> c)
	{
		if (c == '\"')
		{
			isQuo = !isQuo;
			//usefulChars.push_back(c);
		}

		//: if c is in a couple of quotations
		if (isQuo)
		{
			usefulChars.push_back(c);
		}

		else
		{
			// if meet '/', check the next char, if it's also a '/', prove it's a comment, so add a new line before it, else do as normal.
			if (c == '/')
			{
				char c2;
				ifs >> c2;

				//judge the c2, so that it can decide if the quotation is in couple
				if (c2 == '\"')
					isQuo = !isQuo;

				if (c2 == '/')
				{
					usefulChars.push_back('\n');
					usefulChars.push_back(c);
					usefulChars.push_back(c2);

					while (true)
					{
						char c3, c4;
						ifs >> c3; ifs >> c4;
						if (c3 == '\n' || c4 == '\n')
							break;

						if (c3 == ' '&&c4 == ' ')
						{
							usefulChars.push_back('\n'); break;
						}

						else if (c3 != ' '&& c4 == ' ')
						{
							usefulChars.push_back(c3); ifs >> c3;
							if (c3 == ' ')
							{
								usefulChars.push_back('\n'); break;
							}
							else
							{
								usefulChars.push_back(c4); usefulChars.push_back(c3);
							}
						}
						else if (c3 == '/'&&c4 == '/')
						{
							usefulChars.push_back('\n'); usefulChars.push_back(c3); usefulChars.push_back(c4);
						}
						else if (c3 != '/'&&c4 == '/')
						{
							ifs >> c3;
							if (c3 == '/')
							{
								usefulChars.push_back('\n'); usefulChars.push_back(c4); usefulChars.push_back(c3); break;
							}
							else
							{
								usefulChars.push_back(c4); usefulChars.push_back(c3);
							}
						}
						else
						{
							usefulChars.push_back(c3); usefulChars.push_back(c4);
						}

					}
				}
				else
				{
					usefulChars.push_back(c);
					usefulChars.push_back(c2);
				}

			}

			// if meet ';',add a new line after it
			else if (c == ';')
			{
				usefulChars.push_back(c);
				usefulChars.push_back('\n');
			}

			//if meet '{' or '}',add a new line before it
			else if (c == '{' || c == '}')
			{
				usefulChars.push_back('\n');
				usefulChars.push_back(c);
			}

			// if meet a space, check the next char, if it's also a space, then replace the two spaces with a new line. If it's not space, just keep the two chars as normal.
			else if (c == ' ')
			{
				char c2;
				ifs >> c2;
				
				//judge the c2, so that it can decide if the quotation is in couple
				if (c2 == '\"')
					isQuo = !isQuo;
				
				if (c2 == ' ')
				{
					usefulChars.push_back('\n');
					while (c2 == ' ')
					{
						ifs >> c2;
					}
					//!usefulChars.push_back(c2);
					ifs.seekg(-1, ios::cur);
				}
				else
				{
					usefulChars.push_back(c);
					ifs.seekg(-1, ios::cur);
				}

			}

			

			// If the situation is not above, just do as normal.
			else
			{
				usefulChars.push_back(c);
			}
		}
	}
}

//write the data in usefulChars to the converted file.
void Convertor::writeTo()
{
	ofstream ofs(convertedFilename);
	for (vector<char>::iterator i = usefulChars.begin(); i != usefulChars.end(); i++)
	{
		ofs << *i;
	}
}
