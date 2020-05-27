// 
// PURPOSE: Demo code to help with completion of SYDE 121::Lab Assignment #8 Part2
//          No particular optimizations applied. The code structure emphasizes simplicity.
//          The code constructs emphasize those covered in the course.
//
#include <iostream>
#include <vector>

#include "lab08_box.hpp"
#include "lab08_produce.hpp"

using namespace std;

// Purpose: Simple test scenario to test Produce constructors
void test_produce_constructors() {
	Produce p1, p2("Carrots", 1, 1, 1, 2019);
	WinterProduce wp1("Carrots", 1, 1, 1, 2019), wp2("Carrot", 1, 1, 1, 2019);
	SpringProduce sp1("Carrots", 2, 1, 1, 2019), sp2("Carrots", 1, 1, 1, 2019);
	SummerProduce smp1("Carrots", 1, 1, 1, 2019), smp2("Carrots", 1, 1, 1, 2020);
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

// Purpose: Simple test scenario to test FruitsAndVeggiesBox constructors and fill_the_box()
void test_fill_the_box() {
	// TODO: complete function definition here
}

// Purpose: Invokes Produce test functions
void test_produce_methods() {
	test_produce_constructors();
	test_produce_print();
	test_produce_comparisons();	
}

int main() {
	//test_produce_methods();
	test_fill_the_box();
	// TODO: include additional test cases
	// TODO: consider using assertions as practice
		
	return 0;
}
