#include "../headers/backend/Lexer.hpp"

//HELPER FUNCTION IN DEBUGING 
string tokenTypeToString(Tokens type) {
  switch(type) {
    case INT_SPT: return "INT_SPT";
    case PRINTL: return "PRINTL";
    case VOID_SPT: return "VOID_SPT";
    case SEMICOLON: return "SEMICOLON";
    case ASSIGNMENT: return "ASSIGNMENT";
    case FUNCTION: return "FUNCTION";
    case OPEN_PAREN: return "OPEN PARENTHESIS";
    case CLOSE_PAREN: return "CLOSE PARENTHESIS";
    case OPEN_BRAC_CURL: return "OPEN CURLY BRACKETS";
    case CLOSE_BRAC_CURL: return "CLOSE CURLY BRACKETS";
    case IDENTIFIER: return "IDENTIFIER";
    case COLON: return "COLON";
    case MULTIPLY: return "MULTIPLY";
    case ADD: return "ADD";
    case SUBTRACT: return "SUBTRACT";
    case DIVIDE: return "DIVIDE";
    default: return "UNKNOWN";
  }
}

void Tokenize(const string input){
  vector <Token> tokens;
  size_t pos = 0;

  while (pos < input.length()){
    if (isdigit(input[pos])){
      size_t start = pos;
      while(pos < input.length() && isdigit(input[pos])) pos++;
      tokens.push_back({INT_SPT, input.substr(start, pos-start)}); 
      pos++;
    }else if (input[pos] == ';'){
      tokens.push_back({SEMICOLON, nullopt}); 
      pos++;
    }else if (input[pos] == ':') {
      tokens.push_back({COLON, nullopt});
      pos++;
    }else if (input[pos] == '('){
      tokens.push_back({OPEN_PAREN, nullopt}); 
      pos++;
    } else if (input[pos] == ')'){
      tokens.push_back({CLOSE_PAREN, nullopt}); 
      pos++;
    }else if (input[pos] == '{'){
      tokens.push_back({OPEN_BRAC_CURL, nullopt}); 
      pos++;
    } else if (input[pos] == '}'){
      tokens.push_back({CLOSE_BRAC_CURL, nullopt}); 
      pos++;
    } else if (input[pos] == '='){
      tokens.push_back({ASSIGNMENT,nullopt});
      pos++;
    } else if (input[pos] == '*') {
      tokens.push_back({MULTIPLY, nullopt});
      pos++;
    }  else if (input[pos] == '+') {
      tokens.push_back({ADD, nullopt});
      pos++;
    } else if (input[pos] == '-') {
      tokens.push_back({SUBTRACT, nullopt});
      pos++;
    } else if (input[pos] == '/') {
      tokens.push_back({DIVIDE, nullopt});
      pos++;
    } else if (isalpha(input[pos])) {
      size_t start = pos;
      while(pos < input.length() && input[pos] != ' ' && input[pos] != ':' && input[pos] != '(' && input[pos] != ';' && input[pos] != ')') pos++;
      string valToken = input.substr(start, pos-start);
      if (valToken == "void"){
        tokens.push_back({VOID_SPT, nullopt}); 
      }else if (valToken == "printl"){
        tokens.push_back({PRINTL, nullopt});
      }else {
        tokens.push_back({IDENTIFIER, input.substr(start, pos-start)}); 
      }
    } else {
      pos++;
    }

  }
  for (const auto& token : tokens) {
    cout << "Token Type: " << tokenTypeToString(token.type);
    if (token.value) {
      cout << ", Value: " << token.value.value() << endl;  // Print value if present
    } else {
      cout << ", Value: None" << endl;  // Indicate that there's no value
    }
  }
}
string readfile(const string& filename) {
  ifstream file(filename);
  if (!file) {
    throw runtime_error("could not open the file!");
  }
  stringstream buffer;
  buffer << file.rdbuf();  
  return buffer.str();      
}



int main(int arg, char *argv[]) {
  ifstream inputFile(argv[1]);
  if (!inputFile) {
    cerr << "Error opening file" << endl;
    return 0;
  };
  string content = readfile(argv[1]);
  Tokenize(content);
  return 0;
}
