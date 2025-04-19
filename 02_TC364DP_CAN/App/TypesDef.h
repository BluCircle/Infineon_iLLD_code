#ifndef APP_TYPESDEF_H_
#define APP_TYPESDEF_H_

#include "Ifx_Types.h"


/* Gpio Settings */
#define HW_GPIO_CH     8
#define GPIO_CH1       0
#define GPIO_CH2       1
#define GPIO_CH3       2
#define GPIO_CH4       3
#define GPIO_CH5       4
#define GPIO_CH6       5
#define GPIO_CH7       6
#define GPIO_CH8       7

#define GPIO_LOW       0
#define GPIO_HIGH      1


/* CAN Settings */
#define HW_CAN_CH      2
#define CAN_CH1        0
#define CAN_CH2        1
#define MY_CAN_ID      0x557
#define ACCEPT_CAN_ID  0x558


#define TX_DATA_INIT_SHIFT_OFFSET   6                           /* Define the shift offset value for the TX data     */
#define NUMBER_OF_CAN_FD_CASES      4                           /* Define the number of CAN FD use cases             */
#define MAXIMUM_CAN_FD_DATA_PAYLOAD 64

#define CAN_DEFAULT_BAUDRATE      500000
#define CAN_DEFAULT_DATA_BAUDRATE 2000000

#define ISR_PRIORITY_CAN_BUSOFF   1
#define ISR_PRIORITY_CAN_TX       3
#define ISR_PRIORITY_CAN_RX       4






#endif /* APP_TYPESDEF_H_ */
