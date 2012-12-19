void ExecuteSetStepper1Command(byte *input)
{
  // Stepper command: [command ID][speed in rpm][steps]
  stepper1.setSpeed(input[1]);
  stepper1.step(input[2]);
  delay(100);
  
  // RBakerFlag -> Should return some information!
}
