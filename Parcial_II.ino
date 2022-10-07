int PIN_LED1 = 4;
int PIN_LED2 = 5;
int PIN_LED3 = 6;
int PIN_LED4 = 7;
int PIN_LED5 = 8;

int myLEDs[5] = {4,5,6,7,8};

int PIN_PIEZO = 3;

int PIN_BTN = 2;

int PIN_SENSOR = 0;
int hValue = 0;

int btnState = 0;

void setup()
{
  for (int i = 0;i < 5;i++){
    pinMode(myLEDs[i], OUTPUT);
  }
  
  pinMode(PIN_PIEZO, OUTPUT);
  pinMode(PIN_BTN, INPUT);
  Serial.begin(9600);

  
}

void loop()
{
  //hValue = makePercent(analogRead(PIN_SENSOR));
   hValue = analogRead(PIN_SENSOR);
  

  //Serial.println(hValue);
  
 
  btnState = digitalRead(PIN_BTN);
  
 Serial.println(btnState);
  
  
  if (hValue >= 0 && hValue <= 175){
    
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_PIEZO, HIGH);
    tone(PIN_PIEZO, 800, 20);
  }
  
  if (hValue > 175 && hValue <= 350){
    
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_PIEZO, LOW);
    
  }
  if (hValue > 350 && hValue <= 525){
    
    digitalWrite(PIN_LED3, HIGH);
    digitalWrite(PIN_PIEZO, LOW);
    
  }
  if (hValue > 525 && hValue <= 700){
    
    digitalWrite(PIN_LED4, HIGH);
    digitalWrite(PIN_PIEZO, LOW);
    
  }
  if (hValue > 700 && hValue <= 876){
    
    digitalWrite(PIN_LED5, HIGH);
    digitalWrite(PIN_PIEZO, HIGH);
    tone(PIN_PIEZO, 1200);
    
    if (btnState == 1){
      
      digitalWrite(PIN_PIEZO, LOW);
      delay (5000);
    }
    
    
  }
  
  //delay (200);
  
  
}

/*int makePercent(float value){
  value = round (value*876/100);
  return value;
}*/
