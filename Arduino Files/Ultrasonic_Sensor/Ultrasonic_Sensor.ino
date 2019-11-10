// defines pins numbers
const int trigPin = 10;
const int echoPin = 9;
int green = 13;
int red = 7;

// defines variables
long duration;
int distance;
long randNumber;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  randNumber = random(2);
  if(randNumber == 0){
    digitalWrite(red, HIGH);
  }else{
    digitalWrite(green, HIGH);
  }
  sensor();
  delay(250);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
}

void sensor(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  delay(1000);
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
