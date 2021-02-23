# cpsc360-assignment2

For some people,text-to-speech programs work better when reading numbers using words (e.g., one hundred and forty-two) rather than digits (e.g., 142). To help them, write a program totranslatenon-negative integers into wordsusing these rules:

•English has unique names for the numbers 0-19: “zero”, “one”, “two”, “three”, “four”, “five”, “six”, “seven”, "eight”, “nine”, “ten”, “eleven”, “twelve”,  “thirteen”, “fourteen”, “fifteen”, “sixteen”, “seventeen”, “eighteen”, “nineteen”.

•The  subsequent multiples of  10  are  named  “twenty”, “thirty”, “forty”, “fifty”, “sixty”, “seventy”, “eighty”, “ninety”.

•The combination of one of those multiples of ten with a digit 1-9 is always hyphenated: e.g., 31 ⇒“thirty-one”, 77 ⇒“seventy-seven”.

•Multiples of 100 are counted 1-9 and set off from any following non-zero digits by “and”: e.g., 200 ⇒“two hundred”, 412 ⇒“four hundred and twelve”, 777 ⇒“seven hundred and seventy-seven”.

•Thousands and millions are counted off using the above rules to form numbers 1-999, and are set off from any non-zero remainder by a comma: e.g., 1,253,101 ⇒“one million, two hundred and fifty-three thousand, one hundred and one”.

•If a number with a non-empty thousands/millions component is followed by a remainder of 1-99, then  instead  of  a  comma  the  parts  are  separated  by  “and”:  e.g.,  1,000,011 ⇒“one  million  and eleven”, 20,222,043 ⇒“twenty million, two hundred and twenty-two thousand and forty-three”.
