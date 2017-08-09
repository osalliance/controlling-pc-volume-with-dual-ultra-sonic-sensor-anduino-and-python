#define TRIG_RIGHT 2
#define ECHO_RIGHT 3

#define TRIG_LEFT 8
#define ECHO_LEFT 9

int duration_right, duration_left;
float distance_right_cm, distance_left_cm;

void setup() {

  Serial.begin(9600);
  
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);

  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);

}

void loop() {
  digitalWrite(TRIG_RIGHT, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_RIGHT, LOW);
  duration_right  = pulseIn(ECHO_RIGHT, HIGH);
  distance_right_cm = duration_right * (17.0/1000);
  if((10<distance_right_cm)&&(distance_right_cm<20)) Serial.write(0xAF);
//  Serial.print("Distance Right = ");
//  Serial.print(distance_right_cm);
//  Serial.println("cm")

  delayMicroseconds(100);

  digitalWrite(TRIG_LEFT, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_LEFT, LOW);
  duration_left  = pulseIn(ECHO_LEFT, HIGH);
  distance_left_cm = duration_left * (17.0/1000);
  if((10<distance_left_cm)&&(distance_left_cm<20)) Serial.write(0xAE);
  
//  Serial.print("Distance Left = ");
//  Serial.print(distance_left_cm);
//  Serial.println("cm");

  delayMicroseconds(100);

}
