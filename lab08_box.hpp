// 
// PURPOSE: Demo code to help with completion of SYDE 121::Lab Assignment #8 Part2
//          No particular optimizations applied. The code structure emphasizes simplicity.
//          The code constructs emphasize those covered in the course.
//
#ifndef LAB_08_BOX_HPP
#define LAB_08_BOX_HPP

#include <iostream>
#include <vector>
#include <fstream>

#include "lab08_produce.hpp"

using namespace std;

// PURPOSE: Models a fruits and veggies box
class FruitsAndVeggiesBox {
	// private attributes
	int order_size;
	vector<WinterProduce> winter_produce;
	vector<SpringProduce> spring_produce;
	vector<SummerProduce> summer_produce;
	vector<FallProduce> fall_produce;
	
	// private helper attributes and methods
	
	// constants that define the files with produce names
    // static keyword is used to set attribute values across all object instances
	static const string WINTER_FILE, SPRING_FILE;
	static const string SUMMER_FILE, FALL_FILE;	
	// constants that define the generation parameters for produce attributes
    // static keyword is used to set attribute values across all object instances
	static const int MAX_WEIGHT, MAX_DAY, MAX_MONTH;
	static const int MAX_YEAR_DIFF, NEXT_YEAR;

	// vectors used to store produce names loaded from files
	vector<string> winter_produce_names, spring_produce_names;
	vector<string> summer_produce_names, fall_produce_names;
    
	// vector used to store the currently available seasons 
	vector<int> produce_seasons;
    
    
	// randomly generated season, item ID, item weight, 
	// and expiry day, expiry month, & expiry year
	int rand_season, rand_item, rand_day, rand_month, rand_year;
	double rand_weight;

	// PURPOSE: Returns the number of items currently stored in the box
	int size();
    
	// PURPOSE: Removes all items if the box is already full
	void empty_the_box();
		
	// PURPOSE: Loads file contents into a vector of strings
	void file_to_vector(vector<string>& return_vector, string file_name);	
	// PURPOSE: Loads the produces names from the four files
	void load_up_produce_names();
    
	// PURPOSE: Prints the loaded names as part of verification
    void print_loaded_names();
	
	// PURPOSE: Sets current seasons based on the current month
	void assign_seasons(int current_month);

    // PURPOSE: Generates random values for the current item
    void generate_random_value(int vector_size);
    
	
	// PURPOSE: Inserts a new unique item of specific type
	void handle_winter_item();
	void handle_spring_item();
	void handle_summer_item();
	void handle_fall_item();
	// PURPOSE: Inserts a new unique item with random values into the box
	void insert_unique_item();	
	
public:
	// enumerations of order sizes, produce seasons, and produce months
	// to limit enum scope, insert "enum class"; available with C++11 extensions
	enum ORDER_SIZE {SMALL_ORDER = 5, MEDIUM_ORDER = 10, LARGE_ORDER = 15};
	enum PRODUCE_SEASONS {WINTER = 1, SPRING, SUMMER, FALL};
	enum PRODUCE_MONTHS {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
	
	// PURPOSE: Default/empty constructor
	FruitsAndVeggiesBox();

	// PURPOSE: Parametric constructor
	FruitsAndVeggiesBox(int new_order_size);


	// PURPOSE: Prints out the current FruitsAndVeggiesBox value
	void print();

	// PURPOSE: Fills the current FruitsAndVeggiesBox object
	//          with random items up to the order size
	//     INPUTS: current_month - the month when the box is generated
	void fill_the_box(int current_month);
    
    int get_size();
};
#endif
