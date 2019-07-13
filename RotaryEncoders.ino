// Left Encoder
int leftA = 0;
int leftB = 0;
const int LEFT_PIN_A = 2;
const int LEFT_PIN_B = 4;
bool leftDataReady = false;
int leftCount = 0;
int lastLeftCount = 0;

// Right encoder
int rightA = 0;
int rightB = 0;
const int RIGHT_PIN_A = 3;
const int RIGHT_PIN_B = 5;
bool rightDataReady = false;
int rightCount = 0;
int lastRightCount = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(LEFT_PIN_A), Left_Encoder_ISR, RISING);
  Serial.println("Left rotary encoder interrupt is attached");  
  attachInterrupt(digitalPinToInterrupt(RIGHT_PIN_A), Right_Encoder_ISR, RISING);
  Serial.println("Right rotary encoder interrupt is attached");
  pinMode(LEFT_PIN_A, INPUT_PULLUP);
  pinMode(LEFT_PIN_B, INPUT_PULLUP);
  pinMode(RIGHT_PIN_A, INPUT_PULLUP);
  pinMode(RIGHT_PIN_B, INPUT_PULLUP);
}

void Left_Encoder_ISR()
{
  leftA = digitalRead(LEFT_PIN_A);
  leftB = digitalRead(LEFT_PIN_B);
  if(leftA == leftB)
    {
      leftCount++;
    }
    else
    {
      leftCount--;
    }
  leftDataReady = true;
}

void Right_Encoder_ISR()
{
  rightA = digitalRead(RIGHT_PIN_A);
  rightB = digitalRead(RIGHT_PIN_B);
  if(rightA == rightB)
    {
      rightCount++;
    }
    else
    {
      rightCount--;
    }
  rightDataReady = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(leftDataReady)
  {
    Serial.print("Left encoder count = ");
    Serial.println(leftCount);
    if (leftCount > lastLeftCount)
    {
      Serial.println("Left encoder is turning Clockwise");
    }
    else
    {
      Serial.println("Left encoder is turning Contra-Clockwise");
    }
    lastLeftCount = leftCount;
    Serial.println("");
    leftDataReady = false;    
  }  
  if(rightDataReady)
  {
    Serial.print("Right encoder count = ");
    Serial.println(rightCount);
    if (rightCount > lastRightCount)
    {
      Serial.println("Right encoder is turning Clockwise");
    }
    else
    {
      Serial.println("Right encoder is turning Contra-Clockwise");
    }
    lastRightCount = rightCount;
    Serial.println("");
    rightDataReady = false;    
  }  
}
