int leftMortPos = 14; //in2
int leftMortNeg = 4; //in1
int rihgtMorPos = 27; //in3
int rihgtMorNeg =23; //in4
int ENA2= 12;
int ENA1 = 26;

int fast =255;
int slow = 100;

void moveForward()
{
    digitalWrite(ENA2, HIGH);
    digitalWrite(ENA1, HIGH);


    digitalWrite(leftMortPos, HIGH);
    digitalWrite(leftMortNeg, LOW);

    digitalWrite(rihgtMorPos, HIGH);
    digitalWrite(rihgtMorNeg, LOW);

    Serial.println("Continue walking");
}

void reverse()
{
    digitalWrite(ENA1, HIGH);
    digitalWrite(ENA2, HIGH);

    digitalWrite(leftMortPos, LOW);
    digitalWrite(leftMortNeg, HIGH);

    digitalWrite(rihgtMorPos, LOW);
    digitalWrite(rihgtMorNeg, HIGH);

    Serial.println("Reverse now");
}

void STop()
{
    digitalWrite(ENA1, LOW);
    digitalWrite(ENA2, LOW);

    digitalWrite(leftMortPos, LOW);
    digitalWrite(leftMortNeg, LOW);

    digitalWrite(rihgtMorPos, LOW);
    digitalWrite(rihgtMorNeg, LOW);

    Serial.println("Stopping");
}

void rightTurn()
{

    digitalWrite(ENA1, HIGH);
    digitalWrite(ENA2, LOW);

    digitalWrite(leftMortPos, HIGH);
    digitalWrite(leftMortNeg, LOW);

    digitalWrite(rihgtMorPos, LOW);
    digitalWrite(rihgtMorNeg, LOW);

    Serial.println("Turning right");
}

void leftTurn()
{

    digitalWrite(ENA1, LOW);
    digitalWrite(ENA2, HIGH);

    digitalWrite(leftMortPos, LOW);
    digitalWrite(leftMortNeg, LOW);

    digitalWrite(rihgtMorPos, HIGH);
    digitalWrite(rihgtMorNeg, LOW);

    Serial.println("Turning left");

}
  
