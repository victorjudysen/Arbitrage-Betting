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
int stakeAmount;

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
    cout << "Summation of Probabilities is: " << sumOfProbabilities << ", "<< "In percentage is: "<< sumIntoPercent << "/100"<< endl;

    cout << endl;
    if (sumIntoPercent < 100) {
        cout << "How much are you staking today?: ";
        cin >> stakeAmount;

        cout << endl;
        
        // Stake on Each
        stakeOnTeamA = (probabilityOfTeamB / sumOfProbabilities) * stakeAmount;
        cout << "The stake on Team A is: " << stakeOnTeamA << endl;

        stakeOnTeamB = (probabilityOfTeamA / sumOfProbabilities) * stakeAmount;
        cout << "The stake on Team B is: " << stakeOnTeamB << endl;

        cout << endl;
        // Payout on Each
        payoutForTeamA = (stakeOnTeamA * oddsOnteamA);
        cout << "The Payout on Team A is: " << payoutForTeamA << endl;

        payoutForTeamB = (stakeOnTeamA * oddsOnteamB);
        cout << "The Payout on Team B is: " << payoutForTeamB << endl;

        // Profit on Each
        profitForTeamA = (payoutForTeamA - stakeOnTeamA);
        profitForTeamA = (payoutForTeamB - stakeOnTeamB);

        cout << endl;
        // Output the final profits
        cout << "If Team A wins, the profit is: " << profitForTeamA << endl;
        cout << "If Team B wins, the profit is: " << profitForTeamB << endl;
    } 
    else {
        cout << "This match has no arbitrage opportunity!!";
    }
    
    return 0;
}

