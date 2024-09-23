//******************************************************************************
// File name:   main.cpp
// Author:      Cole Kashiwamura
// Date:        09/22/24
// Class:       CS200-01
// Assignment:  Base Converter
// Purpose:     Conversions between binary, decimal, and hexadecimal
// Hours:       2.5
//******************************************************************************
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int hexCharToInt(char hexDigit);
char getBase (const std::string& strNumber);
std::string getNumber (const std::string& prompt);
void printTitle (const std::string& myTitle);
std::string binaryToDecimal (const std::string& strNumber);
std::string decimalToBinary (const std::string& strNumber);
std::string decimalToHex (const std::string& strNumber);
std::string hexToDecimal (const std::string& strNumber);
std::string hexToBinary (const std::string& strNumber);
std::string binaryToHex (const std::string& strNumber);

int main () {
  const std::string TITLE = "*****HEX-DECIMAL-BINARY CONVERTER*****";
  const std::string PROMPT = "Enter your string to convert (q to quit): ";

  std::string number;

  printTitle(TITLE);
  do {
    std::cout << std::endl;
    number = getNumber(PROMPT);
    if (number != "q") {
      if (getBase(number) == 'D') {
        std::cout << "The binary conversion is: " << decimalToBinary(number) 
                  << std::endl;
        std::cout << "The hexadecimal conversion is: " << decimalToHex(number) 
                  << std::endl;
      } else if (getBase(number) == 'H') {
        std::cout << "The decimal conversion is: " << hexToDecimal(number) 
                  << std::endl;
        std::cout << "The binary conversion is: " << hexToBinary(number) 
                  << std::endl;
      } else {
        std::cout << "The decimal conversion is: " << binaryToDecimal(number) 
                  << std::endl;
        std::cout << "The hexadecimal conversion is: " << binaryToHex(number) 
                  << std::endl;
      }
    }
  } while (number != "q");
  
  return EXIT_SUCCESS;
}

int hexCharToInt(char hexDigit) {
  switch (hexDigit) {
    case '0':
      return 0;
      break;
    case '1':
      return 1;
      break;
    case '2':
      return 2;
      break;
    case '3':
      return 3;
      break;
    case '4':
      return 4;
      break;
    case '5':
      return 5;
      break;
    case '6':
      return 6;
      break;
    case '7':
      return 7;
      break;
    case '8':
      return 8;
      break;
    case '9':
      return 9;
      break;
    case 'A':
      return 10;
      break;
    case 'B':
      return 11;
      break;
    case 'C':
      return 12;
      break;
    case 'D':
      return 13;
      break;
    case 'E':
      return 14;
      break;
    case 'F':
      return 15;
      break;
  }
  return 0;
}

char getBase (const std::string& strNumber) {
  if (strNumber[1] == 'b') {
    return 'B';
  } else if (strNumber[1] == 'x') {
    return 'H';
  } else {
    return 'D';
  }
}

std::string getNumber (const std::string& prompt) {
  std::string number;

  std::cout << prompt;
  std::cin >> number;

  return number;
}

void printTitle (const std::string& myTitle) {
  std::cout << "**************************************" << std::endl 
            << myTitle << std::endl << "**************************************"
            << std::endl;
}

std::string binaryToDecimal (const std::string& strNumber) {
  int decimal = 0, length = strNumber.length() - 2, power;

  for (int index = 0; index < length; index++) {
    if (strNumber[index + 2] == '1') {
      power = length - (index + 1);
      decimal = decimal + pow(2, power);
    } 
  }

  return std::to_string(decimal);
}

std::string decimalToBinary (const std::string& strNumber) {
  string binary = "0b", digits = "";
  int quotient = stoi(strNumber), remainder;

  do {
    remainder = quotient % 2;
    digits = digits + std::to_string(remainder);
    quotient = quotient / 2;
  } while (quotient != 0);
  for (int index = digits.length(); index > -1; index--) {
    binary = binary + digits[index];
  }

  return binary;
}

std::string decimalToHex (const std::string& strNumber) {
  string hex = "0x", digits = "";
  int quotient = stoi(strNumber), remainder;

  do {
    remainder = quotient % 16;
    switch (remainder) {
      case 0:
        digits = digits + '0';
        break;
      case 1:
        digits = digits + '1';
        break;
      case 2:
        digits = digits + '2';
        break;
      case 3:
        digits = digits + '3';
        break;
      case 4:
        digits = digits + '4';
        break;
      case 5:
        digits = digits + '5';
        break;
      case 6:
        digits = digits + '6';
        break;
      case 7:
        digits = digits + '7';
        break;
      case 8:
        digits = digits + '8';
        break;
      case 9:
        digits = digits + '9';
        break;
      case 10:
        digits = digits + 'A';
        break;
      case 11:
        digits = digits + 'B';
        break;
      case 12:
        digits = digits + 'C';
        break;
      case 13:
        digits = digits + 'D';
        break;
      case 14:
        digits = digits + 'E';
        break;
      case 15:
        digits = digits + 'F';
        break;
    }
    quotient = quotient / 16;
  } while (quotient != 0);
  for (int index = digits.length(); index > -1; index--) {
    hex = hex + digits[index];
  }

  return hex;
}

std::string hexToDecimal (const std::string& strNumber) {
  int decimal = 0, length = strNumber.length() - 2, power;

  for (int index = 0; index < length; index++) {
    power = length - (index + 1);
    decimal = decimal + (hexCharToInt(strNumber[index + 2]) * pow(16, power));
  }

  return std::to_string(decimal);
}

std::string hexToBinary (const std::string& strNumber) {
  return decimalToBinary(hexToDecimal(strNumber));
}

std::string binaryToHex (const std::string& strNumber) {
  return decimalToHex(binaryToDecimal(strNumber));
}