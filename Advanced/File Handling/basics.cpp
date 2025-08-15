#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    //this is C style
    static const char * originalfile = "originalFile.txt";
    static const char * editedfile = "editedFile.txt";

    // rename(originalfile, editedfile);
    remove(editedfile);
    FILE* fh = fopen(originalfile, "w");
    fclose(fh);

    //Welcome to C++ style
    ofstream outFile("example.txt"); // open for writing

    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outFile << "Hello, File Handling in C++!" << endl;
    outFile << "Writing another line." << endl;

    outFile.close(); // always close files
    cout << "Data written to file." << endl;
    return 0;
}