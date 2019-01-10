// Please insert your motor encoder output pulse per rotation
#define ENCODEROUTPUT 64

#define HALLSEN_A 3 // Hall sensor A connected to pin 3 (external interrupt)


volatile long encoderValue = 0;

int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;

int rpm = 0;
boolean measureRpm = false;
int motorPwm = 0;

void setup()
{
  Serial.begin(9600); // Initialize serial with 9600 baudrate

  pinMode(HALLSEN_A, INPUT_PULLUP); // Set hall sensor A as input pullup
  
  // Attach interrupt at hall sensor A on each rising signal
  attachInterrupt(digitalPinToInterrupt(HALLSEN_A), updateEncoder, RISING);

  Serial.print("\n\n");
  Serial.println("Measuring DC Motor's RPM");
}

void loop() {
    
    delay(500);
    encoderValue = 0;

    // Revolutions per minute (RPM) =
    // (total encoder pulse in 1s / motor encoder output) x 60s
    rpm = (float)(encoderValue * 60 / ENCODEROUTPUT);

    // Only update display when there have readings
    if (motorPwm > 0 || rpm > 0) {
      Serial.print(motorPwm);
      Serial.print('\t');
      Serial.print(encoderValue);
      Serial.print(" pulse / ");
      Serial.print(ENCODEROUTPUT);
      Serial.print(" pulse per rotation x 60 seconds = ");
      Serial.print(rpm);
      Serial.println(" RPM");
    }
    
    encoderValue = 0;
  }

void updateEncoder()
{
  // Add encoderValue by 1, each time it detects rising signal
  // from hall sensor A
  encoderValue++;
}

