#include <iostream>
using namespace std;

double team_A;
double team_B;
double probabilityOfTeamA;
double probabilityOfTeamB;
double sumOfProbabilities;

int main() {

    cout << "Enter Team A odds: ";
    cin >> team_A;
    cout << "Enter Team B odds: ";
    cin >> team_B;

    probabilityOfTeamA = 1/team_A;
    probabilityOfTeamB = 1/team_B;
    
    sumOfProbabilities = probabilityOfTeamA + probabilityOfTeamB;
    cout << "The Summation is: " << sumOfProbabilities;

    int sumIntoPercent = sumOfProbabilities * 100;

    
    // if (sumIntoPercent < 100) {

    // }



}