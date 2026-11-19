#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

enum enQuestionLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mixed = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixedOp = 5 };

string GetOperationSymbol(enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return "+";

	case enOperationType::Sub:
		return "-";

	case enOperationType::Mult:
		return "*";

	case enOperationType::Div:
		return "/";

	case enOperationType::MixedOp:
		return "Mixed";
	};
}

string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{

	string arrQuestionLevel[4] = { "Easy","Medium","Hard","Mixed" };

	return arrQuestionLevel[QuestionLevel - 1];
}

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void SetScreenColor(bool Right)
{
	if (Right)
	{
		system("color 2F");
	}
	else
	{
		system("color 4F");
		cout << "\a";
	};
}

short ReadHowManyQuestions()
{
	short NumberOfQuestions = 0;

	do
	{
		cout << "How Many Questions Do You Want To Answer ? [1 to 10] ? ";
		cin >> NumberOfQuestions;
	} while (NumberOfQuestions < 1 || NumberOfQuestions>10);

	return NumberOfQuestions;
}

enQuestionLevel ReadQuestionLevel()
{
	int QuestionLevel = 0;

	do
	{
		cout << "\nEnter Questions Level: [1]:Easy, [2]:Medium, [3]:Hard, [4]:Mixed ? ";
		cin >> QuestionLevel;
	} while (QuestionLevel < 1 || QuestionLevel>4);

	return (enQuestionLevel) QuestionLevel;
}

enOperationType ReadOperationType()
{
	int OpType = 0;

	do
	{
		cout << "\nEnter Operations Type: [1]:Add, [2]:Subtract, [3]:Multiply, [4]:Divide, [5]:Mixed ? ";
		cin >> OpType;
	} while (OpType < 1 || OpType>5);

	return (enOperationType) OpType;
}

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerRestult = false;
};

struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuestions = 0;
	enQuestionLevel QuestionsLevel;
	enOperationType OperationsType;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightAnswers = 0;
	bool IsPass = false;
};

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{

	switch (OpType)
	{
	case enOperationType::Add:
		return Number1 + Number2;

	case enOperationType::Sub:
		return Number1 - Number2;

	case enOperationType::Mult:
		return Number1 * Number2;

	case enOperationType::Div:
		return Number1 / Number2;
		
	default:
		return Number1 + Number2;
	}
}

enOperationType GetRandomOperationType()
{

	int Op = RandomNumber(1, 4);

	return (enOperationType) Op;
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OperationType)
{
	stQuestion Question;


	if (QuestionLevel == enQuestionLevel::Mixed)
	{
		QuestionLevel = (enQuestionLevel) RandomNumber(1, 3);
	};

	if (OperationType == enOperationType::MixedOp)
	{
		OperationType = GetRandomOperationType();
	};

	Question.OperationType = OperationType;

	switch (QuestionLevel)
	{
	case enQuestionLevel::EasyLevel:

		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;

	case enQuestionLevel::MedLevel:

		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;

	case enQuestionLevel::HardLevel:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	}

	return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{

	for (short QuestionNumber = 0;QuestionNumber < Quizz.NumberOfQuestions;QuestionNumber++)
	{

		Quizz.QuestionList[QuestionNumber] = GenerateQuestion(Quizz.QuestionsLevel,Quizz.OperationsType);
	}

}

int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;

	return Answer;
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
	cout << "\n";
	cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
	cout << GetOperationSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
	cout << "\n_____________" << endl;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quizz.QuestionList[QuestionNumber].AnswerRestult = false;
		Quizz.NumberOfWrongAnswers++;

		cout << "\nWrong Answer :-(";
		cout << "\nThe Right Answer is: ";
		cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quizz.QuestionList[QuestionNumber].AnswerRestult = true;
		Quizz.NumberOfRightAnswers++;

		cout << "\nRight Answer :-)";
	};
	cout << endl;


	SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerRestult);
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
	for (short QuestionNumber = 0;QuestionNumber < Quizz.NumberOfQuestions;QuestionNumber++)
	{
		PrintTheQuestion(Quizz, QuestionNumber);

		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

		CorrectTheQuestionAnswer(Quizz, QuestionNumber);
	}

	Quizz.IsPass = Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers;
}

string GetFinalResultsText(bool isPass)
{
	if (isPass)
	{
		return "PASS :-)";
	}
	else
	{
		return "FAIL :-(";
	}
}

void PrintQuizzResults(stQuizz Quizz)
{
	cout << "\n";

	cout << "______________________________\n\n";
	cout << "Final Result Is " << GetFinalResultsText(Quizz.IsPass);
	cout << "\n______________________________\n\n";

	cout << "Number Of Questions    : " << Quizz.NumberOfQuestions << endl;
	cout << "Questions Level        : " << GetQuestionLevelText(Quizz.QuestionsLevel) << endl;
	cout << "Operations Type        : " << GetOperationSymbol(Quizz.OperationsType) << endl;
	cout << "Number Of Right Answers: " << Quizz.NumberOfRightAnswers << endl;
	cout << "Number Of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;
	cout << "______________________________\n";

}

void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionsLevel = ReadQuestionLevel();
	Quizz.OperationsType = ReadOperationType();

	GenerateQuizzQuestions(Quizz);
	AskAndCorrectQuestionListAnswers(Quizz);
	PrintQuizzResults(Quizz);
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
		PlayMathGame();

		cout << endl << "Do You Want To Play Again? [Y/N] ? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}