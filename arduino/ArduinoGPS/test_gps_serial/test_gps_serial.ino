const unsigned int MAX_MESSAGE_LENGTH = 250;

void setup() {
 Serial.begin(9600);
 Serial1.begin(9600);
}

void loop() {

 //Check to see if anything is available in the serial receive buffer
 while (Serial1.available() > 0)
 {
   //Create a place to hold the incoming message
   static char message[MAX_MESSAGE_LENGTH];
   static unsigned int message_pos = 0;

   //Read the next available byte in the serial receive buffer
   char inByte = Serial1.read();

   Serial.println(message);

   //Message coming in (check not terminating character) and guard for over message size
   if ( inByte != '\n' && (message_pos < MAX_MESSAGE_LENGTH - 1) )
   {
     //Add the incoming byte to our message
     message[message_pos] = inByte;
     message_pos++;
   }
   //Full message received...
   else
   {
     //Add null character to string
     message[message_pos] = '\0';

     //Print the message (or do other things)
     Serial.println(message);

     //Reset for the next message
     message_pos = 0;
   }
 }
}
