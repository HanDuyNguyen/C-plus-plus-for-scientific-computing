#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//function that generate a random number in {-1,1}
int generate_random();

int main(){
    
    string current_state = "";
    int random_number = 0;
    int rounds = 0;
    int S = 0;
    int total_win = 0;
    int total_loss = 0;
    bool invalid = false;
    srand(time(0));
    
    ofstream myfile;
    cout << "Please enter your capital: ";
    
    do{
    cin >> S;
    if (S <= 0){
        cout << "-------------------------------------------------------------"<< endl;
        cout << "Your capital must be positive! Please re-enter your capital: ";
    }
    }
    while(S <= 0);
    cout << endl;
    cout << "*************************************************************"<< endl;
    
    int flag = 0;
    do{
        cout << endl;
        if (flag == 0){
            cout << "Excellent! Please enter number of rounds you want to play: ";
        }
        else{
            cout << "Please re-enter number of rounds you want to play: ";
        }
        cin >> rounds;
        
        if (rounds <= 0){
            flag++;
            cout << "Invalid input!" << endl;
            cout << "-------------------------------------------------------------"<< endl; 
            invalid = true;
        }
        else{
            cout << "Valid input!" << endl; 
            cout << "-------------------------------------------------------------"<< endl;
            invalid = false;
            myfile.open ("amount.csv");
            myfile << "Round" << ";" <<"Amount" << endl;
            myfile << 0 << ";" << S << endl;
            int i = 1;
            while (i <= rounds && S > 0){
                random_number = generate_random();
                S += random_number;
                myfile << i << ";" << S << endl;
                if (random_number == -1){
                    current_state = "L";
                    total_loss++;
                }   
                else{
                    current_state = "W";
                    total_win++;
                }
                cout << "Round " << i << ": \t" << current_state << "\t S = " << S << "\t\t total_win = "<< total_win << "\t\t total_loss = " << total_loss << endl;
                i++;
            }
            myfile.close();
            cout << "Total played rounds  = " << i-1 << endl;
        }
    }
    while(invalid);
    cout << "Total wins = " << total_win << endl;
    cout << "Total losses = " << total_loss << endl;
    
	return 0;
}

int generate_random(){
    
    int random_number = 0;
    random_number = 2*(rand()%2) - 1;
    
    return random_number;
}