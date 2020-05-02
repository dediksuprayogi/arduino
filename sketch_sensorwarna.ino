
const int s0=3; //Pin S0 ke Pin 3 Arduino
const int s1=4; //Pin S1 ke Pin 4 Arduino
const int s2=5; //Pin S2 ke Pin 5 Arduino
const int s3=6; //Pin S3 ke Pin 6 Arduino
const int sensorOut=2; //Pin OUT ke Pin D3 Arduino

int merahPin = 9;
int hijauPin = 10;
int biruPin = 11;

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

void setup() {
  // Begins serial communication 
  Serial.begin(9600);
  pinMode(merahPin, OUTPUT);
  pinMode(hijauPin, OUTPUT);
  pinMode(biruPin, OUTPUT);
  
  // put your setup code here, to run once:

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);

  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling
  digitalWrite(s0,HIGH);
  digitalWrite(s1,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
    analogWrite(merahPin, 0);
    analogWrite(hijauPin, 0);
    analogWrite(biruPin, 255);
    
  // Setting red filtered photodiodes to be read
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  // Reading the output frequency
  redFrequency  = pulseIn(sensorOut, LOW);  
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  redFrequency = map(redFrequency, 0,255,255,0);
  Serial.print("R :");  
  Serial.print(redFrequency); 

  // Setting red filtered photodiodes to be read
  digitalWrite(s2, HIGH);  
  digitalWrite(s3, HIGH);  
  // Reading the output frequency
  greenFrequency  = pulseIn(sensorOut, LOW);  
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  greenFrequency = map(greenFrequency, 0,255,255,0);
  Serial.print(" G : ");  
  Serial.print(greenFrequency);  

  // Setting red filtered photodiodes to be read
  digitalWrite(s2, LOW);  
  digitalWrite(s3, HIGH);  
  // Reading the output frequency
  blueFrequency  = pulseIn(sensorOut, LOW);  
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  blueFrequency = map(blueFrequency, 0,255,255,0);
  Serial.print(" B : ");  
  Serial.print(blueFrequency);  
  
  Serial.println();  
  delay(100);
}
