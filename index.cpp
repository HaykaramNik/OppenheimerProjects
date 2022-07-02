#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstring>
#include "controller-project.h"
#include "controller-tasks.h"

void createProject();
void readProjects();
void updateProject();
void deleteProject();
void createTask();
void readTasks();
void updateTask();
void deleteTask();


int main(){

    char sym;
    fstream fs;
    bool b=true;
    while (b)
    {
        cout << "Для просмотра списка проектов введите r\nДля создания нового проекта введите c\nдля переименования проекта введите u\nдля удаления проекта введите d\nдля выхода введите q\n\n";
        cout << "Для редактирования конкретного проекта введите p\n";
        cin >> sym;
        switch (sym)
        {
        case 'c':
            createProject();
            break;
        case 'r':
            readProjects();
            break;
        case 'u':
            updateProject();
            break;
        case 'd':
            deleteProject();
            break;
        case 'q':
            b = false;
            break;
        case 'p':
            string projectName;
            cout << "Введите название проекта!";
            cin >> projectName;
            string path = projectName + ".txt";
            char tasksym;
            cout << "Для просмотра списка задач введите r\nДля создания новой задачи введите c\nдля редактирования задачи введите u\nдля удаления задачи введите d\nдля выхода введите q\n";
            cin >> tasksym;
            switch (tasksym)
            {
            case 'r':
                readTasks();
                break;
            case 'c':
                createTask();
                break;
            case 'u':
                updateTask();
                break;
            case 'd':
                deleteTask();
                break;
            default:
                break;
            }
            break;
        };
    };
    return 0;
}