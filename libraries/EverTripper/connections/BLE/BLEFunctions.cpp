#include "BLEFunctions.h"

BLESerial<> SerialBLE;

String deviceName = "EVERSON-ESP32-BLE";
bool wasConnected = false;
String receivedValue = "";
String completeMessage = "";
void setupBLE()
{
    SerialBLE.begin(deviceName);
}

void loopBLE()
{ // Verificar status de conexão
    if (SerialBLE.connected())
    {
        if (!wasConnected)
        {
            Serial.println("Dispositivo conectado ao terminal Bluetooth");
            wasConnected = true;
        }
    }
    else
    {
        if (wasConnected)
        {
            Serial.println("Dispositivo desconectado do terminal Bluetooth");
            wasConnected = false;
        }
    }
    if (Serial.available())
    {
        SerialBLE.write(Serial.read());
        SerialBLE.flush();
    }
    while (SerialBLE.available())
    {
        char receivedChar = (char)SerialBLE.read();
        receivedValue += receivedChar; // Verificar se a mensagem está completa (terminada por '\n')
        if (receivedChar == '\n')
        {
            completeMessage = receivedValue;
            Serial.println("Mensagem completa recebida: " + completeMessage);
            receivedValue = ""; // Limpar o buffer temporário
        }
    }
    delay(10); // Reduzir o atraso para tornar o loop mais responsivo
}

String getCompleteMessage()
{
    String message = completeMessage;
    completeMessage = ""; // Limpar a mensagem completa após a leitura
    return message;
}