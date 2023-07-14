
# include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
float DetectorDistance=5.8;
float t1;
float t2;
bool D1flag=false;
bool D2flag=false;
int D1Pin=8;
int D2Pin=9;r



void setup() {
  lcd.begin(16,2);
  pinMode(D1Pin,INPUT);
  pinMode(D2Pin,INPUT);
  Serial.begin(9600);

}

void loop() {

  if(!D1flag&&digitalRead(D1Pin)==HIGH)
  {
      t1=millis();
      D1flag=true;
      
  }
  if(!D2flag&&digitalRead(D2Pin)==HIGH)
  {
      t2=millis();
      D2flag=true;
  }
  if(D1flag&&D2flag)
  {
    lcd.clear();
    Serial.println(t1);
    Serial.println(t2);
    Serial.println((DetectorDistance/(t1-t2))*1000);
    lcd.print(t1-t2);
    
    delay(300);
    D1flag=false;
    D2flag=false;
    t1=0;
    t2=0;
    
  }

}
