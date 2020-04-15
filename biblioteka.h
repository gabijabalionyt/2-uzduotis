#define pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>
#include <stdexcept>
#include <list>
#include <deque>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::stoi;
using std::getline;
using std::istringstream;
using std::swap;
using std::istream;
using std::streamsize;
using std::setprecision;
using std::max;
using std::list;
using std::deque;

struct Student
{
    string  Name,
            Surname;
    vector <int> Results;
    int     Exam;
    double FinalAverage,
           FinalMedian;
};


const string Error = "Jusu ivesti duomenys neatitinka reikalavimu. Bandykite dar karta.";

//-----------------------------
double Average (vector<int> Grade);
double Median (vector<int> Grade);
double FinalMark (double Exam, double Score);
double FinalMark (double Exam, vector<int> & Homework);
double FinalMark (const Student& S, double (*Criteria)(vector<int>) = Average);
bool AllLetters (string Input);
bool Digits (const string & str);
void Conversion (string & Text);
bool CompareSurnames (const Student& x, const Student& y);
void NewLine ();
int pasirinkimas ();
bool Fail (const Student & S);
bool Pass (const Student & S);
