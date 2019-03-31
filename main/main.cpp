/*
        ##########
        ##      ##
        ##      ##    Copyright (C) 2017 Vincenzo Pacella
        ##      ##
##########      ############################################################# shaduzlabs.com #####*/

#include "UI.h"

#include <nvs_flash.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// -------------------------------------------------------------------------------------------------

sl::esp32::UI userInterface;

static void displayThread(void* pvParameters)
{
  while (1)
  {

    while (1)
    {
      vTaskDelay(33 / portTICK_PERIOD_MS);
      userInterface.update();
    }
  }

  esp_restart();
}

// -------------------------------------------------------------------------------------------------

extern "C" void app_main()
{
  using namespace sl;
  using namespace sl::esp32;

  ESP_ERROR_CHECK(nvs_flash_init());

  userInterface.init();

  xTaskCreate(&displayThread, "displayThread", 8192 * 2, nullptr, 5, NULL);
}

// -------------------------------------------------------------------------------------------------
