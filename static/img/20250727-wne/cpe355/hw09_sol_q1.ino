//declaring a 1D array of 10 function pointers
void (*lineup[10])() = {NULL}; 
int volatile luptr=0;

void idel(int del)
{ int d;
    for(d=0;d<del;d++);
}
void interA()
{
  idel(10);
  // Check if overflow has ocurred.
  if (luptr < 10)
  { // Put on the end of the lineup 
    //add the function pointer of soundA to the first available position
    lineup[luptr]=&soundA;
    //inc lineup pointer
      luptr++;
    Serial.write(luptr);
  }
}

void interB()
{
  idel(10);
  // Check if overflow has ocurred.
  if (luptr < 10)
  { // Put on the end of the lineup 
    //add the function pointer of soundB to the first available position
    lineup[luptr]=&soundB; 
    //inc lineup pointer
      luptr++;
   Serial.write(luptr);
  }
}

void soundB()
{
digitalWrite(12, HIGH);
delay(2000);
digitalWrite(12, LOW);
delay(1000);
}

void soundA()
{
digitalWrite(12, HIGH);
delay(500);
digitalWrite(12, LOW);
delay(500);
digitalWrite(12, HIGH);
delay(500);
digitalWrite(12, LOW);
delay(500);
digitalWrite(12, HIGH);
delay(500);
digitalWrite(12, LOW);
delay(500);
}

void setup()
{
 attachInterrupt(0,interA,RISING); //Pin 2
 attachInterrupt(1,interB,RISING); //Pin 3
 pinMode(12,OUTPUT);
 Serial.begin(9600);
}

void loop()
{
    //Execute the function that is at the top of the list.
     lineup[0];
     noInterrupts();
     //Shift the line up up one
     int k;
     for(k==0;k<10;k++)
     {
         lineup[k]=lineup[k+1];
     }
     // Fill in guarenteed empty slot 10 with a null
     lineup[10]=NULL;
     // Decrement lineup pointer
     luptr--;
      Serial.write(luptr);
     interrupts();
}
