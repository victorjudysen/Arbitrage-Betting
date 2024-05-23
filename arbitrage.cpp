#include <iostream>
using namespace std;

double oddsOnteamA;
double oddsOnteamB;
double probabilityOfTeamA;
double probabilityOfTeamB;
double sumOfProbabilities;
double stakeOnTeamA;
double stakeOnTeamB;
double payoutForTeamA;
double payoutForTeamB;
double profitForTeamA;
double profitForTeamB;

int main() {

    cout << "Enter Team A odds: ";
    cin >> oddsOnteamA;
    cout << "Enter Team B odds: ";
    cin >> oddsOnteamB;

    cout << endl;

    probabilityOfTeamA = 1/oddsOnteamA;
    probabilityOfTeamB = 1/oddsOnteamB;
    cout << "Probability of Team A is: " << probabilityOfTeamA << endl;
    cout << "Probability of Team B is: " << probabilityOfTeamB << endl;


    sumOfProbabilities = probabilityOfTeamA + probabilityOfTeamB;
    int sumIntoPercent = (sumOfProbabilities) * 100;
    cout << "Summation of Probabilities is: " << sumOfProbabilities << ", "<< "In percentage is: "<< sumIntoPercent << endl;

    
    if (sumIntoPercent < 100) {
        int stakeAmount;
        
        // How much stake on each
        stakeOnTeamA = (probabilityOfTeamB / sumOfProbabilities) * stakeAmount;
        stakeOnTeamB = (probabilityOfTeamA / sumOfProbabilities) * stakeAmount;

        // Payout Calculation
        payoutForTeamA = (stakeOnTeamA * oddsOnteamA);
        payoutForTeamB = (stakeOnTeamA * oddsOnteamB);

        //Profit after winning
        profitForTeamA = (payoutForTeamA - stakeOnTeamA);
        profitForTeamA = (payoutForTeamB - stakeOnTeamB);
    } 
    else {
        cout << "This match has no arbitrage opportunity!!";
    }
    
    cout << endl;

    // Output the final profits
    cout << "If Team A wins, the profit is: " << profitForTeamA << endl;
    cout << "If Team B wins, the profit is: " << profitForTeamB << endl;

    return 0;
}

