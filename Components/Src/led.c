/**
  ******************************************************************************
  * @file    led.c
  * @author  AW
  * @version V1.0
  * @date    3-Oct-2020
  * @brief   Simple LED driver library.
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include "led.h"

/* Typedef -------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

/* Macro ---------------------------------------------------------------------*/
//! Set GPIO Pin to high
#define __led_seth(hled)       (hled)->Port->BSRR |= ((hled)->Pin)

//! Set GPIO Pin to low
#define __led_setl(hled)       (hled)->Port->BSRR |= ((hled)->Pin << 0x10)

//! Turn LED on
#define __led_on(hled)         ((hled)->Logic ? (__led_seth(hled)) : (__led_setl(hled)))

//! Turn LED off
#define __led_off(hled)        ((hled)->Logic ? (__led_setl(hled)) : (__led_seth(hled)))

//! Read LED state
#define __led_read(hled)       ((hled)->Port->ODR & (hled)->Pin)

//! Set LED to selected state (on/off)
#define __led_setto(hled, st)  (st ? __led_on(hled) : __led_off(hled))

/* Private variables ---------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private function ----------------------------------------------------------*/

/* Public function -----------------------------------------------------------*/


/**
 * @brief Turn LED on
 * @param hled LED handle
 * @retval None
 */
void LED_On(LED_HandleTypeDef* hled)
{
	__led_on(hled);
}

/**
 * @brief Turn LED off
 * @param hled LED handle
 * @retval None
 */
void LED_Off(LED_HandleTypeDef* hled)
{
	__led_off(hled);
}

/**
 * @brief Toggle LED state
 * @param hled LED handle
 * @retval None
 */
void LED_Toggle(LED_HandleTypeDef* hled)
{
	__led_setto(hled, !__led_read(hled));
}

/**
 * @brief Set LED to selected state (SET/RESET)
 * @param hled LED handle
 * @retval None
 */
void LED_SetTo(LED_HandleTypeDef* hled, unsigned char state)
{
	__led_setto(hled, state);
}

#undef __led_on
#undef __led_off
#undef __led_read
#undef __led_setto
