#include "Hw_Can.h"
#include "Hw_Config_Can.h"
#include "Hw_Gpio.h"
mcmcanType  g_mcmcan;
uint8       g_isrRxCount = 0;
const uint8  g_dlcLookUpTable[]={0,1,2,3,4,5,6,7,8,12,16,20,24,32,48,64};

//IFX_INTERRUPT(canIsrBusoffHandler, 0, ISR_PRIORITY_CAN_BUSOFF);
IFX_INTERRUPT(canIsrTxHandler, 0, ISR_PRIORITY_CAN_TX);
IFX_INTERRUPT(canIsrRxHandler, 0, ISR_PRIORITY_CAN_RX);


void canIsrTxHandler()
{

}


void canIsrRxHandler()
{
   //IfxCan_Node_clearInterruptFlag(g_mcmcan.canNode.node, IfxCan_Interrupt_messageStoredToDedicatedRxBuffer);

    IfxCan_Node_clearInterruptFlag(g_mcmcan.canNode.node, IfxCan_Interrupt_rxFifo0NewMessage);
   /* Received message content should be updated with the data stored in the RX FIFO 0 */
    g_mcmcan.rxMsg.readFromRxFifo0 = TRUE;


    IfxCan_Can_readMessage(&g_mcmcan.canNode, &g_mcmcan.rxMsg, (uint32*)&g_mcmcan.rxData[0]);
    Hw_Gpio_Toggle(g_mcmcan.rxData[0]);
    g_isrRxCount++;
}


void Hw_Can_Init(void)
{
    IfxCan_Can_initModuleConfig(&g_mcmcan.canConfig, &MODULE_CAN0);
    IfxCan_Can_initModule(&g_mcmcan.canModule, &g_mcmcan.canConfig);

//    IfxCan_enableModule(&MODULE_CAN0);
    IfxCan_Can_initNodeConfig(&g_mcmcan.canNodeConfig, &g_mcmcan.canModule);
    g_mcmcan.canNodeConfig.nodeId = IfxCan_NodeId_0;
    g_mcmcan.canNodeConfig.frame.type = IfxCan_FrameType_transmitAndReceive;
    g_mcmcan.canNodeConfig.frame.mode = IfxCan_FrameMode_fdLongAndFast;
    g_mcmcan.canNodeConfig.baudRate.baudrate = CAN_DEFAULT_BAUDRATE;
    g_mcmcan.canNodeConfig.fastBaudRate.baudrate = CAN_DEFAULT_DATA_BAUDRATE;

    g_mcmcan.canNodeConfig.txConfig.txBufferDataFieldSize = IfxCan_DataFieldSize_64;
    g_mcmcan.canNodeConfig.rxConfig.rxBufferDataFieldSize = IfxCan_DataFieldSize_64;

    IfxCan_Can_Pins canPins;
    canPins.rxPin  = &IfxCan_RXD00B_P20_7_IN;
    canPins.rxPinMode = IfxPort_InputMode_pullUp;
    canPins.txPin = &IfxCan_TXD00_P20_8_OUT;
    canPins.txPinMode = IfxPort_OutputMode_pushPull;
    canPins.padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed2;
    g_mcmcan.canNodeConfig.pins = &canPins;



    g_mcmcan.canNodeConfig.rxConfig.rxMode = IfxCan_RxMode_fifo0;
    g_mcmcan.canNodeConfig.rxConfig.rxFifo0DataFieldSize = IfxCan_DataFieldSize_64;
    g_mcmcan.canNodeConfig.rxConfig.rxFifo0Size = NUMBER_OF_CAN_FD_CASES;

    g_mcmcan.canNodeConfig.interruptConfig.rxFifo0NewMessageEnabled = TRUE;
    g_mcmcan.canNodeConfig.interruptConfig.rxf0n.priority = ISR_PRIORITY_CAN_RX;
    g_mcmcan.canNodeConfig.interruptConfig.rxf0n.interruptLine = IfxCan_InterruptLine_1;
    g_mcmcan.canNodeConfig.interruptConfig.rxf0n.typeOfService = IfxSrc_Tos_cpu0;

//    g_mcmcan.canNodeConfig.interruptConfig.messageStoredToDedicatedRxBufferEnabled = TRUE;
//    g_mcmcan.canNodeConfig.interruptConfig.reint.priority = ISR_PRIORITY_CAN_RX;
//    g_mcmcan.canNodeConfig.interruptConfig.reint.interruptLine = IfxCan_InterruptLine_1;
//    g_mcmcan.canNodeConfig.interruptConfig.reint.typeOfService = IfxSrc_Tos_cpu0;

    IfxCan_Can_initNode(&g_mcmcan.canNode, &g_mcmcan.canNodeConfig);

    g_mcmcan.canFilter.number = 0;
    g_mcmcan.canFilter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxFifo0;
    g_mcmcan.canFilter.type = IfxCan_FilterType_classic;
    g_mcmcan.canFilter.id1 = ACCEPT_CAN_ID;
    g_mcmcan.canFilter.id2 = 0x7FF;
    g_mcmcan.canFilter.rxBufferOffset = DO_NOT_CARE_BUFFER_INDEX ;
    IfxCan_Can_setStandardFilter(&g_mcmcan.canNode, &g_mcmcan.canFilter);
}

void Hw_Can_Transmit_example(void)
{

}
