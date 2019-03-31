/*
        ##########
        ##      ##
        ##      ##    Copyright (C) 2017 Vincenzo Pacella
        ##      ##
##########      ############################################################# shaduzlabs.com #####*/

#pragma once

#include <SSD1306.h>

#include <atomic>

// -------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------

namespace sl
{
namespace esp32
{

class UI
{
public:

  UI();

  void init();
  void update();

private:

  hw::SSD1306 m_lcd;
};

// -------------------------------------------------------------------------------------------------

} // namespace esp32
} // namespace sl
