int Red = 12;
int Redp = 10;
int Green = 7;
int Greenp = 11;
int Yellow = 8;
int Button = 9;
int ButtonState, LastButton = 0, state;



void Pedes(int, int);



void setup() {
pinMode(Red, OUTPUT);
pinMode(Redp, OUTPUT);
pinMode(Yellow, OUTPUT);
pinMode(Green, OUTPUT);
pinMode(Greenp, OUTPUT);
pinMode(Button, INPUT);
}



void loop() {
ButtonState = digitalRead(Button);
if(ButtonState == HIGH && LastButton == LOW){
Pedes(1, LastButton);
}
else if(ButtonState == LOW){
Pedes(0, LastButton);
}
LastButton = ButtonState;
}



void Pedes(int Can, int Last) {
if(Last == 0||Can == 1){
digitalWrite(Green, (Can == 1) ? LOW:HIGH);
digitalWrite(Yellow, (Can == 1) ? HIGH:LOW);
}
else if(Last == HIGH && Can == 0){
  for(int x = 0;x < 13; x++){
    digitalWrite(Greenp, HIGH);
    delay(250);
    digitalWrite(Greenp, LOW);
    delay(250);
  }
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Redp, HIGH);
  digitalWrite(Yellow, HIGH);
  delay(1000);
  digitalWrite(Yellow, LOW);

}
if(Can == 1){

digitalWrite(Yellow, HIGH);
delay(1500);
digitalWrite(Yellow, LOW);
}
digitalWrite(Red, (Can == 1) ? HIGH:LOW);
digitalWrite(Greenp, (Can == 1) ? HIGH:LOW);
digitalWrite(Redp, (Can == 1) ? LOW:HIGH);
}
