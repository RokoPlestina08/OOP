#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
class Card {
public:
	int CardNumber;
	std::string Suite;
};

class Player {
public:
	std::string Name;
	void HandCard(Card card) {
		CardHand.push_back(card);
	}
	void PrintHand() {
		for (int i = 0; i < CardHand.size(); ++i) {
			std::cout << CardHand.at(i).CardNumber << "-" << CardHand.at(i).Suite << "|";
		}
		std::cout << std::endl;
	}
	void CheckPoints() {
		//ThreeOfaKind and FourOfaKind
		auto SortByNumbers = [](Card a, Card b) {return a.CardNumber < b.CardNumber; }; //this sorts by numbers
		auto SortBySuites = [](Card a, Card b) {return a.Suite < b.Suite; }; //this sorts by suites
		std::sort(CardHand.begin(), CardHand.end(), SortByNumbers); //we only sort by numbers here
		int SameCardNumberCount = 1;
		for (int i = 1; i <= 10; ++i) {
			for (auto it = CardHand.begin(); it != (CardHand.end() - 1); ++it) {
				if ((*it).CardNumber == (*(it + 1)).CardNumber) {
					++SameCardNumberCount;
				}
				else SameCardNumberCount = 1;
			}
		}
		if (SameCardNumberCount == 3) Points += 3;
		else if (SameCardNumberCount > 3) Points += 4;
		//Napolitana
		std::sort(CardHand.begin(), CardHand.end(), SortBySuites); //here we sort by suites (since we already sorted by numbers, this will be sorted by numbers and suites)
		int Count = 1;
		for (auto it = CardHand.begin(); (it != CardHand.end() - 1); ++it) {
			if ((*it).Suite == (*(it + 1)).Suite) {
				if ((*it).CardNumber == ((*(it + 1)).CardNumber + 1)) {
					++Count;
				}
			}
			if (Count == 3) {
				Points += 3;
				Count = 1;
			}
		}
		std::cout << Name << " has " << Points << " points!" << std::endl;
	}
private:
	std::vector<Card> CardHand;
	int Points = 0;
};

class Deck {
private:
	std::vector<std::string> Suites = { "Heart","Diamond","Spades","Clubs"};
	std::vector<Card> AvailableCards;
public:
	Deck() {
		for (auto it = Suites.begin(); it != Suites.end(); ++it) {
			for (int i = 1; i <= 10; ++i) {
				Card card;
				card.CardNumber = i;
				card.Suite = *it;
				AvailableCards.push_back(card);
			}
		}
		std::random_shuffle(AvailableCards.begin(), AvailableCards.end());
	}
	void HandCards(int AmountOfPlayers, std::vector<Player> &Players) {
		auto CurrentCard = AvailableCards.begin();
		for (int i = 0; i < AmountOfPlayers; ++i) {
			int CardsDrew = 0;
			for (; CardsDrew < 10; ++CardsDrew) {
				Players.at(i).HandCard(*CurrentCard);
				CurrentCard = AvailableCards.erase(CurrentCard);
			}
		}
	}
};

class Game {
private:
	std::vector<Player> Players;
	int NumberOfPlayers = 0;
public:
	Game() {
		std::cout << "Enter number of players" << std::endl;
		std::cin >> NumberOfPlayers;
		std::cin.ignore();
		for (int i = 0; i < NumberOfPlayers; ++i) {
			Player player;
			std::cout << "Enter player's name" << std::endl;
			std::getline(std::cin, player.Name);
			Players.push_back(player);
		}
	}
	void Play() {
		Deck CurrentDeck;
		CurrentDeck.HandCards(NumberOfPlayers, Players);
		for (int i = 0; i < NumberOfPlayers; ++i) {
			std::cout << "--------------" << std::endl;
			std::cout << Players.at(i).Name << std::endl;
			std::cout << "Hand:" << std::endl;
			Players.at(i).PrintHand();
			Players.at(i).CheckPoints();
		}
	}
};

int main() {

	Game Currentgame;
	Currentgame.Play();
	
	return 0;
}