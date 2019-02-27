#include <iostream>
#include <exception>
#include "../include/parser.hpp"
#include "../include/rpncalc.hpp"

using namespace sc;
using namespace std;

int main(int argc, char **argv)
{
  string expr = "";
  double result = 0.0;
  bool exit = false;

  cout << "sc v0.1" << endl;
  cout << "Written by F. Javier Perez - Type 'q' to exit" << endl;
  while (!exit) {
    cout << "? ";
    getline(cin,expr);
    exit = (expr == "q");
    if (!exit) {
      try {
        expr = parser::parse(expr);
        result = rpncalc::eval(expr);
        cout << "= " << result << endl;
      } catch (exception& e) {
        cout << "[ERROR] " << e.what() << endl;
      }
    }
  }
  return 0;
}
