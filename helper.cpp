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
    char temp[CSTRING_LENGTH];

    while (inFile.getline(temp, CSTRING_LENGTH, ','))
    {
        id[index] = atoi(temp);
        inFile.getline(gender[index], CSTRING_LENGTH, ',');
        inFile.getline(temp, CSTRING_LENGTH, ',');
        age[index] = atoi(temp);
        inFile.getline(occupation[index], CSTRING_LENGTH, ',');
        inFile.getline(temp, CSTRING_LENGTH, ',');
        sleepDuration[index] = atof(temp);
        inFile.getline(temp, CSTRING_LENGTH, ',');
        sleepQuality[index] = atoi(temp);
        inFile.getline(temp, CSTRING_LENGTH, ',');
        physicalActivityLevel[index] = atoi(temp);
        inFile.getline(temp, CSTRING_LENGTH, ',');
        stressLevel[index] = atoi(temp);
        inFile.getline(bmiCategory[index], CSTRING_LENGTH, ',');
        inFile.getline(bloodPressure[index], CSTRING_LENGTH, ',');
        inFile.getline(temp, CSTRING_LENGTH, ',');
        heartRate[index] = atoi(temp);
        inFile.getline(temp, CSTRING_LENGTH, ',');
        dailySteps[index] = atoi(temp);
        inFile.getline(sleepDisorder[index], CSTRING_LENGTH, '\n');

        index++;
    }
}

void printFile(
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
    cout << "ID"
         << "   Gender"
         << "   Age"
         << "   Occupation"
         << "\t Sleep Duration"
         << "\t   Quality of Sleep"
         << "     Physical Activity Level"
         << "\t   Stress Level"
         << "\t   BMI Category"
         << "\t   Blood Pressure"
         << "\tHeart Rate"
         << "\tDaily Steps"
         << "\tSleep Disorder"
         << endl;
    for (int i = 0; i < 15; i++)
    {
        if (i < 9)
        {
            cout << "00" << id[i];
        }
        else if (i >= 9 && i < 99)
        {
            cout << "0" << id[i];
        }
        else
        {
            cout << id[i];
        }

        cout << "  " << gender[i]
             << "  " << age[i];
        cout << endl;
    }
}