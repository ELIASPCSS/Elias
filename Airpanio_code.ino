 const int trigPin = 13;
const int echoPin = 12;

const int buzzer = 11; 

const int greenLED = 10;
const int yellowLED  = 9;
const int redLED = 8;

long duration;
double distance;

double maxDistanceInches = 12; 

int baseFrequency = 10;
int maxFrequency = 1200;
int currentFrequency = 500;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzer, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(buzzer, LOW); 
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  Serial.begin(9600); 
}
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  
  duration = pulseIn(echoPin, HIGH);
 
  
  distance = duration * 0.034 / 2;
 
  
  distance = distance / 2.54;


  if(distance < maxDistanceInches){
     digitalWrite(greenLED, HIGH);
     currentFrequency = (distance/maxDistanceInches)*(maxFrequency - baseFrequency) + baseFrequency;
     tone(buzzer, currentFrequency,100);
     
     Serial.print("Distance: ");
     Serial.println(distance);

     Serial.print("Frequency: ");
     Serial.println(currentFrequency);
     delay(96);
  }
  else{
     digitalWrite(greenLED, LOW);
     noTone(buzzer); 
  }
     
  if(distance < (maxDistanceInches* 0.66))
    digitalWrite(yellowLED, HIGH);
  else
    digitalWrite(yellowLED, LOW);
 
   if(distance < (maxDistanceInches * 0.33)){
    digitalWrite(redLED, HIGH);
    
   }
   else{
   digitalWrite(redLED, LOW);
   
   }
}
