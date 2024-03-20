#pragma once
#include <iostream>
#include <string>
#include <sstream>  
using namespace std;
class Person
{
private:
	//Data members
	string name;
	string email;
	string* phones = new string[2];

public:
	//Mutators (accept and validate user supplied data)
	void setName(string nameValue)
	{
		name = titleCaps(nameValue);
	}

	void setEmail(string emailValue) 
	{
		email = toLower(emailValue);
	}

	void setEmergencyPhone(string Ephone)
	{
		phones[1] = Ephone;
	}

	void setMainPhone(string Mphone)
	{
		phones[0] = Mphone;
	}

	void setPhones(string Mphone, string Ephone)
	{
		phones[0] = Mphone; //Same as *phones = Mphone
		phones[1] = Ephone; //Same as *(phone++) = Ephone
	}

	//Accessors
	string getName() const { return name; }
	string getEmail() const { return email; }
	string getEmergencyPhone() const { return phones[1]; }
	string getMainPhone() const { return phones[0]; }
	string *getPhones() const { return phones; } 

	//Constructors
	//All-Arguments Constructor
	Person(string nameValue = "NA", string emailValue = "none", string Mphone = "none", string Ephone = "none")
	{
		setName(nameValue);
		setEmail(emailValue);
		setMainPhone(Mphone);
		setEmergencyPhone(Ephone);
	}

	//Copy Constructor 
	Person(const Person& sourcePerson) //Pass an item by reference
	{
		*this = sourcePerson;
	}

	//Destructor
	~Person()
	{
		//cout << "Debug - Person Phones Destroyed: " << phones << endl; //Allocate space afterwards
		delete[] phones;
	}

	//User-Defined Methods
	string toUpper(string name)
	{
	for (int i = 0; i < name.length(); i++){
		name[i] = toupper(name[i]);
	}
	return name;
	}

	string toLower(string email)
	{
	for (int i = 0; i < email.length(); i++) {
		email[i] = tolower(email[i]);
	}
	return email;
	}

	string titleCaps(string name)
	{
		bool newName = false;
		for (int i = 0; i < name.length(); i++) {

			if (i == 0)
			{
				name[i] = toupper(name[i]);
			}
			else if (newName == true)
			{
				name[i] = toupper(name[i]);
				newName = false;
			}
			else if(name[i] == ' ')
			{
				newName = true;
			}
			else
			{
				name[i] = tolower(name[i]);
			}
		}
		return name;
	}

	string toString()
	{
		stringstream sout;
		sout << this << " Person [ Name: " << getName()
			<< ", Email: " << getEmail() << "\n\t\t"
			<< "Phones at: " << getPhones() << ", Main Phone: " << phones[0] 
			<< ", Emergency Phone: " << phones[1] << "]" << "\n";
		return sout.str();
	}

	//Overload Operators
	void operator = (const Person& other) //Access by reference and don't change anything (const)
	{
		setName(other.name);
		setEmail(other.email);
		this->phones = new string[2];
		setPhones(other.phones[0], other.phones[1]);

	}
};

