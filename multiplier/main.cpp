#include <iostream>
#include <vector>
#include <string>


using namespace std;

vector<vector<double>> parseInput(string Input)
{
    string row_delimiter = "|";
    string column_delimiter = ",";
    vector<vector<double>> output;

    size_t pos = 0;
    std::string token;
    vector<string> row;
    while ((pos = Input.find(row_delimiter)) != std::string::npos) {
        token = Input.substr(0, pos);
        row.push_back(token);
        Input.erase(0, pos + row_delimiter.length());
    }

    row.push_back(Input);

    for(int i=0; i<row.size(); i++)
        output.push_back(vector<double>());

    for(int i=0; i<row.size(); i++)
    {
        while ((pos = row[i].find(column_delimiter)) != std::string::npos) {
            token = row[i].substr(0, pos);
            output[i].push_back(stof(token));
            row[i].erase(0, pos + column_delimiter.length());
        }
        output[i].push_back(stof(row[i]));

    }


    return output;
}


vector<vector<double>> multiplyMatrix(vector<vector<double>> M1, vector<vector<double>> M2)
{

    vector<vector<double>> temp;

    for(int i=0; i<M1.size(); i++){
        temp.push_back(vector<double>());
        for(int k=0; k<M1[i].size(); k++)
            temp[i].push_back(0);
    }

    for(int i=0; i<M1.size(); i++)
    {
        for(int l=0; l<M2[0].size(); l++)
        {
            for(int k=0; k<M1[i].size(); k++)
            {
                temp[i][l] += M1[i][k]*M2[k][l];
            }
        }
    }

    return temp;
}


void printMatrix(vector<vector<double>> M)
{
    for(int i=0; i<M.size(); i++)
    {
        for(int k=0; k<M[i].size(); k++)
        {
            cout << M[i][k] << ",";
        }

        cout << endl;
    }
}

int main(int argc, char *argv[])
{

    std::string delimiter = ",";
    string input;

    cout << "Enter prob matrix: " << endl;
    cin >> input;
    vector<vector<double>> prob_mat = parseInput(input);

    cout << "Enter transient matrix: " << endl;
    cin >> input;
    vector<vector<double>> trans_mat = parseInput(input);

    int step;
    cout << "Enter Step Number:" << endl;
    cin >> step;

    vector<vector<double>> pi = trans_mat;
    for(int i=0; i<step; i++)
    {
        pi = multiplyMatrix(pi, prob_mat);
        printMatrix(pi);
    }

}
