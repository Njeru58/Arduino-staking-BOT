#define trigPin 9   // Trigger pin of the ultrasonic sensor
#define echoPin 10   // Echo pin of the ultrasonic sensor
#define laserPin 11  // Pin for the laser (LED)
#define servoPin 6   // Pin for the servo

#include <Servo.h>

Servo myServo; // Create a servo object

void setup() {
    Serial.begin(9600); // Start serial communication
    pinMode(trigPin, OUTPUT); // Set trigger pin as output
    pinMode(echoPin, INPUT); // Set echo pin as input
    pinMode(laserPin, OUTPUT); // Set laser pin as output
    myServo.attach(servoPin); // Attach the servo to the specified pin
}

void loop() {
    // Trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echo signal
    long duration = pulseIn(echoPin, HIGH);
    long distance = (duration * 0.034) / 2; // Calculate distance in cm

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Control the laser (LED)
    if (distance < 20) { // If an object is within 20 cm
        digitalWrite(laserPin, HIGH); // Turn on the laser
        myServo.write(90); // Move the servo to a specified angle
    } else {
        digitalWrite(laserPin, LOW); // Turn off the laser
        myServo.write(0); // Move the servo back to the starting position
    }

    delay(500); // Delay for stability
}
