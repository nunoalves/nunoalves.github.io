volatile int red=6;
volatile int green=5;
volatile int yellow=4;

boolean deviceB=false;
void setup()
{
  interrupts();
   attachInterrupt(0,dothisA,CHANGE);
   attachInterrupt(1,dothisB,CHANGE);
   
   pinMode(green,OUTPUT); //Setups red, green and yellow LEDs
   pinMode(red,OUTPUT);
   pinMode(yellow,OUTPUT);

   digitalWrite(green,LOW); //Make sure the LEDs start off
   digitalWrite(yellow,LOW);
   digitalWrite(green,LOW);
 }

void loop()
{
     action3(); //start off doing action3
}

void action3() //do action 3 forever
{
  while(true)
  {  
    digitalWrite(red,HIGH);  
    delay(1000);
    digitalWrite(red,LOW);
  delay(500);
  }
}

void delayplease(int x)  //creates a delay.  The input determines the
{                        // amount of delay
 for(int r=0;r<x*90;r++)
  {for(int t=0;t<1000;t++)
     digitalWrite(0,HIGH);  //I found out that digtil writing takes a
  }                        // long amount of time compared to other 
}                          //commands so this worked well for a delay.




void dothisA()
{
   
  digitalWrite(red,LOW);  //makes sure the LEDs are off
  digitalWrite(yellow,LOW);
  
  for(int i=0;i<5;i++)
    {
      digitalWrite(green,HIGH); //Makes greena nd red leds blink for
      digitalWrite(red,HIGH); //10 seconds
      delayplease(2);
      digitalWrite(green,LOW);
      digitalWrite(red,LOW);
      delayplease(1);
     }
     
   if(deviceB==true) //checks to see if interrupt 2 was 
   dothisB();        //triggered before
      
}


void dothisB()
{
  deviceB=true;           //marks that interrupt 2 has happened
  digitalWrite(red,LOW);   
  interrupts();
  
  digitalWrite(yellow,HIGH);
  delayplease(14);
  digitalWrite(yellow,LOW);
  
  deviceB=false;          // action 2 is done and it goes back
  action3();              // to action 3
        
}
  
