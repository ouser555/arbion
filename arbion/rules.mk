# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
UNICODE_ENABLE = yes         # Unicode


RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.

JOYSTICK_ENABLE = yes
#JOYSTICK_DRIVER = digital //default is analog
ENCODER_ENABLE = yes
#ENCODER_MAP_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

POINTING_DEVICE_ENABLE = yes
#POINTING_DEVICE_DRIVER = analog_joystick
POINTING_DEVICE_DRIVER = custom

SRC += drivers/sensors/analog_joystick.c


