#ifndef COMMANDLIST_H
#define COMMANDLIST_H
#include <string>
using namespace std;

string CommandList[15] = {
	"DELAY",
	"STRING"
	"GUI",
	"UP",
	"DOWN",
	"LEFT",	
	"RIGHT",
	"CAPS",
	"ENTER",
	"SPACE",
	"REPEAT", // create function for these
	"SHIFT-ENTER", 
	"CTRL-ALT-DEL",
	"ALT-F4"
};

string initializer[3] = { 
	"#include <HID>",
	"#include <Keyboard.h",
	"void setup(){"
};

string closingWriter[6] ={
	"}",
	"void loop(){}",
	"void typeKey(int key){",
	"Keyboard.press(key);",
	"delay(500);",
	"Keyboard.release(key);"
};

#endif