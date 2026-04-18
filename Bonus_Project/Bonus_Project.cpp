#include <iostream>
#include <cstdlib>

using namespace std;

enum enQuestionsLevel {EasyLevel=1  ,MiddleLevel=2 , HardLevel=3 , MaxLevel=4 };
enum enOperationType {Add=1  ,Sub=2 , Mult=3 , Div=4 , MaxOp=5 };
struct stGameResults
{
	short RoundsGame = 0;
	string QuestionsLeve = "";
	string Operation = "";
	short NumberOfRightAnswer = 0;
	short NumberOfWrongAnswer = 0;
};

//The Reads
short ReadNumberOfQuestions() {
	short  Number = 0;
	do
	{
		cout << "How many you want Questions? ";
		cin >> Number;
	} while (Number <0);
	return Number;
}
enQuestionsLevel ReadQuestoinLevel() {
	short QLevel = 0;
	do
	{
		cout << "Please Enter Question Level [1]Easy [2]Middle [3]Hard [4]Max : ";
		cin >> QLevel;
	} while (QLevel<0);
	return (enQuestionsLevel)QLevel;
}
enOperationType ReadOperationType() {
	short OPType = 0;
	do
	{
		cout << "Please Enter Operation Type [1]Add [2]Sub [3]Mult [4]Div [5]Max : ";
		cin >> OPType;
	} while (OPType < 0);
	return (enOperationType)OPType;
}
int ReadAnswer() {
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

//The Prints
void PrintQuestion(int Num1, int Num2 ,int Result, string Operation , short& NumberOfRightAnswer , short& NumberOfWrongAnswer) {
	cout << endl << Num1 << endl;
	cout << Operation << endl;
	cout << Num2 << endl;
	cout << "___________________________\n";

	int AnswerUser = ReadAnswer();
	if (AnswerUser == Result) {
		cout << "\nThe right answer ^_^";
		NumberOfRightAnswer++;
		system("color 2F");
	}
	else {
		cout << "\nWrong Answer >_<";
		cout << "\nThe right answer is: " << Result;
		NumberOfWrongAnswer++;
		system("color 4F");
	}
	
}

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

int GeNumbersLevels(enQuestionsLevel QuestionLevel) {
	switch (QuestionLevel) {
	case enQuestionsLevel::EasyLevel:
		return RandomNumber(1, 20);
		break;
	case enQuestionsLevel::MiddleLevel:
		return RandomNumber(20, 50);
		break;
	case enQuestionsLevel::HardLevel:
		return RandomNumber(50, 100);
		break;
		case enQuestionsLevel::MaxLevel:
		return RandomNumber(1, 100);
		break;
	}
}
string GetOperatationType(enOperationType OperationType) {
	switch (OperationType) {
	case enOperationType::Add:
		return "+";
		break;
	case enOperationType::Sub:
		return "-";
		break;
	case enOperationType::Mult:
		return "x";
		break;
	case enOperationType::Div:
		return "/";
	default:
		return "Max";
		break;
	}
}

int CalculatNumbers(int Num1, int Num2, string Operation) {

	if (Operation == "+")
		return  Num1 + Num2;
	else if (Operation == "-")
		return  Num1 - Num2;
	else if (Operation == "x")
		return  Num1 * Num2;
	else if (Operation == "/" && Num2 ==0)
		return  Num1 / Num2;
	else
		return 0;

}

string QuestionLevelName(enQuestionsLevel QuestionLevel) {
	string arrQuestionLevelName[4] = { "Easy"   ,"Middle" , "Hard"  , "Max" };
	return arrQuestionLevelName[QuestionLevel - 1];
}

void FillstGameResults(stGameResults& GameResults,short RoundsGame, short  NumberOfRightAnswer,short NumberOfWrongAnswer,string QuestionsLeveName,string Operation) {
	
	GameResults.RoundsGame = RoundsGame;
	GameResults.NumberOfRightAnswer = NumberOfRightAnswer;
	GameResults.NumberOfWrongAnswer = NumberOfWrongAnswer;
	GameResults.QuestionsLeve = QuestionsLeveName;
	GameResults.Operation = Operation;
}

stGameResults RoundsGame(int RoundsGame) {
	
	stGameResults GameResults;

	int Num1, Num2;
	string Operation = GetOperatationType(ReadOperationType());
	int Result = 0;
	
	enQuestionsLevel Level = ReadQuestoinLevel();
	short  NumberOfRightAnswer = 0 , NumberOfWrongAnswer = 0;
	string QuestionsLeveName = QuestionLevelName(Level);

	for (int i = 1; i <= RoundsGame; i++)
	{
		 Num1 = GeNumbersLevels(Level);
		 Num2 = GeNumbersLevels(Level);
		cout << "\n_________________Question[" << i << "/" << RoundsGame << "]_________________\n";
		Result = CalculatNumbers(Num1, Num2, Operation);
		PrintQuestion(Num1, Num2, Result, Operation , NumberOfRightAnswer , NumberOfWrongAnswer);
	}
	FillstGameResults(GameResults,RoundsGame , NumberOfRightAnswer , NumberOfWrongAnswer, QuestionsLeveName , Operation );
	return GameResults;
}

void FinalResultsPassOrFail(short RightAnswer, short WrongAnswer) {
	if (RightAnswer >= WrongAnswer)
	{
		cout << "\n                 Final Result is Pass";
		system("color 2F");
	}
	else {
		cout << "\n                 Final Result is Fail";
		system("color 4F");
	}
}

void showFinalResults(stGameResults GameResults) {
	cout << "\n_______________________________________________________";
	FinalResultsPassOrFail(GameResults.NumberOfRightAnswer , GameResults.NumberOfWrongAnswer);
	cout << "\n_______________________________________________________";

	cout << "\nNumber of Questions: " << GameResults.RoundsGame << endl;
	cout << "Questions Level: " << GameResults.QuestionsLeve << endl;
	cout << "OpType: " << GameResults.Operation << endl;
	cout << "Number of Right Answer: " << GameResults.NumberOfRightAnswer << endl;
	cout << "Number of Wrong Answer: " << GameResults.NumberOfWrongAnswer << endl;

	cout << "_______________________________________________________";

}

void ResetBG() {
	system("cls");
	system("color 0F");
}

void StartGame() {
	char PlayAgain = 'Y';
	do
	{
		ResetBG();
		int ReadGameRound = ReadNumberOfQuestions();
		stGameResults GameResult=RoundsGame(ReadGameRound);
		showFinalResults(GameResult);
		cout << "\nDo you play again? ";
		cin >> PlayAgain;
	} while (PlayAgain == 'y' || PlayAgain == 'Y');
}


int main()
{
	srand((unsigned)time(NULL));
	StartGame();
}

