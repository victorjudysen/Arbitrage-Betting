/*
Author: Judysen Jnr, III
Date: Thursday, May 23rd 2024
*/

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
    cout << "Probability Summation is: " << sumOfProbabilities << " == " << "["<< sumIntoPercent << "%" << "]"<< endl;

    cout << endl;
    if (sumIntoPercent < 100) {
        cout << "How much are you staking today? --> ";
        cin >> stakeAmount;

        // Stake on Each
        cout << endl;
        cout << "STAKES" << endl;
        stakeOnTeamA = (probabilityOfTeamB / sumOfProbabilities) * stakeAmount;
        cout << "The Stake on Team A is: " << stakeOnTeamA << endl;
        stakeOnTeamB = (probabilityOfTeamA / sumOfProbabilities) * stakeAmount;
        cout << "The Stake on Team B is: " << stakeOnTeamB << endl;

        // Payout on Each
        cout << endl;
        cout << "PAYOUTS" << endl;
        payoutForTeamA = (stakeOnTeamA * oddsOnteamA);
        cout << "The Payout on Team A is: " << payoutForTeamA << endl;
        payoutForTeamB = (stakeOnTeamB * oddsOnteamB);
        cout << "The Payout on Team B is: " << payoutForTeamB << endl;

        // Profit on Each
        profitForTeamA = (payoutForTeamA - stakeAmount);
        profitForTeamB = (payoutForTeamB - stakeAmount);

        // Output the final profits
        cout << endl;
        cout << "PROFITS" << endl;
        cout << "If Team A wins, the profit is: " << profitForTeamA << endl;
        cout << "If Team B wins, the profit is: " << profitForTeamB << endl;
    } 
    else {
        cout << "This match has no arbitrage opportunity, Please do choose another match and Try again!!";
        cout << endl;
    }
    
    return 0;
}

