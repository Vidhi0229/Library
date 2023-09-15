
#include<bits/stdc++.h>
using namespace std;

void Registration(string *name, string *user_type, string *ID);

class Library{
    public:
        string name;
        string user_type;
        string ID;

    Library(string name, string user_type, string ID){
        this -> name = name;
        this -> user_type = user_type;
        this -> ID = ID;
    }
    void display()
    {
        cout << endl << name << " " << user_type << " " << ID <<"\n";
    }

};

int main(int argc, char* argv[]) {
    vector<Library> Register;
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_csv_file>" << endl;
        return 1;
    }

    const char* inputFileName = argv[1];

    std::ifstream file(inputFileName); // Open the CSV file for reading

    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    vector<vector<string>> data; // 2D vector to store CSV data

    std::string line;
    while (getline(file, line)) { // Read lines from the file
        vector<std::string> row;
        istringstream lineStream(line);
        string cell;

        while (getline(lineStream, cell, ',')) { // Split each line by commas
            row.push_back(cell);
        }

        data.push_back(row); // Add the row to the data vector
    }

    file.close(); // Close the file

    cout << data[2][0]<<"\n";

    string name, userType, id;
    Registration(&name, &userType, &id);
    
    Register.push_back(Library(name, userType, id));
    
    //Data.display();

    for (Library& Data : Register) {
        Data.display();
    }

 
    //Print the extracted data
    // for (const auto& row : data) {
    //     for (const auto& cell : row) {
    //         std::cout << cell << '\t';
    //     }
    //     std::cout << '\n';
    // }

    

    return 0;
}

void Registration(string *name, string *user_type, string *ID){

    string t;
    cout << "Greeting New User!!!\n\n";
    cout << "Your Name: ";
    cin >> *name;
    cout << "Enter F if faculty or S if Student\n";
    cin >> t;
    transform(t.begin(), t.end(), t.begin(), ::toupper);

    if(t == "F"){
        *user_type = "Faculty";
        cout << "Enter your Faculty id number: ";
        cin >> *ID;
    }
    else if(t == "S"){
        *user_type = "Student";
        cout << "Enter your student id number: ";
        cin >> *ID;
    }
    else {
        cout << "Invalid input\n";
    }
}

