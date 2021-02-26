#include "ecucan.hh"

CAN_message_t ecu_message;

void printRawEcu(CAN_message_t ecu_message) {
    Serial.print(ecu_message.id); Serial.print(" ");
    for (int i = 0; i < 6; i++) {
            Serial.print(ecu_message.buf[i], HEX); Serial.print(" ");
        }
    Serial.println(" ");
}

void genericECUWrite(int commandId, uint16_t ecuAddress, FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16>* can) {
    ecu_message.flags.extended = true;
    ecu_message.id = 0x09000000 | (commandId << 16) | ecuAddress;
    can->write(ecu_message);
}

void ThrottleCmd(uint8_t throttlePosition, uint16_t ecuAddress, FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16>* can) {
    ecu_message.buf[0] = throttlePosition;
    ecu_message.buf[1] = 0;
    ecu_message.len = 2;
    genericECUWrite(0x06, ecuAddress, can);
}