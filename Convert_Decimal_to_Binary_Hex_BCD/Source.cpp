//Updated on 9/18/2020 fixed the bin to hex and made the program loop 0 through 255 instead of asking for user input. Justin Ritchey 9/12/2020. This is for Program 0 of CIS310 Fall 2020. This program is intended to take a decimal number and convert the decimal to Binary, Hexadecimal and BCD

#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

//functions
string dec_to_binary(double);                                       //fucntion to translate decimal to binary
string dec_to_hex(double);                                          //function to translate decimal to hexadecimal
string dec_to_BCD(double);                                          //function to translate decimal to BCD
void print(string, string, string, int);                            //function to print out the results
ofstream output;




void main()
{
	string bcd = "";                                                //will hold the translated bcd number in a string
	string hex = "";                                                //will hold the translated hex number in a string
	string binary = "";                                             //will hold the translated binary number in a string
	output.open("output.txt");                                      //creating an output file to hold the results
	string spaces = "         ";


	cout << "Decimal" << spaces << "Binary" << spaces << " Hexadecimal" << spaces << " BCD\n";              //foramtting for header of output
	output << "Decimal" << spaces << "Binary" << spaces << " Hexadecimal" << spaces << " BCD\n";;

	for (int i = 0; i < 256;i++)                                   //will loop through all 256 decimals
	{
		binary = dec_to_binary(i);                                 //functions
		hex = dec_to_hex(i);
		bcd = dec_to_BCD(i);
		print(binary, hex, bcd, i);
	}
	system("pause");
}

string dec_to_binary(double decimal)                                //function to convert decimal to binary and send back the string result
{
	string binary = "";                                             //will hold the result in a string
	int dec_check = 0;                                              //int used to check for decimal points
	int swap = 0;                                                   //int used to swap value with a decimal point to one without a decimal point
	double dec_divide = 0;                                          //used to hold the decimal entered to divdie by and get the remainder

	dec_divide = decimal;


	while (dec_divide >= 1)                                         //loop to gather if the decimal has a remainder of 1 or 0 and then assign that number to the string
	{
		dec_divide = dec_divide / 2;                                //Will give either a number with a int or a real number

		dec_check = dec_divide * 10;                                //checking to see if the dec_divide is a real number
		dec_check = dec_check % 10;

		if (dec_check == 0)                                         //if dec_check is an int it would have a remainder of 0 and therefore be asigned a 1 for the binary code
		{
			binary = '0' + binary;
			swap = dec_divide;
			dec_divide = swap;
		}
		else                                                       //if dec_check does have a remainder it will be more than 0 and will be assigned a 1
		{
			binary = '1' + binary;
			swap = dec_divide;
			dec_divide = swap;
		}
	}

	while (binary.size() < 8)                                      //assiging extra 0's if the binary code is short
	{
		binary = '0' + binary;
	}

	binary.insert(4, 1, ' ');                                      //adding a space after the nibble

	return binary;
}

string dec_to_hex(double decimal)                                  //function to convert decmial to hexadecimal
{
	string hex = "";                                               //will hold the result in a string
	int hex_divide = 0;                                            //holds the decimal given by the user to convert   
	int r = 0;

	hex_divide = decimal;

	while (hex.size() < 2)                                         //loop to assign hex values
	{
		if (hex_divide > 16)                                       //if decimal number is over 16, will use the modulo to get remainder
		{
			r = hex_divide % 16;       
		}
		else if (hex_divide < 16)                                  //if decimal is under 16 will assign decimal as remainder
		{
			r = hex_divide;
		}

		if (r == 0)                                                //loop to assign value based on the remainder varaiable       
		{
			hex = '0' + hex;
		}
		if (r == 1)
		{
			hex = '1' + hex;
		}
		if (r == 2)
		{
			hex = '2' + hex;
		}
		if (r == 3)
		{
			hex = '3' + hex;
		}
		if (r == 4)
		{
			hex = '4' + hex;
		}
		if (r == 5)
		{
			hex = '5' + hex;
		}
		if (r == 6)
		{
			hex = '6' + hex;
		}
		if (r == 7)
		{
			hex = '7' + hex;
		}
		if (r == 8)
		{
			hex = '8' + hex;
		}
		if (r == 9)
		{
			hex = '9' + hex;
		}
		if (r == 10)
		{
			hex = 'A' + hex;
		}
		if (r == 11)
		{
			hex = 'B' + hex;
		}
		if (r == 12)
		{
			hex = 'C' + hex;
		}
		if (r == 13)
		{
			hex = 'D' + hex;
		}

		if (r == 14)
		{
			hex = 'E' + hex;
		}
		if (r == 15)
		{
			hex = 'F' + hex;
		}

		hex_divide = hex_divide / 16;                //making decimal into the left over for next remainder number         
		r = hex_divide;                              //setting remainder equal to this number
	}
	return hex;
}


string dec_to_BCD(double decimal)                    //function to convert decimal to BCD
{
	string bcd = "";                                 //stores the final value in a string
	string bcd1 = "";                                //stores temporary binary values to be stores into bcd
	double placeholder = 0;                          //holds a single digit of the decimal entered, to be used to get the individual binary codes for each digit
	int dec_divide = 0;                              //holds the decimal value entered by the user to be used to find the result

	dec_divide = decimal;


	while (dec_divide > 0)                           //loop to gather the BCD going digit by digit of the decimal entered
	{
		placeholder = dec_divide % 10;               //gathering the last digit first
		dec_divide /= 10;

		bcd1 = dec_to_binary(placeholder);           //using the binary function to gather the code

		bcd1.erase(0, 4);                            //removing the added four 0's

		bcd = bcd1 + bcd;                            //storing the indivudal binary codes for each digit into the bcd string

	}

	while (bcd.size() < 14)                         //making sure every bcd has 14 total characters
	{
		if (bcd.size() < 2)
		{
			bcd = "0000" + bcd;
			bcd = " " + bcd;
			bcd = "0000" + bcd;
			bcd = " " + bcd;
			bcd = "0000" + bcd;
			break;
		}
		else if (bcd.size() < 6)                         //if the decimal entered was single digit this add's eight 0's and the space
		{
			bcd = "0000" + bcd;
			bcd = " " + bcd;
			bcd = "0000" + bcd;
			break;
		}

		else                                        //anything more than 10 entered will only need four extra 0's max.
		{
			bcd = "0" + bcd;
		}
	}

	return bcd;
}

void print(string binary, string hex, string bcd, int decimal)             //printing out the results
{
	ofstream output;
	output.open("output.txt");                                             //creating an output file to hold the results

	cout << decimal;
	output << decimal;

	for (int i = 0; i < 15;i++)
	{
		cout << " ";
		output << " ";
	}

	cout << binary;
	output << binary;

	for (int i = 0; i < 7;i++)
	{
		cout << " ";
		output << " ";
	}

	cout << hex;
	output << hex;

	for (int i = 0; i < 19;i++)
	{
		cout << " ";
		output << " ";
	}

	cout << bcd << "\n";
	output << bcd;



}

