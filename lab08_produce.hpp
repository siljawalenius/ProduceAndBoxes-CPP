// 
// PURPOSE: Demo code to help with completion of SYDE 121::Lab Assignment #8 Part1
//          No particular optimizations applied. The code structure emphasizes simplicity.
//          The code constructs emphasize those covered in the course.
//
#ifndef LAB_08_PRODUCE_HPP
#define LAB_08_PRODUCE_HPP
#include <iostream>
#include <string>

using namespace std;

// PURPOSE: Models a generic Produce item
class Produce {
	// PURPOSE: Models Date data type; helper struct
	struct Date {
		int day, month, year;
		// inlined constructor for private data type
		Date(int new_day, int new_month, int new_year) : 
		     day(new_day), month(new_month), year(new_year) {}
	};
	// private attributes
	string item_name;
	double item_weight;
	Date item_expiry;
public:
	// PURPOSE: Default/empty constructor
	Produce();
	// PURPOSE: Parametric constructor
	Produce(string new_iname, double new_iweight, int new_eday, 
			int new_emonth, int new_eyear);
	// PURPOSE: Prints out the current Produce value
	void print();
	// PURPOSE: Overloaded operator== for the Produce object
	bool operator==(Produce& target) const;
};

// PURPOSE: Models a WinterProduce item
class WinterProduce : Produce { 
public:
	// PURPOSE: Default/empty constructor
	WinterProduce();
	// PURPOSE: Parametric constructor
	WinterProduce(string new_iname, double new_iweight, int new_eday, 
			      int new_emonth, int new_eyear);
	// PURPOSE: Prints out the current WinterProduce values
	void print();
	// PURPOSE: Overloaded operator== for the WinterProduce object
	bool operator==(WinterProduce& target) const;
};

// PURPOSE: Models a SpringProduce item
class SpringProduce : Produce { 
public:
	// PURPOSE: Default/empty constructor
	SpringProduce();
	// PURPOSE: Parametric constructor
	SpringProduce(string new_iname, double new_iweight, int new_eday, 
			      int new_emonth, int new_eyear);
	// PURPOSE: Prints out the current SpringProduce value
	void print();
	// PURPOSE: Overloaded operator== for the SpringProduce object
	bool operator==(SpringProduce& target) const;
};

// PURPOSE: Models a SummerProduce item
class SummerProduce : Produce { 
public:
	// PURPOSE: Default/empty constructor
	SummerProduce();
	// PURPOSE: Parametric constructor
	SummerProduce(string new_iname, double new_iweight, int new_eday, 
			      int new_emonth, int new_eyear);
	// PURPOSE: Prints out the current SummerProduce value
	void print();
	// PURPOSE: Overloaded operator== for the SummerProduce object
	bool operator==(SummerProduce& target) const;
};

// PURPOSE: Models a FallProduce item
class FallProduce : Produce { 
public:
	// PURPOSE: Default/empty constructor
	FallProduce();
	// PURPOSE: Parametric constructor
	FallProduce(string new_iname, double new_iweight, int new_eday, 
			    int new_emonth, int new_eyear);
	// PURPOSE: Prints out the current FallProduce value
	void print();
	// PURPOSE: Overloaded operator== for the FallProduce object
	bool operator==(FallProduce& target) const;
};
#endif
