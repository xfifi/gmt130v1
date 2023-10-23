#include "gmt130v1.h"

#include "esphome/components/display/display_color_utils.h"
#include "esphome/core/log.h"

namespace esphome {
namespace gmt130v1 {

static const char *const TAG = "Gmt130V1";

void Gmt130V1::setup() {
  this->tft_ = new TFT_eSPI();
  this->tft_->init();
  this->tft_->fillScreen(TFT_BLACK);

  this->spr_ = new TFT_eSprite(this->tft_);
  if (this->spr_->createSprite(get_width_internal(), get_height_internal()) == nullptr) {
    this->mark_failed();
  }
}

void Gmt130V1::dump_config() {
  LOG_DISPLAY("", "GMT130-V1.0 IPS 240*240 (ST7789)", this);
  LOG_UPDATE_INTERVAL(this);
}

void Gmt130V1::fill(Color color) { this->spr_->fillScreen(display::ColorUtil::color_to_565(color)); }

void Gmt130V1::draw_absolute_pixel_internal(int x, int y, Color color) {
  this->spr_->drawPixel(x, y, display::ColorUtil::color_to_565(color));
}

int Gmt130V1::get_width_internal() {
  if (this->tft_) {
    return this->tft_->getViewportWidth();
  } else {
    return this->width_;
  }
}

int Gmt130V1::get_height_internal() {
  if (this->tft_) {
    return this->tft_->getViewportHeight();
  } else {
    return this->height_;
  }
}

void Gmt130V1::update() {
  this->do_update_();
  this->spr_->pushSprite(0, 0);
}

void Gmt130V1::set_dimensions(uint16_t width, uint16_t height) {
  this->width_ = width;
  this->height_ = height;
}

}  // namespace gmt130v1
}  // namespace esphome
