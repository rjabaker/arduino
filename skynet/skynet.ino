const byte PIN_COMMAND_ID = 1;
const byte SETTING_COMMAND_ID = 2;

const byte STATE_REPLY_ERROR_CODE = 7; // 00000111

int count;

void setup()
{
  SetOutputPins();
  Serial.begin(115200);
}

void loop()
{
  // Reads the first byte of incoming data. Only executes on byte at a time. 
  // Multiple byte execution is slow. 
  if(Serial.available() > 0)
  {
    // Wait for serial to retrieve all the bytes to read.
    delay(10);

    byte input[3];
    input[0] = Serial.read();
    input[1] = Serial.read();
    input[2] = Serial.read();
    
    ExecuteCommand(input);
  }
}

void SetOutputPins()
{
  // Configure the pins for output.
  // For now, we're only using pin 13.
  pinMode(13, OUTPUT);
}

void ExecuteCommand(byte *input)
{
  switch(input[0])
  {
  // case PIN_COMMAND_ID:
  case PIN_COMMAND_ID:
    ExecutePinCommand(input);
    break;
  case SETTING_COMMAND_ID:
    ExecuteSettingCommand(input);
    break;
  }
}



