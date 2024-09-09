#include<vector>
#include<iostream>

using namespace std;

class AddVertices
{
    char vertice;

public:
    AddVertices(char v)
    {
        this->vertice = v;
    }
};

class Graph{
    vector<vector<int>>graph;
    vector<char>vertices;
    int size = 0;
public:
    void addVertices()
    {
        char c;

        while(true)
        {
        cout<<"Enter a vertice, press # after finish:";
        cin>>c;
        if(c=='#')
        {
            break;
        }
        system("CLS");
        this->vertices.push_back(c);
        }

        size = vertices.size();
        vector<vector<int>>zeroMatrix(size, vector<int>(size,0));
        graph = zeroMatrix;
    }

    void addEdge(int src, int dest)
    {   
        if(src<size && dest<size && src>=0 && dest>=0)
        {
            graph[src][dest] = 1;
        }
        else
        {
            cout<<"Vertice doesnt exist"<<src<<":"<<dest<<endl;
        }
    }

    bool checkEdge(int src, int dest)
    {
        if(src<size && dest<size && src>=0 && dest>=0)
        {
            return graph[src][dest] == 1;
        }
        else
        {
            cout<<"Vertice doesnt exist"<<src<<":"<<dest<<endl;
            return false;
        }
    }

    void print()
    {
        cout<<"  ";
        for(int i =0; i<vertices.size(); i++)
        {
            cout<<vertices[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i<graph.size(); i++)
        {
            cout<<vertices[i]<<" ";
            for(int j = 0; j<graph.size(); j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
};


int main()
{
    Graph firstMatrix;
    firstMatrix.addVertices();
    firstMatrix.print();
    firstMatrix.addEdge(0,1);
    firstMatrix.addEdge(0,2);
    firstMatrix.addEdge(1,1);
    firstMatrix.addEdge(3,3);
    firstMatrix.addEdge(0,4);
    firstMatrix.print();


    return 0;
}