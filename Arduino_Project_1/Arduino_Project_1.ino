int orangeCircuit, yellowCircuit, greenCircuit, cyanCircuit, 
    blueCircuit, navyCircuit, pinkCircuit, brownCircuit;
int ledY, ledG, rgbR, rgbB, rgbG, ledB, ledN, ledP, ledBr, 
    ledO, ledML;
long startTime;
long miniStartTime;
bool firstTime;
int count;

void setup()
{
  orangeCircuit = 13; // 4 leds
  yellowCircuit = 12; // 2 leds
  greenCircuit = 11; // 3 leds
  cyanCircuit = 10; // 4 leds
  blueCircuit = 9; // 4 leds
  navyCircuit = 8; // 6 leds
  pinkCircuit = 7; // 5 leds
  brownCircuit = 6; // 4 leds
  ledY = 5;
  ledG = 4;
  rgbR = 3;
  rgbB = 2;
  rgbG = 1;
  ledB = 0;
  ledN = A0;
  ledP = A1;
  ledBr = A2;
  ledO = A3;
  ledML = A4;
  
  pinMode(orangeCircuit, OUTPUT);
  pinMode(yellowCircuit, OUTPUT);
  pinMode(greenCircuit, OUTPUT);
  pinMode(cyanCircuit, OUTPUT);
  pinMode(blueCircuit, OUTPUT);
  pinMode(navyCircuit, OUTPUT);
  pinMode(pinkCircuit, OUTPUT);
  pinMode(brownCircuit, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(rgbR, OUTPUT);
  pinMode(rgbB, OUTPUT);
  pinMode(rgbG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledN, OUTPUT);
  pinMode(ledP, OUTPUT);
  pinMode(ledBr, OUTPUT);
  pinMode(ledO, OUTPUT);
  pinMode(ledML, OUTPUT);
  
  startTime = 0;
  firstTime = true;
  count = 0;
}

void allOn()
{
  digitalWrite(orangeCircuit, HIGH);
  digitalWrite(yellowCircuit, HIGH);
  digitalWrite(greenCircuit, HIGH);
  digitalWrite(cyanCircuit, HIGH);
  digitalWrite(blueCircuit, HIGH);
  digitalWrite(navyCircuit, HIGH);
  digitalWrite(pinkCircuit, HIGH);
  digitalWrite(brownCircuit, HIGH);
  digitalWrite(ledY, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledB, HIGH);
  //digitalWrite(rgbR, HIGH);
  //digitalWrite(rgbB, HIGH);
  //digitalWrite(rgbG, HIGH);
  digitalWrite(ledN, HIGH);
  digitalWrite(ledP, HIGH);
  digitalWrite(ledBr, HIGH);
  digitalWrite(ledO, HIGH);
  digitalWrite(ledML, HIGH);
}

void allOff()
{
  digitalWrite(orangeCircuit, LOW);
  digitalWrite(yellowCircuit, LOW);
  digitalWrite(greenCircuit, LOW);
  digitalWrite(cyanCircuit, LOW);
  digitalWrite(blueCircuit, LOW);
  digitalWrite(navyCircuit, LOW);
  digitalWrite(pinkCircuit, LOW);
  digitalWrite(brownCircuit, LOW);
  digitalWrite(ledY, LOW);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);
  //digitalWrite(rgbR, LOW);
  //digitalWrite(rgbB, LOW);
  //digitalWrite(rgbG, LOW);
  digitalWrite(ledN, LOW);
  digitalWrite(ledP, LOW);
  digitalWrite(ledBr, LOW);
  digitalWrite(ledO, LOW);
  digitalWrite(ledML, LOW);
}

//@author Lihan
void endOfPattern()
{
  count += 1;
  firstTime = true;
}

//@author Lihan
//tested
void fullSpectrum(int red, int blue, int green)
{
  long time = millis();
  int powerR = 127.5*cos(2*PI*time/2000) + 127.5;
  int powerB = 127.5*sin(2*PI*time/2000) + 127.5;
  int powerG = 0;//127.5*sin(2*PI*time/2000) + 127.5; //rgbG stopped working after the box is taped
  
  analogWrite(rgbR, powerR);
  analogWrite(rgbB, powerB);
  analogWrite(rgbG, powerG);
}

//@author Alex
//tested
void initPattern()
{
  long time = millis();
  long secs = time/1000;
  if(secs == 0){
    digitalWrite(greenCircuit,HIGH);
    digitalWrite(cyanCircuit,HIGH);
  }
  if(secs == 1){
    digitalWrite(greenCircuit,LOW);
    digitalWrite(cyanCircuit,LOW);
    digitalWrite(blueCircuit,HIGH);
    digitalWrite(yellowCircuit,HIGH);
  }
  if(secs == 2){
    digitalWrite(blueCircuit,LOW);
    digitalWrite(yellowCircuit,LOW);
    digitalWrite(orangeCircuit,HIGH);
    digitalWrite(navyCircuit,HIGH);
  }
  if(secs == 3){
    digitalWrite(orangeCircuit,LOW);
    digitalWrite(navyCircuit,LOW);
    digitalWrite(pinkCircuit,HIGH);
    digitalWrite(brownCircuit,HIGH);
  }
  if(secs == 4){
    digitalWrite(pinkCircuit,LOW);
    digitalWrite(brownCircuit,LOW);
  }
}

//@author Lihan
//tested
void pattern1()
{
  long time = millis();
  long halfsec = time/500;
  
  if (firstTime)
  {
    startTime = halfsec;
    firstTime = false;
  }
  
  long deltaTime = halfsec - startTime;
  
  if(deltaTime%12 == 1)
  {
    //pattern 1
    digitalWrite(yellowCircuit, HIGH);
    
    //pattern 1.1
    digitalWrite(ledY, HIGH);
  }
  else if(deltaTime%12 == 2)
  {
    //turn off the previous ones
    digitalWrite(yellowCircuit, LOW);
    digitalWrite(ledY, LOW);
    
    //pattern 1
    digitalWrite(greenCircuit, HIGH);
        
    //pattern 1.2
    digitalWrite(ledG, HIGH);
  }
  else if(deltaTime%12 == 3)
  {
    //turn off the previous ones
    digitalWrite(greenCircuit, LOW);
    digitalWrite(ledG, LOW);
    
    //pattern 1
    digitalWrite(cyanCircuit, HIGH);
  }
  else if(deltaTime%12 == 4)
  {
    //turn off the previous ones
    digitalWrite(cyanCircuit, LOW);
    
    //pattern 1
    digitalWrite(blueCircuit, HIGH);
    
    //pattern 1.1
    digitalWrite(ledB, HIGH);
  }
  else if(deltaTime%12 == 5)
  {
    //turn off the previous ones
    digitalWrite(blueCircuit, LOW);
    digitalWrite(ledB, LOW);
    
    //pattern 1
    digitalWrite(navyCircuit, HIGH);
    
    //pattern 1.1
    digitalWrite(ledN, HIGH);
  }
  else if(deltaTime%12 == 6)
  {
    //turn off the previous ones
    digitalWrite(navyCircuit, LOW);
    digitalWrite(ledN, LOW);
    
    //pattern 1
    digitalWrite(pinkCircuit, HIGH);
    digitalWrite(ledP, HIGH);
  }
  else if(deltaTime%12 == 7)
  {
    //turn off the previous ones
    digitalWrite(pinkCircuit, LOW);
    digitalWrite(ledP, LOW);
    
    //pattern 1
    digitalWrite(brownCircuit, HIGH);
    digitalWrite(ledBr, HIGH);
  }
  else if(deltaTime%12 == 8)
  {
    //turn off the previous ones
    digitalWrite(brownCircuit, LOW);
    digitalWrite(ledBr, LOW); 
    
    //pattern 1
    digitalWrite(orangeCircuit, HIGH);
    
    //pattern 1.1
    digitalWrite(ledO, HIGH);
  }
  else if(deltaTime%12 == 9)
  {
    //turn off the previous ones
    digitalWrite(orangeCircuit, LOW);
    digitalWrite(ledO, LOW);
    
    //pattern 1.1
    digitalWrite(ledML, HIGH);
  }
  else if(deltaTime%12 == 10)
  {
    //turn off the previous ones
    digitalWrite(ledML, LOW);

    //digitalWrite(ledY, HIGH);
  }
  //else if(deltaTime%12 == 10)
  //{
    /*
    if(millis()%500 < 250)
      allOn();
    else
      allOff();
    //wow this works
    //amazing
    */
    //digitalWrite(ledY, LOW);
  //}
  else if (deltaTime%12 == 11) //else doesn't work as intended if you commented out an else if lol 
  //previously did 1-10 and else -> 0=else=endOfPattern()=jump to next pattern
  {
    endOfPattern();
  }
}

void loop()
{
  //allOn();
  long time = millis();
  long sec = time/1000;
  if(sec < 5)
    initPattern();
  else
  {
    fullSpectrum(rgbR, rgbB, rgbG);
    if(count%3 == 0)
    {
      pattern1();
    }
    else if(count%3 == 1)
    {
      graduallyOn();
      //allOn();
    }
    else
    {
      graduallyOff();
    }
  }
}

//@author Lihan
//
void graduallyOn()
{
  long time = millis();
  long halfsec = time/500;
  
  if (firstTime)
  {
    startTime = halfsec;
    firstTime = false;
  }
  
  long deltaTime = halfsec - startTime;
  
  if(deltaTime%12 == 0)
  {
    //pattern 1
    digitalWrite(yellowCircuit, HIGH);
    
    //pattern 1.1
    digitalWrite(ledY, HIGH);
  }
  else if(deltaTime%12 == 1)
  {/*
    //turn off the previous ones
    digitalWrite(yellowCircuit, LOW);
    digitalWrite(ledY, LOW);*/
    
    //pattern 1
    digitalWrite(greenCircuit, HIGH);
        
    //pattern 1.2
    digitalWrite(ledG, HIGH);
  }
  else if(deltaTime%12 == 2)
  {/*
    //turn off the previous ones
    digitalWrite(greenCircuit, LOW);
    digitalWrite(ledG, LOW);*/
    
    //pattern 1
    digitalWrite(cyanCircuit, HIGH);
  }
  else if(deltaTime%12 == 3)
  {/*
    //turn off the previous ones
    digitalWrite(cyanCircuit, LOW);*/
    
    //pattern 1
    digitalWrite(blueCircuit, HIGH);
    
    //pattern 1.1
    digitalWrite(ledB, HIGH);
  }
  else if(deltaTime%12 == 4)
  {/*
    //turn off the previous ones
    digitalWrite(blueCircuit, LOW);
    digitalWrite(ledB, LOW);*/
    
    //pattern 1
    digitalWrite(navyCircuit, HIGH);
    
    //pattern 1.1
    digitalWrite(ledN, HIGH);
  }
  else if(deltaTime%12 == 5)
  {/*
    //turn off the previous ones
    digitalWrite(navyCircuit, LOW);
    digitalWrite(ledN, LOW);*/
    
    //pattern 1
    digitalWrite(pinkCircuit, HIGH);
    digitalWrite(ledP, HIGH);
  }
  else if(deltaTime%12 == 6)
  {/*
    //turn off the previous ones
    digitalWrite(pinkCircuit, LOW);
    digitalWrite(ledP, LOW);*/
    
    //pattern 1
    digitalWrite(brownCircuit, HIGH);
    digitalWrite(ledBr, HIGH);
  }
  else if(deltaTime%12 == 7)
  {/*
    //turn off the previous ones
    digitalWrite(brownCircuit, LOW);
    digitalWrite(ledBr, LOW); */
    
    //pattern 1
    digitalWrite(orangeCircuit, HIGH);
    
    //pattern 1.1
    digitalWrite(ledO, HIGH);
  }
  else if(deltaTime%12 == 8)
  {/*
    //turn off the previous ones
    digitalWrite(orangeCircuit, LOW);
    digitalWrite(ledO, LOW);*/
    
    //pattern 1.1
    digitalWrite(ledML, HIGH);
  }
  else if(deltaTime%12 == 9)
  {/*
    //turn off the previous ones
    digitalWrite(ledML, LOW);*/

    digitalWrite(ledY, HIGH);
  }
  else if(deltaTime%12 == 10)
  {/*
    if(millis()%500 < 250)
      allOn();
    else
      allOff();
    //wow this works
    //amazing
    */
    endOfPattern(); //skips next second/time unit
  }
  else if(deltaTime%12 == 11)
  {/*
    if(millis()%500 < 250)
      allOn();
    else
    {
      allOff();
      endOfPattern();
    }*/
    //endOfPattern();
  }
}

//@author Lihan
void graduallyOff()
{
  long time = millis();
  long halfsec = time/500;
  
  if (firstTime)
  {
    startTime = halfsec;
    firstTime = false;
    allOn();
  }
  
  long deltaTime = halfsec - startTime;
  
  if(deltaTime%12 == 9)
  {
    if(millis()%500 < 250)
      allOn();
    else
      allOff();
    //wow this works
    //amazing
  }
  else if(deltaTime%12 == 8)
  {
    //turn off the previous ones
    digitalWrite(yellowCircuit, LOW);
    digitalWrite(ledY, LOW);
  }
  else if(deltaTime%12 == 7)
  {
    digitalWrite(greenCircuit, LOW);
    digitalWrite(ledG, LOW);
  }
  else if(deltaTime%12 == 6)
  {
    digitalWrite(cyanCircuit, LOW);
  }
  else if(deltaTime%12 == 5)
  {
    digitalWrite(blueCircuit, LOW);
    digitalWrite(ledB, LOW);
  }
  else if(deltaTime%12 == 4)
  {
    //turn off the previous ones
    digitalWrite(navyCircuit, LOW);
    digitalWrite(ledN, LOW);
  }
  else if(deltaTime%12 == 3)
  {
    digitalWrite(pinkCircuit, LOW);
    digitalWrite(ledP, LOW);
  }
  else if(deltaTime%12 == 2)
  {
    digitalWrite(brownCircuit, LOW);
    digitalWrite(ledBr, LOW); 
  }
  else if(deltaTime%12 == 1)
  {
    digitalWrite(orangeCircuit, LOW);
    digitalWrite(ledO, LOW);
  }
  else if(deltaTime%12 == 0)
  {
    //turn off the previous ones
    digitalWrite(ledML, LOW);
  }
  else if(deltaTime%12 == 10)
  {
    if(millis()%500 < 250)
      allOn();
    else
      allOff();
    //wow this works
    //amazing
  }
  else if(deltaTime%12 == 11)
  {
    endOfPattern();
  }
}

//general note:
//graduallyOn() and graduallyOff() is just modified versions of pattern1()

//pattern1() notes/mumbles
  //012345678
  // 1234567
  //  2 4
  
  //int start = halfsec%9; // how to only get start once
  //^make it work when started at any second
  //0123456789 // time
  //  0123456789 // pattern time
  //ask for help
  //yay figured it out
  //need to grab it before the loop
  //i.e. global variable
  //nope it will still be updated every time
  //no it won't...right?

  //grab startTime -> if currTime == startTime + 0, 1, 2, 3
  
  //I'm just going to hack it with a boolean

//fullSpectrum() notes
  // R: 255->0->255
  // B: 0->255->0 but with 2*period
  // G: 0->255->0
  // y = Asin(bt) + C
  // A = magnitude
  // 2PI/b = period
  // C = delta y

//var names notes
// led yellowCircuit, led greenCircuit, 
// rgb led - red, rgb led - blue, rgb led - green
// there will be 2 rgb leds on a parallel circuit
// led blueCircuit, led navyCircuit, led pinkCircuit
// led brownCircuit, led orangeCircuit
// led in the middle - top one (left)
// led in the middle - bottom one (right)
// orangeCircuit is always in top left corner

// Note: Pin 1 and 0 -> communications 
// Also messes with input (?)
// Oh right without print you can't test things
// Serial.begin(9600) -> necessary for Serial.print()

// yellowCircuit is in series
