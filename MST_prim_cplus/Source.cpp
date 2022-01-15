#include <iostream>
#include "MST_Prim.h"
using namespace std;

class matrix
{
public :
    int** mat;
    int matixLength;
    matrix(int length)
    {
        matixLength = length;
        mat = new int*[matixLength];
        for (int i = 0; i < matixLength; i++)
        {
            mat[i] = new int [matixLength];
            for (int j = 0; j < matixLength; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
};

matrix input_graph()
{
    cout << "\n  NOTICE: this a undedirected graph !!! \n\n";

    int matrixLength = 0;
    cout << "\n enter number of graph nodes :";
    cin >> matrixLength;

    cout << "\n\n";

    matrix m(matrixLength);

    for (int i = 0; i < m.matixLength;i++)
    {
        int edge = 0;
        for (int j = i + 1; j < m.matixLength;j++)
        {
            cout << "\n  value of node " << i + 1 << "  to  " << j + 1 << " : ";
            cin >> m.mat[i][j];
            m.mat[j][i] = m.mat[i][j];
        }
    }
    return m;
}

int inputStarterNode()
{
    int start = 1;
    cout << "\n\n enter starter node : ";
    cin >> start;
    cout << "\n\n";
    return start;
}

vector<Vertex> createGraph(matrix m)
{
    vector<Vertex> graph;

    for (int i = 0; i < m.matixLength; i++)
    {
        Vertex temp;
        temp.Vnumber = i + 1;
        for (int j = 0; j < m.matixLength;j++)
        {

            Vertex child;
            if (m.mat[i][j] != 0 && i != j)
            {
                child.Vnumber = j + 1;
                if (m.mat[i][j] == 0) {
                    child.EdgeValue = INFINITY;
                }
                else {
                    child.EdgeValue = m.mat[i][j];
                }

                temp.VChildren.push_back(child);
            }
        }
        graph.push_back(temp);

    }
    return graph;
}

void showVertices(vector<Vertex> graph) {
    cout << "\n\n";
    for (int i = 0; i < graph.size();i++)
    {
        cout << endl << "node " << graph.at(i).Vnumber << "\n    childs  \n";
        for (int j = 0; j < graph.at(i).VChildren.size(); j++)
        {
            cout << "      child " << graph.at(i).VChildren.at(j).Vnumber << "    edge : " << graph.at(i).VChildren.at(j).EdgeValue << "\n";
        }
    }
    cout << "\n\n";
}

void showMST(vector<Vertex> answer)
{
    cout << "------PRIM MST IS  ";
    for (int i = 1; i < answer.size();i++) {

        cout << "\n\n\n\t" << " node " << answer.at(i).Vparent << "  to  " << answer.at(i).Vnumber << "  with value  " << answer.at(i).Vkey;
    }
}
void main()
{
    matrix m = input_graph();

    int start = inputStarterNode();

    vector<Vertex> graph = createGraph(m);
    
    showVertices(graph);

    MST_Prim x(graph, start);

    vector<Vertex> answer = x.get_MST();

    showMST(answer);
    
    cout << "\n\n\n\n";
	system("pause");
}