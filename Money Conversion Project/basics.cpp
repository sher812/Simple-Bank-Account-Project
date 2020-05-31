
#include "basics.h"

int totalCents(int dollars, int cents) {
	if (dollars < 0 || cents < 0) {		//return -1 when money is negative
	  return -1;
	}
	return dollars*100 + cents;		//else return money in cents
}

int sumAsCents(int moneyOneDollars, int moneyOneCents, int moneyTwoDollars, int moneyTwoCents) {
	if (moneyOneDollars < 0 || moneyOneCents < 0 || moneyTwoDollars < 0 || moneyTwoCents < 0) {	//return -1 when money is negative
	  return -1;
	}
	return moneyOneDollars*100 + moneyOneCents + moneyTwoDollars*100 + moneyTwoCents;	//else return sum of money in cents
}

int split(int moneyOneDollars, int moneyOneCents, int moneyTwoDollars, int moneyTwoCents) {

	int a;

	if (moneyOneDollars < 0 || moneyOneCents < 0 || moneyTwoDollars < 0 || moneyTwoCents < 0) {	//return -1 when money is negative
	  return -1;
	}

	a = (moneyOneDollars*100 + moneyOneCents + moneyTwoDollars*100 + moneyTwoCents)/2;	//else return the money split in the form of cents
	return a;
}

