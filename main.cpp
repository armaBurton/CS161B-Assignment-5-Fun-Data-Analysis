#include "helper.h"

int main()
{
    ifstream inFile;
    int index = 0,
        id[FOUR_HUNDO];
    char gender[FOUR_HUNDO][CSTRING_LENGTH];
    int age[FOUR_HUNDO];
    char occupation[FOUR_HUNDO][CSTRING_LENGTH];
    double sleepDuration[FOUR_HUNDO];
    int sleepQuality[FOUR_HUNDO],
        physicalActivityLevel[FOUR_HUNDO],
        stressLevel[FOUR_HUNDO];
    char bmiCategory[FOUR_HUNDO][CSTRING_LENGTH],
        bloodPressure[FOUR_HUNDO][CSTRING_LENGTH];
    int heartRate[FOUR_HUNDO],
        dailySteps[FOUR_HUNDO];
    char sleepDisorder[FOUR_HUNDO][CSTRING_LENGTH];
    char data[FOUR_HUNDO][CSTRING_LENGTH];

    if (!openFile(inFile))
    {
        cout << "File did not open. Program terminating.\n";
        return 0;
    }
    // readFile(inFile, index, data);

    readFile(
        inFile,
        index,
        id,
        gender,
        age,
        occupation,
        sleepDuration,
        sleepQuality,
        physicalActivityLevel,
        stressLevel,
        bmiCategory,
        bloodPressure,
        heartRate,
        dailySteps,
        sleepDisorder);

    printFile(
        index,
        id,
        gender,
        age,
        occupation,
        sleepDuration,
        sleepQuality,
        physicalActivityLevel,
        stressLevel,
        bmiCategory,
        bloodPressure,
        heartRate,
        dailySteps,
        sleepDisorder);

    averageSleepDuration(index, sleepDuration);
    averagePhysicalActivityLevel(physicalActivityLevel);
    averageStressLevel(stressLevel);
    averageBloodPressure(bloodPressure);

    inFile.close();
    cout << endl;
}
