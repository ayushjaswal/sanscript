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
  STRING_SPT,
  VARIABLE,
  FOR_LOOP,
  WHILE_LOOP,
  FOR_EACH,
  IF, 
  ELSE,
  ELIF,
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
