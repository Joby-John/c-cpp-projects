#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<vector>
#include<filesystem>
#include<set>

using namespace std;

class listFile
{
public:
    void listFiles()
    {
        string folderPath = "./"; // to acces current directory

        vector<string>files; // to store files list
        set<string>ignore = {"./main.cpp", "./main.exe"};//files to ignore from listing, this can also be used to hide files

        try
        {
            for(const auto& fileName: filesystem::directory_iterator(folderPath))
            {
                if(ignore.find(fileName.path().string()) == ignore.end())
                    cout<<fileName<<endl;
            }
        }
        catch(const filesystem::filesystem_error& e)
        {
            cerr <<e.what() << '\n';
        }

        system("pause");
        
    }

    
};

class Write
{
public:
    void create()
    {
        string name = "";
        cout<<"Enter the file name: ";
        cin>>name;

        ofstream newFile(name+".txt");

        if(newFile.is_open())
        {
            cout<<"Enter the text here, to end entering on a new line type 'endI':- ";

            while(true)
            {
                string line = "";
                cin.clear();
                getline(cin, line);

                if(line == "endI")
                {
                    break;
                }
                else
                {
                    newFile<<line;
                    newFile<<"\n";
                }
            }
        }
        else
        {
            cout<<"err opening file"<<endl;
        }

        newFile.close();    

    }

    void append( const string& fName)
    {

    }
};

class Read
{
private:
    string fileName;
    public:
        void read(const string& fName)
        {
            fileName = fName;
        }

};

class Delete
{
private:
    string fileName;
    public:
        void del(const string& fname)
        {
            fileName = fname;
        }
};

class vControl
{
public:
    void init()
    {
        
    }

    void status()
    {

    }

    void add()
    {
        //add
    }

    void commit()
    {
        //commit
    }

    void displayLog()
    {
        //display commit log with hash
    }

    void revert(string commitHash)
    {

    }

    
};

void mainMenu()
{
        int choice;

    Write writeObj;
    listFile listObj;
    Read readObj;
    Delete deleteObj;
    vControl vcObj;

    while (true) {
        system("CLS");
        cout << "\nMain Menu\n";
        cout << "1. List Files\n";
        cout << "2. Create File\n";
        cout << "3. Read File\n";
        cout << "4. Append to File\n";
        cout << "5. Delete File\n";
        cout << "6. Initialize Version Control\n";
        cout << "7. Check Version Control Status\n";
        cout << "8. Add File to Version Control\n";
        cout << "9. Commit Changes\n";
        cout << "10. Display Commit Log\n";
        cout << "11. Revert to Previous Commit\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("CLS");
                listObj.listFiles();
                break;
            case 2:
                writeObj.create();
                break;
            case 3: {
                string fileName;
                cout << "Enter the file name to read: ";
                cin >> fileName;
                readObj.read(fileName);
                break;
            }
            case 4: {
                string fileName;
                cout << "Enter the file name to append: ";
                cin >> fileName;
                writeObj.append(fileName);
                break;
            }
            case 5: {
                string fileName;
                cout << "Enter the file name to delete: ";
                cin >> fileName;
                deleteObj.del(fileName);
                break;
            }
            case 6:
                vcObj.init();
                break;
            case 7:
                vcObj.status();
                break;
            case 8:
                vcObj.add();
                break;
            case 9:
                vcObj.commit();
                break;
            case 10:
                vcObj.displayLog();
                break;
            case 11: {
                string commitHash;
                cout << "Enter the commit hash to revert to: ";
                cin >> commitHash;
                vcObj.revert(commitHash);
                break;
            }
            case 12:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}


int main()
{
    system("CLS");
    
    mainMenu();
    return 0;
}