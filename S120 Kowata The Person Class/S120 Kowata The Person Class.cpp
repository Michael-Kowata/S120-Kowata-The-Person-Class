// S120 Kowata The Person Class.cpp 
// Program that reads the name, email, phone numbers, majors, courses, grades and ids which are stored in an vector using copy constructors, 
// destructors, and a overloaded function. Added a student class based on the person class to read this information from a file and store it in a vector. 
// (Updated as of lab04)


#include <iostream>
#include "Person.h"
#include <fstream>
#include <vector>
#include "Student.h"

using namespace std;

//void experiment01();
//void experiment02();
//void experiment03();
void experiment04();

////Data used for experiment02()
//string name, email;
//vector<Person>vPeople;
//vector<Person>vEmail;
//
////Functions used for experiment02()
//vector<Person> makeDatabase();
//void showVector(vector<Person>v);
//vector<Person> emailFilter(vector<Person> v, string emailProvider);


//Data used for experiment04()
string name, email, mainPhone, emergencyPhone, major, course, line;
//Set these datatypes later after reading it from the file to their correct datatypes
string strSchoolId;
int schoolId;
string strGrade;
char grade;

//Functions used for experiment04()
vector<Student*> makeStudentDatabase();
void showStudentDatabase(vector<Student*> db);

int main()
{
	//experiment01(); //Test the basic creation of the Person Class
	//experiment02(); //Test the reading and management of the Person Class from a file
	//experiment03(); //Test the copy creation of the Person Class
	experiment04(); //Test inheritence for a student database

}


//void experiment01() {
//
//	Person p1("mirabel mADRIGAL", "MM.ENCANTO@GMAIL.COM");
//	cout << " p1 " << p1.toString() << endl;
//	Person p2("BRUNO mAdRiGaL", "BM.encanto@GMAIL.com");
//	cout << " p2 " << p2.toString() << endl;
//
//}

//void experiment02() {
//	makeDatabase();
//	cout << "In order of the file listing: " << endl;
//	showVector(vPeople);
//	cout << "\n\n";
//	cout << "In order of gmail, hotmail, then aol: " << endl;
//	showVector(emailFilter(vPeople, "gmail"));
//	showVector(emailFilter(vPeople, "hotmail"));
//	showVector(emailFilter(vPeople, "aol"));
//}

////User-Defined Methods for experiment02()
//vector<Person> makeDatabase()
//{
//	ifstream myinfile;
//	myinfile.open("c:/temp/people.txt"); //This file path will change depending on the location of the file on your device
//	if (!myinfile)
//	{
//		cout << "ERROR - file not found\n";
//		exit(1);
//	}
//	while (getline(myinfile, name)) {
//		getline(myinfile, email);
//		vPeople.push_back(Person(name, email));
//	}
//	return vPeople;
//	myinfile.close();
//}

//void showVector(vector<Person>v)
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i].toString() << endl;
//	}
//}
//
//vector<Person> emailFilter(vector<Person> v, string emailProvider)
//{
//	vEmail.clear();
//	for (int i = 0; i < vPeople.size(); i++)
//	{
//		email = vPeople[i].getEmail();
//		name = vPeople[i].getName();
//		if (email.find(emailProvider) != std::string::npos)
//		{
//			vEmail.push_back(Person(name, email));
//		}
//	}
//	return vEmail;
//}

//void experiment03() {
//	// Test the zero - argument constructor
//	Person p1;
//	cout << "p1: " << p1.toString() << endl;
//
//	// test the all - arguments constructor
//	Person p2("bart simPSON", "bart@aol.com", "555-1234", "555-0000");
//	cout << "p2: " << p2.toString() << endl;
//
//	//test the copy constructor (p3 is a clone of p2)
//	Person p3(p2);
//	cout << "p3: " << p3.toString() << endl;
//
//	//test the overloaded assignment operator (p3 is a clone of p1)
//	p3 = p1;
//	cout << "p3: " << p3.toString() << endl;
//
//	// test the mutators
//	p3.setName("homer simpson");
//	p3.setMainPhone("555-9999");
//	p3.setEmergencyPhone("555-0000");
//
//	//Compare p1 and its clone p3
//	cout << "p1: " << p1.toString() << endl;
//	cout << "p3: " << p3.toString() << endl;
//	std::cout << "\nAll done!\n";
//}

void experiment04()
{
	vector<Student*> db = makeStudentDatabase();
	showStudentDatabase(db);

	for (Student* student : db) {
		cout << "+++ Deleting Student: " << student << " " << student->getName() << endl;
		delete student; 
	}
	db.clear(); 
	cout << "All Done!";
}

//User-Defined Methods for experiment04()
vector<Student*> makeStudentDatabase()
{
	vector<Student*>db;
	ifstream myinfile;
	myinfile.open("c:/temp/student.txt"); //This file path will change depending on the location of the file on your device
	if (!myinfile)
	{
		cout << "ERROR - file not found\n";
		exit(1);
	}
	while (getline(myinfile, name)) {
		getline(myinfile, email);
		getline(myinfile, mainPhone);
		getline(myinfile, emergencyPhone);
		getline(myinfile, strSchoolId);
		schoolId = stoi(strSchoolId);
		getline(myinfile, major);
		Student* student = new Student(name, email, new string[2]{ mainPhone, emergencyPhone }, {}, {}, major, schoolId);


		while (getline(myinfile, line) and line != "#")
		{
			string grade;
			stringstream ss(line);
			getline(ss, course, ' ');
			getline(ss, grade);

			student->addCourseGrade(course, grade[0]);
		}
		db.push_back(student);
	}
	return db;
	myinfile.close();
}

void showStudentDatabase(vector<Student*> db) {
	for (int i = 0; i < db.size(); i++)
	{
		cout << db[i]->toString() << endl;
	}
}

