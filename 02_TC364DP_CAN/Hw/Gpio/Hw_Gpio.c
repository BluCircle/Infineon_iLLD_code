
#include "Hw_Gpio.h"
#include "Hw_Config_Gpio.h"

void Hw_Gpio_Init(void)
{
    for(int i = 0; i < HW_GPIO_CH; i++)
    {
        IfxPort_setPinMode(Hw_Gpio_Config_Tbl[i].port, Hw_Gpio_Config_Tbl[i].pinIndex, Hw_Gpio_Config_Tbl[i].mode);
        IfxPort_setPinState(Hw_Gpio_Config_Tbl[i].port, Hw_Gpio_Config_Tbl[i].pinIndex, Hw_Gpio_Config_Tbl[i].init_state);
    }
}


uint8 Hw_Gpio_Read(uint8 ch)
{
    uint8 ret;
    ret = IfxPort_getPinState(Hw_Gpio_Config_Tbl[ch].port, Hw_Gpio_Config_Tbl[ch].pinIndex);
    return ret;
}


void Hw_Gpio_Write(uint8 ch, uint8 cmd)
{
    if(cmd == GPIO_HIGH)
        IfxPort_setPinState(Hw_Gpio_Config_Tbl[ch].port, Hw_Gpio_Config_Tbl[ch].pinIndex, IfxPort_State_high);
    else if(cmd == GPIO_LOW)
        IfxPort_setPinState(Hw_Gpio_Config_Tbl[ch].port, Hw_Gpio_Config_Tbl[ch].pinIndex, IfxPort_State_low);
}

void Hw_Gpio_Toggle(uint8 ch)
{
    IfxPort_togglePin(Hw_Gpio_Config_Tbl[ch].port, Hw_Gpio_Config_Tbl[ch].pinIndex);
}
