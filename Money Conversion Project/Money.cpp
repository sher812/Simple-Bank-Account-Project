
#include "Money.h"

Money::Money() {

	DolR = 0;	//dollar and cent variables are set to 0 when there is no input
	cntS = 0;
}

Money::Money(int dollars, int cents) {

	DolR = dollars;	//allocate the values of dollars and cents input to the private variables
	cntS = cents;

	if (DolR < 0) {
	DolR = 0;
	}

	if (cntS < 0) {
	cntS = 0;
	}
	
	if (cntS > 99) {
	cntS = cents%100;
	DolR = DolR + cents/100;
	}	
}

int Money::getDollars() const {

	return DolR + cntS/100;

}

int Money::getCents() const {

	return cntS%100;	//return the resulting amount of cents, taking into account the amount of dollars there will be
}

int Money::asCents() const {

	if (DolR < 0) {
		if (cntS < 0) {
		return 0;
		}
	return cntS;
	}
	
	if (DolR > 0 || DolR == 0) {
		if (cntS < 0) {	
		return DolR*100;
		}
	return DolR*100 + cntS; //return money value all in cents 
	}

	return DolR*100 + cntS;
}

void Money::addDollars(int dollars) {

	if (dollars > 0) {	//making sure that there are no negative values
	DolR = DolR + dollars;	//add the 'dollars' to our 'DolR' variable
	}
	
}

void Money::addCents(int cents) {

	if (cents > 0) {	//making sure that there are no negative values
	cntS = cntS + cents;	//add the 'cents' to our 'cntS' variable
	}
	
	DolR = DolR + cntS/100;	//making sure we do wrapping upwards
	cntS = cntS%100;
}

void Money::subtractDollars(int dollars) {

	if (dollars > 0) {	//making sure that there are no, and there will be no negative values
		if (DolR > dollars || DolR == dollars) {
		DolR = DolR - dollars;			//subtract the great 'DolR' value from 'dollars'
		}
	}
}

void Money::subtractCents(int cents) {

int sum = DolR*100 + cntS;
int Cen = cntS; //so that both if statements get compared with original cntS value

	if (cents > 0 && sum > cents) {	//making sure that there are no, and there will be no negative values

		if (Cen%100 > cents%100 || cntS%100 == cents%100) {
		cntS = cntS%100 - cents%100;
		DolR = DolR - cents/100;
		}
	
		if (Cen%100 < cents%100) {
		cntS = 100 - cents%100 + cntS%100;
		DolR = DolR - cents/100 - 1;
		}

 
	}

	if (sum == cents && cents > 0) {	//when both values are equal and non-zero
	 cntS = 0;
	 DolR = 0;
	}

}

void Money::add(const Money &other) {


	int sub = this->asCents();	//substitute copy for original value of asCents() because asCents() changes as 'DolR' and 'cntS' changes
	DolR = (sub + other.asCents())/100;	//'DolR' variable has now the 'other' value's dollars added on 
	cntS = (sub + other.asCents())%100;	//'cntS' variable has now the 'other' value's cents added on
}

void Money::subtract(const Money &other) {


	int sub = this->asCents(); //so that both if statements get compared with the original values

	if (sub > other.asCents()) {
		DolR = (sub - other.asCents())/100;	//'DolR' variable has now the 'other' value's dollars subtracted
		cntS = (sub - other.asCents())%100;	//'cntS' variable has now the 'other' value's cents subtracted
	}

	if (sub == other.asCents()) {
		DolR = 0;
		cntS = 0;
	}
}

void Money::split(Money &other) {

	int sum = this->asCents() + other.asCents(); //sum of the two monies
	DolR = (sum/2)/100;	//allocate split dollar value
	cntS = (sum/2)%100;	//allocate split cent value
	other.DolR = (sum/2)/100;	//allocate split dollar value to 'other'
	other.cntS = (sum/2)%100;	//allocate split cent value to 'other'
}

Money::~Money() {
	//TODO: implement
}
