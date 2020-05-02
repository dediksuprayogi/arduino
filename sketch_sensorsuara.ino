int sensorSuara = A0;

int merahPin = 9;
int hijauPin = 10;
int biruPin = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorSuara, INPUT);
  pinMode(merahPin, OUTPUT);
  pinMode(hijauPin, OUTPUT);
  pinMode(biruPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int outputSuara = analogRead(sensorSuara);
  Serial.println(outputSuara);

  if (outputSuara < 59){
    analogWrite(merahPin, 255);
    analogWrite(hijauPin, 255);
    analogWrite(biruPin, 255);
  }
  else if (outputSuara < 61){
    analogWrite(merahPin, 0);
    analogWrite(hijauPin, 255);
    analogWrite(biruPin, 0);
  }
  else if (outputSuara < 63 ){
    analogWrite(merahPin, 255);
    analogWrite(hijauPin, 255);
    analogWrite(biruPin, 0);
  }
  else if (outputSuara < 69 ){
    analogWrite(merahPin, 0);
    analogWrite(hijauPin, 0);
    analogWrite(biruPin, 255);
  }else if (outputSuara > 70) {
    offAll();
    analogWrite(merahPin, 255);
    analogWrite(hijauPin, 0);
    analogWrite(biruPin, 0);
  }
  delay(200);
}

void offAll(){
  digitalWrite(merahPin, LOW);
  digitalWrite(hijauPin, LOW);
  digitalWrite(biruPin, LOW);
}
