#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

class Chef 
{
	private:
		string id;
		string name;
		vector <string> vOrder;

	public:

		void addOrder(string order)
		{
			vOrder.emplace_back(order);
		}

		vector<string> getOrders() const { return vOrder; };
		string getName() const { return name; };
		string getId() const { return id; };

		void setOrder(vector<string> v) { vOrder = v; };
		void setName(string name) { this->name = name; };
		void setId(string id) { this->id = id; };

		Chef(string id = "0000-0000", string name = "NPC",  vector<string> v = {})
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