/* This demo has 8 IR receivers conected. the instances are IrReceiver and irrecvArray[0] to irrecvArray[7]
  allReceiverArray points to all receivers so the program can loop through this array
*/

//default maximum IR connected is 20 but the can be changed if allowed by memory
//#define IR_MAXCOUNTIR 30
//default MICROS_PER_TICK is 50 micro seconds but have to be change if you have more than 3 IRs suggested value is 100 to 400
#define MICROS_PER_TICK   100

#include <IRremote.h>
static const int irCount = 8;
static const int RECV_PINS[] = {2, 3, 4, 5, 6, 7, 11, 12};

IRrecv irrecvArray[irCount - 1];
IRrecv* allReceiverArray[irCount];
bool atLeastOneReceived = true;
unsigned long int lastActivity = 0;

void setup()
{
  Serial.begin(115200);
  for (int i = 0; i < irCount - 1; i++) {
    // ReceivePin, EnableLEDFeedback, FeedbackLEDPin
    irrecvArray[i].begin(RECV_PINS[i], 0, 0);
    allReceiverArray[i] = &irrecvArray[i];
  }
  IrReceiver.begin(RECV_PINS[irCount - 1], 0, 0);
  allReceiverArray[irCount - 1] = &IrReceiver;

  Serial.println("*********");
  Serial.println("* START");
  Serial.print("* Monitoring IR from pins ");
  for (int i = 0; i < irCount; i++) {
    Serial.print(RECV_PINS[i]);
    Serial.print(" ");
  }
  Serial.println(" ");
  Serial.print("* Verify IR from pins     ");
  int count_of_irparams = lst_of_irparams.GetCount();
  for (int i = 0; i < count_of_irparams; ++i) {
    irparams_struct *irparams = lst_of_irparams.GetItem(i);
    Serial.print(irparams->IRReceivePin);
    Serial.print(" ");
  }
  Serial.println(" ");
  Serial.println("*******");
}

void loop() {
  for (int i = 0; i < irCount; i++) {
    if (allReceiverArray[i]->decode()) {
      Serial.print("Pin: ");
      Serial.println(allReceiverArray[i]->irparams.IRReceivePin);
      Serial.print(i);

      if (allReceiverArray[i]->decodedIRData.flags & (IRDATA_FLAGS_IS_AUTO_REPEAT | IRDATA_FLAGS_IS_REPEAT)) {
        Serial.println("Repeat");
      } else {
        Serial.print("Command: 0x");
        Serial.println(allReceiverArray[i]->decodedIRData.command, HEX);
      }
      //allReceiverArray[i]->printIRResultRawFormatted(&Serial, false);
      allReceiverArray[i]->resume(); // Receive the next value
      atLeastOneReceived = true;
      lastActivity = millis ();
    }
  }

  unsigned long int elapsedTime;
  elapsedTime = millis() - lastActivity;
  if ((atLeastOneReceived)  && (elapsedTime  > 500)) {
    Serial.println("Waiting for IR Signal...");
    //Serial.println(elapsedTime );
    Serial.println("");
    Serial.println("");
    atLeastOneReceived = false;
  }
  //delay(500);
}
