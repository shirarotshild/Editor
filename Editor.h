#include <string>
#include <iostream>
#include "Document.h"
using namespace std;
class Editor{
	private:
	Document document;
	void sendLine(string line);
	vector<string> split(string str, char splitBy);
	
	
	
	public:
	void loop();
	Editor();
	

};