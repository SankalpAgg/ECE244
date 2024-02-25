//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "Shape.h"
#include "globals.h"

// This is the shape array, to be dynamically allocated
Shape **shapesArray;

// The number of shapes in the database, to be incremented
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
string Name, type;
int locX, locY, sizeX, sizeY, Angle;

bool checkShapeName_list(string name) {
  for (int j = 0; j < 7; j++) {
    if (name == keyWordsList[j]) {
      return true;
    }
  }
  return false;
}

bool checkShapeName_type(string name) {
  for (int j = 0; j < 4; j++) {
    if (name == shapeTypesList[j]) {
      return true;
    }
  }
  return false;
}

bool checkShapeExist(string name) {
  for (int i = 0; i < shapeCount; i++)
    if (shapesArray[i] != NULL && shapesArray[i]->getName() == name) {
      return true;
    }
  return false;
}

bool callMaxError(stringstream &lineStream) {
  lineStream >> ws;
  lineStream >> max_shapes;

  if (lineStream.fail()) {
    if (lineStream.eof()) {
      cout << "Error: too few arguments" << endl;
      return true;
    } else {
      cout << "Error: invalid argument" << endl;
      return true;
    }
  }

  lineStream >> ws;
  if (!lineStream.fail()) {
    if (!lineStream.eof()) {
      if (lineStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        return true;
      } else {
        cout << "Error: too many arguments" << endl;
        return true;
      }
    }
  }

  if (max_shapes < 0) {
    cout << "Error: invalid value" << endl;
    return true;
  }
  return false;
}

bool callCreateError(stringstream &lineStream) {
  lineStream >> ws;
  if (lineStream.eof()) {
    cout << "Error: too few arguments" << endl;
    return true;
  }

  lineStream >> ws;
  lineStream >> Name;
  if (checkShapeName_list(Name) == true || checkShapeName_type(Name) == true) {
    cout << "Error: invalid shape name" << endl;
    return true;
  }
  if (checkShapeExist(Name) == true) {
    cout << "Error:"
         << " "
         << "shape"
         << " " << Name << " "
         << "exists" << endl;
    return true;
  }

  if (lineStream.eof()) {
    cout << "Error: too few arguments" << endl;
    return true;
  }

  lineStream >> ws;
  lineStream >> type;
  bool flag;
  for (int i = 0; i < 4; i++) {
    if (type == shapeTypesList[i]) {
      flag = true;
    }
  }
  if (flag == false) {
    cout << "Error:"
         << " invalid shape type" << endl;
    return true;
  }
  if (lineStream.fail()) {
    if (lineStream.eof()) {
      cout << "Error: too few arguments" << endl;
      return true;
    }
  }

  lineStream >> ws;
  lineStream >> locX;
  if (lineStream.fail()) {
    if (lineStream.eof()) {
      cout << "Error: too few arguments" << endl;
      return true;
    } else {
      cout << "Error: invalid argument" << endl;
      return true;
    }
  }

  if (!lineStream.fail()) {
    if (!lineStream.eof()) {
      if (lineStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        return true;
      } 
    }
  }

  if (locX < 0) {
    cout << "Error: invalid value" << endl;
    return true;
  }

  lineStream >> ws;
  lineStream >> locY;
  if (lineStream.fail()) {
    if (lineStream.eof()) {
      cout << "Error: too few arguments" << endl;
      return true;
    } else {
      cout << "Error: invalid argument" << endl;
      return true;
    }
  }

  if (!lineStream.fail()) {
    if (!lineStream.eof()) {
      if (lineStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        return true;
      } 
    }
  }

  if (locY < 0) {
    cout << "Error: invalid value" << endl;
    return true;
  }

  lineStream >> ws;
  lineStream >> sizeX;
  if (lineStream.fail()) {
    if (lineStream.eof()) {
      cout << "Error: too few arguments" << endl;
      return true;
    } else {
      cout << "Error: invalid argument" << endl;
      return true;
    }
  }

  if (!lineStream.fail()) {
    if (!lineStream.eof()) {
      if (lineStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        return true;
      } 
    }
  }

  if (sizeX < 0) {
    cout << "Error: invalid value" << endl;
    return true;
  }

  lineStream >> ws;
  lineStream >> sizeY;
  if (lineStream.fail()) {
    if (lineStream.eof()) {
      cout << "Error: too few arguments" << endl;
      return true;
    } else {
      cout << "Error: invalid argument" << endl;
      return true;
    }
  }
lineStream >> ws;
  if (!lineStream.fail()) {
    if (!lineStream.eof()) {
      if (lineStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        return true;
      } else {
        cout << "Error: too many arguments" << endl;
        return true;
      }
    }
  }

  if (sizeY < 0) {
    cout << "Error: invalid value" << endl;
    return true;
  }

  if (type == "circle") {
    if (sizeX != sizeY) {
      cout << "Error: invalid value" << endl;
      return true;
    }
  }
lineStream >> ws;
  if (!lineStream.fail()) {
    if (!lineStream.eof()) {
      cout << "Error: too many arguments" << endl;
      return true;
    }
  }

  if (max_shapes == shapeCount) {
    cout << "Error:"
         << " "
         << "shape array is full" << endl;
    return true;
  }

  return false;
}

bool callMoveError(stringstream &lineStream) {
  lineStream >> ws;
  if (lineStream.eof()) {
    cout << "Error: too few arguments" << endl;
    return true;
  }

  lineStream >> ws;
  lineStream >> Name;
  
  if (checkShapeName_list(Name) == true || checkShapeName_type(Name) == true) {
    cout << "Error: invalid shape name" << endl;
    return true;
  }
  if (checkShapeExist(Name) == false) {
    cout << "Error:"
         << " "
         << "shape"
         << " " << Name << " "
         << "not found" << endl;
    return true;
  }

  if (lineStream.eof()) {
    cout << "Error: too few arguments" << endl;
    return true;
  }

lineStream >> ws;
  lineStream >> locX;
  if (lineStream.fail()) {
    if (lineStream.eof()) {
      cout << "Error: too few arguments" << endl;
      return true;
    } else {
      cout << "Error: invalid argument" << endl;
      return true;
    }
  }

  if (!lineStream.fail()) {
    if (!lineStream.eof()) {
      if (lineStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        return true;
      } 
    }
  }

  if (locX < 0) {
    cout << "Error: invalid value" << endl;
    return true;
  }

  lineStream >> ws;
  lineStream >> locY;
  if (lineStream.fail()) {
    if (lineStream.eof()) {
      cout << "Error: too few arguments" << endl;
      return true;
    } else {
      cout << "Error: invalid argument" << endl;
      return true;
    }
  }
lineStream >> ws;
  if (!lineStream.fail()) {
    if (!lineStream.eof()) {
      if (lineStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        return true;
      } 
    }
  }

  if (locY < 0) {
    cout << "Error: invalid value" << endl;
    return true;
  }
  
lineStream >> ws;
  if (!lineStream.fail()) {
    if (!lineStream.eof()) {
      cout << "Error: too many arguments" << endl;
      return true;
    }
  }
  return false;
}

bool callRotateError(stringstream &lineStream) {
  lineStream >> ws;
  if (lineStream.eof()) {
    cout << "Error: too few arguments" << endl;
    return true;
  }

  lineStream >> ws;
  lineStream >> Name;
  lineStream >> ws;
  if (checkShapeName_list(Name) == true || checkShapeName_type(Name) == true) {
    cout << "Error: invalid shape name" << endl;
    return true;
  }
  if (checkShapeExist(Name) == false) {
    cout << "Error:"
         << " "
         << "shape"
         << " " << Name << " "
         << "not found" << endl;
    return true;
  }

  if (lineStream.eof()) {
    cout << "Error: too few arguments" << endl;
    return true;
  }

  lineStream >> ws;
  lineStream >> Angle;
  if (lineStream.fail()) {
    if (lineStream.eof()) {
      cout << "Error: too few arguments" << endl;
      return true;
    } else {
      cout << "Error: invalid argument" << endl;
      return true;
    }
  }
lineStream >> ws;
  if (!lineStream.fail()) {
    if (!lineStream.eof()) {
      if (lineStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        return true;
      } 
    }
  }

  if (Angle < 0 || Angle > 360) {
    cout << "Error: invalid value" << endl;
    return true;
  }
lineStream >> ws;
  if (!lineStream.fail()) {
    if (!lineStream.eof()) {
      cout << "Error: too many arguments" << endl;
      return true;
    }
  }
  return false;
}

bool callDrawError(stringstream &lineStream) {
  lineStream >> ws;
  if (lineStream.eof()) {
    cout << "Error: too few arguments" << endl;
    return true;
  }

  lineStream >> ws;
  lineStream >> Name;
  lineStream >> ws;
  if (Name == "all") {
    if (!lineStream.fail()) {
      if (!lineStream.eof()) {
        cout << "Error: too many arguments" << endl;
        return true;
      }
    }
  } else {
    if (checkShapeName_list(Name) == true ||
        checkShapeName_type(Name) == true) {
      cout << "Error: invalid shape name" << endl;
      return true;
    }
    if (checkShapeExist(Name) == false) {
      cout << "Error:"
           << " "
           << "shape"
           << " " << Name << " "
           << "not found" << endl;
      return true;
    }

    if (!lineStream.fail()) {
      if (!lineStream.eof()) {
        cout << "Error: too many arguments" << endl;
        return true;
      }
    }
  }
  return false;
}

bool callDeleteError(stringstream &lineStream) {
  lineStream >> ws;
  if (lineStream.eof()) {
    cout << "Error: too few arguments" << endl;
    return true;
  }

  lineStream >> ws;
  lineStream >> Name;
  lineStream >> ws;
  if (Name == "all") {
    if (!lineStream.fail()) {
      if (!lineStream.eof()) {
        cout << "Error: too many arguments" << endl;
        return true;
      }
    }
  } else {
    if (checkShapeName_list(Name) == true ||
        checkShapeName_type(Name) == true) {
      cout << "Error: invalid shape name" << endl;
      return true;
    }
    if (checkShapeExist(Name) == false) {
      cout << "Error:"
           << " "
           << "shape"
           << " " << Name << " "
           << "not found" << endl;
      return true;
    }

    if (!lineStream.fail()) {
      if (!lineStream.eof()) {
        cout << "Error: too many arguments" << endl;
        return true;
      }
    }
  }
  return false;
}

void formMaxArray(stringstream &lineStream) {
  if (callMaxError(lineStream) == true) {
    return;
  }
  delete[] shapesArray;
  shapesArray = NULL;
  shapeCount = 0;
  shapesArray = new Shape *[max_shapes];
  cout << "New database: max shapes is"
       << " " << max_shapes << endl;
  return;
}

void createShape(stringstream &lineStream) {
  if (callCreateError(lineStream) == true) {
    return;
  }
  shapesArray[shapeCount] = new Shape(Name, type, locX, locY, sizeX, sizeY);
  cout << "Created" << " ";
  shapesArray[shapeCount]->draw();
  shapeCount++;
}

void moveShape(stringstream &lineStream) {
  if (callMoveError(lineStream) == true) {
    return;
  }
  for (int i = 0; i < shapeCount; i++) {
    if (shapesArray[i] != NULL && shapesArray[i]->getName() == Name){
    shapesArray[i]->setXlocation(locX);
    shapesArray[i]->setYlocation(locY);
    cout << "Moved"
         << " " << Name << " "
         << "to"
         << " " << locX << " " << locY << endl;
    return;
    }
  }
}

void rotateShape(stringstream &lineStream) {
  if (callRotateError(lineStream) == true) {
    return;
  }
  for (int i = 0; i < shapeCount; i++) {
    if (shapesArray[i] != NULL && shapesArray[i]->getName() == Name){
    shapesArray[i]->setRotate(Angle);
    cout << "Rotated"
         << " " << Name << " "
         << "by"
         << " " << Angle << " "
         << "degrees" << endl;
    return;
    }
  }
}

void drawShape(stringstream &lineStream) {
  if (callDrawError(lineStream) == true) {
    return;
  }
  if (Name == "all") {
    cout << "Drew all shapes" << endl;
    for (int i = 0; i < shapeCount; i++) {
      if (shapesArray[i] != NULL) {
        shapesArray[i]->draw();
      }
    }
  } else {
    for (int i = 0; i < shapeCount; i++) {
      if (shapesArray[i] != NULL && shapesArray[i]->getName() == Name) {
        cout << "Drew" << " ";
        shapesArray[i]->draw();
        break;
      }
    }
  }
}

void deleteShape(stringstream &lineStream) {
  if (callDeleteError(lineStream) == true) {
    return;
  }
  if (Name == "all") {
    for (int i = 0; i < shapeCount; i++) {
      if (shapesArray[i] != NULL) {
        delete shapesArray[i];
      }
    }
    cout << "Deleted: all shapes" << endl;
    shapeCount = 0;
  } else {
    for (int i = 0; i < shapeCount; i++) {
      if (shapesArray[i] != NULL && shapesArray[i]->getName() == Name) {
        delete shapesArray[i];
        shapesArray[i] = NULL;
        cout << "Deleted shape"
             << " " << Name << " " << endl;
        break;
      }
    }
  }
}

int main() {
  string line;
  string command;

  cout << "> ";        // Prompt for input
  getline(cin, line);  // Get a line from standard input

  while (!cin.eof()) {
    // Put the line in a linestream for parsing
    // Making a new sstream for each line so flags etc. are cleared
    stringstream lineStream(line);
    // Read from string stream into the command
    // The only way this can fail is if the eof is encountered
    lineStream >> ws;
    lineStream >> command;

    if (lineStream.fail()) {
      cout << "Error: invalid command" << endl;
    } else if (checkShapeName_list(command) == false &&
               checkShapeName_type(command) == false) {
      cout << "Error: invalid command" << endl;
    }
    // Check for the command and act accordingly
    // ECE244 Student: Insert your code here
    // if(command == ""){
    //     cout << "Error: invalid command" << endl;
    // }
    else {
      if (command == "maxShapes") {
        formMaxArray(lineStream);
      } else if (command == "create") {
        createShape(lineStream);
      } else if (command == "move") {
        moveShape(lineStream);
      } else if (command == "rotate") {
        rotateShape(lineStream);
      } else if (command == "draw") {
        drawShape(lineStream);
      } else if (command == "delete") {
        deleteShape(lineStream);
      }
    }
    // Once the command has been processed, prompt for the
    // next command
    cout << "> ";  // Prompt for input
    getline(cin, line);

    // End input loop until EOF.
  }
  return 0;
}


// check on valgrind
// capital letters for error messages
