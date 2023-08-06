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
    input:  "Sleep_and_lifestyle.csv"
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

/*
    Name:   printFile()
    Desc:   Prints the contents of the file to the console.
    input:  None
    output: int, char, double
    return: none
*/
void printFile(
    int index,
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
    cout.setf(ios::left, ios::adjustfield);
    cout.width(6);
    cout << "ID";
    cout.width(9);
    cout << "Gender";
    cout.width(5);
    cout << "Age";
    cout.width(23);
    cout << "Occupation";
    cout.width(17);
    cout << "Sleep Duration";
    cout.width(26);
    cout << "Physical Activity Level";
    cout.width(15);
    cout << "Stress Level";
    cout.width(15);
    cout << "BMI Category";
    cout.width(17);
    cout << "Blood Pressure";
    cout.width(13);
    cout << "Heart Rate";
    cout.width(14);
    cout << "Daily Steps";
    cout << "Sleep Disorder";
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < 30; i++)
    {
        cout.setf(ios::left, ios::adjustfield);
        cout.width(6);
        cout << id[i];
        cout.width(9);
        cout << gender[i];
        cout.width(5);
        cout << age[i];
        cout.width(23);
        cout << occupation[i];
        cout.width(17);
        cout << sleepDuration[i];
        cout.width(26);
        cout << physicalActivityLevel[i];
        cout.width(15);
        cout << stressLevel[i];
        cout.width(15);
        cout << bmiCategory[i];
        cout.width(17);
        cout << bloodPressure[i];
        cout.width(13);
        cout << heartRate[i];
        cout.width(14);
        cout << dailySteps[i];
        cout << sleepDisorder[i];

        cout << endl;
    }
}

/*
    Name:   averageSleepDuration()
    Desc:   Finds and displays the average sleep duration
    input:  None
    output: double
    return: none
*/
void averageSleepDuration(int index, double sleepDuration[])
{
    double sum = 0;
    for (int i = 0; i < 30; i++)
    {
        sum += sleepDuration[i];
    }
    cout << endl
         << "Average Sleep Duration: " << sum / 30;
}

/*
    Name:   averagePhysicalActivityLevel()
    Desc:   Finds and displays the average physical activity
    input:  None
    output: double
    return: none
*/
void averagePhysicalActivityLevel(int physicalActivityLevel[])
{
    int sum = 0;
    for (int i = 0; i < 30; i++)
    {
        sum += physicalActivityLevel[i];
    }
    cout << "\tAverage Physical Activity Level: " << static_cast<double>(sum) / 30;
}

/*
    Name:   averageStressLevel()
    Desc:   Finds and displays the average stress level
    input:  None
    output: double
    return: none
*/
void averageStressLevel(int stressLevel[])
{
    int sum = 0;
    for (int i = 0; i < 30; i++)
    {
        sum += stressLevel[i];
    }
    cout << "\tAverage Stress Level: " << static_cast<double>(sum) / 30;
}

/*
    Name:   averageBloodPressure()
    Desc:   Finds and displays the average stress level
    input:  None
    output: double
    return: none
*/
void averageBloodPressure(char bloodPressure[][CSTRING_LENGTH])
{
    double sumSystolic = 0, sumDiastolic = 0;

    for (int i = 0; i < 30; ++i)
    {
        // find first occurance of '/' in bloodPressure[i]
        // and set pointer
        char *slash = strchr(bloodPressure[i], '/');
        if (slash)
        {
            *slash = '\0';
            // conver cstring to double
            double systolic = atof(bloodPressure[i]);
            double diatolic = atof(slash + 1);

            sumSystolic += systolic;
            sumDiastolic += diatolic;
        }
    }

    cout << "\tAverage Blood Pressure: " << sumSystolic / 30 << "/" << sumDiastolic / 30;
}