/**
 * @file  remedial.c
 * @brief FreeRTOS multitasking example for ESP32.
 *
 * @note
 *   - Demonstrates creation of multiple tasks.
 *   - Demonstrates task scheduling.
 *   - Demonstrates task priorities.
 *   - Demonstrates independent task periods.
 *   - Uses GPIO toggling for timing visualization.
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

/* GPIO definitions */
#define LED_TASK_FAST      (2U)
#define LED_TASK_MEDIUM    (5U)
#define LED_TASK_SLOW      (4U)

/**
 * @brief Fast periodic task.
 *
 * Executes every 200 ms.
 *
 * @param[in] pvParameters Unused task parameters.
 */
static void TaskFast(void *pvParameters)
{
    (void)pvParameters;

    while (1)
    {
        gpio_set_level(LED_TASK_FAST, 1);

        printf("[TaskFast] Running on core %d\n",
               xPortGetCoreID());

        vTaskDelay(pdMS_TO_TICKS(100));

        gpio_set_level(LED_TASK_FAST, 0);

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

/**
 * @brief Medium periodic task.
 *
 * Executes every 600 ms.
 *
 * @param[in] pvParameters Unused task parameters.
 */
static void TaskMedium(void *pvParameters)
{
    (void)pvParameters;

    while (1)
    {
        gpio_set_level(LED_TASK_MEDIUM,
                       !gpio_get_level(LED_TASK_MEDIUM));

        printf("[TaskMedium] Running on core %d\n",
               xPortGetCoreID());

        /*
         * TODO:
         * Analyze why TaskSlow never executes.
         *
         * Students must determine an appropriate
         * method to allow lower-priority tasks
         * to receive CPU time.
         */
    }
}

/**
 * @brief Slow periodic task.
 *
 * Executes every 1000 ms.
 *
 * @param[in] pvParameters Unused task parameters.
 */
static void TaskSlow(void *pvParameters)
{
    (void)pvParameters;

    while (1)
    {
        gpio_set_level(LED_TASK_SLOW, 1);

        printf("[TaskSlow] Running on core %d\n",
               xPortGetCoreID());

        vTaskDelay(pdMS_TO_TICKS(500));

        gpio_set_level(LED_TASK_SLOW, 0);

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

/**
 * @brief Application entry point.
 */
void app_main(void)
{
    /* Configure GPIO outputs */
    gpio_reset_pin(LED_TASK_FAST);
    gpio_set_direction(
        LED_TASK_FAST,
        GPIO_MODE_OUTPUT);

    gpio_reset_pin(LED_TASK_MEDIUM);
    gpio_set_direction(
        LED_TASK_MEDIUM,
        GPIO_MODE_OUTPUT);

    gpio_reset_pin(LED_TASK_SLOW);
    gpio_set_direction(
        LED_TASK_SLOW,
        GPIO_MODE_OUTPUT);

    /* Create fast task */
    (void)xTaskCreate(
        TaskFast,
        "TaskFast",
        2048,
        NULL,
        2,
        NULL);

    /* Create medium task */
    (void)xTaskCreate(
        TaskMedium,
        "TaskMedium",
        2048,
        NULL,
        3,
        NULL);

    /* Create slow task */
    (void)xTaskCreate(
        TaskSlow,
        "TaskSlow",
        2048,
        NULL,
        1,
        NULL);
}