//
//  Triangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class Rectangle here

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Shape.h"
#include "Triangle.h"

// Build a Circle object
Triangle::Triangle(string n, float xcent, float ycent, float x1, float y1, float x2, float y2, float x3, float y3):Shape(n, xcent, ycent) {
    x_1 = x1;
    y_1 = y1;
    x_2 = x2;
    y_2 = y2;
    x_3 = x3;
    y_3 = y3;
}

Triangle::~Triangle() {
    // Nothing to do
}

// Accessor
float Triangle::getcoorx1() const {
    return x_1;
}

// Mutator
void Triangle::setcoorx1(float x1) {
    x_1 = x1;
}

// Accessor
float Triangle::getcoory1() const {
    return y_1;
}

// Mutator
void Triangle::setcoory1(float y1) {
    y_1 = y1;
}

// Accessor
float Triangle::getcoorx2() const {
    return x_2;
}

// Mutator
void Triangle::setcoorx2(float x2) {
    x_2 = x2;
}

// Accessor
float Triangle::getcoory2() const {
    return y_2;
}

// Mutator
void Triangle::setcoory2(float y2) {
    y_2 = y2;
}

// Accessor
float Triangle::getcoorx3() const {
    return x_3;
}

// Mutator
void Triangle::setcoorx3(float x3) {
    x_3 = x3;
}

// Accessor
float Triangle::getcoory3() const {
    return y_3;
}

// Mutator
void Triangle::setcoory3(float y3) {
    y_3 = y3;
}

void Triangle::draw() const {
    // Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    cout << "triangle: " << name << " "
         << x_centre << " " << y_centre
         << " " << x_1 << " " << y_1 << " " << x_2 << " " << y_2 << " " << x_3 << " " << y_3 << " " << computeArea()
         << endl;
}

float Triangle::computeArea() const {
    return ((abs(x_1*(y_2-y_3)+x_2*(y_3-y_1)+x_3*(y_1-y_2)))/2);
}

Shape* Triangle::clone() const {
    return (new Triangle(*this));
}
