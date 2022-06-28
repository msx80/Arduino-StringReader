#include <StringReader.h>

#define MAX_COMMAND_LENGTH 150
#define TERMINATOR '\n'

StringReader<MAX_COMMAND_LENGTH> reader(&Serial, TERMINATOR, &onCommand);

void onCommand(char* str)
{
	Serial.print("Received: ");
	Serial.println(str);
}

void setup()
{
	Serial.begin(115200);
	while (!Serial);
}

void loop() 
{
	reader.update();
}
