/*
        ##########
        ##      ##
        ##      ##    Copyright (C) 2017 Vincenzo Pacella
        ##      ##
##########      ############################################################# shaduzlabs.com #####*/

#include "UI.h"

#include <esp_log.h>

#include <sstream>

// -------------------------------------------------------------------------------------------------

#include "fonts/DroidSansMono_Regular_12_1bpp.h"

namespace
{
constexpr gpio_num_t k_outputPinRST = gpio_num_t(CONFIG_SSD1306_RST);
constexpr gpio_num_t k_outputPinDC = gpio_num_t(CONFIG_SSD1306_DC);

constexpr gpio_num_t k_spiPinCS = gpio_num_t(CONFIG_SSD1306_CS);
constexpr gpio_num_t k_spiPinMOSI = gpio_num_t(CONFIG_SSD1306_SDA);
constexpr gpio_num_t k_spiPinSCLK = gpio_num_t(CONFIG_SSD1306_SCL);
} // namespace

// -------------------------------------------------------------------------------------------------

namespace sl
{
namespace esp32
{

// -------------------------------------------------------------------------------------------------
UI::UI()
 : m_lcd(hw::SSD1306::PinConfig{k_spiPinSCLK, k_spiPinCS, k_spiPinMOSI, k_outputPinDC, k_outputPinRST})
{
}

// -------------------------------------------------------------------------------------------------

void UI::init()
{
  m_lcd.black();
}

// -------------------------------------------------------------------------------------------------

void UI::update()
{
  static unsigned currentFrame = 0;
  static sl::rastr::Color colorCircle{0xff,0xff,0xff};
  static sl::rastr::Color colorText{sl::rastr::BlendMode::invert};
  static auto column = 64;
  static auto row = 32;

  if(colorCircle.getValue() > 0)
    m_lcd.black();
  else
    m_lcd.white();

  m_lcd.circleFilled(column, row, currentFrame * 8, colorCircle, colorCircle);
  m_lcd.putText(24, 38, "Hello World!", colorText, k_font_DroidSansMono_Regular_12_1bpp);

  if(++currentFrame >= 16)
  {
    colorCircle.invert();
    currentFrame = 0;
    column = esp_random() % 128;
    row = esp_random() % 64;
  }

  m_lcd.display();
}

// -------------------------------------------------------------------------------------------------

} // namespace esp32
} // namespace sl
