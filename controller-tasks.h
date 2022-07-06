#include "supportFunctions/Tasks-support-functions.h"

using namespace std;


void createTask(string path){
    fstream fs;
    string task;
    string str;
    string strArr[4];

    strArr[0] = "Введите название задачи\n";
    strArr[1] = "Введите статус задачи\n";
    strArr[2] = "Введите орисание задачи\n";
    strArr[3] = "Введите срок выполнения задачи\n";
    
    for(int i = 0; i < 4; ++i){
        cout << strArr[i];
        cin >> str;
        task += str;
        task += ",";
    }
    fs.open(path, fstream::app);
    fs << task << "\n";
    fs.close();
    
};


vector<string> readTasks(string path){
    ifstream fs;
    string line;
    int count = 0;
    string str = "";
    vector<string> tasks;


    cout << "-------------------------------------------------------\n";
    cout << "                     СПИСОК ЗАДАЧ                      \n";

    fs.open(path.c_str());

    while (getline(fs, line))
    {
        int i = 0;
        while(true){
            if(line[i] == ','){
                cout << str << endl;
                tasks.push_back(str);
                str = "";
                break;
            }else{
                str += line[i];
                ++i;
            };
        }
    }
    fs.close();

    return tasks;
};


void updateTask(string path, int taskIndex){
    string taskArr[4];
    string taskStr;
    char sym;
    bool boolean = true;

    while (boolean)
    {
        cout << "-------------------------------------------------------\n";
        cout << "Чтобы изменить название задачи введите n\n";
        cout << "Чтобы изменить статус задачи введите s\n";
        cout << "Чтобы изменить описание задачи o\n";
        cout << "Чтобы изменить срок выполнения задачи d\n";
        cout << "Для возврата в меню задач введите q\n";
        cout << "-------------------------------------------------------\n";
        cin >> taskStr;
        if(taskStr.size()>1){
            cout << "-------------------------------------------------------\n";
            cout << "Вы ввели некорректную команду\n";
            continue;
        };

        sym = (char)taskStr[0];

        switch (sym)
        {
        case 'n':
            supportUpdateTask(path,taskIndex,0);
            break;
        case 's':
            supportUpdateTask(path,taskIndex,1);
            break;
        case 'o':
            supportUpdateTask(path,taskIndex,2);
            break;
        case 'd':
            supportUpdateTask(path,taskIndex,3);
            break;
        case 'q':
            boolean = false;
            break;
        default:
            cout << "Введенной вами команды не существует\n";
            break;
        }
    }
};


void deleteTask(string path, int taskIndex){
    fstream projfs;
    string line;
    string taskStr;
    int count = 0;

    projfs.open(path, fstream::in);

    while (getline(projfs, line))
    {
        count++;
        if(count == taskIndex){
            continue;
        }else{
            taskStr += line;
            taskStr += "\n";
        }
    }

    projfs.close();
    projfs.open(path, fstream::out);
    projfs << taskStr;
    projfs.close();
};