#pragma once
#include <fstream>
#include <string>
#include <stack>
#include <list>
#include <iostream>
class noFile
{
	std::string mes;
public:
	noFile() :mes("Error:file cannot be open!") {}
	void Error() const{ std::cerr << mes << std::endl; }
};
class balance {
	std::ifstream fin;
	int currentLine;
	int Errors;
	struct Symbol
	{
		char Token;
		int TheLine;
	};
	enum CommentType {SlashSlash,Slashstar};
	bool CheckMatch(char Symb1,char Symb2,int Line1,int Line2);
	char GetNextSymbol();
	void PutBackChar(char c);
	void SkipComment(enum CommentType type);
	void SkipQuote(char type);
	char Nextchar();
public:
	balance(std::string s);
	int CheckBalance();
};
balance::balance(std::string s)
{
	fin.open(s);
	if (!fin) throw noFile();
	else{
		currentLine = 1;
		Errors = 0;
	}
}
int balance::CheckBalance()
{
	struct Symbol node;
	std::stack<Symbol, std::list<Symbol>> st;
	char Lastchar, Match;
	while (Lastchar = GetNextSymbol())
	{
		switch (Lastchar) {
		case'(':case'[':case'{':
			node.TheLine = currentLine;
			node.Token = Lastchar;
			st.push(node);
			break;
		case')':case']':case'}':
            if (st.empty())
			{
				++Errors;
				std::cout << "at line " << currentLine << " has a redundant " << Lastchar << std::endl;
			}
			else
			{
				node = st.top();
				st.pop();
				if (!CheckMatch(node.Token, Lastchar, node.TheLine, currentLine))
				{
					++Errors;
				}
			}
		}
	}
	while (!st.empty())
	{
		node = st.top();
		st.pop();
		std::cout << "at line " << node.TheLine  << node.Token << " does not a match " <<std::endl;
		++Errors;
	}
	return Errors;
}
bool balance::CheckMatch(char Symb1, char Symb2, int Line1, int Line2)
{
	if (Symb1 == '(' && Symb2 == ')' ||
		Symb1 == '[' && Symb2 == ']' ||
		Symb1 == '{' && Symb2 == '}')
		return 1;
	else
	{
		std::cout << "the " << Symb1 << " at line " << Line1 << " dosenot match the " << Symb2 << " at line " << Line2 << std::endl;
		return 0;
	}
}
char balance::GetNextSymbol()
{
    char ch;
	while ((ch = Nextchar()))
	{
		if (ch == '/') {
			char next = Nextchar();
			if (next == '*') { SkipComment(Slashstar); continue; }
			else if (next == '/') { SkipComment(SlashSlash); continue; }
			else { PutBackChar(next); continue; }
		}
		if (ch == '\'' || ch == '"') { SkipQuote(ch); continue; }
		if (ch == '{' || ch == '[' || ch == '(' || ch == '}' || ch == ']' || ch == ')')
			return ch;
	}
	return 0;
}
void balance::PutBackChar(char ch)
{
	fin.putback(ch);
	if (ch == '\n') currentLine--;
}
char balance::Nextchar()
{
    int c = fin.get();
	if (c == EOF) return 0;
	char ch = static_cast<char>(c);
	if (ch == '\n') ++currentLine;
	return ch;
}
void balance::SkipComment(enum CommentType type)
{
	char ch;
	if (type == SlashSlash)
	{
		while ((ch = Nextchar()) && ch != '\n');
		return;
	}
    char flag = 0;
	if (type == Slashstar)
	{
		while (ch = Nextchar())
		{
            if (flag == '*' && ch == '/') return;
			flag = ch;
		}
		++Errors;
		std::cout << "Comment is invalid!" << std::endl;
		return;
	}
}
void balance::SkipQuote(char ch)
{
	char used = ch;
	while (ch = Nextchar())
	{
		if (ch == used) return;
		else if (ch == '\n')
		{
			++Errors;
			std::cout << "Quote is invalid at line " << currentLine << std::endl;
			return;
		}
		else if (ch == '\\')ch = Nextchar();//for special situation like \'
	}
}