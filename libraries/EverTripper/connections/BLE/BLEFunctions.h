#ifndef BLEFUNCTIONS_H
#define BLEFUNCTIONS_H

#include <BLESerial.h>

extern BLESerial<> SerialBLE;

void setupBLE();
void loopBLE(); 
String getCompleteMessage();

#endif
