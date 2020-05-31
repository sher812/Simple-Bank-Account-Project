#include <iostream>
#include <cctype>
#include <cstdlib>
#include <vector>

#include "basics.h"

// David's custom test

// flags to enable tests for the later parts of the assignment
#define ENABLE_T2_TESTS
#define ENABLE_T3_TESTS
#define ENABLE_T4_TESTS

// include headers for classes being tested
#include "Money.h"
using namespace std;

/*
	The outcome of each test case is described by this enum, which should make
	the result more obvious than if a boolean value was used in its place.
*/
enum TestResult { TR_PASS, TR_FAIL };

/*
	Helper macro to eliminate a lot of of code repetition. Macros aren't the best,
	but this is an easy way to get what we want.
*/

#define ASSERT(condition)                                                         \
    if ((condition) == false) {                                                   \
        cout << "FAILURE: " << __FILE__ << ":" << __LINE__ << "\n"                \
             << "\tExpression '" << #condition << "' evaluated to false" << endl; \
        return TR_FAIL;                                                           \
    }

TestResult test_functionTotalValid() {
    ASSERT(totalCents(1, 5) == 105);
    ASSERT(totalCents(0, 1) == 1);
    ASSERT(totalCents(5, 25) == 525);
    ASSERT(totalCents(80, 99) == 8099);
    ASSERT(totalCents(0, 0) == 0);
    ASSERT(totalCents(0, 120) == 120);
    ASSERT(totalCents(6, 500) == 1100);
    ASSERT(totalCents(2, 101) == 301);

    return TR_PASS;
}

TestResult test_functionTotalInvalid() {
    ASSERT(totalCents(0, -30) == -1);
    ASSERT(totalCents(5, -3) == -1);
    ASSERT(totalCents(-2, 10) == -1);
    ASSERT(totalCents(-3, -10) == -1);

    return TR_PASS;
}

TestResult test_functionSumValid() {
    ASSERT(sumAsCents(4, 50, 3, 30) == 780);
    ASSERT(sumAsCents(5, 10, 3, 5) == 815);
    ASSERT(sumAsCents(1, 15, 16, 25) == 1740);
    ASSERT(sumAsCents(0, 7, 3, 92) == 399);
    ASSERT(sumAsCents(12, 25, 8, 25) == 2050);

    ASSERT(sumAsCents(4, 99, 3, 10) == 809);
    ASSERT(sumAsCents(5, 50, 3, 50) == 900);
    ASSERT(sumAsCents(1, 150, 0, 250) == 500);
    ASSERT(sumAsCents(0, 75, 7, 92) == 867);
    ASSERT(sumAsCents(0, 99, 0, 99) == 198);

    return TR_PASS;
}

TestResult test_functionSumInvalid() {
    ASSERT(sumAsCents(-4, 99, 3, 10) == -1);
    ASSERT(sumAsCents(5, 50, 3, -50) == -1);
    ASSERT(sumAsCents(2, -150, 0, 250) == -1);
    ASSERT(sumAsCents(0, 75, -7, 92) == -1);
    ASSERT(sumAsCents(0, 99, -1, -99) == -1);

    return TR_PASS;
}

TestResult test_functionSplitValid() {
    ASSERT(split(4, 50, 3, 30) == 390);
    ASSERT(split(5, 10, 3, 5) == 407);
    ASSERT(split(1, 15, 16, 25) == 870);
    ASSERT(split(0, 7, 3, 92) == 199);
    ASSERT(split(12, 25, 8, 25) == 1025);

    ASSERT(split(4, 99, 3, 10) == 404);
    ASSERT(split(5, 50, 3, 50) == 450);
    ASSERT(split(1, 150, 0, 250) == 250);
    ASSERT(split(0, 75, 7, 92) == 433);
    ASSERT(split(0, 99, 0, 99) == 99);

    return TR_PASS;
}

TestResult test_functionSplitInvalid() {
    ASSERT(split(-4, 99, 3, 10) == -1);
    ASSERT(split(5, 50, 3, -50) == -1);
    ASSERT(split(2, -150, 0, 250) == -1);
    ASSERT(split(0, 75, -7, 92) == -1);
    ASSERT(split(0, 99, -1, -99) == -1);

    return TR_PASS;
}

#ifdef ENABLE_T2_TESTS
/*
	Test creating a default Money creates it with the correct default dollars and cents,
	and that the getCents(), getDollars() and asCents() methods work properly.
*/
TestResult test_DefaultMoney() {
    Money amount;

    ASSERT(amount.getDollars() == 0);
    ASSERT(amount.getCents() == 0);

    return TR_PASS;
}

/*
 * Test that invalid combinations result in the correct output, i.e when a value is less than zero
 * we ignore it, for instance when dollars is -2 and cents is 150 we return 1 dollar and 50 cents
 * ignoring the invalid input.
 */
TestResult test_InvalidMoneyOne(){
	Money amount(-3, 80);

	ASSERT(amount.getDollars() == 0);
	ASSERT(amount.getCents() == 80);
	ASSERT(amount.asCents() == 80);

	return TR_PASS;
}

TestResult test_InvalidMoneyTwo(){
	Money amount(-5, -69);

	ASSERT(amount.getDollars() == 0);
	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 0);

	return TR_PASS;
}

TestResult test_InvalidMoneyThree(){
	Money amount(420, -139);

	ASSERT(amount.getDollars() == 420);
	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 42000);

	return TR_PASS;
}

TestResult test_InvalidMoneyFour(){
	Money amount(-5, 120);

	ASSERT(amount.getDollars() == 1);
	ASSERT(amount.getCents() == 20);
	ASSERT(amount.asCents() == 120);

	return TR_PASS;
}

TestResult test_InvalidMoneyFive(){
	Money amount(-80, 758);

	ASSERT(amount.getDollars() == 7);
	ASSERT(amount.getCents() == 58);
	ASSERT(amount.asCents() == 758);

	return TR_PASS;
}

TestResult test_InvalidMoneySix(){
	Money amount(-80, 52859);

	ASSERT(amount.getDollars() == 528);
	ASSERT(amount.getCents() == 59);
	ASSERT(amount.asCents() == 52859);

	return TR_PASS;
}
/*
	Test creating a simple Money creates it with the correct default dollars and cents,
	and that the getCents(), getDollars() and asCents() methods work properly.
*/
TestResult test_SimpleMoney() {
    Money amount(3,5);
    ASSERT(amount.getDollars() == 3);
    ASSERT(amount.getCents() == 5);
    ASSERT(amount.asCents() == 305);



    return TR_PASS;
}

/*
	Test creating a Money creates it with the correct default dollars and cents,
	and that the getCents(), getDollars() and asCents() methods work properly.
*/
TestResult test_WrappingMoney() {
    Money amount(3,201);
    ASSERT(amount.getDollars() == 5);
    ASSERT(amount.getCents() == 1);
    ASSERT(amount.asCents() == 501);

    return TR_PASS;
}

#endif /*ENABLE_T2_TESTS*/

#ifdef ENABLE_T3_TESTS
/*
	Test that the addDollars() method works correctly.
*/
TestResult test_addDollars() {
	Money amount(3,5);
	ASSERT(amount.getDollars() == 3);
	ASSERT(amount.getCents() == 5);
	ASSERT(amount.asCents() == 305);

    amount.addDollars(5);

	ASSERT(amount.getDollars() == 8);
	ASSERT(amount.getCents() == 5);
	ASSERT(amount.asCents() == 805);

    return TR_PASS;
}

TestResult test_addDollarsTwo() {
	Money amount(3,573);
	ASSERT(amount.getCents() == 73);
	ASSERT(amount.getDollars() == 8);
	ASSERT(amount.asCents() == 873);

    amount.addDollars(12);

	ASSERT(amount.asCents() == 2073);
	ASSERT(amount.getDollars() == 20);
	ASSERT(amount.getCents() == 73);

    return TR_PASS;
}

TestResult test_addDollasThree() {
	Money amount(420,69);
	ASSERT(amount.getCents() == 69);
	ASSERT(amount.getDollars() == 420);
	ASSERT(amount.asCents() == 42069);

    amount.addDollars(-4);

	ASSERT(amount.asCents() == 42069);
	ASSERT(amount.getCents() == 69);
	ASSERT(amount.getDollars() == 420);

    return TR_PASS;
}

TestResult test_addDollarsInvalidOne() {
	Money amount(3,-420);
	ASSERT(amount.getDollars() == 3);
	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 300);

    amount.addDollars(-4);

	ASSERT(amount.getDollars() == 3);
	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 300);

    return TR_PASS;
}

TestResult test_addDollarsInvalidTwo() {
	Money amount(-3,420);
	ASSERT(amount.getCents() == 20);
	ASSERT(amount.getDollars() == 4);
	ASSERT(amount.asCents() == 420);

    amount.addDollars(2);

	ASSERT(amount.asCents() == 620);
	ASSERT(amount.getDollars() == 6);
	ASSERT(amount.getCents() == 20);

    return TR_PASS;
}
/*
	Test that the addCents() method works correctly.
*/
TestResult test_addCents() {
	Money amount(3,5);
	ASSERT(amount.getDollars() == 3);
	ASSERT(amount.getCents() == 5);
	ASSERT(amount.asCents() == 305);

    amount.addCents(5);

	ASSERT(amount.getDollars() == 3);
	ASSERT(amount.getCents() == 10);
	ASSERT(amount.asCents() == 310);

    amount.addCents(208);

	ASSERT(amount.getDollars() == 5);
	ASSERT(amount.getCents() == 18);
	ASSERT(amount.asCents() == 518);

    return TR_PASS;
}

TestResult test_addCentsTwo() {
	Money amount(7,14);
	ASSERT(amount.getCents() == 14);
	ASSERT(amount.getDollars() == 7);
	ASSERT(amount.asCents() == 714);

    amount.addCents(77);

	ASSERT(amount.asCents() == 791);
	ASSERT(amount.getCents() == 91);
	ASSERT(amount.getDollars() == 7);

    amount.addCents(792);

	ASSERT(amount.getCents() == 83);
	ASSERT(amount.asCents() == 1583);
	ASSERT(amount.getDollars() == 15);


    return TR_PASS;
}

TestResult test_addCentsThree() {
	Money amount(-7,14);
	ASSERT(amount.getCents() == 14);
	ASSERT(amount.asCents() == 14);
	ASSERT(amount.getDollars() == 0);


    amount.addCents(85);

	ASSERT(amount.getCents() == 99);
	ASSERT(amount.asCents() == 99);
	ASSERT(amount.getDollars() == 0);


    amount.addCents(1); // RARE CONDITION

	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 100);
	ASSERT(amount.getDollars() == 1);


    return TR_PASS;
}


/*
	Test that the subtractDollars() method works correctly.
*/
TestResult test_subtractDollars() {
	Money amount(3,5);
	ASSERT(amount.getDollars() == 3);
	ASSERT(amount.getCents() == 5);
	ASSERT(amount.asCents() == 305);

    amount.subtractDollars(2);

	ASSERT(amount.getDollars() == 1);
	ASSERT(amount.getCents() == 5);
	ASSERT(amount.asCents() == 105);

    return TR_PASS;
}

TestResult test_subtractDollarsTwo() {
	Money amount(10,0);
	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 1000);
	ASSERT(amount.getDollars() == 10);


    amount.subtractDollars(9);

	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 100);
	ASSERT(amount.getDollars() == 1);


    return TR_PASS;
}

TestResult test_subtractDollarsThree() {
	Money amount(-1,99);
	ASSERT(amount.getCents() == 99);
	ASSERT(amount.asCents() == 99);
	ASSERT(amount.getDollars() == 0);

    amount.subtractDollars(1);

	ASSERT(amount.getCents() == 99);
	ASSERT(amount.asCents() == 99);
	ASSERT(amount.getDollars() == 0);


    return TR_PASS;
}

TestResult test_subtractDollarsFour() {
	Money amount(699,-600);
	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 69900);
	ASSERT(amount.getDollars() == 699);


    amount.subtractDollars(698);

	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 100);
	ASSERT(amount.getDollars() == 1);


    return TR_PASS;
}

TestResult test_subtractDollarsFive() {
	Money amount(3,600);
	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 900);
	ASSERT(amount.getDollars() == 9);


    amount.subtractDollars(9);

	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 0);
	ASSERT(amount.getDollars() == 0);

    return TR_PASS;
}

TestResult test_subtractDollarsSix() {
	Money amount(4,120);
	ASSERT(amount.getCents() == 20);
	ASSERT(amount.asCents() == 520);
	ASSERT(amount.getDollars() == 5);


    amount.subtractDollars(5);

	ASSERT(amount.getCents() == 20);
	ASSERT(amount.asCents() == 20);
	ASSERT(amount.getDollars() == 0);

	amount.subtractDollars(1);

	ASSERT(amount.getCents() == 20);
	ASSERT(amount.asCents() == 20);
	ASSERT(amount.getDollars() == 0);


	amount.addCents(80);

	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 100);
	ASSERT(amount.getDollars() == 1);


	amount.subtractCents(1);

	ASSERT(amount.getCents() == 99);
	ASSERT(amount.asCents() == 99);
	ASSERT(amount.getDollars() == 0);


	amount.subtractDollars(100);

	ASSERT(amount.getCents() == 99);
	ASSERT(amount.asCents() == 99);
	ASSERT(amount.getDollars() == 0);


    return TR_PASS;
}

TestResult test_subtractDollarsSeven() {
	Money amount(24,578);
	ASSERT(amount.getDollars() == 29);
	ASSERT(amount.getCents() == 78);
	ASSERT(amount.asCents() == 2978);

    amount.subtractDollars(27);

	ASSERT(amount.getDollars() == 2);
	ASSERT(amount.getCents() == 78);
	ASSERT(amount.asCents() == 278);

	amount.subtractCents(279);

	ASSERT(amount.getCents() == 78);
	ASSERT(amount.asCents() == 278);
	ASSERT(amount.getDollars() == 2);


	amount.subtractCents(179);
	ASSERT(amount.getCents() == 99);
	ASSERT(amount.asCents() == 99);
	ASSERT(amount.getDollars() == 0);


    return TR_PASS;
}

TestResult test_subtractDollarsEight() {
	Money amount(24,578);
	ASSERT(amount.getDollars() == 29);
	ASSERT(amount.getCents() == 78);
	ASSERT(amount.asCents() == 2978);

    amount.subtractDollars(27);

	ASSERT(amount.getDollars() == 2);
	ASSERT(amount.getCents() == 78);
	ASSERT(amount.asCents() == 278);

	amount.subtractDollars(2);
	ASSERT(amount.getDollars() == 0);
	ASSERT(amount.getCents() == 78);
	ASSERT(amount.asCents() == 78);

    return TR_PASS;
}

TestResult test_subtractDollarsNine() {
	Money amount(24,578);
	ASSERT(amount.getDollars() == 29);
	ASSERT(amount.getCents() == 78);
	ASSERT(amount.asCents() == 2978);

    amount.subtractDollars(27);

	ASSERT(amount.getDollars() == 2);
	ASSERT(amount.getCents() == 78);
	ASSERT(amount.asCents() == 278);

	amount.subtractDollars(1);
	ASSERT(amount.getDollars() == 1);
	ASSERT(amount.getCents() == 78);
	ASSERT(amount.asCents() == 178);

    return TR_PASS;
}

/*
	Test that the subtractCents() method works correctly.
*/
TestResult test_subtractCents() {
	Money amount(3,50);
	ASSERT(amount.getDollars() == 3);
	ASSERT(amount.getCents() == 50);
	ASSERT(amount.asCents() == 350);

    amount.subtractCents(5);

	ASSERT(amount.getDollars() == 3);
	ASSERT(amount.getCents() == 45);
	ASSERT(amount.asCents() == 345);

    return TR_PASS;
}

TestResult test_subtractCentsTwo() {
	Money amount(5,-12);
	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 500);
	ASSERT(amount.getDollars() == 5);


    amount.subtractCents(1);

	ASSERT(amount.getCents() == 99);
	ASSERT(amount.asCents() == 499);
	ASSERT(amount.getDollars() == 4);


    return TR_PASS;
}

TestResult test_subtractCentsThree() {
	Money amount(5,50);
	ASSERT(amount.getDollars() == 5);
	ASSERT(amount.getCents() == 50);
	ASSERT(amount.asCents() == 550);

    amount.subtractCents(-70);

	ASSERT(amount.getDollars() == 5);
	ASSERT(amount.getCents() == 50);
	ASSERT(amount.asCents() == 550);

    return TR_PASS;
}

TestResult test_subtractCentsFour() {
	Money amount(2,353);
	ASSERT(amount.getDollars() == 5);
	ASSERT(amount.getCents() == 53);
	ASSERT(amount.asCents() == 553);

    amount.subtractCents(422);

	ASSERT(amount.getDollars() == 1);
	ASSERT(amount.getCents() == 31);
	ASSERT(amount.asCents() == 131);

    return TR_PASS;
}

TestResult test_subtractCentsFive() {
	Money amount(2,353);
	ASSERT(amount.getDollars() == 5);
	ASSERT(amount.getCents() == 53);
	ASSERT(amount.asCents() == 553);

    amount.subtractCents(322);

	ASSERT(amount.getDollars() == 2);
	ASSERT(amount.getCents() == 31);
	ASSERT(amount.asCents() == 231);

	amount.subtractCents(12);

	ASSERT(amount.getDollars() == 2);
	ASSERT(amount.getCents() == 19);
	ASSERT(amount.asCents() == 219);

    return TR_PASS;
}

TestResult test_subtractCentsSix() {
	Money amount(3,353);
	ASSERT(amount.getDollars() == 6);
	ASSERT(amount.getCents() == 53);
	ASSERT(amount.asCents() == 653);

    amount.subtractDollars(5);

	ASSERT(amount.getDollars() == 1);
	ASSERT(amount.getCents() == 53);
	ASSERT(amount.asCents() == 153);

	amount.subtractCents(142);

	ASSERT(amount.getDollars() == 0);
	ASSERT(amount.getCents() == 11);
	ASSERT(amount.asCents() == 11);

	amount.subtractCents(69);

	ASSERT(amount.getDollars() == 0);
	ASSERT(amount.getCents() == 11);
	ASSERT(amount.asCents() == 11);

    return TR_PASS;
}

TestResult test_subtractCentsSeven() {
	Money amount(12,22);
	ASSERT(amount.getDollars() == 12);
	ASSERT(amount.getCents() == 22);
	ASSERT(amount.asCents() == 1222);

    amount.subtractCents(117);

	ASSERT(amount.getDollars() == 11);
	ASSERT(amount.getCents() == 5);
	ASSERT(amount.asCents() == 1105);

    return TR_PASS;
}

TestResult test_subtractCentsEight() {
	Money amount(2,353);
	ASSERT(amount.getDollars() == 5);
	ASSERT(amount.getCents() == 53);
	ASSERT(amount.asCents() == 553);

    amount.subtractCents(422);

	ASSERT(amount.getDollars() == 1);
	ASSERT(amount.getCents() == 31);
	ASSERT(amount.asCents() == 131);

	amount.subtractCents(500);

	ASSERT(amount.getDollars() == 1);
	ASSERT(amount.getCents() == 31);
	ASSERT(amount.asCents() == 131);

    return TR_PASS;
}

TestResult test_subtractCentsNine() {
	Money amount(2,353);
	ASSERT(amount.getDollars() == 5);
	ASSERT(amount.getCents() == 53);
	ASSERT(amount.asCents() == 553);

    amount.subtractCents(553);

	ASSERT(amount.getDollars() == 0);
	ASSERT(amount.getCents() == 0);
	ASSERT(amount.asCents() == 0);

    return TR_PASS;
}
/*
	Test that the subtract method are correctly ignored.
*/
TestResult test_subtractIgnore() {
	Money amount(3,5);
	ASSERT(amount.getDollars() == 3);
	ASSERT(amount.getCents() == 5);
	ASSERT(amount.asCents() == 305);

    amount.subtractDollars(-1);
    amount.subtractCents(-1);

	ASSERT(amount.getDollars() == 3);
	ASSERT(amount.getCents() == 5);
	ASSERT(amount.asCents() == 305);

    amount.subtractDollars(5);
    amount.subtractCents(800);

	ASSERT(amount.getDollars() == 3);
	ASSERT(amount.getCents() == 5);
	ASSERT(amount.asCents() == 305);

    return TR_PASS;
}

TestResult test_taskThree() {
	Money amount(2,353);
	ASSERT(amount.getDollars() == 5);
	ASSERT(amount.getCents() == 53);
	ASSERT(amount.asCents() == 553);

	amount.subtractDollars(3);
	ASSERT(amount.getDollars() == 2);
	ASSERT(amount.getCents() == 53);
	ASSERT(amount.asCents() == 253);

	amount.addDollars(4);

	ASSERT(amount.getDollars() == 6);
	ASSERT(amount.getCents() == 53);
	ASSERT(amount.asCents() == 653);

	amount.addCents(120);


	ASSERT(amount.getDollars() == 7);
	ASSERT(amount.getCents() == 73);
	ASSERT(amount.asCents() == 773);

	amount.subtractCents(668);

	ASSERT(amount.getDollars() == 1);
	ASSERT(amount.getCents() == 5);
	ASSERT(amount.asCents() == 105);

    return TR_PASS;
}

#endif /*ENABLE_T3_TESTS*/

/*
 * Personal flag to know when task 4 tests start
 *
 *
 *
 *
 *
 */

#ifdef ENABLE_T4_TESTS
/*
	Test the adding of two Money objects.
*/
TestResult test_AddMoney() {
    Money amount1(3,10);
    Money amount2(2,5);

    ASSERT(amount1.asCents() == 310);
    ASSERT(amount2.asCents() == 205);

    amount1.add(amount2);
    ASSERT(amount1.asCents() == 515);
    ASSERT(amount2.asCents() == 205);

    Money amount3(3,90);
    ASSERT(amount3.asCents() == 390);

    amount1.add(amount3);
    ASSERT(amount1.asCents() == 905);
    ASSERT(amount2.asCents() == 205);
    ASSERT(amount3.asCents() == 390);

    return TR_PASS;
}

TestResult test_AddMoneyTwo() {
    Money amount1(2,58);
    Money amount2(3,32);

    ASSERT(amount1.asCents() == 258);
    ASSERT(amount2.asCents() == 332);

    amount1.add(amount2);
    ASSERT(amount1.asCents() == 590);
    ASSERT(amount2.asCents() == 332);

    Money amount3(1,-82);
    ASSERT(amount3.asCents() == 100);

    amount1.add(amount3);
    ASSERT(amount1.asCents() == 690);
    ASSERT(amount2.asCents() == 332);
    ASSERT(amount3.asCents() == 100);

    return TR_PASS;
}

TestResult test_AddMoneyThree() {
    Money amount1(3,10);
    Money amount2(-2,-5);

    ASSERT(amount1.asCents() == 310);
    ASSERT(amount2.asCents() == 0);

    amount1.add(amount2);
    ASSERT(amount1.asCents() == 310);
    ASSERT(amount2.asCents() == 0);

    Money amount3(3,55);
    ASSERT(amount3.asCents() == 355);

    amount1.add(amount3);
    ASSERT(amount1.asCents() == 665);
    ASSERT(amount2.asCents() == 0);
    ASSERT(amount3.asCents() == 355);

    amount3.add(amount1);
    ASSERT(amount1.asCents() == 665);
    ASSERT(amount2.asCents() == 0);
    ASSERT(amount3.asCents() == 1020);

    return TR_PASS;
}

TestResult test_AddMoneyFour() {
    Money amount1(5,99);
    Money amount2(0,1);

    ASSERT(amount1.asCents() == 599);
    ASSERT(amount2.asCents() == 1);

    amount1.add(amount2);
    ASSERT(amount1.asCents() == 600);
    ASSERT(amount2.asCents() == 1);

    Money amount3(0,1);
    ASSERT(amount3.asCents() == 1);

    amount1.add(amount3);
    ASSERT(amount1.asCents() == 601);
    ASSERT(amount2.asCents() == 1);
    ASSERT(amount3.asCents() == 1);

    amount3.add(amount1);
    ASSERT(amount1.asCents() == 601);
    ASSERT(amount2.asCents() == 1);
    ASSERT(amount3.asCents() == 602);

    return TR_PASS;
}

TestResult test_AddMoneyFive() {
    Money amount1(3,10);
    Money amount2(7,12);

    ASSERT(amount1.asCents() == 310);
    ASSERT(amount2.asCents() == 712);

    amount2.add(amount1);
    ASSERT(amount1.asCents() == 310);
    ASSERT(amount2.asCents() == 1022);

    ASSERT(amount1.getDollars() == 3);
    ASSERT(amount1.getCents() == 10);
    ASSERT(amount2.getDollars() == 10);
    ASSERT(amount2.getCents() == 22);

    Money amount3(-3,-55);
    ASSERT(amount3.asCents() == 0);

    amount3.add(amount2);
    ASSERT(amount1.asCents() == 310);
    ASSERT(amount2.asCents() == 1022);
    ASSERT(amount3.asCents() == 1022);

    ASSERT(amount1.getDollars() == 3);
    ASSERT(amount1.getCents() == 10);
    ASSERT(amount2.getDollars() == 10);
    ASSERT(amount2.getCents() == 22);
    ASSERT(amount3.getDollars() == 10);
    ASSERT(amount3.getCents() == 22); // Might need to change ///////////////////

    return TR_PASS;
}


///////////////// HAVE NOT CHANGED BELOW FUNCTIONS //////////////////////////////////////

/*
	Test the subtracting of two Money objects.
*/
TestResult test_SubtractMoney() {
    Money amount1(3,80);
    Money amount2(2,5);

    ASSERT(amount1.asCents() == 380);
    ASSERT(amount2.asCents() == 205);

    amount1.subtract(amount2);

    ASSERT(amount1.getDollars() == 1);
    ASSERT(amount1.getCents() == 75);
    ASSERT(amount1.asCents() == 175);
    ASSERT(amount2.asCents() == 205);

    Money amount3(0,90);
    ASSERT(amount3.asCents() == 90);

    amount1.subtract(amount3);

    ASSERT(amount1.getDollars() == 0);
    ASSERT(amount1.getCents() == 85);
    ASSERT(amount1.asCents() == 85);
    ASSERT(amount2.asCents() == 205);
    ASSERT(amount3.asCents() == 90);

    return TR_PASS;
}

TestResult test_SubtractMoneyTwo() {
    Money amount1(3,80);
    Money amount2(2,90);

    ASSERT(amount1.asCents() == 380);
    ASSERT(amount2.asCents() == 290);

    amount1.subtract(amount2);

    ASSERT(amount1.getDollars() == 0);
    ASSERT(amount1.getCents() == 90);
    ASSERT(amount1.asCents() == 90);
    ASSERT(amount2.asCents() == 290);

    Money amount3(0,90);
    ASSERT(amount3.asCents() == 90);

    amount1.subtract(amount3);

    ASSERT(amount1.getDollars() == 0);
    ASSERT(amount1.getCents() == 0);
    ASSERT(amount1.asCents() == 0);
    ASSERT(amount2.asCents() == 290);
    ASSERT(amount3.asCents() == 90);

    return TR_PASS;
}

TestResult test_SubtractMoneyThree() {
    Money amount1(3,480);
    Money amount2(5,50);

    ASSERT(amount1.asCents() == 780);
    ASSERT(amount2.asCents() == 550);

    amount1.subtract(amount2);

    ASSERT(amount1.getDollars() == 2);
    ASSERT(amount1.getCents() == 30);
    ASSERT(amount1.asCents() == 230);
    ASSERT(amount2.asCents() == 550);

    Money amount3(0,220);
    ASSERT(amount3.asCents() == 220);

    amount1.subtract(amount3);

    ASSERT(amount1.getDollars() == 0);
    ASSERT(amount1.getCents() == 10);
    ASSERT(amount1.asCents() == 10);
    ASSERT(amount2.asCents() == 550);
    ASSERT(amount3.asCents() == 220);

    return TR_PASS;
}

TestResult test_SubtractMoneyFour() {
    Money amount1(8,120);
    Money amount2(4,1223);

    ASSERT(amount1.asCents() == 920);
    ASSERT(amount2.asCents() == 1623);

    amount1.subtract(amount2);

    ASSERT(amount1.getDollars() == 9);
    ASSERT(amount1.getCents() == 20);
    ASSERT(amount1.asCents() == 920);
    ASSERT(amount2.asCents() == 1623);

    Money amount4(120,40);
    amount1.subtract(amount4);

    ASSERT(amount4.asCents() == 12040)

    ASSERT(amount1.getDollars() == 9);
    ASSERT(amount1.getCents() == 20);
    ASSERT(amount1.asCents() == 920);
    ASSERT(amount4.asCents() == 12040);

    Money amount3(8,120);
    ASSERT(amount3.asCents() == 920);

    amount1.subtract(amount3);

    ASSERT(amount1.getDollars() == 0);
    ASSERT(amount1.getCents() == 0);
    ASSERT(amount1.asCents() == 0);
    ASSERT(amount2.asCents() == 1623);
    ASSERT(amount3.asCents() == 920);

    return TR_PASS;
}

TestResult test_SubtractMoneyFive() {
    Money amount1(5,27);
    Money amount2(2,448);

    ASSERT(amount1.asCents() == 527);
    ASSERT(amount2.asCents() == 648);

    amount2.subtract(amount1);

    ASSERT(amount2.getDollars() == 1);
    ASSERT(amount2.getCents() == 21);
    ASSERT(amount2.asCents() == 121);

    ASSERT(amount1.getDollars() == 5);
    ASSERT(amount1.getCents() == 27);
    ASSERT(amount1.asCents() == 527);

    Money amount3(2,33);
    ASSERT(amount3.asCents() == 233);

    amount3.subtract(amount2);

    ASSERT(amount1.getDollars() == 5);
    ASSERT(amount1.getCents() == 27);
    ASSERT(amount1.asCents() == 527);
    ASSERT(amount2.getDollars() == 1);
    ASSERT(amount2.getCents() == 21);
    ASSERT(amount2.asCents() == 121);
    ASSERT(amount3.getDollars() == 1);
    ASSERT(amount3.getCents() == 12);
    ASSERT(amount3.asCents() == 112);

    return TR_PASS;
}

/*
	Test the splitting of two Money objects.
*/
TestResult test_SplitMoney() {
    Money amount1(6,20);
    Money amount2(10,30);

    ASSERT(amount1.asCents() == 620);
    ASSERT(amount2.asCents() == 1030);

    amount1.split(amount2);

    ASSERT(amount1.getDollars() == 8);
    ASSERT(amount1.getCents() == 25);
    ASSERT(amount1.asCents() == 825);
    ASSERT(amount2.getDollars() == 8);
    ASSERT(amount2.getCents() == 25);
    ASSERT(amount2.asCents() == 825);

    return TR_PASS;
}

TestResult test_SplitMoneyTwo() {
    Money amount1(4,27);
    Money amount2(1,34);

    ASSERT(amount1.asCents() == 427);
    ASSERT(amount2.asCents() == 134);

    amount1.split(amount2);

    ASSERT(amount1.getDollars() == 2);
    ASSERT(amount1.getCents() == 80);
    ASSERT(amount1.asCents() == 280);
    ASSERT(amount2.getDollars() == 2);
    ASSERT(amount2.getCents() == 80);
    ASSERT(amount2.asCents() == 280);

    return TR_PASS;
}

TestResult test_SplitMoneyThree() {
    Money amount1(6,120);
    Money amount2(7,10);

    ASSERT(amount1.asCents() == 720);
    ASSERT(amount2.asCents() == 710);

    amount1.subtract(amount2);
    amount1.split(amount2);

    ASSERT(amount1.getDollars() == 3);
    ASSERT(amount1.getCents() == 60);
    ASSERT(amount1.asCents() == 360);
    ASSERT(amount2.getDollars() == 3);
    ASSERT(amount2.getCents() == 60);
    ASSERT(amount2.asCents() == 360);

    return TR_PASS;
}

TestResult test_SplitMoneyFour() {
    Money amount1(6,120);
    Money amount2(6,120);

    ASSERT(amount1.asCents() == 720);
    ASSERT(amount2.asCents() == 720);

    amount1.split(amount2);

    ASSERT(amount1.getDollars() == 7);
    ASSERT(amount1.getCents() == 20);
    ASSERT(amount1.asCents() == 720);
    ASSERT(amount2.getDollars() == 7);
    ASSERT(amount2.getCents() == 20);
    ASSERT(amount2.asCents() == 720);

    return TR_PASS;
}

TestResult test_SplitMoneyFive() {
    Money amount1(7,120);
    Money amount2(5,178);

    ASSERT(amount1.asCents() == 820);
    ASSERT(amount2.asCents() == 678);

    amount1.subtract(amount2);
    amount1.split(amount2);

    ASSERT(amount1.getDollars() == 4);
    ASSERT(amount1.getCents() == 10);
    ASSERT(amount1.asCents() == 410);
    ASSERT(amount2.getDollars() == 4);
    ASSERT(amount2.getCents() == 10);
    ASSERT(amount2.asCents() == 410);

    return TR_PASS;
}

TestResult test_SplitMoneySix() {
    Money amount1(1,20);
    Money amount2(5,91);

    ASSERT(amount1.asCents() == 120);
    ASSERT(amount2.asCents() == 591);

    amount1.split(amount2);

    ASSERT(amount1.getDollars() == 3);
    ASSERT(amount1.getCents() == 55);
    ASSERT(amount1.asCents() == 355);
    ASSERT(amount2.getDollars() == 3);
    ASSERT(amount2.getCents() == 55);
    ASSERT(amount2.asCents() == 355);

    return TR_PASS;
}

TestResult test_SplitMoneySeven() {
    Money amount1(1,20);
    Money amount2(5,90);

    ASSERT(amount1.asCents() == 120);
    ASSERT(amount2.asCents() == 590);

    amount1.split(amount2);

    ASSERT(amount1.getDollars() == 3);
    ASSERT(amount1.getCents() == 55);
    ASSERT(amount1.asCents() == 355);
    ASSERT(amount2.getDollars() == 3);
    ASSERT(amount2.getCents() == 55);
    ASSERT(amount2.asCents() == 355);

    return TR_PASS;
}

TestResult test_SplitMoneyEight() {
    Money amount1(167,22);
    Money amount2(145,93);

    ASSERT(amount1.asCents() == 16722);
    ASSERT(amount2.asCents() == 14593);

    amount1.split(amount2);

    ASSERT(amount1.getDollars() == 156);
    ASSERT(amount1.getCents() == 57);
    ASSERT(amount1.asCents() == 15657);
    ASSERT(amount2.getDollars() == 156);
    ASSERT(amount2.getCents() == 57);
    ASSERT(amount2.asCents() == 15657);

    return TR_PASS;
}

TestResult test_SplitMoneyNine() {
    Money amount1(167,22);
    Money amount2(145,94);

    ASSERT(amount1.asCents() == 16722);
    ASSERT(amount2.asCents() == 14594);

    amount1.split(amount2);

    ASSERT(amount1.getDollars() == 156);
    ASSERT(amount1.getCents() == 58);
    ASSERT(amount1.asCents() == 15658);
    ASSERT(amount2.getDollars() == 156);
    ASSERT(amount2.getCents() == 58);
    ASSERT(amount2.asCents() == 15658);

    return TR_PASS;
}

TestResult test_TaskFour() {
    Money amount1(6,222);
    Money amount2(7,93);

    ASSERT(amount1.asCents() == 822);
    ASSERT(amount2.asCents() == 793);

    amount1.subtract(amount2);
    amount1.split(amount2);

    ASSERT(amount1.getDollars() == 4);
    ASSERT(amount1.getCents() == 11);
    ASSERT(amount1.asCents() == 411);
    ASSERT(amount2.getDollars() == 4);
    ASSERT(amount2.getCents() == 11);
    ASSERT(amount2.asCents() == 411);

    amount2.add(amount1);
    amount2.split(amount1);

    ASSERT(amount1.getDollars() == 6);
    ASSERT(amount1.getCents() == 16);
    ASSERT(amount1.asCents() == 616);
    ASSERT(amount2.getDollars() == 6);
    ASSERT(amount2.getCents() == 16);
    ASSERT(amount2.asCents() == 616);




    return TR_PASS;
}

#endif /*ENABLE_T4_TESTS*/

/*
This function collects up all the tests as a vector of function pointers. If you create your own
tests and want to be able to run them, make sure you add them to the `tests` vector here.
*/
vector<TestResult (*)()> generateTests() {
    vector<TestResult (*)()> tests;

    tests.push_back(&test_functionTotalValid);
    tests.push_back(&test_functionTotalInvalid);
    tests.push_back(&test_functionSumValid);
    tests.push_back(&test_functionSumInvalid);
    tests.push_back(&test_functionSplitValid);
    tests.push_back(&test_functionSplitInvalid);

#ifdef ENABLE_T2_TESTS
    tests.push_back(&test_DefaultMoney);
    tests.push_back(&test_InvalidMoneyOne);
    tests.push_back(&test_InvalidMoneyTwo);
    tests.push_back(&test_InvalidMoneyThree);
    tests.push_back(&test_InvalidMoneyFour);
    tests.push_back(&test_InvalidMoneyFive);
    tests.push_back(&test_InvalidMoneySix);
    tests.push_back(&test_SimpleMoney);
    tests.push_back(&test_WrappingMoney);
#endif /*ENABLE_T2_TESTS*/

#ifdef ENABLE_T3_TESTS
    tests.push_back(&test_addDollars);
    tests.push_back(&test_addDollarsTwo);
    tests.push_back(&test_addDollarsInvalidOne);
    tests.push_back(&test_addDollarsInvalidTwo);
    tests.push_back(&test_addCents);
    tests.push_back(&test_addCentsTwo);
    tests.push_back(&test_addCentsThree);
    tests.push_back(&test_subtractDollars);
    tests.push_back(&test_subtractDollarsTwo);
    tests.push_back(&test_subtractDollarsThree);
    tests.push_back(&test_subtractDollarsFour);
    tests.push_back(&test_subtractDollarsFive);
    tests.push_back(&test_subtractDollarsSix);
    tests.push_back(&test_subtractDollarsSeven);
    tests.push_back(&test_subtractDollarsEight);
    tests.push_back(&test_subtractDollarsNine);
    tests.push_back(&test_subtractCents);
    tests.push_back(&test_subtractCentsTwo);
    tests.push_back(&test_subtractCentsThree);
    tests.push_back(&test_subtractCentsFour);
    tests.push_back(&test_subtractCentsFive);
    tests.push_back(&test_subtractCentsSix);
    tests.push_back(&test_subtractCentsSeven);
    tests.push_back(&test_subtractCentsEight);
    tests.push_back(&test_subtractCentsNine);
    tests.push_back(&test_subtractIgnore);
    tests.push_back(&test_taskThree);
#endif /*ENABLE_T3_TESTS*/

#ifdef ENABLE_T4_TESTS
    tests.push_back(&test_AddMoney);
    tests.push_back(&test_AddMoneyTwo);
    tests.push_back(&test_AddMoneyThree);
    tests.push_back(&test_AddMoneyFour);
    tests.push_back(&test_AddMoneyFive);
    tests.push_back(&test_SubtractMoney);
    tests.push_back(&test_SubtractMoneyTwo);
    tests.push_back(&test_SubtractMoneyThree);
    tests.push_back(&test_SubtractMoneyFour);
    tests.push_back(&test_SubtractMoneyFive);
    tests.push_back(&test_SplitMoney);
    tests.push_back(&test_SplitMoneyTwo);
    tests.push_back(&test_SplitMoneyThree);
    tests.push_back(&test_SplitMoneyFour);
    tests.push_back(&test_SplitMoneyFive);
    tests.push_back(&test_SplitMoneySix);
    tests.push_back(&test_SplitMoneySeven);
    tests.push_back(&test_SplitMoneyEight);
    tests.push_back(&test_SplitMoneyNine);
    tests.push_back(&test_TaskFour);
#endif /*ENABLE_T4_TESTS*/

    return tests;
}

int main(int argc, char const* argv[]) {
    // If one or more test numbers are passed as command-line parameters, execute them
    vector<TestResult (*)()> tests_to_run = generateTests();
    unsigned int pass_count = 0;
    unsigned int fail_count = 0;
    unsigned int run_count = 0;
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            unsigned int test_num = atoi(argv[i]);
            if (test_num > tests_to_run.size()) {
                cout << "ERROR: unknown test case " << test_num << endl;
                continue;
            }
            // run the test
            ++run_count;
            TestResult result = tests_to_run[test_num]();
            if (result == TR_FAIL) {
                cout << "FAIL: Test " << test_num << " failed." << endl;
                ++fail_count;
            } else {
                cout << "PASS: Test " << test_num << " passed." << endl;
                ++pass_count;
            }
        }
    } else {
        // otherwise, run all tests
        // Make sure to update this section as you add more tests
        // Add the tests for the first task
        for (unsigned int t = 0; t < tests_to_run.size(); ++t) {
            ++run_count;
            TestResult result = tests_to_run[t]();
            if (result == TR_FAIL) {
                cout << "FAIL: Test " << t << " failed." << endl;
                ++fail_count;
            } else {
                cout << "PASS: Test " << t << " passed." << endl;
                ++pass_count;
            }
        }
    }
    cout << "\n-------------------------------------------------\n"
         << "Total Run: " << run_count << "\n"
         << "Total PASSED: " << pass_count << "\n"
         << "Total FAILED: " << fail_count << "\n"
         << "-------------------------------------------------\n" << endl;

    // Return 0 if everything was OK
    return 0;
}
