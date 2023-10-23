import esphome.codegen as cg
import esphome.config_validation as cv

from esphome import pins
from esphome.components import display
from esphome.const import (
    CONF_HEIGHT,
    CONF_ID,
    CONF_LAMBDA,
    CONF_WIDTH,
    CONF_CS_PIN,
    CONF_DC_PIN,
    CONF_RESET_PIN,
    CONF_NUMBER,
)
from esphome.const import __version__ as ESPHOME_VERSION
from . import gmt130v1_ns

AUTO_LOAD = ["psram"]
DEPENDENCIES = ["esp32"]

CONF_BACKLIGHT = "backlight"
CONF_LOAD_FONTS = "load_fonts"
CONF_LOAD_SMOOTH_FONTS = "load_smooth_fonts"
CONF_ENABLE_LIBRARY_WARNINGS = "enable_library_warnings"

GMT130V1 = gmt130v1_ns.class_(
    "Gmt130V1", cg.PollingComponent, display.DisplayBuffer
)
