//MayankAmeti - CSCN73030 - Fall 2024 - Assignment 2 #
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct STUDENTDATA {
	string FirstName;
	string LastName;
	string StudentEmail; // Added student Email
};

int main() {

#ifdef PRE_RELEASE
	cout << "PreRelease Version Source Code Is Running Now" << endl;
	ifstream Inputfile("StudentData_Emails.txt");//Reads when  Pre-Release mode is enabled
#else
	cout << "Standard Version Source Code Is Running Now" << endl;
	ifstream Inputfile("StudentData.txt"); // Reads when pre-release mode is disabled 
#endif

	//open file
	if (!Inputfile.is_open()) {

		cerr << "Unable to open file!" << std::endl;
		return 1;
	}

	vector <STUDENTDATA> students;

	string line;

	// Reading each line from a file
	while (getline(Inputfile, line)) {
		istringstream parse(line);
		string FirstName, LastName,StudentEmail;

		getline(parse, LastName, ',');
		getline(parse, FirstName,',');

		#ifdef PRE_RELEASE
		getline(parse, StudentEmail);  // Read email if in pre-release mode
		#endif
		//Creating a Student Object
		STUDENTDATA student{ FirstName, LastName , StudentEmail };
		//Storing into vector space
		students.push_back(student);
	}
	

	
#ifdef DEBUG
	for (const auto& student : students) {
		cout << "Last Name: " << student.LastName << ", First Name: " << student.FirstName << " , Email: " << student.StudentEmail << endl;
	}
#endif
	
	//close file
	Inputfile.close();
	
	return 1;
}