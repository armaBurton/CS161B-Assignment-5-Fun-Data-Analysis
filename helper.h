#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

const int FOUR_HUNDO = 400;
const int CSTRING_LENGTH = 30;

bool openFile(ifstream &inFile);

void readFile(
    ifstream &inFile,
    int &index,
    int id[],
    char gender[][CSTRING_LENGTH],
    int age[],
    char occupation[][CSTRING_LENGTH],
    double sleepDuration[],
    int sleepQuality[],
    int physicalActivityLevel[],
    int stressLevel[],
    char bmiCategory[][CSTRING_LENGTH],
    char bloodPressure[][CSTRING_LENGTH],
    int heartRate[],
    int dailySteps[],
    char sleepDisorder[][CSTRING_LENGTH]);