// Student Name: Silja Walenius
// Student Number: 20710274
//
// SYDE 121 Lab: 08
// Filename: Lab08_01
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Fresh Fruits and Veggies
// Purpose: Stores book class objects in a library object to print
// Due Date: Tuesday, December 3, 2019


#include <iostream>
#include <vector>

#include "lab08_box.hpp"
#include "lab08_produce.hpp"

#define ASSERT_FALSE(T) if ((T)) return false;
#define ASSERT_TRUE(T) if (!(T)) return false;

using namespace std;

//DRIVER FUNCTIONS
// Purpose: Simple test scenario to test Produce constructors
void test_produce_constructors() {
    Produce p1, p2("Carrots", 1, 1, 1, 2019);
    WinterProduce wp1("Carrots", 1, 1, 1, 2019), wp2("Carrot", 1, 1, 1, 2019);
    SpringProduce sp1("Carrots", 2, 1, 1, 2019), sp2("Carrots", 1, 1, 1, 2019);
    SummerProduce smp1("Carrots", 1, 1, 1, 2019);
    SummerProduce smp2("Carrots", 1, 1, 1, 2020);
    FallProduce fp1("Carrots", 1, 1, 1, 2019), fp2("Carrots", 1, 1, 1, 2019);
}

// Purpose: Simple test scenario to test Produce print()
void test_produce_print() {
    Produce p1;
    WinterProduce wp1("Carrots", 1, 1, 1, 2019);
    SpringProduce sp1("Carrots", 2, 1, 1, 2019);
    SummerProduce smp1("Carrots", 1, 1, 2, 2019);
    FallProduce fp1("Carrots", 1, 1, 1, 2020);
    p1.print();
    wp1.print();
    sp1.print();
    smp1.print();
    fp1.print();
}

// Purpose: Simple test scenario to test Produce operator==
void test_produce_comparisons() {
    Produce p1, p2("Carrots", 1, 1, 1, 2019);
    WinterProduce wp1("Carrots", 1, 1, 1, 2019), wp2("Carrot", 1, 1, 1, 2019);
    SpringProduce sp1("Carrots", 2, 1, 1, 2019), sp2("Carrots", 1, 1, 1, 2019);
    SummerProduce smp1("Carrots", 1, 1, 1, 2019), smp2("Carrots", 1, 1, 1, 2020);
    FallProduce fp1("Carrots", 1, 1, 1, 2019), fp2("Carrots", 1, 1, 1, 2019);
    
    cout << (p1 == p2 ? "p1 and p2 are equal" : "p1 and p2 are not equal") << endl;
    cout << (wp1 == wp2 ? "wp1 and wp2 are equal" : "wp1 and wp2 are not equal") << endl;
    cout << (sp1 == sp2 ? "sp1 and sp2 are equal" : "sp1 and sp2 are not equal") << endl;
    cout << (smp1 == smp2 ? "smp1 and smp2 are equal" : "smp1 and smp2 are not equal") << endl;
    cout << (fp1 == fp2 ? "fp1 and fp2 are equal" : "fp1 and fp2 are not equal") << endl;

    // attempt to compare different types; will not compile
    //cout << (sp1 == fp2 ? "fp1 and fp2 are equal" : "fp1 and fp2 are not equal") << endl;
}


//TEST PUBLIC BOX.CPP FUNCTIONS

// Purpose: Simple test scenario to test FruitsAndVeggiesBox constructors and fill_the_box()
bool test_fill_the_box_medium() {
    
    FruitsAndVeggiesBox test_box(FruitsAndVeggiesBox::MEDIUM_ORDER);
    
    //test filling the box for February (should be WINTER AND SPRING produce)
    test_box.fill_the_box(2);
    
    //test printing the box
    test_box.print();

    //TESTING REPLACEMENT OF BOX CONTENTS
    cout << "Replacing box contents with summer/fall items \n" << endl;
    test_box.fill_the_box(7);

    //test printing the summer box
    test_box.print();
    
    int size = test_box.get_size();
    cout << "Total Items in Box is " << size << endl;
    if(size == 0){
        return false;
    }
    return true;
}

// Purpose: Invokes Produce test functions
void test_produce_methods() {
    test_produce_constructors();
    test_produce_print();
    test_produce_comparisons();
}

bool test_large_box(){
    cout << "\n *****testing large box***** \n" << endl;
    FruitsAndVeggiesBox testbox_large(FruitsAndVeggiesBox::LARGE_ORDER);
    testbox_large.fill_the_box(9);
    testbox_large.print();
    
    int size = testbox_large.get_size();
    cout << "Total Items in Box is " << size << endl;
    if(size == 0){
        return false;
    }
    
    return true;
}

//MAIN FUNCTION
int main() {
    //test the creation of produce items
    //test_produce_methods();
    
    //test the box filling, emptying, and replacing of contents
    //test print method
    //initial contents : winter
    //replaced contents: summer/fall contents
    ASSERT_TRUE(test_fill_the_box_medium());
    
    //test large box filling with Summer produce items
    ASSERT_TRUE(test_large_box());
    
    
        
    return 0;
}

