// 
// PURPOSE: Demo code to help with completion of SYDE 121::Lab Assignment #8 Part2
//          No particular optimizations applied. The code structure emphasizes simplicity.
//          The code constructs emphasize those covered in the course.
//
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>

#include "lab08_box.hpp"
#include "lab08_produce.hpp"

#define ASSERT_FALSE(T) if ((T)) return false;
#define ASSERT_TRUE(T) if (!(T)) return false;

using namespace std;


// constants that define the files with produce names
const string FruitsAndVeggiesBox::WINTER_FILE = "winter.txt";
const string FruitsAndVeggiesBox::SPRING_FILE = "spring.txt";
const string FruitsAndVeggiesBox::SUMMER_FILE = "summer.txt";
const string FruitsAndVeggiesBox::FALL_FILE = "fall.txt";

// constants that define the generation parameters for produce attributes
const int FruitsAndVeggiesBox::MAX_WEIGHT = 100 /* in grams */, FruitsAndVeggiesBox::MAX_DAY = 31 /* not checking for Feb 31st */;
const int FruitsAndVeggiesBox::MAX_MONTH = 12, FruitsAndVeggiesBox::MAX_YEAR_DIFF = 2 /* 2020 and 2021 are valid */;
const int FruitsAndVeggiesBox::NEXT_YEAR = 2020;

FruitsAndVeggiesBox::FruitsAndVeggiesBox() : order_size(0) {}

FruitsAndVeggiesBox::FruitsAndVeggiesBox(int new_order_size) : 
	order_size(new_order_size) {}

void FruitsAndVeggiesBox::print() {
	// print each vector separately by invoking class-specific print()
    for (int index = 0; index < winter_produce.size(); index++){
        winter_produce[index].print();
        cout << "\n";
    }

    for (int index = 0; index < spring_produce.size(); index++){
		spring_produce[index].print();
        cout << "\n";
    }

    for (int index = 0; index < summer_produce.size(); index++){
		summer_produce[index].print();
        cout << "\n";
    }
    
    for (int index = 0; index < fall_produce.size(); index++){
		fall_produce[index].print();
        cout << "\n";
    }
}

int FruitsAndVeggiesBox::size() {
	int cur_size = 0;
	// add the number of items already inserted
    //loop through each  vector, count amount of items in each
    //add 1 for each item in each vector
    
    for (int index = 0; index < winter_produce.size(); index++){
        cur_size++;
    }
    for (int index = 0; index < spring_produce.size(); index++){
        cur_size++;
    }
    for (int index = 0; index < fall_produce.size(); index++){
        cur_size++;
    }
    for (int index = 0; index < summer_produce.size(); index++){
        cur_size++;
    }
	return cur_size;
}


void FruitsAndVeggiesBox::empty_the_box() {

	// clear the box if some items already inserted
    //if vector size is greater than 0, set size back to 0
    
    if (winter_produce.size() != 0){
        winter_produce.clear();
    }
    if (spring_produce.size() != 0){
        spring_produce.clear();
    }
    if (summer_produce.size() != 0){
        summer_produce.clear();
    }
    if (fall_produce.size() != 0){
        fall_produce.clear();
    }
}


void FruitsAndVeggiesBox::file_to_vector(vector<string>& return_vector, string file_name) {

	// step0. initialize corresponding variables
	string line; ifstream my_file;

	// step1. open the corresponding file	
	my_file.open(file_name.c_str());

	// step2. load the values from the file
    if(!my_file.fail()){

       while (!my_file.eof()){
           getline(my_file, line);
            return_vector.push_back(line);
            //cout << line;
        }
    }
		// step3. close the file
        my_file.close();
    
}


void FruitsAndVeggiesBox::load_up_produce_names() {
	// load up the four files one at a time
	file_to_vector(winter_produce_names, WINTER_FILE);
	file_to_vector(spring_produce_names, SPRING_FILE);
	file_to_vector(summer_produce_names, SUMMER_FILE);
	file_to_vector(fall_produce_names, FALL_FILE);
	
	//check what names were loaded
	//print_loaded_names();
}


void FruitsAndVeggiesBox::print_loaded_names() {
	// print each vector separately by listing each group of names separately
    
    for (int i = 0; i< winter_produce_names.size(); i++){
        cout << winter_produce_names[i] << endl;
    }
    cout << "\n";
    for (int i = 0; i< spring_produce_names.size(); i++){
        cout << spring_produce_names[i] << endl;
    }
    cout << "\n";
    for (int i = 0; i< fall_produce_names.size(); i++){
        cout << fall_produce_names[i] << endl;
    }
    cout << "\n";
    for (int i = 0; i< summer_produce_names.size(); i++){
        cout << summer_produce_names[i] << endl;
    }
    
}


void FruitsAndVeggiesBox::assign_seasons(int current_month) {
	// remove previously set seasons
	produce_seasons.clear(); 
	// insert corresponding seasons based on specified rules
	switch (current_month) {
		case JAN:
			produce_seasons.push_back(WINTER);
			break;
		case FEB:
		case MAR:
			produce_seasons.push_back(WINTER);
			produce_seasons.push_back(SPRING);
			break;
		case APR:
			produce_seasons.push_back(SPRING);
			break;
		case MAY:
		case JUN:
			produce_seasons.push_back(SPRING);
			produce_seasons.push_back(SUMMER);
			break;
		case JUL:
			produce_seasons.push_back(SUMMER);
			break;
		case AUG:
		case SEP:
			produce_seasons.push_back(SUMMER);
			produce_seasons.push_back(FALL);
			break;
		case OCT:
			produce_seasons.push_back(FALL);
			break;
		case NOV:
		case DEC:
			produce_seasons.push_back(FALL);
			produce_seasons.push_back(WINTER);
			break;
	}
}

void FruitsAndVeggiesBox::generate_random_value(int vector_size) {
	// generate random values for the current produce item
	rand_item = rand() % vector_size; // random item name
	rand_weight = rand() % MAX_WEIGHT + 1;
    rand_day = rand() % MAX_DAY + 1;
	rand_month = rand() % MAX_MONTH + 1;
    rand_year = rand() % MAX_YEAR_DIFF + NEXT_YEAR;
}

void FruitsAndVeggiesBox::handle_winter_item() {
	// step0. initialize corresponding variables
    bool prod_copy = false;
    int size = (int) winter_produce_names.size();
    //cout << "Winter Box Size is " << size << endl;

	// step1. generate a unique item, check if its already there, if yes, regenerate
    do{
        prod_copy = false;
        // step1.1. generate random values for the winter produce item
        generate_random_value(size);
        
        // step1.2. create a new WinterProduce instance with the matching values
        WinterProduce temp(winter_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);
        
        //TEST OUTPUTS TO ENSURE CORRECT VALUES
        //cout <<"Your random number is "<<  rand_item << endl;
        //cout << "Your random item is "<< winter_produce_names[rand_item] << endl;
        
        // step1.3. iterate through the winter produce vector to check if the item is unique
        // if no copies exist yet, keep checking through the items in the vector to find a match
        for (int i = 0; i < winter_produce.size() && !prod_copy; i++){
            if (temp == winter_produce[i]){
                prod_copy = true;
            }else{
                prod_copy = false;
            }
        }
        
    } while (prod_copy==true);
    
	// step2. once a unique item is generated, store it into the vector
    winter_produce.push_back(WinterProduce (winter_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year));
    
}

void FruitsAndVeggiesBox::handle_spring_item() {

	// step0. initialize corresponding variables
    bool prod_copy = false;
    int size = (int) spring_produce_names.size();
	// step1. keep repeating this until a unique item is generated
    
    do {
        prod_copy = false;
        // step1.1. generate random values for the spring produce item
        generate_random_value(size);
        
        // step1.2. create a new SpringProduce instance with the matching values
        SpringProduce temp(spring_produce_names[rand_item],rand_weight, rand_day, rand_month, rand_year);
        
        // step1.3. iterate through the spring produce vector to check if the item is unique
        // if no copies exist yet, keep checking through the items in the vector to find a match
        for (int i = 0; i < spring_produce.size() && !prod_copy; i++){
            if (temp == spring_produce[i]){
                prod_copy = true;
            } else {
                prod_copy = false;
            }
        }
    } while (prod_copy == true);
	// step2. once a unique item is generated, store it into the vector
    
    spring_produce.push_back(SpringProduce(spring_produce_names[rand_item],rand_weight, rand_day, rand_month, rand_year));
}

void FruitsAndVeggiesBox::handle_summer_item() {

	// step0. initialize corresponding variables
    bool prod_copy = false;
    int size = (int)summer_produce_names.size();

	// step1. keep repeating this until a unique item is generated
    do{
        // step1.1. generate random values for the summer produce item
        generate_random_value(size);

        // step1.2. create a new SummerProduce instance with the matching values
        SummerProduce temp(summer_produce_names[rand_item],rand_weight, rand_day, rand_month, rand_year);
                                   
        // step1.3. iterate through the summer produce vector to check if the item is unique
        // if no copies exist yet, keep checking through the items in the vector to find a match
        for (int i = 0; i < summer_produce.size() && !prod_copy; i++){
            if (temp == summer_produce[i]){
                prod_copy = true;
            } else {
                prod_copy = false;
            }
        }
    } while (prod_copy == true);

	// step2. once a unique item is generated, store it into the vector
    summer_produce.push_back(SummerProduce(summer_produce_names[rand_item],rand_weight, rand_day, rand_month, rand_year));
}

void FruitsAndVeggiesBox::handle_fall_item() {
	
	// step0. initialize corresponding variables
    bool prod_copy = false;
    int size = (int) winter_produce_names.size();

	// step1. keep repeating this until a unique item is generated
    do{
        // step1.1. generate random values for the fall produce item
        generate_random_value(size);
        
        // step1.2. create a new FallProduce instance with the matching values
        FallProduce temp(fall_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);
        
        // step1.3. iterate through the fall produce vector to check if the item is unique
        // if no copies exist yet, keep checking through the items in the vector to find a match 
        for (int i = 0; i< fall_produce.size() && !prod_copy; i++){
            if (temp == fall_produce[i]){
                prod_copy = true;
            }else{
                prod_copy = false;
            }
        }
        
    }while(prod_copy == true);

	// step2. once a unique item is generated, store it into the vector
    fall_produce.push_back(FallProduce(fall_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year));
}

void FruitsAndVeggiesBox::insert_unique_item() {
	// step1. randomly generate a unique produce item
    
	// step1.1. randomly select a season from available seasons
	rand_season = rand() % produce_seasons.size();
    
	// step1.2. insert a new unique item with random values into the box
	switch (produce_seasons[rand_season]) {
		case WINTER:
			// step1.3a. insert winter produce item
            handle_winter_item();
			break;			
			
		case SPRING:
			// step1.3b. insert spring produce item
            handle_spring_item();
			break;
			
		case SUMMER:
			// step1.3c. insert summer produce item
            handle_summer_item();
			break;
			
		case FALL:
			// step1.3d. insert fall produce item
            handle_fall_item();
			break;
	}
}

void FruitsAndVeggiesBox::fill_the_box(int current_month) {

	// step0. set the randomization seed
    srand((unsigned)time(0));
	
	// step1. remove all items if some already inserted
    empty_the_box();
	// step2. load up produce names	
    load_up_produce_names();
    
    //print_loaded_names();
    
	// step3. decide which seasons are current
    assign_seasons(current_month);

	// step4. insert matching unique items based on the current seasons
    //4.1. find out order size of box
    //fill box up to that order size
    for (int i = 0; i < order_size; i++){
        insert_unique_item();
    }
}
int FruitsAndVeggiesBox::get_size(){
    return size();
}
