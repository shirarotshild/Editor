#include <string>
#include <iostream>
#include <sstream>
#include "Editor.h"

using namespace std;
Editor::Editor(){
 document=Document();
}
void Editor::loop(){
string a;
	while(1){
		getline(cin, a);
		if (!a.compare("Q"))
			break;
		sendLine(a);
	}
}
void Editor :: sendLine(string line){
static bool isText = false;
int l = line.length();
	if(isText){
		document.write(line);
		//cout<<"write"<<endl;
		if(!line.compare("."))
			isText = false;
		return;
	}
	if(line.at(0) == '/'){
		document.sleshText(line.substr(1));
		return;		
	}
	if( line.at(0) == '?'){
		document.questionMarkText(line.substr(1));
		//cout<<"?text"<<endl;
		return;
	}
	if(line.at(0) == 's'){
		vector<string> arr = split(line, '/');
		if(arr.size() >= 3){
			document.sOldNew(arr[1], arr[2]);
			return;
		}
	}
	if(!line.compare("a")){
		isText = true;
		document.a();
		//cout<<"a"<<endl;
		return;
	}
	if(!line.compare("i")){
		isText = true;
		document.i();
		//cout<<"i"<<endl;
		return;
	}
	if(!line.compare("c")){
		isText = true;
		document.c();
		//cout<<"c"<<endl;
		return;
	}
	if(!line.compare("%p")){
		document.p();
		//cout<<"p"<<endl;
		return;
	}
	if( l > 1&& line.substr(l-1,l) == "d"){
		string temp=line.substr(0,l-1);
		int numberLine=stoi(temp); 
		document.d(numberLine-1);
		//cout<<"d"<<endl;
		//cout<<numberLine<<endl;
		return;
	}
	if( l > 1 && line.substr(l-1,l) == "n"){
		string temp=line.substr(0,l-1);
		int numberLine=stoi(temp); 
		//cout<<"n"<<endl;
		//cout<<numberLine<<endl;
		document.n(numberLine-1);
		return;
	}
	if( l > 1 && line.substr(l-1,l) == "j"){
		int index=0;
		while(1){
			if(line.at(index) == ',') break;
			index++;
		}
		string temp1=line.substr(0,index);
		string temp2=line.substr(index+1,l-1);
		int numberLine1=stoi(temp1); 
		int numberLine2=stoi(temp2); 
		document.j(numberLine1-1,numberLine2-1);
		//cout<<"j"<<endl;
		//cout<<numberLine1<<endl;
		//cout<<numberLine2<<endl;
		return;
	}
	
}


vector<string> Editor::split(string str, char splitBy){
	vector<string> words;
   string word = ""; 
   for (auto x : str) { 
       if (x == splitBy) {  
		   words.push_back(word);
           word = ""; 
       } 
       else{ 
           word = word + x; 
       } 
   }  
   words.push_back(word);
   return words;
} 	