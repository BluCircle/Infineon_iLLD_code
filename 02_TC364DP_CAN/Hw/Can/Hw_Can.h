#ifndef HW_CAN_HW_CAN_H_
#define HW_CAN_HW_CAN_H_

#include "TypesDef.h"
#include <stdio.h>
#include <string.h>
#include "Ifx_Types.h"
#include "IfxCan_Can.h"
#include "IfxCan.h"
#include "IfxCpu_Irq.h"
//#include "IfxPort.h"



typedef struct
{
    IfxCan_Can_Config canConfig;
    IfxCan_Can canModule;
    IfxCan_Can_Node canNode;
    IfxCan_Can_NodeConfig canNodeConfig;
    IfxCan_Filter canFilter;
    IfxCan_Message txMsg;
    IfxCan_Message rxMsg;
    uint8 txData[MAXIMUM_CAN_FD_DATA_PAYLOAD];
    uint8 rxData[MAXIMUM_CAN_FD_DATA_PAYLOAD];
} mcmcanType;

void Hw_Can_Init(void);
void Hw_Can_Transmit_example(void);


#endif /* HW_CAN_HW_CAN_H_ */
