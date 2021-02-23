//
//  main.cpp
//
//  Created by Roberto Flores on 12/20/16.
//  Copyright © 2016 Roberto Flores. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

vector<string>* process(vector<unsigned long>& input);

int main() {
    vector<unsigned long> input;
    vector<string>        expected;
    string                failed;

    for (int test = 0; test < 11; test++) {
        input   .clear();
        expected.clear();
        switch (test) {
            case 0 :
                // both input and expected result are empty.
                break;
            case 1 : {
                int           size  =   1;
                unsigned long one[] = { 11 };
                string        two[] = { "eleven" };
                for (int i=0; i<size; i++) input   .push_back( one[i] );
                for (int i=0; i<size; i++) expected.push_back( two[i] );
            }   break;
            case 2 : {
                int           size  =   1;
                unsigned long one[] = { 222 };
                string        two[] = { "two hundred and twenty-two" };
                for (int i=0; i<size; i++) input   .push_back( one[i] );
                for (int i=0; i<size; i++) expected.push_back( two[i] );
            }   break;
            case 3 : {
                int           size  =   1;
                unsigned long one[] = { 33333 };
                string        two[] = { "thirty-three thousand, three hundred and thirty-three" };
                for (int i=0; i<size; i++) input   .push_back( one[i] );
                for (int i=0; i<size; i++) expected.push_back( two[i] );
            }   break;
            case 4 : {
                int           size  =   1;
                unsigned long one[] = { 444444444 };
                string        two[] = { "four hundred and forty-four million, four hundred and forty-four thousand, four hundred and forty-four" };
                for (int i=0; i<size; i++) input   .push_back( one[i] );
                for (int i=0; i<size; i++) expected.push_back( two[i] );
            }   break;
            case 5 : {
                int           size  =   3;
                unsigned long one[] = { 1, 222143, 1000001 };
                string        two[] = {
                    "one",
                    "two hundred and twenty-two thousand, one hundred and forty-three",
                    "one million and one"
                };
                for (int i=0; i<size; i++) input   .push_back( one[i] );
                for (int i=0; i<size; i++) expected.push_back( two[i] );
            }   break;
            case 6 : {
                int           size  =   36;
                unsigned long one[] = {
                     0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
                    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                    20, 21, 30, 32, 40, 43, 50, 54, 60, 65,
                    70, 76, 80, 87, 90, 98
                };
                string        two[] = {
                    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                    "twenty", "twenty-one", "thirty", "thirty-two", "forty", "forty-three", "fifty", "fifty-four", "sixty", "sixty-five",
                    "seventy", "seventy-six", "eighty", "eighty-seven", "ninety", "ninety-eight"
                };
                for (int i=0; i<size; i++) input   .push_back( one[i] );
                for (int i=0; i<size; i++) expected.push_back( two[i] );
            }   break;
            case 7 : {
                int           size  =   16;
                unsigned long one[] = {
                    112, 131, 244, 355, 466, 577, 688, 799, 4199, 9999,
                    49876, 55430, 77777, 99999, 650123, 999999
                };
                string        two[] = {
                    "one hundred and twelve",
                    "one hundred and thirty-one",
                    "two hundred and forty-four",
                    "three hundred and fifty-five",
                    "four hundred and sixty-six",
                    "five hundred and seventy-seven",
                    "six hundred and eighty-eight",
                    "seven hundred and ninety-nine",
                    "four thousand, one hundred and ninety-nine",
                    "nine thousand, nine hundred and ninety-nine",
                    "forty-nine thousand, eight hundred and seventy-six",
                    "fifty-five thousand, four hundred and thirty",
                    "seventy-seven thousand, seven hundred and seventy-seven",
                    "ninety-nine thousand, nine hundred and ninety-nine",
                    "six hundred and fifty thousand, one hundred and twenty-three",
                    "nine hundred and ninety-nine thousand, nine hundred and ninety-nine"
                };
                for (int i=0; i<size; i++) input   .push_back( one[i] );
                for (int i=0; i<size; i++) expected.push_back( two[i] );
            }   break;
            case 8 : {
                int           size  =   12;
                unsigned long one[] = {
                    201000, 321000, 32001234, 98123000, 65001011,
                    65123011, 120000000, 103000000, 123456789, 123000789,
                    777777777, 999999999
                };
                string        two[] = {
                    "two hundred and one thousand",
                    "three hundred and twenty-one thousand",
                    "thirty-two million, one thousand, two hundred and thirty-four",
                    "ninety-eight million, one hundred and twenty-three thousand",
                    "sixty-five million, one thousand and eleven",
                    "sixty-five million, one hundred and twenty-three thousand and eleven",
                    "one hundred and twenty million",
                    "one hundred and three million",
                    "one hundred and twenty-three million, four hundred and fifty-six thousand, seven hundred and eighty-nine",
                    "one hundred and twenty-three million, seven hundred and eighty-nine",
                    "seven hundred and seventy-seven million, seven hundred and seventy-seven thousand, seven hundred and seventy-seven",
                    "nine hundred and ninety-nine million, nine hundred and ninety-nine thousand, nine hundred and ninety-nine"
                };
                for (int i=0; i<size; i++) input   .push_back( one[i] );
                for (int i=0; i<size; i++) expected.push_back( two[i] );
            }   break;
            case 9 : {
                int           size  =   14;
                unsigned long one[] = {
                    100, 800, 1000, 5200, 10000,
                    61000, 100000, 1000000, 87012000, 200400000,
                    300040000, 400005000, 500000600, 100000000
                };
                string        two[] = {
                    "one hundred",
                    "eight hundred",
                    "one thousand",
                    "five thousand, two hundred",
                    "ten thousand",
                    "sixty-one thousand",
                    "one hundred thousand",
                    "one million",
                    "eighty-seven million, twelve thousand",
                    "two hundred million, four hundred thousand",
                    "three hundred million, forty thousand",
                    "four hundred million, five thousand",
                    "five hundred million, six hundred",
                    "one hundred million"
                };
                for (int i=0; i<size; i++) input   .push_back( one[i] );
                for (int i=0; i<size; i++) expected.push_back( two[i] );
            }   break;
            case 10 : {
                int           size  =   17;
                unsigned long one[] = {
                    102, 908, 1001, 2012, 3078,
                    20002, 30012, 72009, 400005, 540065,
                    765056, 2000003, 3000019, 20000123, 65001011,
                    600000070, 700000008
                };
                string        two[] = {
                    "one hundred and two",
                    "nine hundred and eight",
                    "one thousand and one",
                    "two thousand and twelve",
                    "three thousand and seventy-eight",
                    "twenty thousand and two",
                    "thirty thousand and twelve",
                    "seventy-two thousand and nine",
                    "four hundred thousand and five",
                    "five hundred and forty thousand and sixty-five",
                    "seven hundred and sixty-five thousand and fifty-six",
                    "two million and three",
                    "three million and nineteen",
                    "twenty million, one hundred and twenty-three",
                    "sixty-five million, one thousand and eleven",
                    "six hundred million and seventy",
                    "seven hundred million and eight"
                };
                for (int i=0; i<size; i++) input   .push_back( one[i] );
                for (int i=0; i<size; i++) expected.push_back( two[i] );
            }   break;
            default:
                cout << "we should never get here" << endl;
                return -1;
        }
        failed.clear();
        cout << "test " << setw(2) << test << ": ";
        vector<string>* actual = process( input );
        if (actual == NULL) {
            failed = "result was NULL";
        } else {
            if (actual->size() != expected.size()) {
                stringstream stream;
                stream << "incorrect result size: expected " << expected.size() << " but was " << actual->size();
                failed = stream.str();
            } else {
                for (long unsigned int i=0; i<expected.size(); i++) {
                    const string one = expected.at(i);
                    const string two = actual ->at(i);
                    if (one != two) {
                        stringstream stream;
                        stream << " incorrect result @ index " << i << ": expected '" << expected.at(i) << "' but was '" << actual->at(i) << "'";
                        failed = stream.str();
                        break;
                    }
                }
            }
        }
        cout << (failed.empty() ? "ok" : failed) << endl;
        delete actual;
    }
    return EXIT_SUCCESS;
}
