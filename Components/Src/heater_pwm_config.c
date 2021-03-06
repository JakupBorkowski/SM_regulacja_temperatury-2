/**
  ******************************************************************************
  * @file    heater_pwm_config.c
  * @author  AW
  * @version V1.0
  * @date    15-Nov-2020
  * @brief   Simple PWM-controled heater driver library configuration file
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include "heater_pwm.h"
#include "heater_pwm_config.h"
#include "main.h"
#include "tim.h"

/* Typedef -------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

/* Macro ---------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/
HEATER_PWM_HandleTypeDef hheaterpwm1 = {
  .Timer = &htim3, .Channel = TIM_CHANNEL_4
};

/* Private function prototypes -----------------------------------------------*/

/* Private function ----------------------------------------------------------*/

/* Public function -----------------------------------------------------------*/
