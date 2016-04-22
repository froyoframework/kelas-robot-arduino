#define trigPin 13
#define echoPin 12

//Arduino PLL Speed Control：
int E1 = 4;   
int M1 = 5;
int E2 = 7;                         
int M2 = 6;

// sensor
int maximumRange = 200;
int minimumRange = 0;
long duration, distance;

void moveForward() {
  digitalWrite(E1, HIGH);   
  digitalWrite(E2, HIGH);       
  analogWrite(M1, 0);   //PLL Speed Control
  analogWrite(M2, 255);       //PLL Speed Control
}

void moveBackward() {
  digitalWrite(E1, HIGH);   
  digitalWrite(E2, HIGH);       
  analogWrite(M1, 255);       //PLL Speed Control
  analogWrite(M2, 0);   //PLL Speed Control
}

void turnLeft() {
  digitalWrite(E1, LOW);   
  digitalWrite(E2, HIGH);       
  analogWrite(M1, 80);   //PLL Speed Control
  analogWrite(M2, 200);       //PLL Speed Control
}

void turnRight() {
  digitalWrite(E1, HIGH);   
  digitalWrite(E2, HIGH);       
  analogWrite(M1, 40);   //PLL Speed Control
  analogWrite(M2, 150);       //PLL Speed Control
}

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(M1, OUTPUT);   
  pinMode(M2, OUTPUT); 
  pinMode(E1, OUTPUT); 
  pinMode(E2, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  // calculate the distance (in cm) based on the speed of sound
  distance = duration/58.2;

  if (distance >= maximumRange || distance <= minimumRange){
    /* Send a negative number to computer and Turn LED ON 
    to indicate "out of range" */
    Serial.println("-1");
    moveForward();
  } else {
    /* Send the distance to the computer using Serial protocol, and
    turn LED OFF to indicate successful reading. */
    Serial.println(distance);
    turnLeft(); 
  }
   
  delay(50);
}
