#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>

using namespace std;

class listFile
{
public:
    void listFiles(const string& path)
    {

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
    public:
        void read(const string& fName)
        {

        }

};

class Delete
{
    public:
        void del(const string& fname)
        {

        }
};

class vControl
{
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


int main()
{
    system("CLS");
    Write firstFile;

    firstFile.create();
    return 0;
}