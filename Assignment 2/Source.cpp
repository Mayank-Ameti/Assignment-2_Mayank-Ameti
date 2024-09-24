#include <iostream>
#include <fstream>
#include <vector>
#include<sstream>
#include <string>

using namespace std;

struct STUDENTDATA {
	string FirstName;
	string LastName;
};

int main() {

	ifstream Inputfile("StudentData.txt");
	if (!Inputfile.is_open()) {

		cerr << "Unable to open file!" << std::endl;
		return 1;
	}

	vector <STUDENTDATA> students;

	string line;

	// Reading each line from a file
	while (getline(Inputfile, line)) {
		istringstream parse(line);
		string FirstName, LastName;

		getline(parse, LastName, ',');
		getline(parse, FirstName);

		//Creating a Student Object
		STUDENTDATA student{ FirstName, LastName };
		//Storing into vector space
		students.push_back(student);
	}
	

	//Prints the Parsed data
#ifdef DEBUG
	for (const auto& student : students) {
		cout << "Last Name: " << student.LastName << ", First Name: " << student.FirstName << std::endl;
	}
#endif
	Inputfile.close();
	return 1;
}