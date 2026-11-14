#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

enum enGameChoices { Rock = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoices Player1Choice;
	enGameChoices ComputerChoice;
	enWinner RoundWinner;
	string WinnerName = "";
};

struct stGameResults
{
	short NumberOfRounds = 0;
	short Player1WonTimes = 0;
	short ComputerWonTimes = 0;
	short DrawTimes = 0;
	enWinner FinalWinner;
	string FinalWinnerName = "";
};

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player 1","Computer","Draw" };

	return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoices::Rock:
		if (RoundInfo.ComputerChoice == enGameChoices::Paper)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoices::Paper:
		if (RoundInfo.ComputerChoice == enGameChoices::Scissors)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoices::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoices::Rock)
		{
			return enWinner::Computer;
		}
		break;


	}

	return enWinner::Player1;
}

string ChoiceName(enGameChoices GameChoice)
{
	string arrGameChoices[3] = { "Rock","Paper","Scissors" };

	return arrGameChoices[GameChoice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F");
		break;
	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;

	default: 
		system("color 6F");
		break;
	}
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n____________ Round[" << RoundInfo.RoundNumber << "] ___________\n\n";
	cout << "Player 1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner: [" << RoundInfo.WinnerName << "] \n";
	cout << "__________________________________\n" << endl;
	
	SetWinnerScreenColor(RoundInfo.RoundWinner);
}

enWinner WhoWonTheGame(short Player1WonTimes,short ComputerWonTimes)
{
	if (Player1WonTimes > ComputerWonTimes)
	{
		return enWinner::Player1;
	}
	else if (ComputerWonTimes > Player1WonTimes)
	{
		return enWinner::Computer;
	}
	else
	{
		return enWinner::Draw;
	}
}

stGameResults FillGameResults(short NumberOfRounds, short Player1WonTimes, short ComputerWonTimes, short DrawTimes)
{
	stGameResults GameResults;

	GameResults.NumberOfRounds = NumberOfRounds;
	GameResults.Player1WonTimes = Player1WonTimes;
	GameResults.ComputerWonTimes = ComputerWonTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.FinalWinner = WhoWonTheGame(Player1WonTimes, ComputerWonTimes);
	GameResults.FinalWinnerName = WinnerName(GameResults.FinalWinner);

	return GameResults;
}

enGameChoices ReadPlayer1Choice()
{
	short Choice;
	do
	{
		cout << "\nYour Choice: [1]:Rock, [2]:Paper, [3]:Scissors ?";
		cin >> Choice;

	} while (Choice < 1 || Choice>3);

	return (enGameChoices)Choice;
}

enGameChoices GetComputerChoice()
{
	return (enGameChoices)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;

	short Player1WonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;

	for (int RoundNumber = 1;RoundNumber <= HowManyRounds;RoundNumber++)
	{
		cout << "\nRound[" << RoundNumber << "] begins: \n";
		RoundInfo.RoundNumber = RoundNumber;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.RoundWinner);

		if (RoundInfo.RoundWinner == enWinner::Player1)
		{
			Player1WonTimes++;
		}
		else if (RoundInfo.RoundWinner == enWinner::Computer)
		{
			ComputerWonTimes++;
		}
		else
		{
			DrawTimes++;
		}

		PrintRoundResults(RoundInfo);
	}

	return FillGameResults(HowManyRounds, Player1WonTimes, ComputerWonTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
	string t = "";
	
	for (int i = 1;i < NumberOfTabs;i++)
	{
		t = t + "\t";
		cout << t;
	}

	return t;
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "___________________________________________________\n\n";
	cout << Tabs(2) << "                   +++ G a m e  O v e r +++\n";
	cout << Tabs(2) << "___________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "\n                _____________________ [Game Results ]______________________\n\n";
	cout << Tabs(2) << "Game Rounds        :     " << GameResults.NumberOfRounds << endl;
	cout << Tabs(2) << "Player 1 Won Times :     " << GameResults.Player1WonTimes << endl;
	cout << Tabs(2) << "Computer Won Times :     " << GameResults.ComputerWonTimes << endl;
	cout << Tabs(2) << "Draw Times         :     " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       :     " << GameResults.FinalWinnerName << endl;
	cout << Tabs(2) << "_____________________________________________________________\n\n";


}

short ReadHowManyRounds()
{
	short NumberOfRounds = 1;

	do
	{
		cout << "\nHow Many Rounds From 1 to 10 ?\n";
		cin >> NumberOfRounds;
	} while (NumberOfRounds < 1 || NumberOfRounds>10);

	return NumberOfRounds;
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{

	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame((ReadHowManyRounds()));
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);

		cout << endl << "Do You Want To Play Again? [Y/N]?";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{

	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}