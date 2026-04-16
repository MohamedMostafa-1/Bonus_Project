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
void PrintQuestion(int Num1, int Num2 ,int Result, string Operation ) {
	cout << endl << Num1 << endl;
	cout << Operation << endl;
	cout << Num2 << endl;
	cout << "___________________________";

	int AnswerUser = ReadAnswer();
	if (AnswerUser == Result)
		cout << "\nThe right answer ^_^";
	else {
		cout << "\nWrong Answer ＞﹏＜";
		cout << "\nThe right answer is: " << Result;
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
		return RandomNumber(1, 50);
		break;
	case enQuestionsLevel::HardLevel:
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
	else if (Operation == "/")
		return  Num1 / Num2;

}

void RoundsGame(int RoundGame) {

	int Num1 = GeNumbersLevels(ReadQuestoinLevel());
	int Num2 = GeNumbersLevels(ReadQuestoinLevel());
	int Result = 0;
	string Operation = GetOperatationType(ReadOperationType());


	for (int i = 1; i <= RoundGame; i++)
	{
		cout << "\n_________________Question[" << i << "/" << RoundGame << "]_________________\n";
		Result = CalculatNumbers(Num1, Num2, Operation);
		PrintQuestion(Num1, Num2, Result, Operation);
	}
}



int main()
{
	srand((unsigned)time(NULL));
  
}

