#pragma once 
#ifndef LEXER_HPP
#define LEXER_HPP

//Dependecies
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <optional>
using namespace std;

enum Tokens {
  INT_SPT,
  VARIABLE,
  PRINTL,
  VOID_SPT,
  SEMICOLON,
  COLON,
  ASSIGNMENT, 
  FUNCTION,
  IDENTIFIER,
  OPEN_PAREN,
  CLOSE_PAREN,
  OPEN_BRAC_CURL,
  CLOSE_BRAC_CURL,
  MULTIPLY,
  ADD,
  SUBTRACT,
  DIVIDE,
  EQUALS,
  LTE,
  GTE
};

struct Token {
  Tokens type;
  optional<string>value;
};

void Tokenize(const string input);
string tokenTypeToString(Tokens type);
string readfile(const string& filename);

#endif
