const int buttonPin = 4;
int buttonState = 0;
int lastButtonState = 0;
int startTime = 0;
int endTime = 0;
int pressedTime = 0;
int idleTime = 0;
int firstChar = 8;
int secondChar = 1;
int thirdChar = 0;
int testArray[] = {firstChar, secondChar, thirdChar}; //why does "*"=539 ???
int count = 0;
int timer = 3000;
boolean beenPressed = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);//read button state

  if (buttonState != lastButtonState) {   //if button state changed
    updateState();

    lastButtonState = buttonState;  //save button state for next round
  }
  idleTime = millis() - endTime; //calculate time since last release
  if (beenPressed && idleTime >= timer) {
    for (count = 0; count < 3; count++) {
      Serial.print(testArray[count]);
      testArray[count] = 0;
    }
    Serial.println();
    endTime = millis();
    beenPressed = false;
  }
}

void updateState() {  //button was just pressed
  if (buttonState == LOW) {
    startTime = millis();  //record start time
    
  } else {
    endTime = millis(); //record end time
    pressedTime = endTime - startTime;  //calculate time since pressed
    beenPressed = true;
    //Serial.println(pressedTime); //could just announce time pressed
    //if (pressedTime <= 200) {
    // Serial.println(".");  //print dot
    // } else {
    //   Serial.println("_");  //print dash
    // }
  }

}
