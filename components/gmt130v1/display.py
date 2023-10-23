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
