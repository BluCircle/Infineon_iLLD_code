#ifndef CONFIG_CAN_HW_CONFIG_CAN_H_
#define CONFIG_CAN_HW_CONFIG_CAN_H_

#include "IfxCan_Can.h"
#include "IfxPort.h"
#include "IfxPort_PinMap.h"



const IfxCan_Can_Pins Hw_CanPin_Config_Tbl[HW_CAN_CH] =
{
  {&IfxCan_TXD00_P20_8_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD00B_P20_7_IN, IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed2},
  {&IfxCan_TXD10_P13_0_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD10D_P13_1_IN, IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed2}
};


#endif /* CONFIG_CAN_HW_CONFIG_CAN_H_ */
