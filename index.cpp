#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include "controller-project.h"
#include "controller-tasks.h"

int main(){

    string symStr;
    char sym;
    fstream fs;
    bool projbool = true;
    string projectName;
    char tasksym;
    string path;
    bool taskbool;
    string taskName;
    int taskIndex = -1;
    vector<string> tasks;

    while (projbool)
    {
        ProjectsMenu();
        cin >> symStr;
        if(symStr.size()>1){
            cout << "-------------------------------------------------------\n";
            cout << "Вы ввели некорректную команду\n";
            continue;
        };

        sym = (char)symStr[0];

        bool subProjBool = true;

        switch (sym)
        {
        case 'c':
            createProject();
            break;
        case 'r':
            while (subProjBool){
                
                readProjects();
                taskbool = true;
                projectName = "";

                subProjectsMenu();
                
                cin >> symStr;

                if(symStr.size()>1){
                    cout << "-------------------------------------------------------\n";
                    cout << "Вы ввели некорректную команду\n";
                    continue;
                };

                sym = (char)symStr[0];

                switch (sym)
                {
                case 'n':
                    renameProject();
                    break;
                case 'd':
                    deleteProject();
                    break;
                case 'p':
                    while(taskbool){
                        bool subTaskBool = true;
                        if(projectName == ""){
                            string inStr = "Введите название проекта!";
                            string outStr = "Проекта с таким названием не существует";

                            projectName = verifyProject(inStr,outStr,"update");

                            path = "./Projects/" + projectName + ".txt";
                        }
                        tasksMenu();
                        
                        cin >> symStr;

                        if(symStr.size()>1){
                            cout << "-------------------------------------------------------\n";
                            cout << "Вы ввели некорректную команду\n";
                            continue;
                        };

                        sym = (char)symStr[0];

                        switch (sym)
                        {
                        case 'r':
                            tasks = readTasks(path);
                            while(subTaskBool){
                                if(taskName == ""){
                                    string inStr = "Введите название задачи";
                                    string outStr = "Введенной вами задачи не существует";
                                    taskName = verifyTask(tasks,inStr,outStr,"update");
                                }
                                if(taskIndex == -1){
                                    taskIndex = taskContentRetIndex(path,taskName);
                                }
                                
                                subTasksMenu();

                                cin >> symStr;
                                if(symStr.size()>1){
                                    cout << "-------------------------------------------------------\n";
                                    cout << "Вы ввели некорректную команду\n";
                                    continue;
                                };

                                sym = (char)symStr[0];

                                switch (sym)
                                {
                                case 'u':
                                    updateTask(path,taskIndex);
                                    break;
                                case 'd':
                                    deleteTask(path,taskIndex);
                                    taskName = "";
                                    taskIndex = -1;
                                    subTaskBool = false;
                                    break;
                                case 'q':
                                    taskIndex == -1;
                                    taskName = "";
                                    subTaskBool = false;
                                    break;
                                default:
                                    cout << "-------------------------------------------------------\n";
                                    cout << "Введенной вами команды не существует\n";
                                    break;
                                }
                            }
                            break;
                        case 'c':
                            createTask(path);
                            break;
                        case 'q':
                            taskbool = false;
                            break;
                        default:
                            cout << "-------------------------------------------------------\n";
                            cout << "Введенной вами команды не существует\n";
                            break;
                        }
                    };
                    break;
                case 'q':
                    subProjBool = false;
                    break;
                default:
                    cout << "-------------------------------------------------------\n";
                    cout << "Введенной вами команды не существует\n";
                    break;
                }
            }
            break;
        case 'q':
            projbool = false;
            break;
        default:
            cout << "-------------------------------------------------------\n";
            cout << "Введенной вами команды не существует\n";
            break;
        };
    };
    return 0;
}