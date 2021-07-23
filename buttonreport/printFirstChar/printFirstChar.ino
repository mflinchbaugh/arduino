const int buttonPin = 4;
int buttonState = 0;
int lastButtonState = 0;
int startTime = 0;
int endTime = 0;
int pressedTime = 0;
int idleTime = 0;
int firstChar = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (buttonPin, INPUT);
  //init serial window
  Serial.begin(9600);
    while (!Serial) {
    ;
  }
}
void loop() {
  buttonState = digitalRead(buttonPin);//read button state
  
  if (buttonState != lastButtonState) {   //if button state changed
    updateState();

  lastButtonState = buttonState;  //save button state for next round
  }
}

void updateState() {  //button was just pressed
  if (buttonState == LOW) {
   startTime = millis();  //record start time
   idleTime = startTime - endTime; //calculate time since last release
  } else {
    endTime = millis(); //record end time
    pressedTime = endTime - startTime;  //calculate time since pressed
    //Serial.println(pressedTime); //could just announce time pressed
      if (pressedTime <= 200) {
        firstChar = ".";  //store dot
      } else {
        firstChar = "_";  //store dash
      }
      if (idleTime >=3000){
        Serial.println(firstChar);
      }
  }
}
