import requests
from bs4 import BeautifulSoup

def fetch_odds(url):
    response = requests.get(url)
    if response.status_code != 200:
        print("Failed to retrieve data from the betting site.")
        return []

    soup = BeautifulSoup(response.text, 'html.parser')
    events = []
    for event in soup.find_all('div', class_='m-table-row m-content-row match-row'):
        try:
            team_names = event.find('div', class_='teams')
            home_team = team_names.find('div', class_='home-team').text.strip()
            away_team = team_names.find('div', class_='away-team').text.strip()
            
            odds = event.find_all('span', class_='m-outcome-odds')
            if len(odds) >= 2:
                event_data = {
                    'team_a': home_team,
                    'team_b': away_team,
                    'odds_a': float(odds[0].text.strip()),
                    'odds_b': float(odds[1].text.strip())
                }
                events.append(event_data)
        except Exception as e:
            print(f"Error processing event: {e}")
            continue
    return events

def calculate_arbitrage(event):
    odds_on_team_a = event['odds_a']
    odds_on_team_b = event['odds_b']

    probability_of_team_a = 1 / odds_on_team_a
    probability_of_team_b = 1 / odds_on_team_b

    sum_of_probabilities = probability_of_team_a + probability_of_team_b
    sum_into_percent = sum_of_probabilities * 100

    if sum_into_percent < 100:
        stake_amount = 100  # Assuming a stake amount of 100 units for calculation

        stake_on_team_a = (probability_of_team_b / sum_of_probabilities) * stake_amount
        stake_on_team_b = (probability_of_team_a / sum_of_probabilities) * stake_amount

        payout_for_team_a = stake_on_team_a * odds_on_team_a
        payout_for_team_b = stake_on_team_b * odds_on_team_b

        profit_for_team_a = payout_for_team_a - stake_amount
        profit_for_team_b = payout_for_team_b - stake_amount

        return {
            'team_a': event['team_a'],
            'team_b': event['team_b'],
            'odds_a': odds_on_team_a,
            'odds_b': odds_on_team_b,
            'stake_on_team_a': stake_on_team_a,
            'stake_on_team_b': stake_on_team_b,
            'payout_for_team_a': payout_for_team_a,
            'payout_for_team_b': payout_for_team_b,
            'profit_for_team_a': profit_for_team_a,
            'profit_for_team_b': profit_for_team_b
        }
    return None

def main():
    url = "https://www.sportybet.com/tz/sport/tennis"
    events = fetch_odds(url)

    if not events:
        print("No events found or failed to fetch data.")
        return

    for event in events:
        arbitrage_info = calculate_arbitrage(event)
        if arbitrage_info:
            print("\nArbitrage Opportunity Found:")
            print(f"Teams: {arbitrage_info['team_a']} vs {arbitrage_info['team_b']}")
            print(f"Odds: {arbitrage_info['odds_a']} (Team A) vs {arbitrage_info['odds_b']} (Team B)")
            print(f"Stake on Team A: {arbitrage_info['stake_on_team_a']:.2f}")
            print(f"Stake on Team B: {arbitrage_info['stake_on_team_b']:.2f}")
            print(f"Payout if Team A wins: {arbitrage_info['payout_for_team_a']:.2f}")
            print(f"Payout if Team B wins: {arbitrage_info['payout_for_team_b']:.2f}")
            print(f"Profit if Team A wins: {arbitrage_info['profit_for_team_a']:.2f}")
            print(f"Profit if Team B wins: {arbitrage_info['profit_for_team_b']:.2f}")
        else:
            print("\nNo arbitrage opportunity for the event:", event['team_a'], "vs", event['team_b'])

if __name__ == "__main__":
    main()
