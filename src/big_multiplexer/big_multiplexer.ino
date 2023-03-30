long int A = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0,OUTPUT);
  pinMode(D0,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  digitalWrite(D0,0);
  digitalWrite(D5,0);
  digitalWrite(D6,0);
  digitalWrite(D7,0);
}

void loop() {
  A = A*0.6 + analogRead(A0)*0.4;
  Serial.println(A);
  delay(100);
}
