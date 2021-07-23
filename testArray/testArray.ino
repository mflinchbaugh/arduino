int firstChar = 18;
int secondChar = 1;
int thirdChar = 0;
int testArray[] = {firstChar, secondChar,thirdChar}; //why does "*"=539 ???
int count = 0;
int timer = 1000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (count=0;count<3;count++) {
    Serial.println(testArray[count]);
    delay(timer);
  }
}
