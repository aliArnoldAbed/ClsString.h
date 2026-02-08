#pragma once
#include <string>
#include <iostream>
# include <cctype>
#include <vector>
using namespace std;
class ClsString
{
private :
	string _Value;
	
	static char _Invertlettercase(char Letter)
	{
		return isupper(Letter) ? tolower(Letter) : toupper(Letter);
	}
	static short _CountCapitalLetter(string word)
	{
		short Counter = 0;
		for (short i = 0; i <= word.length(); i++)
		{
			if (isupper(word[i]))
			{
				Counter++;
			}

		}
		return Counter;
	}
	static short _CountSmallLetter(string word)
	{
		short Counter = 0;
		for (short i = 0; i < word.length(); i++)
		{
			if (islower(word[i]))
			{
				Counter++;
			}

		}
		return Counter;
	}
	static bool IsVowel(char Letter)
	{
		return (Letter == 'i') || (Letter == 'o') || (Letter == 'u') || (Letter == 'a') || (Letter == 'e');
	}
	static string TrimLeft(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}
	static string TrimRight(string S1)
	{
		for (int i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}

		}


	}
	static string Trim(string S1)
	{

		return TrimLeft(TrimRight(S1));
	}
public :
enum _encountletter { CountCapitalLetter = 1, CountSmallletter = 2, Countall = 3 };
	enum _enTirm {tirmleft =1 , tirmRight =2 , tirmall=3};
	ClsString()
	{
		_Value = "";
	}
	ClsString(string Value)
	{
		_Value = Value;
	}
	void SetString(string Value)
	{
		_Value = Value;
	}
	string GetString()
	{
		return _Value;
	}
	__declspec(property (get = GetString, put = SetString))string Value;
	 static short countword(string word, string Delm = " ")
	{
		
		string Sward;
		short counter = 0;
		short pos;
		while ((pos = word.find(Delm)) != string::npos)
		{
			Sward = word.substr(0, pos);

			if (Sward != "")
			{
				counter++;
			}
			word.erase(0, pos + Delm.length());


		}
		if (word != " ")
		{
			counter++;
		}

		return counter;
	}
	 short countword()
	 {
		 return countword(_Value);
	 }
	static void GetFirstLetterFromAllWordFromString(string word)
	 {

		bool firstletter = true;
		for (short i = 0; i < word.length(); i++)
		{
			if (word[i] != ' ' && firstletter)
			{
				cout << word[i] << " ";
			}
			firstletter = (word[i] == ' ') ? true : false;
		}

	 }
	void GetFirstLetterFromAllWordFromString()
	{
		GetFirstLetterFromAllWordFromString(_Value);
	}
	static string  turntoupperFirstLetterOfEachWard(string  word)
	{

		bool firstletter = true;
		for (short i = 0; i < word.length(); i++)
		{
			if (word[i] != ' ' && firstletter)
			{
				word[i] = toupper(word[i]);
			}
			firstletter = (word[i] == ' ') ? true : false;
		}
		return word;
	}
	string  turntoupperFirstLetterOfEachWard()
	{
		return   turntoupperFirstLetterOfEachWard(_Value);
	}
	static string  turntolowerFirstLetterOfEachWard(string  word)
	{
		bool firstletter = true;
		for (short i = 0; i < word.length(); i++)
		{
			if (word[i] != ' ' && firstletter)
			{
				word[i] = tolower(word[i]);
			}
			firstletter = (word[i] == ' ') ? true : false;
		}
		return word;
	}
	string  turntolowerFirstLetterOfEachWard()
	{
		return  turntolowerFirstLetterOfEachWard(_Value);
	}
	static string AllToUpper(string word)
	{
		for (short i = 0; i <word.length(); i++)
		{
			word[i] = toupper(word[i]);
		}
		return word;
	}
	string AllToUpper()
	{
		return AllToUpper(_Value);
	}
	
	static string invertalllettercase(string Word)
	{
		for (short i = 0; i < Word.length(); i++)
		{
			Word[i] = _Invertlettercase(Word[i]) ;


		}
		return Word;
	}
	string invertalllettercase()
	{
		return invertalllettercase(_Value);
	}
	static short CountLetter(string Word, _encountletter CountType)
	{
		switch (CountType)
		{
		case _encountletter::CountCapitalLetter:
			return _CountCapitalLetter(Word);
		case _encountletter::CountSmallletter:
			return _CountSmallLetter(Word);
		case _encountletter::Countall:
			return _CountCapitalLetter(Word) + _CountSmallLetter(Word);


		}


	}
	short CountLetter()
	{
		return CountLetter(_Value, Countall);
	}

	static short CountRepeatedCharcter(string word, char C1)
	{
		short Counter = 0;
		for (short i = 0; i <word.length(); i++)
		{
			if (word[i] == C1)
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountRepeatedCharcter(char C1)
	{
		return CountRepeatedCharcter(_Value, C1);
	}
	
	static short CountVowel(string Word)
	{
		short Counter=0;
		for (short i = 0; i < Word.length(); i++)
		{
			if (IsVowel(Word[i]))
			{
				 Counter++;
			}

		}
		return Counter;
	}
	short CountVowel()
	{
		return CountVowel(_Value);
	}
	void Printvowel(string Str1)
	{


		for (short i = 0; i < Str1.length(); i++)
		{
			if (IsVowel(Str1[i]))
			{
				cout << Str1[i] << " ";
			}


		}
	}

	 void  PrintEachWordalone (string word, string Delm = " ")
	{
		
		string Sward;
		
		short pos;
		while ((pos = word.find(Delm)) != string::npos)
		{
			Sward = word.substr(0, pos);

			if (Sward != "")
			{
				cout <<Sward<<" ";
			}
			word.erase(0, pos + Delm.length());


		}
		if (word != " ")
		{
			cout << Sward << " ";;
		}

		
	}
	static  vector <string > Split(string word, string Delim = " ")
	 {
	
		 vector <string > Vsplet;
		 string Sword= "";
		 short pos=0;
		 while ((pos = word.find(Delim)) != std::string::npos)
		 {
			 Sword = word.substr(0, pos);
			 if (Sword != "")
			 {
				 Vsplet.push_back(Sword);
			 }
			word =word.erase(0,  pos + Delim.length() );
		 }
		 if (word != "")
		 {
			 Vsplet.push_back(word);
		 }
		 return Vsplet;
	 }
	vector <string > Split()
	{
		return Split(_Value);
	}
	static string tirmalldeilm(string word, _enTirm tirm)
	{
		switch (tirm)
		{
		case ClsString::tirmleft:
			return TrimLeft(word);
			
		case ClsString::tirmRight:
			return TrimRight(word);
			
		case ClsString::tirmall:
			return Trim(word);
			
		
		}
	}
	string tirmalldeilm(_enTirm tirm)
	{
		return tirmalldeilm(_Value, tirm);
	}
	string JoinString(vector <string >Vs , string Delim = " ")
	{
	
		string Sward = "";
		for (string& Ward : Vs)
		{
			Sward += Ward+ Delim;
		}
		return Sward;
	}
	string  JoinString(string ArrString[5], short length, string Delim)
	{
		string Str1 = "";
		for (int i = 0; i < length; i++)
		{
			Str1 = Str1 + ArrString[i] + Delim;
		}
		return Str1.substr(0, Str1.length() - Delim.length());
	}
	static string ReverseString(string word)
	{
		vector <string>Vsplit = Split(word);
		vector <string> ::iterator iter = Vsplit.end();
		string Sward = "";
		while (iter != Vsplit.begin())
		{
			iter--;
			Sward += *iter+" ";
		

		}
			return Sward;
	}
	string ReverseString()
	{
		return ReverseString(_Value);
	}
	static string ReplaceString(string S1, string Replaced, string ReplacedTo)
	{
		vector <string > Vsplit = Split(S1);
		string Sword = "";
		string Deilm = " ";
		for (string& Word : Vsplit)
		{
			if (Word == Replaced)
			{
				Word = ReplacedTo;
			}
			Sword += Word + Deilm;

		}
		return Sword;

		
	}
	string ReplaceString(string Replaced, string ReplacedTo)
	{
		return ReplaceString(_Value, Replaced, ReplacedTo);
	}
	static string OmittingPunct(string S1)
	{
		string S2 = " ";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
			
		}
		return S2;
	}

};


