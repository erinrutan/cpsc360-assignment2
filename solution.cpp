//  CPSC 360 - Erin Rutan - assignment 2 - 2/23/2021
//
//  solution.cpp
//
//  Created by Roberto Flores on 12/21/16.
//  Copyright © 2016 Roberto Flores. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// lists of numbers to use to translate from integers to strings
string zeroToNineteen[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
		"nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
		"seventeen", "eighteen", "nineteen"};

string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};


int stringToInt(string input) {
	// takes a string and returns it as an integer
	istringstream iss (input);
	int intNum;
	iss >> intNum;
	return intNum;
}

string lengthOne(string input) {
	return zeroToNineteen[stringToInt(input)];
}

string lengthTwo(string input) {
	// could get weird thing from lengthThree, so check for that
	if (input.length() < 2) {
		return lengthOne(input);
	}
	// get the first digit and second digit
	int firstDigit = stringToInt(input.substr(0,1));
	int secondDigit = stringToInt(input.substr(1,1));
	// if first digit is 0 or 1, return the string corresponding to that number
	if (firstDigit == 0 || firstDigit == 1) {
		return zeroToNineteen[stringToInt(input)];
	}
	// if the number is an increment of ten, don't return "twenty-zero"
	else if (secondDigit == 0) {
		return tens[firstDigit - 2];
	}
	// else, return the number in string form (e.g 21 -> "twenty-one")
	else {
		return tens[firstDigit - 2] + "-" + zeroToNineteen[secondDigit];
	}
}

string lengthThree(string input) {
	// could get weird thing from lengthFour, so check for that
	if (input.length() < 3) {
		return lengthTwo(input);
	}
	// get the first digit and last two
	int firstDigit = stringToInt(input.substr(0,1));
	int lastTwo = stringToInt(input.substr(1,2));
	// get the second and last digits to check if all zeros
	int secondDigit = stringToInt(input.substr(1,1));
	int thirdDigit = stringToInt(input.substr(2,1));
	// if all zeros, add nothing
	if (firstDigit == 0 && secondDigit == 0 && thirdDigit == 0) {
		return "";
	}

	// if last two are 0s just return the hundred
	else if (secondDigit == 0 && thirdDigit == 0) {
		return zeroToNineteen[firstDigit] + " hundred";
	}
	// if first digit is 0, treat it like a two digit number
	else if (firstDigit == 0) {
		return lengthTwo(to_string(lastTwo));
	}
	// else, return whatever hundred and [two digit number]
	else {
		return zeroToNineteen[firstDigit] + " hundred and " + lengthTwo(to_string(lastTwo));
	}
}

string lengthFour(string input) {
	// could get weird thing from lengthFive, so check for that
	if (input.length() < 4) {
		return lengthThree(input);
	}
	// get the digits (to check how to output)
	int firstDigit = stringToInt(input.substr(0,1));
	int secondDigit = stringToInt(input.substr(1,1));
	int thirdDigit = stringToInt(input.substr(2,1));
	int fourthDigit = stringToInt(input.substr(3,1));
	// get last three to handle like 3 digit number
	int lastThree = stringToInt(input.substr(1,3));
	// if first digit is 0, treat it like a three digit number
	if (firstDigit == 0) {
		return lengthThree(to_string(lastThree));
	}
	if (secondDigit == 0 && thirdDigit == 0 && fourthDigit == 0) {
		return zeroToNineteen[firstDigit] + " thousand";
	}
	// if the second digit is a zero (i.e. 2,045) -> num thousand and num
	else if (secondDigit == 0) {
		return zeroToNineteen[firstDigit] + " thousand and " + lengthThree(to_string(lastThree));
	}
	// else, (2,345) return whatever num thousand, num
	else {
		return zeroToNineteen[firstDigit] + " thousand, " + lengthThree(to_string(lastThree));
	}
}

string lengthFive(string input) {
	// could get weird thing from lengthSix, so check for that
	if (input.length() < 5) {
		return lengthFour(input);
	}
	// get the digits to determine how to output
	int thirdDigit = stringToInt(input.substr(2,1));
	int fourthDigit =  stringToInt(input.substr(3,1));
	int fifthDigit =  stringToInt(input.substr(4,1));
	// get first two and last three to handle as 2 and 3 digit numbers
	int firstTwo = stringToInt(input.substr(0,2));
	int lastThree = stringToInt(input.substr(2,3));
	// if last three == 0, just thousand
	if (thirdDigit == 0 && fourthDigit == 0 && fifthDigit == 0) {
		return lengthTwo(to_string(firstTwo)) + " thousand";
	}
	// if third digit is 0, (i.e. 24,089) -> num thousand and num
	if (thirdDigit == 0) {
		return lengthTwo(to_string(firstTwo)) + " thousand and " + lengthThree(to_string(lastThree));
	}
	// else,(24,367) return num thousand, num
	else {
		return lengthTwo(to_string(firstTwo))  + " thousand, " + lengthThree(to_string(lastThree));
	}
}

string lengthSix(string input) {
	// could get weird thing from lengthSeven or lengthEight, or lengthNine, so check for that
	if (input.length() < 6) {
		return lengthFive(input);
	}
	// get digits to determine how to output
	int firstDigit = stringToInt(input.substr(0,1));
	int secondDigit = stringToInt(input.substr(1,1));
	int thirdDigit = stringToInt(input.substr(2,1));
	int fourthDigit = stringToInt(input.substr(3,1));
	int fifthDigit = stringToInt(input.substr(4,1));
	int sixthDigit = stringToInt(input.substr(5,1));
	// get first three and last three to handle as 3 digit numbers
	int firstThree = stringToInt(input.substr(0,3));
	int lastThree = stringToInt(input.substr(3,3));

	// if first three digits are 0, skip to last three digits
	if (firstDigit == 0 && secondDigit == 0 && thirdDigit == 0) {
		return lengthThree(to_string(lastThree));
	}
	// if last three are zeros, it's just num thousand
	else if (fourthDigit == 0 && fifthDigit == 0 && sixthDigit == 0) {
		return lengthThree(to_string(firstThree)) + " thousand";
	}
	// if fourth digit is 0, (i.e. 247,089) -> num thousand and num
	else if (fourthDigit == 0) {
		return lengthThree(to_string(firstThree)) + " thousand and " + lengthThree(to_string(lastThree));
	}
	// else,(274,367) return num thousand, num
	else {
		return lengthThree(to_string(firstThree))  + " thousand, " + lengthThree(to_string(lastThree));
	}
}

string lengthSeven(string input) {
	// get the digits to determine how to output
	int firstDigit = stringToInt(input.substr(0,1));
	int secondDigit = stringToInt(input.substr(1,1));
	int thirdDigit = stringToInt(input.substr(2,1));
	int fourthDigit = stringToInt(input.substr(3,1));
	int fifthDigit = stringToInt(input.substr(4,1));
	// get last 6 to handle with lengthSix func, last 3 to handle with lengthThree
	int lastSix = stringToInt(input.substr(1,6));
	int lastThree = stringToInt(input.substr(4,3));
	// check if last six digits are zeros, if so then just num million
	int count = 0;
	for (int j = 0; j < to_string(lastSix).length(); j++) {
		if (stringToInt(to_string(lastSix).substr(j,1)) == 0) {
			count++;
		}
		if (count == to_string(lastSix).length()) {
			return zeroToNineteen[firstDigit] + " million";
		}
	}
	// if middle digits 0, (i.e. 1,000,089) -> num million and (three digit num)
	if (secondDigit == 0 && thirdDigit == 0 && fourthDigit == 0 && fifthDigit == 0) {
		return zeroToNineteen[firstDigit] + " million and " + lengthThree(to_string(lastThree));
	}
	// else,(1,274,367) return num million, (6 digit num)
	else {
		return zeroToNineteen[firstDigit]  + " million, " + lengthSix(to_string(lastSix));
	}
}

string lengthEight(string input) {
	// get digits to determine how to output
	int thirdDigit = stringToInt(input.substr(2,1));
	int fourthDigit = stringToInt(input.substr(3,1));
	int fifthDigit = stringToInt(input.substr(4,1));
	int sixthDigit = stringToInt(input.substr(5,1));
	// get first two, last six and last three to handle with separate functions
	int firstTwo = stringToInt(input.substr(0,2));
	int lastSix = stringToInt(input.substr(2,6));
	int lastThree = stringToInt(input.substr(5,3));
	// check if last six digits are zeros, if so then just num million
	int count = 0;
	for (int j = 0; j < to_string(lastSix).length(); j++) {
		if (stringToInt(to_string(lastSix).substr(j,1)) == 0) {
			count++;
		}
		if (count == to_string(lastSix).length()) {
			return lengthTwo(to_string(firstTwo)) + " million";
		}
	}
	// if middle four 0, (i.e. 13,000,089) -> num million and (three digit num)
	if (thirdDigit == 0 && fourthDigit == 0 && fifthDigit == 0 && sixthDigit == 0) {
		return lengthTwo(to_string(firstTwo)) + " million and " + lengthSix(to_string(lastThree));
	}
	// else,(13,274,367) return num million, (6 digit num)
	else {
		return lengthTwo(to_string(firstTwo)) + " million, " + lengthSix(to_string(lastSix));
	}
}

string lengthNine(string input) {
	// get the digits to determine how to output
	int fourthDigit = stringToInt(input.substr(3,1));
	int fifthDigit = stringToInt(input.substr(4,1));
	int sixthDigit = stringToInt(input.substr(5,1));
	int seventhDigit = stringToInt(input.substr(6,1));
	// get first three, last six and last three to handle with functions
	int firstThree = stringToInt(input.substr(0,3));
	int lastSix = stringToInt(input.substr(3,6));
	int lastThree = stringToInt(input.substr(6,3));
	// check if last six digits are zeros, if so then just num million
	int count = 0;
	for (int j = 0; j < to_string(lastSix).length(); j++) {
		if (stringToInt(to_string(lastSix).substr(j,1)) == 0) {
			count++;
		}
		if (count == to_string(lastSix).length()) {
			return lengthThree(to_string(firstThree)) + " million";
		}
	}
	// if middle four digits 0, (i.e. 132,000,089) -> num million and (three digit num)
	if ((fourthDigit == 0) && (fifthDigit == 0) && (sixthDigit == 0) && (seventhDigit == 0)) {
		return lengthThree(to_string(firstThree)) + " million and " + lengthThree(to_string(lastThree));
	}
	// else,(132,274,367) return num million, (6 digit num)
	else {
		return lengthThree(to_string(firstThree)) + " million, " + lengthSix(to_string(lastSix));
	}
}

vector<string>* process(vector<unsigned long>& input) {
	// get number of numbers to translate
	int numNumbers = input.size();

	// create output vector, will hold the string translations of numbers in input
	vector<string>* output = new vector<string>();

	for (int i = 0; i < numNumbers; i++) {
		// get number to translate and turn it into a string
		string strNum = to_string(input[i]);

		// get the length of the number
		int numLength = strNum.length();

		// check number length and handle accordingly with separate function
		string translation = "";
		switch (numLength) {
			case 1:
				translation = lengthOne(strNum);
				output->push_back(translation);
				break;
			case 2:
				translation = lengthTwo(strNum);
				output->push_back(translation);
				break;
			case 3:
				translation = lengthThree(strNum);
				output->push_back(translation);
				break;
			case 4:
				translation = lengthFour(strNum);
				output->push_back(translation);
				break;
			case 5:
				translation = lengthFive(strNum);
				output->push_back(translation);
				break;
			case 6:
				translation = lengthSix(strNum);
				output->push_back(translation);
				break;
			case 7:
				translation = lengthSeven(strNum);
				output->push_back(translation);
				break;
			case 8:
				translation = lengthEight(strNum);
				output->push_back(translation);
				break;
			case 9:
				translation = lengthNine(strNum);
				output->push_back(translation);
				break;
			default:
				cout << "something has gone terribly wrong" << endl;
		}
	}
	return output;
}


