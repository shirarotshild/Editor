#include <string>
#include <iostream>
#include <vector>
using namespace std;

 

class Document{
	private:
	vector<string> v;
	bool writeI;
	bool writeC;
	bool flagC;
	int currentLine;
	int currentLineI;
	bool replace(std::string& str, const std::string& from, const std::string& to);
	
	public:
	Document();
	void n(int number_line);
	void p ();
	void a();
	void i();
	void c();
	void d(int number_line);
	void sleshText(string line);
	void questionMarkText(string text);
	void sOldNew(string oldText, string newText);
	void j(int number_line1 , int number_line2);
	void write(string line);
	void Q();


};