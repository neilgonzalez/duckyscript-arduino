//takes a command and finds its equivalent in arduino
#include <string>
using namespace std;
string equivalentCommand(string command) { 

		if(command == "REM") { 
			return "/*";
		}
		if(command == "DELAY"){
			return "delay(";
		}
		else if(command == "STRING"){
			return "Keyboard.print(\"";
		}
		else if(command == "GUI"){
			return "Keyboard.press(KEY_LEFT_GUI";
		}
		else if(command == "UP"){
			return "typeKey(KEY_UP_ARROW";
		}
		else if(command=="DOWN"){
			return "typeKey(DOWN_ARROW";
		}
		else if(command=="LEFT"){
			return "typeKey(KEY_LEFT_ARROW";
		}
		else if(command == "RIGHT"){
			return "typeKey(KEY_RIGHT_ARROW";
		}
		else if(command == "CAPS"){
			return "typeKey(KEY_CAPS_LOCK";
		}
		else if(command == "ENTER"){
			return "typeKey(KEY_ENTER";
		}
		else if(command == "SPACE"){
			return "Keyboard.print(\" \"";
		}
		//create functions for the rest



	}

