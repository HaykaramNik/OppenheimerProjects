using namespace std;

void createProject(){
    string projectName;
    string path;
    fstream fs;

    cout << "Введите названте нового проекта\n\n";
    cin >> projectName;
    path = projectName + ".txt";
    cout << path << endl;

    fs.open("projects.txt", fstream::in | fstream::out | fstream::app);
    fs << path << "\n";
    fs.close();
    
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if(fs.is_open()){
        fs << "barev";
    };
};
void deleteProject(){
    string projectName;
    string path;
    cout << "Введите название проекта который хотите удалить\n";
    cin >> projectName;
    path = projectName + ".txt";
    remove(path.c_str());
}
void updateProject(){
    fstream fs;
    fstream newfs;
    fstream projfs;
    string line;
    string projectName;
    string path;
    string newProjectName;
    string newPath;
    string projectstr;
    string newline;

    cout << "Введите название проекта!\n";
    cin >> projectName;
    path = projectName + ".txt";
    cout << "Введите название нового проекта\n";
    cin >> newProjectName;
    newPath = newProjectName + ".txt";

    fs.open(path, fstream::in | fstream::out | fstream::app);
    newfs.open(newPath, fstream::in | fstream::out | fstream::app);
    cout << "\n\n";
    while (getline(fs, line)){
        newfs << line << "\n";
    };
    fs.close();
    remove(path.c_str());
    newfs.close();

    projfs.open("projects.txt", fstream::in);
    
    while (getline(projfs, newline))
    {
        if(newline == path){
            projectstr += newPath;
            projectstr += "\n";
        }else{
            projectstr += newline;
            projectstr += "\n";
        }
    }
    projfs.close();
    cout << projectstr;
    projfs.open("projects.txt",fstream::out);
    projfs << projectstr;
    projfs.close();
};
void readProjects(){
    fstream fs;
    string vd;
    string line;

    fs.open("projects.txt", fstream::in | fstream::out | fstream::app);
    cout << "\n\n";
    while (getline(fs, line)){
        cout << line << "\n";
    }
    cout << "\nВведите любую кнопку чтобы продолжить\n";
    cin >> vd;
    cout << "\n";
    fs.close();
}