#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

struct activity
{
    int label;
    int start;
    int end;
};
bool compareAct(activity a, activity b)
{
    return a.end < b.end;
}
void sortAct(activity list[], int size)
{
    sort(list, list + size, compareAct);
}

void maxActivity(activity act[], int size)
{
    sortAct(act, 20);
    int j = 0;
    cout << endl;
    cout << "maximum activities that can be done" << endl;
    cout << endl;
    cout << act[j].label << " " << act[j].start << " " << act[j].end << endl;

    for (int i = 0; i < size; i++)
    {

        if (act[i].start >= act[j].end)
        {
            cout << act[i].label << " " << act[i].start << " " << act[i].end << endl;
            j = i;
        }
    }
}

int main()
{

    fstream file;
    string filename = "activityinput.txt";
    int w, k;

    activity act[20];

    file.open(filename.c_str());
    file >> w;
    for (int i = 0; i < w; i++)
    {
        file >> k;
        act[i].label = k;
        file >> k;
        act[i].start = k;
        file >> k;
        act[i].end = k;
    }
    maxActivity(act, 20);
    cout << endl;

    return 0;
}
