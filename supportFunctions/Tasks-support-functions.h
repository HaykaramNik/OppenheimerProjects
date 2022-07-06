using namespace std;

void tasksMenu(){
    cout << "-------------------------------------------------------\n";
    cout << "Для просмотра списка задач введите r\n";
    cout << "Для создания новой задачи введите c\n";
    cout << "Для возврата в список проектов введите q\n";
    cout << "-------------------------------------------------------\n";
}

void subTasksMenu(){
    cout << "-------------------------------------------------------\n";
    cout << "Для редактирования задачи введите u\n";
    cout << "Для удаления задачи введите d\n";
    cout << "Для возврата в список задач введите q\n";
    cout << "-------------------------------------------------------\n";
}



int taskContentRetIndex(string path, string task){
    ifstream fs;
    string str = "";
    int count = 0;
    int lineCount = 0;
    string line;
    bool flag = false;;

    fs.open(path);

    while(getline(fs, line)){
        lineCount++;
        for(int i=0;i<line.size();++i){
            if(line[i]==','){
                if(task != str && count == 0){
                    str = "";
                    continue;
                }else if(count == 0){
                    flag = true;
                }

                count++;
                
                switch (count)
                {
                case 1:
                    cout << "-------------------------------------------------------\n";
                    cout << "Название         - " << str << endl;
                    break;
                case 2:
                    cout << "Статус           - " << str << endl;
                    break;
                case 3:
                    cout << "Описание         - " << str << endl;
                    break;
                case 4:
                    cout << "Срок выполнения  - " << str << endl;
                    break;
                };
                str = "";
            }else{
                str += line[i];
            }
        }
        if(flag){
            break;
        }
        count = 0;
    }

    fs.close();

    return lineCount;
}

string verifyTask(vector<string> tasks, string inStr, string outStr, string command){
    string taskName;
    fstream projfs;
    string line;
    bool boolean = false;

    while(true){
        cout << "-------------------------------------------------------\n";
        cout << inStr << endl;
        cout << "-------------------------------------------------------\n";
        cin >> taskName;

        for(int i = 0; i < tasks.size(); ++i){
            if(tasks[i] == taskName){
                boolean = true;
                break;
            }
        }

        if((boolean == true && command == "create") || (boolean == false && (command == "delete" || command == "update")) ){
            cout << "-------------------------------------------------------\n";
            cout << outStr << endl;
            boolean = false;
            continue;
        };
        break;
    };

    return taskName;
};

void supportUpdateTask(string path, int taskIndex, int command){
    fstream fs;
    int count = 0;
    int lineCount = 0;
    int subTaskIndex = 0;
    string line;
    string newTaskStr;
    string taskSymStr;
    string task;
    string subTask;

    fs.open(path, fstream::in);

    while(getline(fs, line)){
        lineCount++;
        if(lineCount == taskIndex){
            for(int i = 0; i < line.size(); ++i){
                subTask += line[i];
                if(line[i] == ','){
                    if(command == count){
                        subTask = "";
                        cout << "-------------------------------------------------------\n";
                        cin >> taskSymStr;
                        taskSymStr += ",";
                        task += taskSymStr;

                    }else{
                        task += subTask;
                        subTask = "";
                    }
                    count++;
                }
            }
            task += "\n";
        }else{
            task += line;
            task += "\n";
        }
    }

    fs.close();

    fs.open(path, fstream::out);
    fs << task;
    fs.close();
}