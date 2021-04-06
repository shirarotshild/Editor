#include <string>
#include <iostream>
#include <vector>
#include "Document.h"

Document::Document(){
	currentLine = 0;
	currentLineI=0;
	writeI = false;
	writeC = false;
	flagC=false;
}
void Document::n(int number_line){
cout<<number_line+1<< "	"<<v[number_line]<<endl;
currentLine=number_line+1;	
}
void Document::p(){
	for(int i =0; i< v.size(); i++){
		cout << v[i] << endl;
	}	
		currentLine = v.size();
		//cout << currentLine << endl;
}
void Document::a(){
	
}
void Document::i(){
	writeI=true;
	currentLineI=currentLine-1;
}
void Document::c(){
	writeC=true;
}
void Document::d(int number_line){
	v.erase(v.begin() + number_line);
	currentLine=number_line;
}
void Document::sleshText(string line){
	for(int i = currentLine; i< v.size(); i++){
		size_t found = v[i].find(line);
		if(found !=  string::npos){
			currentLine=i+1;
			cout<< v[i]<<endl;
			return;
		}
	}
	currentLine=v.size();
}
void Document::questionMarkText(string line){
	for(int i = 0; i< currentLine-1; i++){
		//size_t found = v[i].find(line);
		if(v[i].find(line) !=  string::npos){
			currentLine=i+1;
			cout<< v[i]<<endl;
			return;
		}
	}
	currentLine=0;
	//cout<<currentLine<<endl;
	
}
void Document::sOldNew(string oldText, string newText){
	replace(v[currentLine-1], oldText, newText);
}
void Document::j(int number_line1 ,int number_line2){
	string temp=v[number_line1]+ " " + v[number_line2];
	v[number_line1]=temp;
	v.erase(v.begin() + number_line2);
}

void Document :: write(string line){
	if(writeC){
	v[currentLine-1]=line;
	writeC=false;
	flagC=true;
	
	}
	else if(writeI){
		if(!line.compare(".")){ 
	    writeI=false;
	    return;
		}
		vector<string>::iterator it;
		it = v.begin();
		v.insert (it+currentLineI,line);
		currentLineI++;
		currentLine++;
		
		
	}
	else{
	if(!line.compare(".")){
		if(flagC){currentLine=v.size();
			flagC=false;}
	return;
	}
	vector<string>::iterator it;
	it = v.begin();
	v.insert (it+currentLine,line);
	currentLine++;
	}
	//cout<<currentLine<<endl;
}


bool Document::replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
	

