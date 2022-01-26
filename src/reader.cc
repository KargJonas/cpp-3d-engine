#include "./triangle.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <regex>

string readFile(string location) {
  fstream file;
  file.open(location, ios::in);

  if (!file.is_open()) {
    perror("Read file error");
    exit(EXIT_FAILURE);
  }
  
  string currentLine;

  while (getline(file, currentLine)) {
    std::regex removeText ("^endloop|^outer loop|^facet normal|^solid.*$|^endsolid.*$|^vertex|^endfacet");

    std::regex trim ("^\\s+|\\s+$");

    currentLine = std::regex_replace (currentLine, removeText, "");
    currentLine = std::regex_replace (currentLine, trim, "");

    if (currentLine.empty()) continue;

    std::cout << currentLine << std::endl;

    string str = "Geeks-for-Geeks";
 
    // Returns first token
    char *token = strtok(str, "-");
   
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }
 
    return 0;
  }

  file.close();

  return "lol";
}