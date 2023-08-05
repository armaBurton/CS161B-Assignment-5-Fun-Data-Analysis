#include "helper.h"

/*
    Name:   openFile()
    Desc:   Opens the file
    input:  None
    output: none
    return: bool
*/
bool openFile(ifstream &inFile)
{
    inFile.open("Sleep_and_lifestyle.csv");
    if (!inFile)
    {
        return false;
    }
    return true;
}

/*
    Name:   readFile()
    Desc:   Reads the file
    input:  None
    output: none
    return: none
*/
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
    char sleepDisorder[][CSTRING_LENGTH])
{
    char burnThisLine[FOUR_HUNDO];
    inFile.getline(burnThisLine, FOUR_HUNDO, '\n');
    cout << burnThisLine << endl;
}