/*
Ducky script translator for ducky-like arduino boards
accepts a .txt file written for the USB Rubber Ducky and
outputs a .ino file that can be uploaded using arduino IDE
example usage:
dusckyscript.exe payload.txt payload.ino
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "CommandList.h"
#include "translator.h"
using namespace std;

void initializeArduinoFile(string);
string equivalentCommand(string);
void mainFilePayloadReader(string, string);
string getCommand(string);
string getValue(string);
void writeLine(string, string, string);
void addtypeKeyHelper(string);


int main(int argc, char* argv[]) { 
	initializeArduinoFile(argv[2]);
	mainFilePayloadReader(argv[1], argv[2]);
	addtypeKeyHelper(argv[2]);



	return 0;
}

//write out data from the initializer array to the arduino file
void initializeArduinoFile(string filename) { 
	ofstream arduinoFile;
	arduinoFile.open(filename, ios_base::app);
	if (!arduinoFile.is_open()) { 
		cout << "error could not create .ino file for writing" <<endl;
	}
	else { 
		for(int itr = 0; itr < 3; itr++) { 
			arduinoFile << initializer[itr] <<endl;
		}
	}

}
//recieves a line from a file and returns the command at the beginning
string getCommand(string line) { 
	int init_pos = 0;
	int cm_end_pos = line.find_first_of(" ");
	return line.substr(init_pos, cm_end_pos);

}

//given a delay or string command it returns the value
string getValue(string line) { 
		int space_pos = line.find_first_of(" ");
		int line_end = line.length();
		
		return line.substr(space_pos + 1, line_end);

}

//writes the full command out to the arduino script
void writeLine(string command, string value, string filename) { 
	ofstream writer(filename, ios_base::app);
	writer << command << value << endl;

}

void addtypeKeyHelper(string filename) { 
ofstream arduinoFile;
	arduinoFile.open(filename, ios_base::app);
	if (!arduinoFile.is_open()) { 
		cout << "error could not create .ino file for writing" <<endl;
	}
	else { 
		for(int itr = 0; itr < 6; itr++) { 
			arduinoFile << closingWriter[itr] <<endl;
		}
	}


}



void mainFilePayloadReader(string filename, string targetfile) { 
//open the payload file
	string line;
	ifstream payload(filename);
	if (!payload.is_open()) { 
		cout <<"error reading .txt payload script" <<endl;
	}
	else { 
		while (getline(payload, line)) { 
			//write out a comment
			if(getCommand(line) == "REM" && line != "") {
				writeLine(equivalentCommand(getCommand(line)), getValue(line) + "*/", targetfile);
				cout << "trying to write comment" <<endl;
			}	
			else if (getCommand(line) == "GUI" && line != "") { 
				if (getValue(line) != "GUI") { 
					//there is a paramter with GUI like GUI+r for run box
					writeLine(equivalentCommand(getCommand(line)) , getValue(line) +  ");", targetfile);
					writeLine("Keyboard.press(" + getValue(line) , getValue(line)  +  ");", targetfile);
					writeLine("Keyboard.releaseAll();", "",filename);
					cout << "found a windows press combination .. writing.." <<endl;
					//prbably puy this in a separate function
				}
			}

			else if (getCommand(line) == "STRING" && line != "") { 
				writeLine(equivalentCommand(getCommand(line)) , getValue(line) + "\");", targetfile);

			}
			else if (line != ""){ 
				writeLine(equivalentCommand(getCommand(line)) , getValue(line) + ");", targetfile);
				cout << "writing standard line out" <<endl;

			}

			
			
		}

		addtypeKeyHelper(targetfile);
	}	
//

}


