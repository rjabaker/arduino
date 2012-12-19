const byte DIGITAL_PIN_WRITE_COMMAND_ID = 1;
const byte SETTING_COMMAND_ID = 2;
const byte ANALOG_PIN_WRITE_COMMAND_ID = 3;
const byte SET_PIN_MODE_COMMAND_ID = 4;
const byte SET_STEPPER_1_COMMAND_ID = 30;

const byte STATE_REPLY_ERROR_CODE = 7; // 00000111

#include <Stepper.h>

Stepper stepper1(200, 9, 10, 11, 12);

void setup()
{
  SetOutputPins();
  Serial.begin(115200);
  
  // Blink the LED at pin 13 to show that the module as started/restarted.
  blink(13, 3, 100);
  blink(13, 3, 50);
  blink(13, 3, 100);
}

void loop()
{
  // Reads the first byte of incoming data. Only executes on byte at a time. 
  // Multiple byte execution is slow. 
  if (Serial.available() > 0)
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
  // Configure the default pins for output.
  pinMode(13, OUTPUT);
}

void blink(int whatPin, int howManyTimes, int milliSecs)
{
  for (int i = 0; i < howManyTimes; i++)
  {
    digitalWrite(whatPin, HIGH);
    delay(milliSecs / 2);
    digitalWrite(whatPin, LOW);
    delay(milliSecs / 2);
  }
}

void ExecuteCommand(byte *input)
{
  switch(input[0])
  {
    case DIGITAL_PIN_WRITE_COMMAND_ID:
      ExecuteDigitalPinWriteCommand(input);
      break;
    case SETTING_COMMAND_ID:
      ExecuteSettingCommand(input);
      break;
    case ANALOG_PIN_WRITE_COMMAND_ID:
      ExecuteAnalogPinWriteCommand(input);
      break;
    case SET_PIN_MODE_COMMAND_ID:
      ExecuteSetPinModeCommand(input);
      break;
    case SET_STEPPER_1_COMMAND_ID:
      ExecuteSetStepper1Command(input);
      break;      
  }
}



