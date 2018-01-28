# include <Servo.h>  // calls the commands

Servo servoXAxis;     // creates the object for the Servo which moves in the X direction
Servo servoYAxis;     // creates the object for the Servo which moves in the y direction
Servo servoZAxis;     // creates the object for the Servo which moves in the z direction

int angleX = 0 ;       // initialise and declare the variable to store the angles in the X direction
int currentAngleX = 0;  //initialise and declare the variable to store the current angle during machining
int angleY = 0;
int currentAngleY = 0;
int angleZ = 0;
int currentAngleZ = 0;
int Radius = 0;

float LengthX = 0;  // variables to store the length of the X direction
float LengthY = 0;
float depth = 0;

const int completeLedPin = 3; // lights when machining is complete

void setup ()
{
  Serial.begin(9600); // initialise the baud rate
  servoXAxis.attach(4);   // arduino pin to attach the Xservo motor
  servoYAxis.attach(5);   // arduino pin to attach the Yservo motor
  servoZAxis.attach(6);   // arduino pin to attach the Zservo motor
  pinMode(completeLedPin, OUTPUT);
}

void loop()
{
  homePosition(); // function returns everything to home position to enable machining
  setZ();
  drawSquare();    // function to draw the square
  homePosition();
  setZ();         // allows you to set the required depth of cutting tool
  drawTriangle();  // function to draw the triangle
  homePosition();
  setZ();
  drawCircle();   // function to draw the circle
  homePosition();

}

void homePosition()
{
  servoXAxis.write(0);
  servoYAxis.write(0);
  servoZAxis.write(0);
}

void drawSquare()
{
  drawSideA(); //function draws the first side of the square from 0,0
  drawSideB(); // draws the second side from where the first command left
  drawSideC(); // draws the third side
  drawSideD(); // draws the foourth side
}

void drawTriangle()
{
  drawSideAA();  // draws the first side of the triangle from 0,0
  drawSideBB();  // draws the second side
  drawSideCC();  // draws the last side of the triangle
}


void drawSideA()
{
if (LengthX < 100)
{
  servoXAxis.write(angleX ++);
  currentAngleX = servoXAxis.read();
   Serial.println(currentAngleX);
   delay(250);
  LengthX = currentAngleX * 1.5;
  Serial.println(LengthX);
}
if(LengthX == 100)
  {
    servoXAxis.write(currentAngleX);
  }
}



void drawSideB()
{
  if(LengthY < 100)
  {
    servoYAxis.write(angleY ++);
    currentAngleY = servoXAxis.read();
    Serial.println(currentAngleY);
    delay(100);
    LengthY = currentAngleY * 1.5;
    Serial.println(LengthY);
  }
  if(LengthY == 100)
  {
    servoYAxis.write(currentAngleY);
  }
}

void drawSideC()
{
  if(LengthX == 100)
  {
    servoXAxis.write(angleX --);
    currentAngleX = servoXAxis.read();
    Serial.println(currentAngleX);
    delay(100);
    LengthX = currentAngleX * 1.5;
    Serial.println(100);
  }
  if(LengthX == 0)
  {
    servoXAxis.write(currentAngleX);
  }
}

void drawSideD()
{
  if(LengthY == 100)
  {
    servoYAxis.write(angleY --);
    currentAngleY = servoXAxis.read();
    Serial.println(currentAngleY);
    delay(100);
    LengthY = currentAngleY * 1.5;
    Serial.println(LengthY);
  }

  if(LengthY == 0)
  {
    servoYAxis.write(currentAngleY);
  }

}

void drawSideAA()
{
  if (LengthX < 120)
  {
    servoXAxis.write(angleX ++);
    currentAngleX = servoXAxis.read();
     Serial.println(currentAngleX);
     delay(250);
    LengthX = currentAngleX * 1.5;
    Serial.println(LengthX);
  }
  if(LengthX == 120)
    {
      servoXAxis.write(currentAngleX);
    }
}

void drawSideBB()
{
  if(LengthY == 0  && LengthX == 120)
  {
    servoXAxis.write(angleX ++);
    servoYAxis.write(angleY ++);
    currentAngleX = servoXAxis.read();
    currentAngleY = servoYAxis.read();
    LengthX = currentAngleX * 1.5;
    LengthY = currentAngleY * 1.5;
  }

  if(LengthY == 40 && LengthX == 150)
  {
    servoXAxis.write(currentAngleX);
    servoYAxis.write(currentAngleY);
  }

}

void drawSideCC()
{
  if(LengthY == 40 && LengthX == 150)
  {
    servoXAxis.write(angleX --);
    servoYAxis.write(angleY --);
    currentAngleX = servoXAxis.read();
    currentAngleY = servoYAxis.read();
    LengthX = currentAngleX * 1.5;
    LengthY = currentAngleY * 1.5;
  }

  if(LengthX == 0 && LengthY == 0)
  {
    servoXAxis.write(currentAngleX);
    servoYAxis.write(currentAngleY);
  }
}

void drawCircle()
{
  setRadius(60);

  if(LengthX == Radius && LengthY < 60)
  {
    servoXAxis.write(angleX ++);
    servoYAxis.write(angleY ++);
    currentAngleX = servoXAxis.read();
    currentAngleY = servoYAxis.read();
    LengthX = currentAngleX * 1.5;
    LengthY = currentAngleY * 1.5;
  }

  if(LengthY == 60 && LengthX < 60)
  {
    servoXAxis.write(currentAngleX);
    servoYAxis.write(currentAngleY);
  }

  if(LengthY == 60 && LengthX < 60 )
  {
    servoXAxis.write(angleX ++);
    servoYAxis.write(angleY ++);
    currentAngleX = servoXAxis.read();
    currentAngleY = servoYAxis.read();
    LengthX = currentAngleX * 1.5;
    LengthY = currentAngleY * 1.5;
  }

  if(LengthY < 60 && LengthX == 60)
  {
    servoXAxis.write(currentAngleX);
    servoYAxis.write(currentAngleY);
  }


  if(LengthX == Radius && LengthY < 60)
  {
    servoXAxis.write(angleX ++);
    servoYAxis.write(angleY ++);
    currentAngleX = servoXAxis.read();
    currentAngleY = servoYAxis.read();
    LengthX = currentAngleX * 1.5;
    LengthY = currentAngleY * 1.5;
  }

  if(LengthY == 60 && LengthX < 60)
  {
    servoXAxis.write(currentAngleX);
    servoYAxis.write(currentAngleY);
  }

  if (LengthY == Radius && LengthX < 60)
  {
    servoXAxis.write(angleX ++);
    servoYAxis.write(angleY ++);
    currentAngleX = servoXAxis.read();
    currentAngleY = servoYAxis.read();
    LengthX = currentAngleX * 1.5;
    LengthY = currentAngleY * 1.5;
  }
  if(LengthY < 60 && LengthX == 60)
  {
    servoXAxis.write(currentAngleX);
    servoYAxis.write(currentAngleY);
  }
}

void setRadius(int Radius)
{
  if(LengthX == 0 && LengthY == 0)
  {
    servoXAxis.write(angleX ++);
    currentAngleX = servoXAxis.read();
     Serial.println(currentAngleX);
     delay(250);
    LengthX = currentAngleX * 1.5;
    Serial.println(LengthX);
  }
  if(LengthX == Radius)
  {
    servoXAxis.write(currentAngleX);
  }
}

void setZ()
{
  if(depth == 0)
  {
    servoZAxis.write(angleZ ++);
    currentAngleZ = servoZAxis.read();
    depth = currentAngleZ * 1.25;
  }
  if(depth == 5)
  {
    servoZAxis.write(currentAngleZ);
  }

}

