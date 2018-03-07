#define NUMREADINGS 15

int senseLimit = 15; int probePin = 0; int val = 0;

int LED1 = 2; 
int LED2 = 3;
int LED3 = 4; 
int LED4 = 5; 
int LED5 = 9; 
//int LED6 = 7; 
//int LED7 = 8;

int buzzer = 13;

int buzzerTone = 0;

unsigned long previousMillis = 0; const long interval = 1000;

int readings[NUMREADINGS]; 
int index = 0; 
int total = 0; 
int average = 0;

void setup() {
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(13, OUTPUT);

  Serial.begin(9600);

  for (int i = 0; i < NUMREADINGS; i++) 
    readings[i] = 0;

}

void loop() {
  // put your main code here, to run repeatedly:
  fantome();
}


void fantome() {

    val = analogRead(probePin);
    
    if(val >= 1){
    
        val = constrain(val, 1, senseLimit); val = map(val, 1, senseLimit, 1, 1023);
        
        total -= readings[index]; readings[index] = val; total += readings[index]; index = (index + 1);
        
        if (index >= NUMREADINGS) index = 0;
        
        average = total / NUMREADINGS;
        
        if (average > 100) {digitalWrite(LED1, HIGH);} else {digitalWrite(LED1, LOW);}
        
        if (average > 200) {digitalWrite(LED2, HIGH);} else {digitalWrite(LED2, LOW);}
        
        if (average > 300) {digitalWrite(LED3, HIGH);} else {digitalWrite(LED3, LOW);}
        
        if (average > 400) {digitalWrite(LED4, HIGH);} else {digitalWrite(LED4, LOW);}
        
        if (average > 500) {digitalWrite(LED5, HIGH);} else {digitalWrite(LED5, LOW);}
        
     //   if (average > 600) {digitalWrite(LED6, HIGH);} else {digitalWrite(LED6, LOW);}
        
     //   if (average > 700) {digitalWrite(LED7, HIGH); tone(buzzer, 1000);} else {digitalWrite(LED7, LOW); noTone(buzzer);}
        
        Serial.println(val);
        
        } // use output to aid in calibrating 

}
