const byte PIN_MODE_STATE_ID_OUTPUT = 1;
const byte PIN_MODE_STATE_ID_INPUT = 2;
const byte PIN_MODE_STATE_ID_INPUT_PULLUP = 3;

void ExecuteSetPinModeCommand(byte *input)
{
  // RBakerFlag -> Need to send a reply package!
  
   switch(input[2])
   {
     case PIN_MODE_STATE_ID_OUTPUT:
       pinMode(input[1], OUTPUT);
       break;
     case PIN_MODE_STATE_ID_INPUT:
       pinMode(input[1], INPUT);
       break;
     case PIN_MODE_STATE_ID_INPUT_PULLUP:
       pinMode(input[1], INPUT_PULLUP);
       break;
   }
}
