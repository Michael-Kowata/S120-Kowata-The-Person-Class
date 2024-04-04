#pragma once
#include "Person.h"
#include <vector>
#include <iomanip>

class Student : public Person
{
	private:
		vector <string> vOrder;

	public:

		void addOrder(string order)
		{
			vOrder.emplace_back(order);
		}

		vector<string> getOrders() const { return vOrder; };
		//string getName() const { return name; };
		//string getId() const { return id; };

		void setCourse(vector<string> v) { vOrder = v; };
		//void setName(string name) { this->name = name; };
		//void setId(string id) { this->id = id; };

		Chef(string nameValue, string emailValue, string id = "0000-0000", vector<string> v)
			:Person(nameValue, emailValue)
		{
			setOrder(v);
			setName(name);
			setId(id);
		}

		string toString() const {
			vector<string> orders = getOrders();
			stringstream sout;
			sout << this << " Person [ Id: " << getId()
				<< ", Name: " << getName() << ", Orders: {";

			for (int i = 0; i < orders.size(); i++) {
				sout << orders[i] << ", ";
			}
			sout << "} ]";
			return sout.str();
		}

		friend ostream& operator << (ostream& sout, const Chef& c) { //Only promise not to change Company
			sout << c.toString();
			return sout;
		}
};