// Digital and Analog Pin Commands

void ExecuteDigitalPinWriteCommand(byte *input)
{
  if (input[2] == 0)
  {
    digitalWrite(input[1], LOW);
    WritePinState(input[1], input[2]);
  }
  else if(input[2] == 1)
  {
    digitalWrite(input[1], HIGH);
    WritePinState(input[1], input[2]);
  }
  else
  {
    // Write error. Not sure when this case would ever happen.
    WritePinState(input[1], STATE_REPLY_ERROR_CODE);
  }
}

void ExecuteAnalogPinWriteCommand(byte *input)
{
  // On this board (UNO), analog write only works on pins
  // 3, 5, 6, 9, 10 and 11.
  analogWrite(input[1], input[2]);
  
  // RBakerFlag -> Need to send a reply package!
}

void WritePinState(int pinMapping, byte state)
{
  // RBakerFlag -> Need to fix this reply package!
  
  // Writes the pin state in the form XXXXXXSS, where X
  // is the pin mapping and S is the state.
  byte pinStateCode = byte(pinMapping << 3) + state;

  Serial.write(pinStateCode);
  Serial.flush();
}
