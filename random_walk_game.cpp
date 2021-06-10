#include <iostream>
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
    
    do{
    cout << "Please enter your capital: ";
    cin >> S;
    cout << endl;
    }
    while(S <= 0);
    
    
    
    do{
        cout << "Please enter number of rounds you want to play: ";
        cin >> rounds;
        
        if (rounds <= 0){
            cout << "Invalid input!" << endl;
            cout << "************************" << endl;
            invalid = true;
        }
        else{
            cout << "Valid input" << endl; 
            cout << "***********************" << endl;
            invalid = false;
            
            int i = 1;
            while (i <= rounds && S > 0){
                random_number = generate_random();
                S += random_number;
                if (random_number == -1){
                    current_state = "loss";
                    total_loss++;
                }   
                else{
                    current_state = "win";
                    total_win++;
                }
                cout << "Round " << i << ": \t" << current_state << "\t S = " << S << "\t\t total_win = "<< total_win << "\t\t total_loss = " << total_loss << endl;
                i++;
            }
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