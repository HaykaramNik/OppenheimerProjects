#include "./supportFunctions/Projects-support-functions.h"

using namespace std;

void createProject(){
    string projectName;
    string path;
    fstream fs;
    string inStr = "Введите названте нового проекта";
    string outStr = "Проект с таким названием уже существует";
    string command = "create";

    projectName = verifyProject(inStr, outStr, command);
    
    path = "./Projects/" + projectName + ".txt";

    fs.open("projects.txt", fstream::app);
    fs << projectName << "\n";
    fs.close();
    
    fs.open(path, fstream::out);
    fs.close();
};

void readProjects(){
    fstream fs;
    string vd;
    string line;

    fs.open("projects.txt", fstream::in | fstream::out | fstream::app);
    cout << "-------------------------------------------------------\n";
    cout << "                   СПИСОК ПРОЕКТОВ                     \n";
    while (getline(fs, line)){
        cout << line << "\n";
    }
    fs.close();
};

void renameProject(){
    string projectName;
    string path;
    string newProjectName;
    string newPath;
    string inStr = "Введите название проекта который хотите переименовать";
    string outStr = "Проекта с таким названием не существует";
    string command = "update";

    projectName = verifyProject(inStr, outStr, command);

    path = "./Projects/" + projectName + ".txt";
    cout << "-------------------------------------------------------\n";
    cout << "Введите новое название проекта!\n";
    cout << "-------------------------------------------------------\n";
    cin >> newProjectName;
    newPath = "./Projects/" + newProjectName + ".txt";

    rename(path.c_str(),newPath.c_str());

    projectDeleteOrRename(projectName,"rename",newProjectName);
};

void deleteProject(){
    string projectName;
    string path;
    string inStr = "Введите название проекта который хотите удалить";
    string outStr = "Проекта с таким названием не существует";
    string command = "delete";

    projectName = verifyProject(inStr, outStr, command);

    path = "./Projects/" + projectName + ".txt";
    remove(path.c_str());

    projectDeleteOrRename(projectName,"delete");
};





