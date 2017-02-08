//coding:utf-8
//filename:test.cpp

/*
Description:This file is to test the use of class Convertor
Author: Li Chengpeng
Time: Feb 2,2017
*/

#include "Convertor.h"
#include "Convertor2.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    void entry(const std::vector<std::string>&,const std::vector<std::string>&);
	//The file names which you want to change the content.
	//vector<string> student = { "student1.txt", "student2.txt", "student3.txt", "student4.txt", "student5.txt" };
	vector<string> student = { "student5.txt" };

	//The file names which you want to store the new message.
	vector<string> cStu;
	for (vector<string>::iterator iter = student.begin(); iter != student.end(); iter++)
		cStu.push_back("changed_" + *iter);

	//Provide the entry for users to changed format of files.
	//Parameter: first: the origin files' name in a vector<string>, second: the changed files' names.
	entry(student, cStu);
}
