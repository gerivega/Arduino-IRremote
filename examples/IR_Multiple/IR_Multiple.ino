/* This demo has 8 IR receivers conected. the instances are IrReceiver and irrecv1 to irrecv7

*/

//default maximum IR connected is 20 but the can be changed if allowed by memory
//#define IR_MAXCOUNTIR 30
//default MICROS_PER_TICK is 50 micro seconds but have to be change if you have more than 3 IRs suggested value is 100 to 400
#define MICROS_PER_TICK   100

#include <IRremote.h>

static const int RECV_PIN1 = 2;
static const int RECV_PIN2 = 3;
static const int RECV_PIN3 = 4;
static const int RECV_PIN4 = 5;
static const int RECV_PIN5 = 6;
static const int RECV_PIN6 = 7;
static const int RECV_PIN7 = 11;
static const int RECV_PIN8 = 12;

IRrecv irrecv1(RECV_PIN1); // IR pins can be assigned here
IRrecv irrecv2(RECV_PIN2);
IRrecv irrecv3(RECV_PIN3);
IRrecv irrecv4(RECV_PIN4);
IRrecv irrecv5;
IRrecv irrecv6;
IRrecv irrecv7;
bool atLeastOneReceived = true;
unsigned long int lastActivity = 0;

void setup()
{
  Serial.begin(115200);
  // ReceivePin, EnableLEDFeedback, FeedbackLEDPin
  irrecv5.begin(RECV_PIN5, 0, 0);       // pins can also be assigned
  irrecv6.begin(RECV_PIN6, 0, 0);
  irrecv7.begin(RECV_PIN7, 0, 0);
  IrReceiver.begin(RECV_PIN8, 0, 0);    // IrReceiver is created by the library
  Serial.println("*********");
  Serial.println("* START");
  Serial.print("* Monitoring IR from pins ");
  Serial.print(RECV_PIN1);
  Serial.print(" ");
  Serial.print(RECV_PIN2);
  Serial.print(" ");
  Serial.print(RECV_PIN3);
  Serial.print(" ");
  Serial.print(RECV_PIN4);
  Serial.print(" ");
  Serial.print(RECV_PIN5);
  Serial.print(" ");
  Serial.print(RECV_PIN6);
  Serial.print(" ");
  Serial.print(RECV_PIN7);
  Serial.print(" ");
  Serial.print(RECV_PIN8);
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
  if (IrReceiver.decode()) {
    Serial.print("Pin: ");
    Serial.println(IrReceiver.irparams.IRReceivePin);
    if (IrReceiver.decodedIRData.flags & (IRDATA_FLAGS_IS_AUTO_REPEAT | IRDATA_FLAGS_IS_REPEAT)) {
      Serial.println("0Repeat");
    } else {
      Serial.print("0Command: 0x");
      Serial.println(IrReceiver.decodedIRData.command, HEX);
    }
    //IrReceiver.printIRResultRawFormatted(&Serial, false);
    IrReceiver.resume(); // Receive the next value
    atLeastOneReceived = true;
    lastActivity = millis ();
  }
  if (irrecv1.decode()) {
    Serial.print("Pin: ");
    Serial.println(irrecv1.irparams.IRReceivePin);
    if (irrecv1.decodedIRData.flags & (IRDATA_FLAGS_IS_AUTO_REPEAT | IRDATA_FLAGS_IS_REPEAT)) {
      Serial.println("1Repeat");
    } else {
      Serial.print("1Command: 0x");
      Serial.println(irrecv1.decodedIRData.command, HEX);
    }
    //irrecv1.printIRResultRawFormatted(&Serial, false);
    irrecv1.resume(); // Receive the next value
    atLeastOneReceived = true;
    lastActivity = millis ();
  }

  if (irrecv2.decode()) {
    Serial.print("Pin: ");
    Serial.println(irrecv2.irparams.IRReceivePin);
    if (irrecv2.decodedIRData.flags & (IRDATA_FLAGS_IS_AUTO_REPEAT | IRDATA_FLAGS_IS_REPEAT)) {
      Serial.println("2Repeat");
    } else {
      Serial.print("2Command: 0x");
      Serial.println(irrecv2.decodedIRData.command, HEX);
    }
    //irrecv2.printIRResultRawFormatted(&Serial, false);
    irrecv2.resume(); // Receive the next value
    atLeastOneReceived = true;
    lastActivity = millis ();
  }

  if (irrecv3.decode()) {
    Serial.print("Pin: ");
    Serial.println(irrecv3.irparams.IRReceivePin);
    if (irrecv3.decodedIRData.flags & (IRDATA_FLAGS_IS_AUTO_REPEAT | IRDATA_FLAGS_IS_REPEAT)) {
      Serial.println("3Repeat");
    } else {
      Serial.print("3Command: 0x");
      Serial.println(irrecv3.decodedIRData.command, HEX);
    }
    //irrecv3.printIRResultRawFormatted(&Serial, false);
    irrecv3.resume(); // Receive the next value
    atLeastOneReceived = true;
    lastActivity = millis ();
  }

  if (irrecv4.decode()) {
    Serial.print("Pin: ");
    Serial.println(irrecv4.irparams.IRReceivePin);
    if (irrecv4.decodedIRData.flags & (IRDATA_FLAGS_IS_AUTO_REPEAT | IRDATA_FLAGS_IS_REPEAT)) {
      Serial.println("4Repeat");
    } else {
      Serial.print("4Command: 0x");
      Serial.println(irrecv4.decodedIRData.command, HEX);
    }
    //irrecv4.printIRResultRawFormatted(&Serial, false);
    irrecv4.resume(); // Receive the next value
    atLeastOneReceived = true;
    lastActivity = millis ();
  }

  if (irrecv5.decode()) {
    Serial.print("Pin: ");
    Serial.println(irrecv5.irparams.IRReceivePin);
    if (irrecv5.decodedIRData.flags & (IRDATA_FLAGS_IS_AUTO_REPEAT | IRDATA_FLAGS_IS_REPEAT)) {
      Serial.println("5Repeat");
    } else {
      Serial.print("5Command: 0x");
      Serial.println(irrecv5.decodedIRData.command, HEX);
    }
    //irrecv5.printIRResultRawFormatted(&Serial, false);
    irrecv5.resume(); // Receive the next value
    atLeastOneReceived = true;
    lastActivity = millis ();
  }

  if (irrecv6.decode()) {
    Serial.print("Pin: ");
    Serial.println(irrecv6.irparams.IRReceivePin);
    if (irrecv6.decodedIRData.flags & (IRDATA_FLAGS_IS_AUTO_REPEAT | IRDATA_FLAGS_IS_REPEAT)) {
      Serial.println("6Repeat");
    } else {
      Serial.print("6Command: 0x");
      Serial.println(irrecv6.decodedIRData.command, HEX);
    }
    //irrecv6.printIRResultRawFormatted(&Serial, false);
    irrecv6.resume(); // Receive the next value
    atLeastOneReceived = true;
    lastActivity = millis ();
  }

  if (irrecv7.decode()) {
    Serial.print("Pin: ");
    Serial.println(irrecv7.irparams.IRReceivePin);
    if (irrecv7.decodedIRData.flags & (IRDATA_FLAGS_IS_AUTO_REPEAT | IRDATA_FLAGS_IS_REPEAT)) {
      Serial.println("7Repeat");
    } else {
      Serial.print("7Command: 0x");
      Serial.println(irrecv7.decodedIRData.command, HEX);
    }
    //irrecv7.printIRResultRawFormatted(&Serial, false);
    irrecv7.resume(); // Receive the next value
    atLeastOneReceived = true;
    lastActivity = millis ();
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
