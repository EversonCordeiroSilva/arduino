#include "central.h"

void setup() {
  Serial.begin(9600);
  setupBLE();
  setupLVGL();
}

void loop() {
  loopBLE();
  loopLVGL();
  // Atualizar o texto do rótulo com o valor recebido do BLE
  String receivedText = getCompleteMessage();
  if (receivedText.length() > 0) {
    updateLabelText(receivedText);
  }
}