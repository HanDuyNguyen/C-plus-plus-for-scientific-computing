#include<iostream>
#include <vector>

using namespace std;

void fillVector(vector<int>&);
void printVector(const vector<int>&);
void sortVector(vector<int>&);
bool searchVector(const int x, const vector<int>&);

int main()
{
    vector<int> myVector;
    fillVector(myVector);
    printVector(myVector);
    sortVector(myVector);
    printVector(myVector);
    if (searchVector(5, myVector) == true){
        cout <<"found!";
    }
    else{
        cout <<"not found!";
    }
    return 0;
}

void fillVector(vector<int>& vec){
    cout << "Please input your vector's elements! Enter -1 to stop." << endl;
    int input;
    cin >> input;
    
    while (input != -1){
        vec.push_back(input);
        cin >> input;
    }
}

void printVector(const vector<int>& vec){
    cout << "Print vector: ";
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

void sortVector(vector<int>& vec){
    for (int i  = 0; i < vec.size() - 1; i++){
        for (int j = i+1; j < vec.size(); j++ ){
            if (vec[j] < vec[i]){
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}

bool searchVector(const int x, const vector<int>& vec){
    int l = 0;
    int m = 0;
    int h = vec.size() - 1;
    
    while (l <= h){
        m = (l+h)/2;
        if (vec[m] == x){
            return true;
        }
        else if (vec[m] > x){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return false;
}