// S120 Kowata The Person Class.cpp 
// Program that reads the name, email, phone numbers, majors, courses, grades and ids which are stored in an vector using copy constructors, 
// destructors, and a overloaded function. Added a student class based on the person class to read this information from a file and store it in a vector. 
// (Updated as of lab04)


#include <iostream>
#include "Person.h"
#include <fstream>
#include <vector>
#include "Student.h"
#include "Chef.h"
#include <map>

using namespace std;

//void experiment01();
//void experiment02();
//void experiment03();
//void experiment04();
void experiment05();

//--------------------------------------------------------------------------------------------------------
////Data used for experiment02()
//string name, email;
//vector<Person>vPeople;
//vector<Person>vEmail;
//
////Functions used for experiment02()
//vector<Person> makeDatabase();
//void showVector(vector<Person>v);
//vector<Person> emailFilter(vector<Person> v, string emailProvider);

//--------------------------------------------------------------------------------------------------------
////Data used for experiment04()
//string name, email, mainPhone, emergencyPhone, major, course, line;
////Set these datatypes later after reading it from the file to their correct datatypes
//string strSchoolId;
//int schoolId;
//string strGrade;
//char grade;
//
////Functions used for experiment04()
//vector<Student*> makeStudentDatabase();
//void showStudentDatabase(vector<Student*> db);

//--------------------------------------------------------------------------------------------------------
//Data used for experiment05()
string name, id, order;
vector<Student> vDatabase;
map <string, int> mID;
multimap <string, int> mmRoster;
int dbPos = 0;

vector<Chef> makeChefDatabase();
//template <class T1, class T2> void showMap(map<T1, T2>& m);
template <class T> void showDatabase(vector<T>& vdb, string caption = "", string terminator = " ");
//template <class T1, class T2> void showMultimap(multimap<T1, T2>& mm);

//--------------------------------------------------------------------------------------------------------
int main()
{
	//experiment01(); //Test the basic creation of the Person Class
	//experiment02(); //Test the reading and management of the Person Class from a file
	//experiment03(); //Test the copy creation of the Person Class
	//experiment04(); //Test inheritence for a student database
	experiment05();

}

//--------------------------------------------------------------------------------------------------------
//void experiment01() {
//
//	Person p1("mirabel mADRIGAL", "MM.ENCANTO@GMAIL.COM");
//	cout << " p1 " << p1.toString() << endl;
//	Person p2("BRUNO mAdRiGaL", "BM.encanto@GMAIL.com");
//	cout << " p2 " << p2.toString() << endl;
//
//}


//--------------------------------------------------------------------------------------------------------
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


//--------------------------------------------------------------------------------------------------------
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


//--------------------------------------------------------------------------------------------------------
//void experiment04()
//{
//	vector<Student*> db = makeStudentDatabase();
//	showStudentDatabase(db);
//
//	for (Student* student : db) {
//		cout << "+++ Deleting Student: " << student << " " << student->getName() << endl;
//		delete student; 
//	}
//	db.clear(); 
//	cout << "All Done!";
//}
//
////User-Defined Methods for experiment04()
//vector<Student*> makeStudentDatabase()
//{
//	vector<Student*>db;
//	ifstream myinfile;
//	myinfile.open("c:/temp/student.txt"); //This file path will change depending on the location of the file on your device
//	if (!myinfile)
//	{
//		cout << "ERROR - file not found\n";
//		exit(1);
//	}
//	while (getline(myinfile, name)) {
//		getline(myinfile, email);
//		getline(myinfile, mainPhone);
//		getline(myinfile, emergencyPhone);
//		getline(myinfile, strSchoolId);
//		schoolId = stoi(strSchoolId);
//		getline(myinfile, major);
//		Student* student = new Student(name, email, new string[2]{ mainPhone, emergencyPhone }, {}, {}, major, schoolId);
//
//
//		while (getline(myinfile, line) and line != "#")
//		{
//			string grade;
//			stringstream ss(line);
//			getline(ss, course, ' ');
//			getline(ss, grade);
//
//			student->addCourseGrade(course, grade[0]);
//		}
//		db.push_back(student);
//	}
//	return db;
//	myinfile.close();
//}
//
//void showStudentDatabase(vector<Student*> db) {
//	for (int i = 0; i < db.size(); i++)
//	{
//		cout << db[i]->toString() << endl;
//	}
//}


//--------------------------------------------------------------------------------------------------------
void experiment05() {
	makeChefDatabase();
	showDatabase(vDatabase, "Chef Database vDatabase", "\n");

	//map<string, int> mID;
	//for (int i = 0; i < vDatabase.size(); i++)
	//{
	//	string key = vDatabase[i].getId();
	//	mID[key] = i;
	//}
	//cout << "\nMap mID [Key: ID]\n";
	//showMap(mID);

	//multimap <string, int> mmRoster;

	//for (int i = 0; i < vDatabase.size(); i++) {
	//	vector<string> vCourse = vDatabase[i].getCourse();
	//	for (int j = 0; j < vCourse.size(); j++) {
	//		string key = vCourse[j];
	//		mmRoster.insert(make_pair(key, i));
	//	}
	//}

	//cout << "\nMultimap mmRoster [Key: Course]\n";

	//showMultimap(mmRoster);

	//Check by id
	//do
	//{
	//	cout << "\nEnter id value [0000-0000 to end]: ";
	//	string id;
	//	getline(cin, id);
	//	if (id == "0000-0000") break;
	//	if (mID.count(id) == 0)
	//		cout << "Id not found in the database - try again\n";
	//	else
	//		cout << mID[id] << "\t" << vDatabase[mID[id]] << endl;

	//} while (true);

	//Check by classes
	//do
	//{
	//	cout << "\nEnter class value [NONE to end]: ";
	//	string course;
	//	int num = 0;
	//	getline(cin, course);
	//	if (course == "NONE") break;
	//	if (mmRoster.count(course) == 0)
	//		cout << "Class not found in the database - try again\n";
	//	else
	//		for (auto row : mmRoster) {
	//			if (row.first == course) {
	//				cout << course << "\t" << vDatabase[row.second] << endl;
	//			}
	//		}

	//} while (true);

	cout << "\nAll Done!\n";
}

//User-Defined Methods for experiment05()
vector<Chef> makeChefDatabase()
{
	ifstream myinfile;
	myinfile.open("c:/temp/StudentCourseLoad.txt"); //This file path will change depending on the location of the file on your device
	if (!myinfile)
	{
		cout << "ERROR - file not found\n";
		exit(1);
	}
	while (getline(myinfile, id)) {
		getline(myinfile, name);

		Chef chef(id, name);
		while (getline(myinfile, order) and order != "#")
		{
			chef.addOrder(order);
		}
		vDatabase.push_back(chef);

	}
	return vDatabase;
	myinfile.close();
}

template <class T1, class T2> void showMap(map<T1, T2>& m) {

	for (auto row : m) {
		cout << row.first << "\t" << row.second << endl;
	}
}

template <class T1, class T2> void showMultimap(multimap<T1, T2>& mm) {
	for (auto row : mm) {
		cout << row.first << "\t" << row.second << endl;
	}
}

template <class T> void showDatabase(vector<T>& vdb, string caption, string terminator) {
	cout << endl << caption << endl;
	int dbPos = 0;
	for (T obj : vdb) {
		cout << dbPos++ << "\t" << obj << terminator;
	}
	cout << endl;
}
