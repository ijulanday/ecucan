#pragma once

#include <Arduino.h>
#include <FlexCAN_T4.h>

extern CAN_message_t ecu_message;

void printRawEcu(CAN_message_t ecu_message);
void genericECUWrite(int commandId, uint16_t ecuAddress, FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16>* can);
void ThrottleCmd(uint8_t throttlePosition, uint16_t ecuAddress, FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16>* can);