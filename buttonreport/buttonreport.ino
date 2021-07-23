const int buttonPin = 4;
int buttonState = 0;
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
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }
}
  
