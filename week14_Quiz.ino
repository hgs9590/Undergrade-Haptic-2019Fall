int sensorPosPin = A2; // input pin for MR sensor
int rawPos;
int t = 0;
bool mode;

  
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // get incoming byte:
  int inByte = Serial.read();
  
  if(inByte == '1')
  { 
    mode = true;
  }
  // turn the LED on (HIGH is the voltage level)
  else if(inByte=='2')
  {
    mode = false;
  }
  
  if (mode == true) // true
  {
    calculatePosition();
  }  
  else//if (mode == false) // false
  {
    calculateVirtualPosition();
  }
  Serial.println(rawPos);
  delay(10);
}


void calculatePosition()
{
  rawPos = analogRead(sensorPosPin);
}


void calculateVirtualPosition(){
  t = t+1;
  rawPos = 512+512.0 * sin(0.1 * t);
}
