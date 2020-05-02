int merahPin = 3;
int hijauPin = 5;
int biruPin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(merahPin, OUTPUT);
  pinMode(hijauPin, OUTPUT);
  pinMode(biruPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    analogWrite(merahPin, 255);
    analogWrite(hijauPin, 0);
    analogWrite(biruPin, 0);
    delay(2000);
    
    analogWrite(merahPin, 0);
    analogWrite(hijauPin, 255);
    analogWrite(biruPin, 0);
    delay(2000);
  
    analogWrite(merahPin, 0);
    analogWrite(hijauPin, 0);
    analogWrite(biruPin, 255);

    delay(2000);
}
