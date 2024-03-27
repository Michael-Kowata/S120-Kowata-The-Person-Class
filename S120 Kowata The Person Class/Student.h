#pragma once
#include "Person.h"
#include <vector>
#include <iomanip>

class Student : public Person
{
private:
	vector<string> course;
	vector<char> grade;
	string major;
	int schoolId;

public:
	//Mutators 
	void setCourses(vector<string>& vCourse)
	{
		course = vCourse;
	}

	void setGrades(vector<char>& vGrade)
	{
		grade = vGrade;
	}

	void setMajor(string majorValue)
	{
		major = titleCaps(majorValue);
	}

	void setSchoolId(int idValue)
	{
		schoolId = idValue;
	}

	//Accessors
	vector<string> getCourses() const { return course; }
	vector<char> getGrades() const { return grade; }
	string getMajor() const { return major; }
	int getSchoolId() const { return schoolId; }

	//Constructors
	//All-Arguments Constructor (setting up phones all at once)
	Student(string nameValue, string emailValue, string* phones,
		vector<string> vCourse, vector<char> vGrade, string majorValue = "N.A.", int idValue = 000)
		:Person(nameValue, emailValue, phones)
	{
		setCourses(vCourse);
		setGrades(vGrade);
		setMajor(majorValue);
		setSchoolId(idValue);
	}


	//All-Arguments Constructor (setting up phones individually)
	Student(string nameValue, string emailValue, string mainPhone, string emergencyPhone,
		vector<string> vCourse, vector<char> vGrade, string majorValue = "N.A.", int idValue = 000)
		:Person(nameValue, emailValue, mainPhone, emergencyPhone)
	{
		setCourses(vCourse);
		setGrades(vGrade);
		setMajor(majorValue);
		setSchoolId(idValue);
	}

	//User-Defined Methods 
	string toString() 
	{
		stringstream sout;
		sout << this << " Student [ Id: " << getSchoolId() << ", Name: " << getName()
			<< ", Email: " << getEmail() << "\n\t\t" << " PhoneArray Adr: " << getPhones() <<
			", Main Phone: " << getMainPhone() << ", Emergency Phone: " << getEmergencyPhone() <<
			"\n\t\t Major: " << getMajor() << "\n\t\t";

		vector<string> courses = getCourses();
		vector<char> grades = getGrades();

			if (courses.size() == grades.size()) {
				for (int i = 0; i < courses.size(); i++) {
					sout << setw(16);
					sout << " Course: " << courses[i] << "\t\t" << " Grade: " << grades[i];
					sout << "\n\t\t";
				}
			}
			else {
				sout << " No data available. Mismatch of courses and grades.";
			}
			sout << " ]" ;
		return sout.str();
	}
	
	void addCourseGrade(string courseName, char finalGrade) {
		course.emplace_back(courseName);
		grade.emplace_back(finalGrade);

	}

	void setCourse(vector<string> newCourses) {
		course = newCourses;
	}

	void setGrade(vector<char> newGrades) {
		grade = newGrades;
	}

};

