// 
// PURPOSE: Demo code to help with completion of SYDE 121::Lab Assignment #8 Part1
//          No particular optimizations applied. The code structure emphasizes simplicity.
//          The code constructs emphasize those covered in the course.
//
#include <iostream>

#include "lab08_produce.hpp"

using namespace std;

Produce::Produce() : item_name("n/a"), item_weight(0), item_expiry(1,1,2000) {
}

Produce::Produce(string new_iname, double new_iweight, int new_eday, 
			int new_emonth, int new_eyear) : item_name(new_iname), 
			item_weight(new_iweight), item_expiry(new_eday, new_emonth, new_eyear) {
}

void Produce::print() {
	cout << "Item Name: " << item_name << endl;
	cout << "Item Weight: " << item_weight << endl;
	cout << "Item Expiry: " << item_expiry.day << "/" << item_expiry.month 
	     << "/" << item_expiry.year << endl;
}

bool Produce::operator==(Produce& target) const {
	bool are_equal = false;
	are_equal = item_name == target.item_name;
	are_equal = are_equal && item_weight == target.item_weight;
	are_equal = are_equal && item_expiry.day == target.item_expiry.day;
	are_equal = are_equal && item_expiry.month == target.item_expiry.month;
	are_equal = are_equal && item_expiry.year == target.item_expiry.year;
	return are_equal;
}

WinterProduce::WinterProduce() {}

WinterProduce::WinterProduce(string new_iname, double new_iweight, int new_eday, 
			int new_emonth, int new_eyear) : Produce(new_iname, new_iweight, new_eday,
			new_emonth, new_eyear) {}


void WinterProduce::print() {
	cout << "[Winter Produce Item]" << endl;
	Produce::print();
}

bool WinterProduce::operator==(WinterProduce& target) const {
	// no additional attributes in the derived class, so compare the base class only
	return static_cast<Produce>(*this) == static_cast<Produce&>(target);
}

SpringProduce::SpringProduce() {}

SpringProduce::SpringProduce(string new_iname, double new_iweight, int new_eday, 
			int new_emonth, int new_eyear) : Produce(new_iname, new_iweight, new_eday,
			new_emonth, new_eyear) {}


void SpringProduce::print() {
	cout << "[Spring Produce Item]" << endl;
	Produce::print();
}

bool SpringProduce::operator==(SpringProduce& target) const {
	// no additional attributes in the derived class, so compare the base class only
	return static_cast<Produce>(*this) == static_cast<Produce&>(target);
}

SummerProduce::SummerProduce() {}

SummerProduce::SummerProduce(string new_iname, double new_iweight, int new_eday, 
			int new_emonth, int new_eyear) : Produce(new_iname, new_iweight, new_eday,
			new_emonth, new_eyear) {}


void SummerProduce::print() {
	cout << "[Summer Produce Item]" << endl;
	Produce::print();
}

bool SummerProduce::operator==(SummerProduce& target) const {
	// no additional attributes in the derived class, so compare the base class only
	return static_cast<Produce>(*this) == static_cast<Produce&>(target);
}

FallProduce::FallProduce() {}

FallProduce::FallProduce(string new_iname, double new_iweight, int new_eday, 
			int new_emonth, int new_eyear) : Produce(new_iname, new_iweight, new_eday,
			new_emonth, new_eyear) {}


void FallProduce::print() {
	cout << "[Fall Produce Item]" << endl;
	Produce::print();
}

bool FallProduce::operator==(FallProduce& target) const {
	// no additional attributes in the derived class, so compare the base class only
	return static_cast<Produce>(*this) == static_cast<Produce&>(target);
}

