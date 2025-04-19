#ifndef CONFIG_GPIO_HW_CONFIG_GPIO_H_
#define CONFIG_GPIO_HW_CONFIG_GPIO_H_


#include "IfxPort.h"
#include "IfxPort_PinMap.h"


typedef struct
{
  Ifx_P *port;
  uint8 pinIndex;
  IfxPort_Mode mode;
  IfxPort_State init_state;
}Hw_Gpio_ConfigType;


const Hw_Gpio_ConfigType Hw_Gpio_Config_Tbl[HW_GPIO_CH] =
{
  {&MODULE_P33, 4, IfxPort_Mode_outputPushPullGeneral, IfxPort_State_high},
  {&MODULE_P33, 5, IfxPort_Mode_outputPushPullGeneral, IfxPort_State_high},
  {&MODULE_P33, 6, IfxPort_Mode_outputPushPullGeneral, IfxPort_State_high},
  {&MODULE_P33, 7, IfxPort_Mode_outputPushPullGeneral, IfxPort_State_high},
  {&MODULE_P20, 11, IfxPort_Mode_outputPushPullGeneral, IfxPort_State_high},
  {&MODULE_P20, 12, IfxPort_Mode_outputPushPullGeneral, IfxPort_State_high},
  {&MODULE_P20, 13, IfxPort_Mode_outputPushPullGeneral, IfxPort_State_high},
  {&MODULE_P20, 14, IfxPort_Mode_outputPushPullGeneral, IfxPort_State_high}
};





#endif /* CONFIG_GPIO_HW_CONFIG_GPIO_H_ */
