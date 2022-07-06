using namespace std;

void ProjectsMenu(){
    cout << "-------------------------------------------------------\n";
    cout << "Для просмотра списка проектов введите r\n";
    cout << "Для создания нового проекта введите c\n";
    cout << "Для выхода введите q\n";
    cout << "-------------------------------------------------------\n";
};

void subProjectsMenu(){
    cout << "-------------------------------------------------------\n";
    cout << "Для переименования проекта введите n\n";
    cout << "Для удаления проекта введите d\n";
    cout << "Для выбора проекта введите p\n";
    cout << "Для возврата в меню проектов введите q\n";
    cout << "-------------------------------------------------------\n";
}

string verifyProject(string inStr, string outStr, string command){
    string projectName;
    fstream projfs;
    string line;
    bool boolean = false;

    while(true){
        cout << "-------------------------------------------------------\n";
        cout << inStr << endl;
        cout << "-------------------------------------------------------\n";
        cin >> projectName;

        projfs.open("projects.txt", fstream::in);

        while (getline(projfs, line))
        {
            if(line == projectName){
                boolean = true;
                break;
            };
        };

        projfs.close();

        if((boolean == true && command == "create") || (boolean == false && (command == "delete" || command == "update")) ){
            cout << "-------------------------------------------------------\n";
            cout << outStr << endl;
            boolean = false;
            continue;
        };
        break;
    };

    return projectName;
    
};

void projectDeleteOrRename(string projectName,string command, string newProjectName = ""){
    fstream projfs;
    string line;
    string projectStr;

    projfs.open("projects.txt", fstream::in);
    
    while (getline(projfs, line))
    {
        if(line == projectName){
            if(command == "delete"){

            }else if(command == "rename"){
                projectStr += newProjectName;
                projectStr += "\n";
            }else{
                return;
            }
            
        }else{
            projectStr += line;
            projectStr += "\n";
        }
    }

    projfs.close();
    projfs.open("projects.txt",fstream::out);
    projfs << projectStr;
    projfs.close();
};
