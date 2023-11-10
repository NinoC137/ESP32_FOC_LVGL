# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=320,h=480)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(320*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 320
disp_drv.ver_res = 480
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)



# create MAIN
MAIN = lv.obj()
MAIN.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_main_main_main_default
style_main_main_main_default = lv.style_t()
style_main_main_main_default.init()
style_main_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_main_main_main_default.set_bg_opa(0)

# add style for MAIN
MAIN.add_style(style_main_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create MAIN_cont_1
MAIN_cont_1 = lv.obj(MAIN)
MAIN_cont_1.set_pos(int(0),int(0))
MAIN_cont_1.set_size(320,480)
MAIN_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)

# create MAIN_btn_1
MAIN_btn_1 = lv.btn(MAIN_cont_1)
MAIN_btn_1.set_pos(int(29),int(166))
MAIN_btn_1.set_size(253,171)
MAIN_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
MAIN_btn_1_label = lv.label(MAIN_btn_1)
MAIN_btn_1_label.set_text("signin")
MAIN_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
MAIN_btn_1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_main_btn_1_main_main_default
style_main_btn_1_main_main_default = lv.style_t()
style_main_btn_1_main_main_default.init()
style_main_btn_1_main_main_default.set_radius(0)
style_main_btn_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_main_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_main_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_main_btn_1_main_main_default.set_bg_opa(0)
style_main_btn_1_main_main_default.set_border_color(lv.color_make(0xdc,0xdc,0xdc))
style_main_btn_1_main_main_default.set_border_width(0)
style_main_btn_1_main_main_default.set_border_opa(95)
style_main_btn_1_main_main_default.set_text_color(lv.color_make(0xe6,0xe6,0xe6))
try:
    style_main_btn_1_main_main_default.set_text_font(lv.font_montserratMedium_24)
except AttributeError:
    try:
        style_main_btn_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_main_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_main_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for MAIN_btn_1
MAIN_btn_1.add_style(style_main_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create MAIN_label_1
MAIN_label_1 = lv.label(MAIN_cont_1)
MAIN_label_1.set_pos(int(69),int(164))
MAIN_label_1.set_size(181,51)
MAIN_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
MAIN_label_1.set_text("DengsFoc")
MAIN_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_main_label_1_main_main_default
style_main_label_1_main_main_default = lv.style_t()
style_main_label_1_main_main_default.init()
style_main_label_1_main_main_default.set_radius(0)
style_main_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_main_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_main_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_main_label_1_main_main_default.set_bg_opa(0)
style_main_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_main_label_1_main_main_default.set_text_font(lv.font_montserratMedium_26)
except AttributeError:
    try:
        style_main_label_1_main_main_default.set_text_font(lv.font_montserrat_26)
    except AttributeError:
        style_main_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_main_label_1_main_main_default.set_text_letter_space(2)
style_main_label_1_main_main_default.set_text_line_space(0)
style_main_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_main_label_1_main_main_default.set_pad_left(0)
style_main_label_1_main_main_default.set_pad_right(0)
style_main_label_1_main_main_default.set_pad_top(8)
style_main_label_1_main_main_default.set_pad_bottom(0)

# add style for MAIN_label_1
MAIN_label_1.add_style(style_main_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_main_cont_1_main_main_default
style_main_cont_1_main_main_default = lv.style_t()
style_main_cont_1_main_main_default.init()
style_main_cont_1_main_main_default.set_radius(0)
style_main_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_main_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_main_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_main_cont_1_main_main_default.set_bg_opa(255)
style_main_cont_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_main_cont_1_main_main_default.set_border_width(2)
style_main_cont_1_main_main_default.set_border_opa(255)
style_main_cont_1_main_main_default.set_pad_left(0)
style_main_cont_1_main_main_default.set_pad_right(0)
style_main_cont_1_main_main_default.set_pad_top(0)
style_main_cont_1_main_main_default.set_pad_bottom(0)

# add style for MAIN_cont_1
MAIN_cont_1.add_style(style_main_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create menu
menu = lv.obj()
menu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_menu_main_main_default
style_menu_main_main_default = lv.style_t()
style_menu_main_main_default.init()
style_menu_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_menu_main_main_default.set_bg_opa(0)

# add style for menu
menu.add_style(style_menu_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create menu_cont_1
menu_cont_1 = lv.obj(menu)
menu_cont_1.set_pos(int(0),int(0))
menu_cont_1.set_size(320,480)
menu_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)

# create menu_btn_5
menu_btn_5 = lv.btn(menu_cont_1)
menu_btn_5.set_pos(int(30),int(140))
menu_btn_5.set_size(100,100)
menu_btn_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
menu_btn_5_label = lv.label(menu_btn_5)
menu_btn_5_label.set_text("TYPE")
menu_btn_5.set_style_pad_all(0, lv.STATE.DEFAULT)
menu_btn_5_label.align(lv.ALIGN.CENTER,0,0)
# create style style_menu_btn_5_main_main_default
style_menu_btn_5_main_main_default = lv.style_t()
style_menu_btn_5_main_main_default.init()
style_menu_btn_5_main_main_default.set_radius(50)
style_menu_btn_5_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_menu_btn_5_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe6,0xe6))
style_menu_btn_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_menu_btn_5_main_main_default.set_bg_opa(255)
style_menu_btn_5_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_menu_btn_5_main_main_default.set_border_width(0)
style_menu_btn_5_main_main_default.set_border_opa(255)
style_menu_btn_5_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_menu_btn_5_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_menu_btn_5_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_menu_btn_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_menu_btn_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for menu_btn_5
menu_btn_5.add_style(style_menu_btn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create menu_btn_6
menu_btn_6 = lv.btn(menu_cont_1)
menu_btn_6.set_pos(int(30),int(300))
menu_btn_6.set_size(100,100)
menu_btn_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
menu_btn_6_label = lv.label(menu_btn_6)
menu_btn_6_label.set_text("OTHERS")
menu_btn_6.set_style_pad_all(0, lv.STATE.DEFAULT)
menu_btn_6_label.align(lv.ALIGN.CENTER,0,0)
# create style style_menu_btn_6_main_main_default
style_menu_btn_6_main_main_default = lv.style_t()
style_menu_btn_6_main_main_default.init()
style_menu_btn_6_main_main_default.set_radius(50)
style_menu_btn_6_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_menu_btn_6_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe6,0xe6))
style_menu_btn_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_menu_btn_6_main_main_default.set_bg_opa(255)
style_menu_btn_6_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_menu_btn_6_main_main_default.set_border_width(0)
style_menu_btn_6_main_main_default.set_border_opa(255)
style_menu_btn_6_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_menu_btn_6_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_menu_btn_6_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_menu_btn_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_menu_btn_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for menu_btn_6
menu_btn_6.add_style(style_menu_btn_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create menu_btn_7
menu_btn_7 = lv.btn(menu_cont_1)
menu_btn_7.set_pos(int(190),int(300))
menu_btn_7.set_size(100,100)
menu_btn_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
menu_btn_7_label = lv.label(menu_btn_7)
menu_btn_7_label.set_text("WIFI")
menu_btn_7.set_style_pad_all(0, lv.STATE.DEFAULT)
menu_btn_7_label.align(lv.ALIGN.CENTER,0,0)
# create style style_menu_btn_7_main_main_default
style_menu_btn_7_main_main_default = lv.style_t()
style_menu_btn_7_main_main_default.init()
style_menu_btn_7_main_main_default.set_radius(50)
style_menu_btn_7_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_menu_btn_7_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe6,0xe6))
style_menu_btn_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_menu_btn_7_main_main_default.set_bg_opa(255)
style_menu_btn_7_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_menu_btn_7_main_main_default.set_border_width(0)
style_menu_btn_7_main_main_default.set_border_opa(255)
style_menu_btn_7_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_menu_btn_7_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_menu_btn_7_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_menu_btn_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_menu_btn_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for menu_btn_7
menu_btn_7.add_style(style_menu_btn_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create menu_btn_8
menu_btn_8 = lv.btn(menu_cont_1)
menu_btn_8.set_pos(int(190),int(140))
menu_btn_8.set_size(100,100)
menu_btn_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
menu_btn_8_label = lv.label(menu_btn_8)
menu_btn_8_label.set_text("SET")
menu_btn_8.set_style_pad_all(0, lv.STATE.DEFAULT)
menu_btn_8_label.align(lv.ALIGN.CENTER,0,0)
# create style style_menu_btn_8_main_main_default
style_menu_btn_8_main_main_default = lv.style_t()
style_menu_btn_8_main_main_default.init()
style_menu_btn_8_main_main_default.set_radius(50)
style_menu_btn_8_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_menu_btn_8_main_main_default.set_bg_grad_color(lv.color_make(0x97,0xe7,0xff))
style_menu_btn_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_menu_btn_8_main_main_default.set_bg_opa(255)
style_menu_btn_8_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_menu_btn_8_main_main_default.set_border_width(0)
style_menu_btn_8_main_main_default.set_border_opa(255)
style_menu_btn_8_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_menu_btn_8_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_menu_btn_8_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_menu_btn_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_menu_btn_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for menu_btn_8
menu_btn_8.add_style(style_menu_btn_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create menu_btn_9
menu_btn_9 = lv.btn(menu_cont_1)
menu_btn_9.set_pos(int(259),int(423))
menu_btn_9.set_size(56,51)
menu_btn_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
menu_btn_9_label = lv.label(menu_btn_9)
menu_btn_9_label.set_text("DEL")
menu_btn_9.set_style_pad_all(0, lv.STATE.DEFAULT)
menu_btn_9_label.align(lv.ALIGN.CENTER,0,0)
# create style style_menu_btn_9_main_main_default
style_menu_btn_9_main_main_default = lv.style_t()
style_menu_btn_9_main_main_default.init()
style_menu_btn_9_main_main_default.set_radius(5)
style_menu_btn_9_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_menu_btn_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_menu_btn_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_menu_btn_9_main_main_default.set_bg_opa(255)
style_menu_btn_9_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_menu_btn_9_main_main_default.set_border_width(0)
style_menu_btn_9_main_main_default.set_border_opa(255)
style_menu_btn_9_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_menu_btn_9_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_menu_btn_9_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_menu_btn_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_menu_btn_9_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for menu_btn_9
menu_btn_9.add_style(style_menu_btn_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create menu_label_1
menu_label_1 = lv.label(menu_cont_1)
menu_label_1.set_pos(int(2),int(5))
menu_label_1.set_size(310,35)
menu_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
menu_label_1.set_text("Label")
menu_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_menu_label_1_main_main_default
style_menu_label_1_main_main_default = lv.style_t()
style_menu_label_1_main_main_default.init()
style_menu_label_1_main_main_default.set_radius(0)
style_menu_label_1_main_main_default.set_bg_color(lv.color_make(0x14,0x18,0x1c))
style_menu_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_menu_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_menu_label_1_main_main_default.set_bg_opa(255)
style_menu_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_menu_label_1_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_menu_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_menu_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_menu_label_1_main_main_default.set_text_letter_space(2)
style_menu_label_1_main_main_default.set_text_line_space(0)
style_menu_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_menu_label_1_main_main_default.set_pad_left(0)
style_menu_label_1_main_main_default.set_pad_right(0)
style_menu_label_1_main_main_default.set_pad_top(8)
style_menu_label_1_main_main_default.set_pad_bottom(0)

# add style for menu_label_1
menu_label_1.add_style(style_menu_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_menu_cont_1_main_main_default
style_menu_cont_1_main_main_default = lv.style_t()
style_menu_cont_1_main_main_default.init()
style_menu_cont_1_main_main_default.set_radius(0)
style_menu_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_menu_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_menu_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_menu_cont_1_main_main_default.set_bg_opa(255)
style_menu_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_menu_cont_1_main_main_default.set_border_width(2)
style_menu_cont_1_main_main_default.set_border_opa(0)
style_menu_cont_1_main_main_default.set_pad_left(0)
style_menu_cont_1_main_main_default.set_pad_right(0)
style_menu_cont_1_main_main_default.set_pad_top(0)
style_menu_cont_1_main_main_default.set_pad_bottom(0)

# add style for menu_cont_1
menu_cont_1.add_style(style_menu_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE
TYPE = lv.obj()
TYPE.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_type_main_main_default
style_type_main_main_default = lv.style_t()
style_type_main_main_default.init()
style_type_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_type_main_main_default.set_bg_opa(0)

# add style for TYPE
TYPE.add_style(style_type_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_cont_1
TYPE_cont_1 = lv.obj(TYPE)
TYPE_cont_1.set_pos(int(0),int(0))
TYPE_cont_1.set_size(320,480)
TYPE_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)

# create TYPE_RM1
TYPE_RM1 = lv.btn(TYPE_cont_1)
TYPE_RM1.set_pos(int(68),int(107))
TYPE_RM1.set_size(100,100)
TYPE_RM1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_RM1_label = lv.label(TYPE_RM1)
TYPE_RM1_label.set_text("M1")
TYPE_RM1.set_style_pad_all(0, lv.STATE.DEFAULT)
TYPE_RM1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_type_rm1_main_main_default
style_type_rm1_main_main_default = lv.style_t()
style_type_rm1_main_main_default.init()
style_type_rm1_main_main_default.set_radius(50)
style_type_rm1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_rm1_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_rm1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_rm1_main_main_default.set_bg_opa(255)
style_type_rm1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_rm1_main_main_default.set_border_width(0)
style_type_rm1_main_main_default.set_border_opa(255)
style_type_rm1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_type_rm1_main_main_default.set_text_font(lv.font_montserratMedium_36)
except AttributeError:
    try:
        style_type_rm1_main_main_default.set_text_font(lv.font_montserrat_36)
    except AttributeError:
        style_type_rm1_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_rm1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for TYPE_RM1
TYPE_RM1.add_style(style_type_rm1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_RDRV
TYPE_RDRV = lv.btn(TYPE_cont_1)
TYPE_RDRV.set_pos(int(157),int(300))
TYPE_RDRV.set_size(100,100)
TYPE_RDRV.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_RDRV_label = lv.label(TYPE_RDRV)
TYPE_RDRV_label.set_text("DRV")
TYPE_RDRV.set_style_pad_all(0, lv.STATE.DEFAULT)
TYPE_RDRV_label.align(lv.ALIGN.CENTER,0,0)
# create style style_type_rdrv_main_main_default
style_type_rdrv_main_main_default = lv.style_t()
style_type_rdrv_main_main_default.init()
style_type_rdrv_main_main_default.set_radius(50)
style_type_rdrv_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_rdrv_main_main_default.set_bg_grad_color(lv.color_make(0x97,0xe7,0xff))
style_type_rdrv_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_rdrv_main_main_default.set_bg_opa(255)
style_type_rdrv_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_rdrv_main_main_default.set_border_width(0)
style_type_rdrv_main_main_default.set_border_opa(255)
style_type_rdrv_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_type_rdrv_main_main_default.set_text_font(lv.font_montserratMedium_24)
except AttributeError:
    try:
        style_type_rdrv_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_type_rdrv_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_rdrv_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for TYPE_RDRV
TYPE_RDRV.add_style(style_type_rdrv_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_RM1M2
TYPE_RM1M2 = lv.btn(TYPE_cont_1)
TYPE_RM1M2.set_pos(int(30),int(240))
TYPE_RM1M2.set_size(100,100)
TYPE_RM1M2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_RM1M2_label = lv.label(TYPE_RM1M2)
TYPE_RM1M2_label.set_text("M1M2")
TYPE_RM1M2.set_style_pad_all(0, lv.STATE.DEFAULT)
TYPE_RM1M2_label.align(lv.ALIGN.CENTER,0,0)
# create style style_type_rm1m2_main_main_default
style_type_rm1m2_main_main_default = lv.style_t()
style_type_rm1m2_main_main_default.init()
style_type_rm1m2_main_main_default.set_radius(50)
style_type_rm1m2_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_rm1m2_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_rm1m2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_rm1m2_main_main_default.set_bg_opa(255)
style_type_rm1m2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_rm1m2_main_main_default.set_border_width(0)
style_type_rm1m2_main_main_default.set_border_opa(255)
style_type_rm1m2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_type_rm1m2_main_main_default.set_text_font(lv.font_montserratMedium_24)
except AttributeError:
    try:
        style_type_rm1m2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_type_rm1m2_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_rm1m2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for TYPE_RM1M2
TYPE_RM1M2.add_style(style_type_rm1m2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_RM2
TYPE_RM2 = lv.btn(TYPE_cont_1)
TYPE_RM2.set_pos(int(190),int(150))
TYPE_RM2.set_size(100,100)
TYPE_RM2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_RM2_label = lv.label(TYPE_RM2)
TYPE_RM2_label.set_text("M2")
TYPE_RM2.set_style_pad_all(0, lv.STATE.DEFAULT)
TYPE_RM2_label.align(lv.ALIGN.CENTER,0,0)
# create style style_type_rm2_main_main_default
style_type_rm2_main_main_default = lv.style_t()
style_type_rm2_main_main_default.init()
style_type_rm2_main_main_default.set_radius(50)
style_type_rm2_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_rm2_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_rm2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_rm2_main_main_default.set_bg_opa(255)
style_type_rm2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_rm2_main_main_default.set_border_width(0)
style_type_rm2_main_main_default.set_border_opa(255)
style_type_rm2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_type_rm2_main_main_default.set_text_font(lv.font_montserratMedium_31)
except AttributeError:
    try:
        style_type_rm2_main_main_default.set_text_font(lv.font_montserrat_31)
    except AttributeError:
        style_type_rm2_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_rm2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for TYPE_RM2
TYPE_RM2.add_style(style_type_rm2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_btn_1
TYPE_btn_1 = lv.btn(TYPE_cont_1)
TYPE_btn_1.set_pos(int(267),int(-7))
TYPE_btn_1.set_size(56,57)
TYPE_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_btn_1_label = lv.label(TYPE_btn_1)
TYPE_btn_1_label.set_text("X")
TYPE_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
TYPE_btn_1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_type_btn_1_main_main_default
style_type_btn_1_main_main_default = lv.style_t()
style_type_btn_1_main_main_default.init()
style_type_btn_1_main_main_default.set_radius(25)
style_type_btn_1_main_main_default.set_bg_color(lv.color_make(0xfe,0xfe,0xfe))
style_type_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_btn_1_main_main_default.set_bg_opa(0)
style_type_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_btn_1_main_main_default.set_border_width(0)
style_type_btn_1_main_main_default.set_border_opa(255)
style_type_btn_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_type_btn_1_main_main_default.set_text_font(lv.font_montserratMedium_36)
except AttributeError:
    try:
        style_type_btn_1_main_main_default.set_text_font(lv.font_montserrat_36)
    except AttributeError:
        style_type_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for TYPE_btn_1
TYPE_btn_1.add_style(style_type_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_type_cont_1_main_main_default
style_type_cont_1_main_main_default = lv.style_t()
style_type_cont_1_main_main_default.init()
style_type_cont_1_main_main_default.set_radius(0)
style_type_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_type_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_type_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_cont_1_main_main_default.set_bg_opa(255)
style_type_cont_1_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_type_cont_1_main_main_default.set_border_width(2)
style_type_cont_1_main_main_default.set_border_opa(255)
style_type_cont_1_main_main_default.set_pad_left(0)
style_type_cont_1_main_main_default.set_pad_right(0)
style_type_cont_1_main_main_default.set_pad_top(0)
style_type_cont_1_main_main_default.set_pad_bottom(0)

# add style for TYPE_cont_1
TYPE_cont_1.add_style(style_type_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_TM1
TYPE_TM1 = lv.obj(TYPE)
TYPE_TM1.set_pos(int(-305),int(100))
TYPE_TM1.set_size(300,310)
TYPE_TM1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)

# create TYPE_btn_2
TYPE_btn_2 = lv.btn(TYPE_TM1)
TYPE_btn_2.set_pos(int(261),int(1))
TYPE_btn_2.set_size(43,42)
TYPE_btn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_btn_2_label = lv.label(TYPE_btn_2)
TYPE_btn_2_label.set_text("X")
TYPE_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
TYPE_btn_2_label.align(lv.ALIGN.CENTER,0,0)
# create style style_type_btn_2_main_main_default
style_type_btn_2_main_main_default = lv.style_t()
style_type_btn_2_main_main_default.init()
style_type_btn_2_main_main_default.set_radius(5)
style_type_btn_2_main_main_default.set_bg_color(lv.color_make(0x14,0x18,0x1c))
style_type_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_btn_2_main_main_default.set_bg_opa(0)
style_type_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_btn_2_main_main_default.set_border_width(0)
style_type_btn_2_main_main_default.set_border_opa(255)
style_type_btn_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_type_btn_2_main_main_default.set_text_font(lv.font_montserratMedium_36)
except AttributeError:
    try:
        style_type_btn_2_main_main_default.set_text_font(lv.font_montserrat_36)
    except AttributeError:
        style_type_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_btn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for TYPE_btn_2
TYPE_btn_2.add_style(style_type_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_1
TYPE_label_1 = lv.label(TYPE_TM1)
TYPE_label_1.set_pos(int(22),int(69))
TYPE_label_1.set_size(260,28)
TYPE_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_1.set_text("M1")
TYPE_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_1_main_main_default
style_type_label_1_main_main_default = lv.style_t()
style_type_label_1_main_main_default.init()
style_type_label_1_main_main_default.set_radius(0)
style_type_label_1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_1_main_main_default.set_bg_opa(255)
style_type_label_1_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_1_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_1_main_main_default.set_text_letter_space(2)
style_type_label_1_main_main_default.set_text_line_space(0)
style_type_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_1_main_main_default.set_pad_left(0)
style_type_label_1_main_main_default.set_pad_right(0)
style_type_label_1_main_main_default.set_pad_top(8)
style_type_label_1_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_1
TYPE_label_1.add_style(style_type_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M1TAR
TYPE_M1TAR = lv.label(TYPE_TM1)
TYPE_M1TAR.set_pos(int(22),int(97))
TYPE_M1TAR.set_size(130,31)
TYPE_M1TAR.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M1TAR.set_text("TARGET")
TYPE_M1TAR.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m1tar_main_main_default
style_type_m1tar_main_main_default = lv.style_t()
style_type_m1tar_main_main_default.init()
style_type_m1tar_main_main_default.set_radius(0)
style_type_m1tar_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m1tar_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m1tar_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m1tar_main_main_default.set_bg_opa(255)
style_type_m1tar_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m1tar_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m1tar_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m1tar_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m1tar_main_main_default.set_text_letter_space(2)
style_type_m1tar_main_main_default.set_text_line_space(0)
style_type_m1tar_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m1tar_main_main_default.set_pad_left(0)
style_type_m1tar_main_main_default.set_pad_right(0)
style_type_m1tar_main_main_default.set_pad_top(8)
style_type_m1tar_main_main_default.set_pad_bottom(0)

# add style for TYPE_M1TAR
TYPE_M1TAR.add_style(style_type_m1tar_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M1IA
TYPE_M1IA = lv.label(TYPE_TM1)
TYPE_M1IA.set_pos(int(22),int(127))
TYPE_M1IA.set_size(130,31)
TYPE_M1IA.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M1IA.set_text("I(A)")
TYPE_M1IA.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m1ia_main_main_default
style_type_m1ia_main_main_default = lv.style_t()
style_type_m1ia_main_main_default.init()
style_type_m1ia_main_main_default.set_radius(0)
style_type_m1ia_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m1ia_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m1ia_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m1ia_main_main_default.set_bg_opa(255)
style_type_m1ia_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m1ia_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m1ia_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m1ia_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m1ia_main_main_default.set_text_letter_space(2)
style_type_m1ia_main_main_default.set_text_line_space(0)
style_type_m1ia_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m1ia_main_main_default.set_pad_left(0)
style_type_m1ia_main_main_default.set_pad_right(0)
style_type_m1ia_main_main_default.set_pad_top(8)
style_type_m1ia_main_main_default.set_pad_bottom(0)

# add style for TYPE_M1IA
TYPE_M1IA.add_style(style_type_m1ia_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M1V
TYPE_M1V = lv.label(TYPE_TM1)
TYPE_M1V.set_pos(int(22),int(156))
TYPE_M1V.set_size(130,31)
TYPE_M1V.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M1V.set_text("V")
TYPE_M1V.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m1v_main_main_default
style_type_m1v_main_main_default = lv.style_t()
style_type_m1v_main_main_default.init()
style_type_m1v_main_main_default.set_radius(0)
style_type_m1v_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m1v_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m1v_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m1v_main_main_default.set_bg_opa(255)
style_type_m1v_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m1v_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m1v_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m1v_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m1v_main_main_default.set_text_letter_space(2)
style_type_m1v_main_main_default.set_text_line_space(0)
style_type_m1v_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m1v_main_main_default.set_pad_left(0)
style_type_m1v_main_main_default.set_pad_right(0)
style_type_m1v_main_main_default.set_pad_top(8)
style_type_m1v_main_main_default.set_pad_bottom(0)

# add style for TYPE_M1V
TYPE_M1V.add_style(style_type_m1v_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M1POSI
TYPE_M1POSI = lv.label(TYPE_TM1)
TYPE_M1POSI.set_pos(int(22),int(183))
TYPE_M1POSI.set_size(130,31)
TYPE_M1POSI.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M1POSI.set_text("POSITION")
TYPE_M1POSI.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m1posi_main_main_default
style_type_m1posi_main_main_default = lv.style_t()
style_type_m1posi_main_main_default.init()
style_type_m1posi_main_main_default.set_radius(0)
style_type_m1posi_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m1posi_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m1posi_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m1posi_main_main_default.set_bg_opa(255)
style_type_m1posi_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m1posi_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m1posi_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m1posi_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m1posi_main_main_default.set_text_letter_space(2)
style_type_m1posi_main_main_default.set_text_line_space(0)
style_type_m1posi_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m1posi_main_main_default.set_pad_left(0)
style_type_m1posi_main_main_default.set_pad_right(0)
style_type_m1posi_main_main_default.set_pad_top(8)
style_type_m1posi_main_main_default.set_pad_bottom(0)

# add style for TYPE_M1POSI
TYPE_M1POSI.add_style(style_type_m1posi_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M1TAD
TYPE_M1TAD = lv.label(TYPE_TM1)
TYPE_M1TAD.set_pos(int(152),int(96))
TYPE_M1TAD.set_size(130,31)
TYPE_M1TAD.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M1TAD.set_text("Label")
TYPE_M1TAD.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m1tad_main_main_default
style_type_m1tad_main_main_default = lv.style_t()
style_type_m1tad_main_main_default.init()
style_type_m1tad_main_main_default.set_radius(0)
style_type_m1tad_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m1tad_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m1tad_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m1tad_main_main_default.set_bg_opa(255)
style_type_m1tad_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m1tad_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m1tad_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m1tad_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m1tad_main_main_default.set_text_letter_space(2)
style_type_m1tad_main_main_default.set_text_line_space(0)
style_type_m1tad_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m1tad_main_main_default.set_pad_left(0)
style_type_m1tad_main_main_default.set_pad_right(0)
style_type_m1tad_main_main_default.set_pad_top(8)
style_type_m1tad_main_main_default.set_pad_bottom(0)

# add style for TYPE_M1TAD
TYPE_M1TAD.add_style(style_type_m1tad_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M1ID
TYPE_M1ID = lv.label(TYPE_TM1)
TYPE_M1ID.set_pos(int(152),int(127))
TYPE_M1ID.set_size(130,31)
TYPE_M1ID.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M1ID.set_text("Label")
TYPE_M1ID.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m1id_main_main_default
style_type_m1id_main_main_default = lv.style_t()
style_type_m1id_main_main_default.init()
style_type_m1id_main_main_default.set_radius(0)
style_type_m1id_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m1id_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m1id_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m1id_main_main_default.set_bg_opa(255)
style_type_m1id_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m1id_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m1id_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m1id_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m1id_main_main_default.set_text_letter_space(2)
style_type_m1id_main_main_default.set_text_line_space(0)
style_type_m1id_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m1id_main_main_default.set_pad_left(0)
style_type_m1id_main_main_default.set_pad_right(0)
style_type_m1id_main_main_default.set_pad_top(8)
style_type_m1id_main_main_default.set_pad_bottom(0)

# add style for TYPE_M1ID
TYPE_M1ID.add_style(style_type_m1id_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M1VD
TYPE_M1VD = lv.label(TYPE_TM1)
TYPE_M1VD.set_pos(int(152),int(155))
TYPE_M1VD.set_size(130,31)
TYPE_M1VD.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M1VD.set_text("Label")
TYPE_M1VD.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m1vd_main_main_default
style_type_m1vd_main_main_default = lv.style_t()
style_type_m1vd_main_main_default.init()
style_type_m1vd_main_main_default.set_radius(0)
style_type_m1vd_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m1vd_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m1vd_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m1vd_main_main_default.set_bg_opa(255)
style_type_m1vd_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m1vd_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m1vd_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m1vd_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m1vd_main_main_default.set_text_letter_space(2)
style_type_m1vd_main_main_default.set_text_line_space(0)
style_type_m1vd_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m1vd_main_main_default.set_pad_left(0)
style_type_m1vd_main_main_default.set_pad_right(0)
style_type_m1vd_main_main_default.set_pad_top(8)
style_type_m1vd_main_main_default.set_pad_bottom(0)

# add style for TYPE_M1VD
TYPE_M1VD.add_style(style_type_m1vd_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M1PD
TYPE_M1PD = lv.label(TYPE_TM1)
TYPE_M1PD.set_pos(int(152),int(183))
TYPE_M1PD.set_size(130,31)
TYPE_M1PD.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M1PD.set_text("Label")
TYPE_M1PD.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m1pd_main_main_default
style_type_m1pd_main_main_default = lv.style_t()
style_type_m1pd_main_main_default.init()
style_type_m1pd_main_main_default.set_radius(0)
style_type_m1pd_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m1pd_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m1pd_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m1pd_main_main_default.set_bg_opa(255)
style_type_m1pd_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m1pd_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m1pd_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m1pd_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m1pd_main_main_default.set_text_letter_space(2)
style_type_m1pd_main_main_default.set_text_line_space(0)
style_type_m1pd_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m1pd_main_main_default.set_pad_left(0)
style_type_m1pd_main_main_default.set_pad_right(0)
style_type_m1pd_main_main_default.set_pad_top(8)
style_type_m1pd_main_main_default.set_pad_bottom(0)

# add style for TYPE_M1PD
TYPE_M1PD.add_style(style_type_m1pd_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_type_tm1_main_main_default
style_type_tm1_main_main_default = lv.style_t()
style_type_tm1_main_main_default.init()
style_type_tm1_main_main_default.set_radius(0)
style_type_tm1_main_main_default.set_bg_color(lv.color_make(0x14,0x18,0x1c))
style_type_tm1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_type_tm1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_tm1_main_main_default.set_bg_opa(255)
style_type_tm1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_tm1_main_main_default.set_border_width(2)
style_type_tm1_main_main_default.set_border_opa(0)
style_type_tm1_main_main_default.set_pad_left(0)
style_type_tm1_main_main_default.set_pad_right(0)
style_type_tm1_main_main_default.set_pad_top(0)
style_type_tm1_main_main_default.set_pad_bottom(0)

# add style for TYPE_TM1
TYPE_TM1.add_style(style_type_tm1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_TM2
TYPE_TM2 = lv.obj(TYPE)
TYPE_TM2.set_pos(int(320),int(100))
TYPE_TM2.set_size(300,310)
TYPE_TM2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)

# create TYPE_btn_3
TYPE_btn_3 = lv.btn(TYPE_TM2)
TYPE_btn_3.set_pos(int(261),int(1))
TYPE_btn_3.set_size(43,42)
TYPE_btn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_btn_3_label = lv.label(TYPE_btn_3)
TYPE_btn_3_label.set_text("X")
TYPE_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
TYPE_btn_3_label.align(lv.ALIGN.CENTER,0,0)
# create style style_type_btn_3_main_main_default
style_type_btn_3_main_main_default = lv.style_t()
style_type_btn_3_main_main_default.init()
style_type_btn_3_main_main_default.set_radius(5)
style_type_btn_3_main_main_default.set_bg_color(lv.color_make(0x14,0x18,0x1c))
style_type_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_btn_3_main_main_default.set_bg_opa(0)
style_type_btn_3_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_btn_3_main_main_default.set_border_width(0)
style_type_btn_3_main_main_default.set_border_opa(255)
style_type_btn_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_type_btn_3_main_main_default.set_text_font(lv.font_montserratMedium_36)
except AttributeError:
    try:
        style_type_btn_3_main_main_default.set_text_font(lv.font_montserrat_36)
    except AttributeError:
        style_type_btn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_btn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for TYPE_btn_3
TYPE_btn_3.add_style(style_type_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_10
TYPE_label_10 = lv.label(TYPE_TM2)
TYPE_label_10.set_pos(int(22),int(69))
TYPE_label_10.set_size(260,28)
TYPE_label_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_10.set_text("M2")
TYPE_label_10.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_10_main_main_default
style_type_label_10_main_main_default = lv.style_t()
style_type_label_10_main_main_default.init()
style_type_label_10_main_main_default.set_radius(0)
style_type_label_10_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_10_main_main_default.set_bg_opa(255)
style_type_label_10_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_10_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_10_main_main_default.set_text_letter_space(2)
style_type_label_10_main_main_default.set_text_line_space(0)
style_type_label_10_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_10_main_main_default.set_pad_left(0)
style_type_label_10_main_main_default.set_pad_right(0)
style_type_label_10_main_main_default.set_pad_top(8)
style_type_label_10_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_10
TYPE_label_10.add_style(style_type_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_9
TYPE_label_9 = lv.label(TYPE_TM2)
TYPE_label_9.set_pos(int(22),int(97))
TYPE_label_9.set_size(130,31)
TYPE_label_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_9.set_text("TARGET")
TYPE_label_9.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_9_main_main_default
style_type_label_9_main_main_default = lv.style_t()
style_type_label_9_main_main_default.init()
style_type_label_9_main_main_default.set_radius(0)
style_type_label_9_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_9_main_main_default.set_bg_opa(255)
style_type_label_9_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_9_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_9_main_main_default.set_text_letter_space(2)
style_type_label_9_main_main_default.set_text_line_space(0)
style_type_label_9_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_9_main_main_default.set_pad_left(0)
style_type_label_9_main_main_default.set_pad_right(0)
style_type_label_9_main_main_default.set_pad_top(8)
style_type_label_9_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_9
TYPE_label_9.add_style(style_type_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_8
TYPE_label_8 = lv.label(TYPE_TM2)
TYPE_label_8.set_pos(int(22),int(127))
TYPE_label_8.set_size(130,31)
TYPE_label_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_8.set_text("I(A)")
TYPE_label_8.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_8_main_main_default
style_type_label_8_main_main_default = lv.style_t()
style_type_label_8_main_main_default.init()
style_type_label_8_main_main_default.set_radius(0)
style_type_label_8_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_8_main_main_default.set_bg_opa(255)
style_type_label_8_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_8_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_8_main_main_default.set_text_letter_space(2)
style_type_label_8_main_main_default.set_text_line_space(0)
style_type_label_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_8_main_main_default.set_pad_left(0)
style_type_label_8_main_main_default.set_pad_right(0)
style_type_label_8_main_main_default.set_pad_top(8)
style_type_label_8_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_8
TYPE_label_8.add_style(style_type_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_7
TYPE_label_7 = lv.label(TYPE_TM2)
TYPE_label_7.set_pos(int(22),int(156))
TYPE_label_7.set_size(130,31)
TYPE_label_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_7.set_text("V")
TYPE_label_7.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_7_main_main_default
style_type_label_7_main_main_default = lv.style_t()
style_type_label_7_main_main_default.init()
style_type_label_7_main_main_default.set_radius(0)
style_type_label_7_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_7_main_main_default.set_bg_opa(255)
style_type_label_7_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_7_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_7_main_main_default.set_text_letter_space(2)
style_type_label_7_main_main_default.set_text_line_space(0)
style_type_label_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_7_main_main_default.set_pad_left(0)
style_type_label_7_main_main_default.set_pad_right(0)
style_type_label_7_main_main_default.set_pad_top(8)
style_type_label_7_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_7
TYPE_label_7.add_style(style_type_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_6
TYPE_label_6 = lv.label(TYPE_TM2)
TYPE_label_6.set_pos(int(22),int(183))
TYPE_label_6.set_size(130,31)
TYPE_label_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_6.set_text("POSITION")
TYPE_label_6.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_6_main_main_default
style_type_label_6_main_main_default = lv.style_t()
style_type_label_6_main_main_default.init()
style_type_label_6_main_main_default.set_radius(0)
style_type_label_6_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_6_main_main_default.set_bg_opa(255)
style_type_label_6_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_6_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_6_main_main_default.set_text_letter_space(2)
style_type_label_6_main_main_default.set_text_line_space(0)
style_type_label_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_6_main_main_default.set_pad_left(0)
style_type_label_6_main_main_default.set_pad_right(0)
style_type_label_6_main_main_default.set_pad_top(8)
style_type_label_6_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_6
TYPE_label_6.add_style(style_type_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M2TAD
TYPE_M2TAD = lv.label(TYPE_TM2)
TYPE_M2TAD.set_pos(int(152),int(96))
TYPE_M2TAD.set_size(130,31)
TYPE_M2TAD.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M2TAD.set_text("Label")
TYPE_M2TAD.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m2tad_main_main_default
style_type_m2tad_main_main_default = lv.style_t()
style_type_m2tad_main_main_default.init()
style_type_m2tad_main_main_default.set_radius(0)
style_type_m2tad_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m2tad_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m2tad_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m2tad_main_main_default.set_bg_opa(255)
style_type_m2tad_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m2tad_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m2tad_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m2tad_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m2tad_main_main_default.set_text_letter_space(2)
style_type_m2tad_main_main_default.set_text_line_space(0)
style_type_m2tad_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m2tad_main_main_default.set_pad_left(0)
style_type_m2tad_main_main_default.set_pad_right(0)
style_type_m2tad_main_main_default.set_pad_top(8)
style_type_m2tad_main_main_default.set_pad_bottom(0)

# add style for TYPE_M2TAD
TYPE_M2TAD.add_style(style_type_m2tad_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M2ID
TYPE_M2ID = lv.label(TYPE_TM2)
TYPE_M2ID.set_pos(int(152),int(127))
TYPE_M2ID.set_size(130,31)
TYPE_M2ID.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M2ID.set_text("Label")
TYPE_M2ID.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m2id_main_main_default
style_type_m2id_main_main_default = lv.style_t()
style_type_m2id_main_main_default.init()
style_type_m2id_main_main_default.set_radius(0)
style_type_m2id_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m2id_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m2id_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m2id_main_main_default.set_bg_opa(255)
style_type_m2id_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m2id_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m2id_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m2id_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m2id_main_main_default.set_text_letter_space(2)
style_type_m2id_main_main_default.set_text_line_space(0)
style_type_m2id_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m2id_main_main_default.set_pad_left(0)
style_type_m2id_main_main_default.set_pad_right(0)
style_type_m2id_main_main_default.set_pad_top(8)
style_type_m2id_main_main_default.set_pad_bottom(0)

# add style for TYPE_M2ID
TYPE_M2ID.add_style(style_type_m2id_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M2VD
TYPE_M2VD = lv.label(TYPE_TM2)
TYPE_M2VD.set_pos(int(152),int(155))
TYPE_M2VD.set_size(130,31)
TYPE_M2VD.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M2VD.set_text("Label")
TYPE_M2VD.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m2vd_main_main_default
style_type_m2vd_main_main_default = lv.style_t()
style_type_m2vd_main_main_default.init()
style_type_m2vd_main_main_default.set_radius(0)
style_type_m2vd_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m2vd_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m2vd_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m2vd_main_main_default.set_bg_opa(255)
style_type_m2vd_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m2vd_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m2vd_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m2vd_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m2vd_main_main_default.set_text_letter_space(2)
style_type_m2vd_main_main_default.set_text_line_space(0)
style_type_m2vd_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m2vd_main_main_default.set_pad_left(0)
style_type_m2vd_main_main_default.set_pad_right(0)
style_type_m2vd_main_main_default.set_pad_top(8)
style_type_m2vd_main_main_default.set_pad_bottom(0)

# add style for TYPE_M2VD
TYPE_M2VD.add_style(style_type_m2vd_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_M2PD
TYPE_M2PD = lv.label(TYPE_TM2)
TYPE_M2PD.set_pos(int(152),int(183))
TYPE_M2PD.set_size(130,31)
TYPE_M2PD.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_M2PD.set_text("Label")
TYPE_M2PD.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_m2pd_main_main_default
style_type_m2pd_main_main_default = lv.style_t()
style_type_m2pd_main_main_default.init()
style_type_m2pd_main_main_default.set_radius(0)
style_type_m2pd_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_m2pd_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_m2pd_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_m2pd_main_main_default.set_bg_opa(255)
style_type_m2pd_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_m2pd_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_m2pd_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_m2pd_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_m2pd_main_main_default.set_text_letter_space(2)
style_type_m2pd_main_main_default.set_text_line_space(0)
style_type_m2pd_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_m2pd_main_main_default.set_pad_left(0)
style_type_m2pd_main_main_default.set_pad_right(0)
style_type_m2pd_main_main_default.set_pad_top(8)
style_type_m2pd_main_main_default.set_pad_bottom(0)

# add style for TYPE_M2PD
TYPE_M2PD.add_style(style_type_m2pd_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_type_tm2_main_main_default
style_type_tm2_main_main_default = lv.style_t()
style_type_tm2_main_main_default.init()
style_type_tm2_main_main_default.set_radius(0)
style_type_tm2_main_main_default.set_bg_color(lv.color_make(0x14,0x18,0x1c))
style_type_tm2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_type_tm2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_tm2_main_main_default.set_bg_opa(255)
style_type_tm2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_tm2_main_main_default.set_border_width(2)
style_type_tm2_main_main_default.set_border_opa(0)
style_type_tm2_main_main_default.set_pad_left(0)
style_type_tm2_main_main_default.set_pad_right(0)
style_type_tm2_main_main_default.set_pad_top(0)
style_type_tm2_main_main_default.set_pad_bottom(0)

# add style for TYPE_TM2
TYPE_TM2.add_style(style_type_tm2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_TM1M2
TYPE_TM1M2 = lv.obj(TYPE)
TYPE_TM1M2.set_pos(int(-307),int(40))
TYPE_TM1M2.set_size(302,400)
TYPE_TM1M2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)

# create TYPE_btn_4
TYPE_btn_4 = lv.btn(TYPE_TM1M2)
TYPE_btn_4.set_pos(int(261),int(1))
TYPE_btn_4.set_size(43,42)
TYPE_btn_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_btn_4_label = lv.label(TYPE_btn_4)
TYPE_btn_4_label.set_text("X")
TYPE_btn_4.set_style_pad_all(0, lv.STATE.DEFAULT)
TYPE_btn_4_label.align(lv.ALIGN.CENTER,0,0)
# create style style_type_btn_4_main_main_default
style_type_btn_4_main_main_default = lv.style_t()
style_type_btn_4_main_main_default.init()
style_type_btn_4_main_main_default.set_radius(5)
style_type_btn_4_main_main_default.set_bg_color(lv.color_make(0x14,0x18,0x1c))
style_type_btn_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_btn_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_btn_4_main_main_default.set_bg_opa(0)
style_type_btn_4_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_btn_4_main_main_default.set_border_width(0)
style_type_btn_4_main_main_default.set_border_opa(255)
style_type_btn_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_type_btn_4_main_main_default.set_text_font(lv.font_montserratMedium_36)
except AttributeError:
    try:
        style_type_btn_4_main_main_default.set_text_font(lv.font_montserrat_36)
    except AttributeError:
        style_type_btn_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_btn_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for TYPE_btn_4
TYPE_btn_4.add_style(style_type_btn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_19
TYPE_label_19 = lv.label(TYPE_TM1M2)
TYPE_label_19.set_pos(int(22),int(59))
TYPE_label_19.set_size(260,28)
TYPE_label_19.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_19.set_text("M1")
TYPE_label_19.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_19_main_main_default
style_type_label_19_main_main_default = lv.style_t()
style_type_label_19_main_main_default.init()
style_type_label_19_main_main_default.set_radius(0)
style_type_label_19_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_19_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_19_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_19_main_main_default.set_bg_opa(255)
style_type_label_19_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_19_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_19_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_19_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_19_main_main_default.set_text_letter_space(2)
style_type_label_19_main_main_default.set_text_line_space(0)
style_type_label_19_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_19_main_main_default.set_pad_left(0)
style_type_label_19_main_main_default.set_pad_right(0)
style_type_label_19_main_main_default.set_pad_top(8)
style_type_label_19_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_19
TYPE_label_19.add_style(style_type_label_19_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_18
TYPE_label_18 = lv.label(TYPE_TM1M2)
TYPE_label_18.set_pos(int(22),int(87))
TYPE_label_18.set_size(130,31)
TYPE_label_18.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_18.set_text("TARGET")
TYPE_label_18.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_18_main_main_default
style_type_label_18_main_main_default = lv.style_t()
style_type_label_18_main_main_default.init()
style_type_label_18_main_main_default.set_radius(0)
style_type_label_18_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_18_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_18_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_18_main_main_default.set_bg_opa(255)
style_type_label_18_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_18_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_18_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_18_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_18_main_main_default.set_text_letter_space(2)
style_type_label_18_main_main_default.set_text_line_space(0)
style_type_label_18_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_18_main_main_default.set_pad_left(0)
style_type_label_18_main_main_default.set_pad_right(0)
style_type_label_18_main_main_default.set_pad_top(8)
style_type_label_18_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_18
TYPE_label_18.add_style(style_type_label_18_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_17
TYPE_label_17 = lv.label(TYPE_TM1M2)
TYPE_label_17.set_pos(int(22),int(117))
TYPE_label_17.set_size(130,31)
TYPE_label_17.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_17.set_text("I(A)")
TYPE_label_17.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_17_main_main_default
style_type_label_17_main_main_default = lv.style_t()
style_type_label_17_main_main_default.init()
style_type_label_17_main_main_default.set_radius(0)
style_type_label_17_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_17_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_17_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_17_main_main_default.set_bg_opa(255)
style_type_label_17_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_17_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_17_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_17_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_17_main_main_default.set_text_letter_space(2)
style_type_label_17_main_main_default.set_text_line_space(0)
style_type_label_17_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_17_main_main_default.set_pad_left(0)
style_type_label_17_main_main_default.set_pad_right(0)
style_type_label_17_main_main_default.set_pad_top(8)
style_type_label_17_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_17
TYPE_label_17.add_style(style_type_label_17_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_16
TYPE_label_16 = lv.label(TYPE_TM1M2)
TYPE_label_16.set_pos(int(22),int(147))
TYPE_label_16.set_size(130,31)
TYPE_label_16.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_16.set_text("V")
TYPE_label_16.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_16_main_main_default
style_type_label_16_main_main_default = lv.style_t()
style_type_label_16_main_main_default.init()
style_type_label_16_main_main_default.set_radius(0)
style_type_label_16_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_16_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_16_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_16_main_main_default.set_bg_opa(255)
style_type_label_16_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_16_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_16_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_16_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_16_main_main_default.set_text_letter_space(2)
style_type_label_16_main_main_default.set_text_line_space(0)
style_type_label_16_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_16_main_main_default.set_pad_left(0)
style_type_label_16_main_main_default.set_pad_right(0)
style_type_label_16_main_main_default.set_pad_top(8)
style_type_label_16_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_16
TYPE_label_16.add_style(style_type_label_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_15
TYPE_label_15 = lv.label(TYPE_TM1M2)
TYPE_label_15.set_pos(int(22),int(177))
TYPE_label_15.set_size(130,31)
TYPE_label_15.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_15.set_text("POSITION")
TYPE_label_15.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_15_main_main_default
style_type_label_15_main_main_default = lv.style_t()
style_type_label_15_main_main_default.init()
style_type_label_15_main_main_default.set_radius(0)
style_type_label_15_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_15_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_15_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_15_main_main_default.set_bg_opa(255)
style_type_label_15_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_15_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_15_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_15_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_15_main_main_default.set_text_letter_space(2)
style_type_label_15_main_main_default.set_text_line_space(0)
style_type_label_15_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_15_main_main_default.set_pad_left(0)
style_type_label_15_main_main_default.set_pad_right(0)
style_type_label_15_main_main_default.set_pad_top(8)
style_type_label_15_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_15
TYPE_label_15.add_style(style_type_label_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_14
TYPE_label_14 = lv.label(TYPE_TM1M2)
TYPE_label_14.set_pos(int(152),int(87))
TYPE_label_14.set_size(130,31)
TYPE_label_14.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_14.set_text("Label")
TYPE_label_14.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_14_main_main_default
style_type_label_14_main_main_default = lv.style_t()
style_type_label_14_main_main_default.init()
style_type_label_14_main_main_default.set_radius(0)
style_type_label_14_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_14_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_14_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_14_main_main_default.set_bg_opa(255)
style_type_label_14_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_14_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_14_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_14_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_14_main_main_default.set_text_letter_space(2)
style_type_label_14_main_main_default.set_text_line_space(0)
style_type_label_14_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_14_main_main_default.set_pad_left(0)
style_type_label_14_main_main_default.set_pad_right(0)
style_type_label_14_main_main_default.set_pad_top(8)
style_type_label_14_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_14
TYPE_label_14.add_style(style_type_label_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_13
TYPE_label_13 = lv.label(TYPE_TM1M2)
TYPE_label_13.set_pos(int(152),int(117))
TYPE_label_13.set_size(130,31)
TYPE_label_13.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_13.set_text("Label")
TYPE_label_13.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_13_main_main_default
style_type_label_13_main_main_default = lv.style_t()
style_type_label_13_main_main_default.init()
style_type_label_13_main_main_default.set_radius(0)
style_type_label_13_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_13_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_13_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_13_main_main_default.set_bg_opa(255)
style_type_label_13_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_13_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_13_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_13_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_13_main_main_default.set_text_letter_space(2)
style_type_label_13_main_main_default.set_text_line_space(0)
style_type_label_13_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_13_main_main_default.set_pad_left(0)
style_type_label_13_main_main_default.set_pad_right(0)
style_type_label_13_main_main_default.set_pad_top(8)
style_type_label_13_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_13
TYPE_label_13.add_style(style_type_label_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_12
TYPE_label_12 = lv.label(TYPE_TM1M2)
TYPE_label_12.set_pos(int(152),int(147))
TYPE_label_12.set_size(130,31)
TYPE_label_12.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_12.set_text("Label")
TYPE_label_12.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_12_main_main_default
style_type_label_12_main_main_default = lv.style_t()
style_type_label_12_main_main_default.init()
style_type_label_12_main_main_default.set_radius(0)
style_type_label_12_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_12_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_12_main_main_default.set_bg_opa(255)
style_type_label_12_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_12_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_12_main_main_default.set_text_letter_space(2)
style_type_label_12_main_main_default.set_text_line_space(0)
style_type_label_12_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_12_main_main_default.set_pad_left(0)
style_type_label_12_main_main_default.set_pad_right(0)
style_type_label_12_main_main_default.set_pad_top(8)
style_type_label_12_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_12
TYPE_label_12.add_style(style_type_label_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_11
TYPE_label_11 = lv.label(TYPE_TM1M2)
TYPE_label_11.set_pos(int(152),int(177))
TYPE_label_11.set_size(130,31)
TYPE_label_11.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_11.set_text("Label")
TYPE_label_11.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_11_main_main_default
style_type_label_11_main_main_default = lv.style_t()
style_type_label_11_main_main_default.init()
style_type_label_11_main_main_default.set_radius(0)
style_type_label_11_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_11_main_main_default.set_bg_opa(255)
style_type_label_11_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_11_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_11_main_main_default.set_text_letter_space(2)
style_type_label_11_main_main_default.set_text_line_space(0)
style_type_label_11_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_11_main_main_default.set_pad_left(0)
style_type_label_11_main_main_default.set_pad_right(0)
style_type_label_11_main_main_default.set_pad_top(8)
style_type_label_11_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_11
TYPE_label_11.add_style(style_type_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_20
TYPE_label_20 = lv.label(TYPE_TM1M2)
TYPE_label_20.set_pos(int(22),int(208))
TYPE_label_20.set_size(260,28)
TYPE_label_20.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_20.set_text("M2")
TYPE_label_20.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_20_main_main_default
style_type_label_20_main_main_default = lv.style_t()
style_type_label_20_main_main_default.init()
style_type_label_20_main_main_default.set_radius(0)
style_type_label_20_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_20_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_20_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_20_main_main_default.set_bg_opa(255)
style_type_label_20_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_20_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_20_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_20_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_20_main_main_default.set_text_letter_space(2)
style_type_label_20_main_main_default.set_text_line_space(0)
style_type_label_20_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_20_main_main_default.set_pad_left(0)
style_type_label_20_main_main_default.set_pad_right(0)
style_type_label_20_main_main_default.set_pad_top(8)
style_type_label_20_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_20
TYPE_label_20.add_style(style_type_label_20_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_21
TYPE_label_21 = lv.label(TYPE_TM1M2)
TYPE_label_21.set_pos(int(22),int(235))
TYPE_label_21.set_size(130,31)
TYPE_label_21.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_21.set_text("TARGET")
TYPE_label_21.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_21_main_main_default
style_type_label_21_main_main_default = lv.style_t()
style_type_label_21_main_main_default.init()
style_type_label_21_main_main_default.set_radius(0)
style_type_label_21_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_21_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_21_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_21_main_main_default.set_bg_opa(255)
style_type_label_21_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_21_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_21_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_21_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_21_main_main_default.set_text_letter_space(2)
style_type_label_21_main_main_default.set_text_line_space(0)
style_type_label_21_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_21_main_main_default.set_pad_left(0)
style_type_label_21_main_main_default.set_pad_right(0)
style_type_label_21_main_main_default.set_pad_top(8)
style_type_label_21_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_21
TYPE_label_21.add_style(style_type_label_21_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_22
TYPE_label_22 = lv.label(TYPE_TM1M2)
TYPE_label_22.set_pos(int(22),int(266))
TYPE_label_22.set_size(130,31)
TYPE_label_22.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_22.set_text("I(A)")
TYPE_label_22.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_22_main_main_default
style_type_label_22_main_main_default = lv.style_t()
style_type_label_22_main_main_default.init()
style_type_label_22_main_main_default.set_radius(0)
style_type_label_22_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_22_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_22_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_22_main_main_default.set_bg_opa(255)
style_type_label_22_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_22_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_22_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_22_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_22_main_main_default.set_text_letter_space(2)
style_type_label_22_main_main_default.set_text_line_space(0)
style_type_label_22_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_22_main_main_default.set_pad_left(0)
style_type_label_22_main_main_default.set_pad_right(0)
style_type_label_22_main_main_default.set_pad_top(8)
style_type_label_22_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_22
TYPE_label_22.add_style(style_type_label_22_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_23
TYPE_label_23 = lv.label(TYPE_TM1M2)
TYPE_label_23.set_pos(int(22),int(297))
TYPE_label_23.set_size(130,31)
TYPE_label_23.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_23.set_text("V")
TYPE_label_23.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_23_main_main_default
style_type_label_23_main_main_default = lv.style_t()
style_type_label_23_main_main_default.init()
style_type_label_23_main_main_default.set_radius(0)
style_type_label_23_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_23_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_23_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_23_main_main_default.set_bg_opa(255)
style_type_label_23_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_23_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_23_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_23_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_23_main_main_default.set_text_letter_space(2)
style_type_label_23_main_main_default.set_text_line_space(0)
style_type_label_23_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_23_main_main_default.set_pad_left(0)
style_type_label_23_main_main_default.set_pad_right(0)
style_type_label_23_main_main_default.set_pad_top(8)
style_type_label_23_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_23
TYPE_label_23.add_style(style_type_label_23_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_24
TYPE_label_24 = lv.label(TYPE_TM1M2)
TYPE_label_24.set_pos(int(22),int(328))
TYPE_label_24.set_size(130,31)
TYPE_label_24.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_24.set_text("POSITION")
TYPE_label_24.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_24_main_main_default
style_type_label_24_main_main_default = lv.style_t()
style_type_label_24_main_main_default.init()
style_type_label_24_main_main_default.set_radius(0)
style_type_label_24_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_24_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_24_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_24_main_main_default.set_bg_opa(255)
style_type_label_24_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_24_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_24_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_24_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_24_main_main_default.set_text_letter_space(2)
style_type_label_24_main_main_default.set_text_line_space(0)
style_type_label_24_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_24_main_main_default.set_pad_left(0)
style_type_label_24_main_main_default.set_pad_right(0)
style_type_label_24_main_main_default.set_pad_top(8)
style_type_label_24_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_24
TYPE_label_24.add_style(style_type_label_24_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_26
TYPE_label_26 = lv.label(TYPE_TM1M2)
TYPE_label_26.set_pos(int(152),int(235))
TYPE_label_26.set_size(130,31)
TYPE_label_26.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_26.set_text("Label")
TYPE_label_26.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_26_main_main_default
style_type_label_26_main_main_default = lv.style_t()
style_type_label_26_main_main_default.init()
style_type_label_26_main_main_default.set_radius(0)
style_type_label_26_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_26_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_26_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_26_main_main_default.set_bg_opa(255)
style_type_label_26_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_26_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_26_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_26_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_26_main_main_default.set_text_letter_space(2)
style_type_label_26_main_main_default.set_text_line_space(0)
style_type_label_26_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_26_main_main_default.set_pad_left(0)
style_type_label_26_main_main_default.set_pad_right(0)
style_type_label_26_main_main_default.set_pad_top(8)
style_type_label_26_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_26
TYPE_label_26.add_style(style_type_label_26_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_27
TYPE_label_27 = lv.label(TYPE_TM1M2)
TYPE_label_27.set_pos(int(152),int(266))
TYPE_label_27.set_size(130,31)
TYPE_label_27.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_27.set_text("Label")
TYPE_label_27.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_27_main_main_default
style_type_label_27_main_main_default = lv.style_t()
style_type_label_27_main_main_default.init()
style_type_label_27_main_main_default.set_radius(0)
style_type_label_27_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_27_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_27_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_27_main_main_default.set_bg_opa(255)
style_type_label_27_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_27_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_27_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_27_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_27_main_main_default.set_text_letter_space(2)
style_type_label_27_main_main_default.set_text_line_space(0)
style_type_label_27_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_27_main_main_default.set_pad_left(0)
style_type_label_27_main_main_default.set_pad_right(0)
style_type_label_27_main_main_default.set_pad_top(8)
style_type_label_27_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_27
TYPE_label_27.add_style(style_type_label_27_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_28
TYPE_label_28 = lv.label(TYPE_TM1M2)
TYPE_label_28.set_pos(int(152),int(297))
TYPE_label_28.set_size(130,31)
TYPE_label_28.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_28.set_text("Label")
TYPE_label_28.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_28_main_main_default
style_type_label_28_main_main_default = lv.style_t()
style_type_label_28_main_main_default.init()
style_type_label_28_main_main_default.set_radius(0)
style_type_label_28_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_28_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_28_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_28_main_main_default.set_bg_opa(255)
style_type_label_28_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_28_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_28_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_28_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_28_main_main_default.set_text_letter_space(2)
style_type_label_28_main_main_default.set_text_line_space(0)
style_type_label_28_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_28_main_main_default.set_pad_left(0)
style_type_label_28_main_main_default.set_pad_right(0)
style_type_label_28_main_main_default.set_pad_top(8)
style_type_label_28_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_28
TYPE_label_28.add_style(style_type_label_28_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_29
TYPE_label_29 = lv.label(TYPE_TM1M2)
TYPE_label_29.set_pos(int(152),int(328))
TYPE_label_29.set_size(130,31)
TYPE_label_29.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_29.set_text("Label")
TYPE_label_29.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_29_main_main_default
style_type_label_29_main_main_default = lv.style_t()
style_type_label_29_main_main_default.init()
style_type_label_29_main_main_default.set_radius(0)
style_type_label_29_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_29_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_29_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_29_main_main_default.set_bg_opa(255)
style_type_label_29_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_29_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_29_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_29_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_29_main_main_default.set_text_letter_space(2)
style_type_label_29_main_main_default.set_text_line_space(0)
style_type_label_29_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_29_main_main_default.set_pad_left(0)
style_type_label_29_main_main_default.set_pad_right(0)
style_type_label_29_main_main_default.set_pad_top(8)
style_type_label_29_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_29
TYPE_label_29.add_style(style_type_label_29_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_type_tm1m2_main_main_default
style_type_tm1m2_main_main_default = lv.style_t()
style_type_tm1m2_main_main_default.init()
style_type_tm1m2_main_main_default.set_radius(0)
style_type_tm1m2_main_main_default.set_bg_color(lv.color_make(0x14,0x18,0x1c))
style_type_tm1m2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_type_tm1m2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_tm1m2_main_main_default.set_bg_opa(255)
style_type_tm1m2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_tm1m2_main_main_default.set_border_width(2)
style_type_tm1m2_main_main_default.set_border_opa(0)
style_type_tm1m2_main_main_default.set_pad_left(0)
style_type_tm1m2_main_main_default.set_pad_right(0)
style_type_tm1m2_main_main_default.set_pad_top(0)
style_type_tm1m2_main_main_default.set_pad_bottom(0)

# add style for TYPE_TM1M2
TYPE_TM1M2.add_style(style_type_tm1m2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_TDRV
TYPE_TDRV = lv.obj(TYPE)
TYPE_TDRV.set_pos(int(320),int(100))
TYPE_TDRV.set_size(300,310)
TYPE_TDRV.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)

# create TYPE_btn_5
TYPE_btn_5 = lv.btn(TYPE_TDRV)
TYPE_btn_5.set_pos(int(261),int(1))
TYPE_btn_5.set_size(43,42)
TYPE_btn_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_btn_5_label = lv.label(TYPE_btn_5)
TYPE_btn_5_label.set_text("X")
TYPE_btn_5.set_style_pad_all(0, lv.STATE.DEFAULT)
TYPE_btn_5_label.align(lv.ALIGN.CENTER,0,0)
# create style style_type_btn_5_main_main_default
style_type_btn_5_main_main_default = lv.style_t()
style_type_btn_5_main_main_default.init()
style_type_btn_5_main_main_default.set_radius(5)
style_type_btn_5_main_main_default.set_bg_color(lv.color_make(0x14,0x18,0x1c))
style_type_btn_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_btn_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_btn_5_main_main_default.set_bg_opa(0)
style_type_btn_5_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_btn_5_main_main_default.set_border_width(0)
style_type_btn_5_main_main_default.set_border_opa(255)
style_type_btn_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_type_btn_5_main_main_default.set_text_font(lv.font_montserratMedium_36)
except AttributeError:
    try:
        style_type_btn_5_main_main_default.set_text_font(lv.font_montserrat_36)
    except AttributeError:
        style_type_btn_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_btn_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for TYPE_btn_5
TYPE_btn_5.add_style(style_type_btn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_TDR
TYPE_TDR = lv.label(TYPE_TDRV)
TYPE_TDR.set_pos(int(22),int(69))
TYPE_TDR.set_size(260,28)
TYPE_TDR.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_TDR.set_text("DRV")
TYPE_TDR.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_tdr_main_main_default
style_type_tdr_main_main_default = lv.style_t()
style_type_tdr_main_main_default.init()
style_type_tdr_main_main_default.set_radius(0)
style_type_tdr_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_tdr_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_tdr_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_tdr_main_main_default.set_bg_opa(255)
style_type_tdr_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_tdr_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_tdr_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_tdr_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_tdr_main_main_default.set_text_letter_space(2)
style_type_tdr_main_main_default.set_text_line_space(0)
style_type_tdr_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_tdr_main_main_default.set_pad_left(0)
style_type_tdr_main_main_default.set_pad_right(0)
style_type_tdr_main_main_default.set_pad_top(8)
style_type_tdr_main_main_default.set_pad_bottom(0)

# add style for TYPE_TDR
TYPE_TDR.add_style(style_type_tdr_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_37
TYPE_label_37 = lv.label(TYPE_TDRV)
TYPE_label_37.set_pos(int(22),int(97))
TYPE_label_37.set_size(130,31)
TYPE_label_37.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_37.set_text("TARGET")
TYPE_label_37.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_37_main_main_default
style_type_label_37_main_main_default = lv.style_t()
style_type_label_37_main_main_default.init()
style_type_label_37_main_main_default.set_radius(0)
style_type_label_37_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_37_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_37_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_37_main_main_default.set_bg_opa(255)
style_type_label_37_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_37_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_37_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_37_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_37_main_main_default.set_text_letter_space(2)
style_type_label_37_main_main_default.set_text_line_space(0)
style_type_label_37_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_37_main_main_default.set_pad_left(0)
style_type_label_37_main_main_default.set_pad_right(0)
style_type_label_37_main_main_default.set_pad_top(8)
style_type_label_37_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_37
TYPE_label_37.add_style(style_type_label_37_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_36
TYPE_label_36 = lv.label(TYPE_TDRV)
TYPE_label_36.set_pos(int(22),int(127))
TYPE_label_36.set_size(130,31)
TYPE_label_36.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_36.set_text("I(A)")
TYPE_label_36.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_36_main_main_default
style_type_label_36_main_main_default = lv.style_t()
style_type_label_36_main_main_default.init()
style_type_label_36_main_main_default.set_radius(0)
style_type_label_36_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_36_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_36_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_36_main_main_default.set_bg_opa(255)
style_type_label_36_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_36_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_36_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_36_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_36_main_main_default.set_text_letter_space(2)
style_type_label_36_main_main_default.set_text_line_space(0)
style_type_label_36_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_36_main_main_default.set_pad_left(0)
style_type_label_36_main_main_default.set_pad_right(0)
style_type_label_36_main_main_default.set_pad_top(8)
style_type_label_36_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_36
TYPE_label_36.add_style(style_type_label_36_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_35
TYPE_label_35 = lv.label(TYPE_TDRV)
TYPE_label_35.set_pos(int(22),int(156))
TYPE_label_35.set_size(130,31)
TYPE_label_35.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_35.set_text("V")
TYPE_label_35.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_35_main_main_default
style_type_label_35_main_main_default = lv.style_t()
style_type_label_35_main_main_default.init()
style_type_label_35_main_main_default.set_radius(0)
style_type_label_35_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_35_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_35_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_35_main_main_default.set_bg_opa(255)
style_type_label_35_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_35_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_35_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_35_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_35_main_main_default.set_text_letter_space(2)
style_type_label_35_main_main_default.set_text_line_space(0)
style_type_label_35_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_35_main_main_default.set_pad_left(0)
style_type_label_35_main_main_default.set_pad_right(0)
style_type_label_35_main_main_default.set_pad_top(8)
style_type_label_35_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_35
TYPE_label_35.add_style(style_type_label_35_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_34
TYPE_label_34 = lv.label(TYPE_TDRV)
TYPE_label_34.set_pos(int(22),int(183))
TYPE_label_34.set_size(130,31)
TYPE_label_34.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_34.set_text("POSITION")
TYPE_label_34.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_34_main_main_default
style_type_label_34_main_main_default = lv.style_t()
style_type_label_34_main_main_default.init()
style_type_label_34_main_main_default.set_radius(0)
style_type_label_34_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_34_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_34_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_34_main_main_default.set_bg_opa(255)
style_type_label_34_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_34_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_34_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_34_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_34_main_main_default.set_text_letter_space(2)
style_type_label_34_main_main_default.set_text_line_space(0)
style_type_label_34_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_34_main_main_default.set_pad_left(0)
style_type_label_34_main_main_default.set_pad_right(0)
style_type_label_34_main_main_default.set_pad_top(8)
style_type_label_34_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_34
TYPE_label_34.add_style(style_type_label_34_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_33
TYPE_label_33 = lv.label(TYPE_TDRV)
TYPE_label_33.set_pos(int(152),int(96))
TYPE_label_33.set_size(130,31)
TYPE_label_33.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_33.set_text("Label")
TYPE_label_33.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_33_main_main_default
style_type_label_33_main_main_default = lv.style_t()
style_type_label_33_main_main_default.init()
style_type_label_33_main_main_default.set_radius(0)
style_type_label_33_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_33_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_33_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_33_main_main_default.set_bg_opa(255)
style_type_label_33_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_33_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_33_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_33_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_33_main_main_default.set_text_letter_space(2)
style_type_label_33_main_main_default.set_text_line_space(0)
style_type_label_33_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_33_main_main_default.set_pad_left(0)
style_type_label_33_main_main_default.set_pad_right(0)
style_type_label_33_main_main_default.set_pad_top(8)
style_type_label_33_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_33
TYPE_label_33.add_style(style_type_label_33_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_32
TYPE_label_32 = lv.label(TYPE_TDRV)
TYPE_label_32.set_pos(int(152),int(127))
TYPE_label_32.set_size(130,31)
TYPE_label_32.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_32.set_text("Label")
TYPE_label_32.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_32_main_main_default
style_type_label_32_main_main_default = lv.style_t()
style_type_label_32_main_main_default.init()
style_type_label_32_main_main_default.set_radius(0)
style_type_label_32_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_32_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_32_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_32_main_main_default.set_bg_opa(255)
style_type_label_32_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_32_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_32_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_32_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_32_main_main_default.set_text_letter_space(2)
style_type_label_32_main_main_default.set_text_line_space(0)
style_type_label_32_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_32_main_main_default.set_pad_left(0)
style_type_label_32_main_main_default.set_pad_right(0)
style_type_label_32_main_main_default.set_pad_top(8)
style_type_label_32_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_32
TYPE_label_32.add_style(style_type_label_32_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_31
TYPE_label_31 = lv.label(TYPE_TDRV)
TYPE_label_31.set_pos(int(152),int(155))
TYPE_label_31.set_size(130,31)
TYPE_label_31.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_31.set_text("Label")
TYPE_label_31.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_31_main_main_default
style_type_label_31_main_main_default = lv.style_t()
style_type_label_31_main_main_default.init()
style_type_label_31_main_main_default.set_radius(0)
style_type_label_31_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_31_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_31_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_31_main_main_default.set_bg_opa(255)
style_type_label_31_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_31_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_31_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_31_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_31_main_main_default.set_text_letter_space(2)
style_type_label_31_main_main_default.set_text_line_space(0)
style_type_label_31_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_31_main_main_default.set_pad_left(0)
style_type_label_31_main_main_default.set_pad_right(0)
style_type_label_31_main_main_default.set_pad_top(8)
style_type_label_31_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_31
TYPE_label_31.add_style(style_type_label_31_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create TYPE_label_30
TYPE_label_30 = lv.label(TYPE_TDRV)
TYPE_label_30.set_pos(int(152),int(183))
TYPE_label_30.set_size(130,31)
TYPE_label_30.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
TYPE_label_30.set_text("Label")
TYPE_label_30.set_long_mode(lv.label.LONG.WRAP)
# create style style_type_label_30_main_main_default
style_type_label_30_main_main_default = lv.style_t()
style_type_label_30_main_main_default.init()
style_type_label_30_main_main_default.set_radius(0)
style_type_label_30_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_type_label_30_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_type_label_30_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_label_30_main_main_default.set_bg_opa(255)
style_type_label_30_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_type_label_30_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_type_label_30_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_type_label_30_main_main_default.set_text_font(lv.font_montserrat_16)
style_type_label_30_main_main_default.set_text_letter_space(2)
style_type_label_30_main_main_default.set_text_line_space(0)
style_type_label_30_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_type_label_30_main_main_default.set_pad_left(0)
style_type_label_30_main_main_default.set_pad_right(0)
style_type_label_30_main_main_default.set_pad_top(8)
style_type_label_30_main_main_default.set_pad_bottom(0)

# add style for TYPE_label_30
TYPE_label_30.add_style(style_type_label_30_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_type_tdrv_main_main_default
style_type_tdrv_main_main_default = lv.style_t()
style_type_tdrv_main_main_default.init()
style_type_tdrv_main_main_default.set_radius(0)
style_type_tdrv_main_main_default.set_bg_color(lv.color_make(0x14,0x18,0x1c))
style_type_tdrv_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_type_tdrv_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_type_tdrv_main_main_default.set_bg_opa(255)
style_type_tdrv_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_type_tdrv_main_main_default.set_border_width(2)
style_type_tdrv_main_main_default.set_border_opa(0)
style_type_tdrv_main_main_default.set_pad_left(0)
style_type_tdrv_main_main_default.set_pad_right(0)
style_type_tdrv_main_main_default.set_pad_top(0)
style_type_tdrv_main_main_default.set_pad_bottom(0)

# add style for TYPE_TDRV
TYPE_TDRV.add_style(style_type_tdrv_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create OTHERS
OTHERS = lv.obj()
OTHERS.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_others_main_main_default
style_others_main_main_default = lv.style_t()
style_others_main_main_default.init()
style_others_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_others_main_main_default.set_bg_opa(0)

# add style for OTHERS
OTHERS.add_style(style_others_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create OTHERS_tabview_1
OTHERS_tabview_1 = lv.tabview(OTHERS, lv.DIR.TOP, 50)
OTHERS_tabview_1_tab_btns = OTHERS_tabview_1.get_tab_btns()
# create style style_others_tabview_1_extra_btnm_main_default
style_others_tabview_1_extra_btnm_main_default = lv.style_t()
style_others_tabview_1_extra_btnm_main_default.init()
style_others_tabview_1_extra_btnm_main_default.set_radius(0)
style_others_tabview_1_extra_btnm_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_others_tabview_1_extra_btnm_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_others_tabview_1_extra_btnm_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_others_tabview_1_extra_btnm_main_default.set_bg_opa(255)
style_others_tabview_1_extra_btnm_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_others_tabview_1_extra_btnm_main_default.set_border_width(0)
style_others_tabview_1_extra_btnm_main_default.set_border_opa(100)

# add style for OTHERS_tabview_1_tab_btns
OTHERS_tabview_1_tab_btns.add_style(style_others_tabview_1_extra_btnm_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_others_tabview_1_extra_btnm_items_default
style_others_tabview_1_extra_btnm_items_default = lv.style_t()
style_others_tabview_1_extra_btnm_items_default.init()
style_others_tabview_1_extra_btnm_items_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_others_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_others_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_others_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_16)

# add style for OTHERS_tabview_1_tab_btns
OTHERS_tabview_1_tab_btns.add_style(style_others_tabview_1_extra_btnm_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

# create style style_others_tabview_1_extra_btnm_items_checked
style_others_tabview_1_extra_btnm_items_checked = lv.style_t()
style_others_tabview_1_extra_btnm_items_checked.init()
style_others_tabview_1_extra_btnm_items_checked.set_radius(0)
style_others_tabview_1_extra_btnm_items_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_others_tabview_1_extra_btnm_items_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_others_tabview_1_extra_btnm_items_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_others_tabview_1_extra_btnm_items_checked.set_bg_opa(60)
style_others_tabview_1_extra_btnm_items_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_others_tabview_1_extra_btnm_items_checked.set_border_width(4)
style_others_tabview_1_extra_btnm_items_checked.set_border_opa(255)
style_others_tabview_1_extra_btnm_items_checked.set_border_side(lv.BORDER_SIDE.BOTTOM)
style_others_tabview_1_extra_btnm_items_checked.set_text_color(lv.color_make(0x21,0x95,0xf6))
try:
    style_others_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_others_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_others_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_16)

# add style for OTHERS_tabview_1_tab_btns
OTHERS_tabview_1_tab_btns.add_style(style_others_tabview_1_extra_btnm_items_checked, lv.PART.ITEMS|lv.STATE.CHECKED)

OTHERS_tabview_1_MPU = OTHERS_tabview_1.add_tab("MPU")
OTHERS_tabview_1_MPU_label = lv.label(OTHERS_tabview_1_MPU)
OTHERS_tabview_1_MPU_label.set_text("MPU")
OTHERS_tabview_1_APR = OTHERS_tabview_1.add_tab("APR")
OTHERS_tabview_1_APR_label = lv.label(OTHERS_tabview_1_APR)
OTHERS_tabview_1_APR_label.set_text("Air Pressure")
OTHERS_tabview_1_MEN = OTHERS_tabview_1.add_tab("MEN")
OTHERS_tabview_1_MEN_label = lv.label(OTHERS_tabview_1_MEN)
OTHERS_tabview_1_MEN_label.set_text("Menory")
OTHERS_tabview_1_OTHER = OTHERS_tabview_1.add_tab("OTHER")
OTHERS_tabview_1_OTHER_label = lv.label(OTHERS_tabview_1_OTHER)
OTHERS_tabview_1_OTHER_label.set_text("Others")
OTHERS_tabview_1.set_pos(int(15),int(83))
OTHERS_tabview_1.set_size(291,327)
OTHERS_tabview_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.ON)
# create style style_others_tabview_1_main_main_default
style_others_tabview_1_main_main_default = lv.style_t()
style_others_tabview_1_main_main_default.init()
style_others_tabview_1_main_main_default.set_radius(0)
style_others_tabview_1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_others_tabview_1_main_main_default.set_bg_grad_color(lv.color_make(0xea,0xef,0xf3))
style_others_tabview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_others_tabview_1_main_main_default.set_bg_opa(255)
style_others_tabview_1_main_main_default.set_border_color(lv.color_make(0xc0,0xc0,0xc0))
style_others_tabview_1_main_main_default.set_border_width(0)
style_others_tabview_1_main_main_default.set_border_opa(100)
style_others_tabview_1_main_main_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_others_tabview_1_main_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_others_tabview_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_others_tabview_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_others_tabview_1_main_main_default.set_text_letter_space(2)
style_others_tabview_1_main_main_default.set_text_line_space(16)

# add style for OTHERS_tabview_1
OTHERS_tabview_1.add_style(style_others_tabview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create OTHERS_btn_1
OTHERS_btn_1 = lv.btn(OTHERS)
OTHERS_btn_1.set_pos(int(266),int(-7))
OTHERS_btn_1.set_size(50,50)
OTHERS_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
OTHERS_btn_1_label = lv.label(OTHERS_btn_1)
OTHERS_btn_1_label.set_text("X")
OTHERS_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
OTHERS_btn_1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_others_btn_1_main_main_default
style_others_btn_1_main_main_default = lv.style_t()
style_others_btn_1_main_main_default.init()
style_others_btn_1_main_main_default.set_radius(5)
style_others_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_others_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_others_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_others_btn_1_main_main_default.set_bg_opa(0)
style_others_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_others_btn_1_main_main_default.set_border_width(0)
style_others_btn_1_main_main_default.set_border_opa(0)
style_others_btn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_others_btn_1_main_main_default.set_text_font(lv.font_montserratMedium_36)
except AttributeError:
    try:
        style_others_btn_1_main_main_default.set_text_font(lv.font_montserrat_36)
    except AttributeError:
        style_others_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_others_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for OTHERS_btn_1
OTHERS_btn_1.add_style(style_others_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create OTHERS_label_1
OTHERS_label_1 = lv.label(OTHERS)
OTHERS_label_1.set_pos(int(0),int(0))
OTHERS_label_1.set_size(260,35)
OTHERS_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
OTHERS_label_1.set_text("Label")
OTHERS_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_others_label_1_main_main_default
style_others_label_1_main_main_default = lv.style_t()
style_others_label_1_main_main_default.init()
style_others_label_1_main_main_default.set_radius(0)
style_others_label_1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_others_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_others_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_others_label_1_main_main_default.set_bg_opa(255)
style_others_label_1_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_others_label_1_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_others_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_others_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_others_label_1_main_main_default.set_text_letter_space(2)
style_others_label_1_main_main_default.set_text_line_space(0)
style_others_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_others_label_1_main_main_default.set_pad_left(0)
style_others_label_1_main_main_default.set_pad_right(0)
style_others_label_1_main_main_default.set_pad_top(8)
style_others_label_1_main_main_default.set_pad_bottom(0)

# add style for OTHERS_label_1
OTHERS_label_1.add_style(style_others_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SET
SET = lv.obj()
SET.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_set_main_main_default
style_set_main_main_default = lv.style_t()
style_set_main_main_default.init()
style_set_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_set_main_main_default.set_bg_opa(0)

# add style for SET
SET.add_style(style_set_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SET_cont_1
SET_cont_1 = lv.obj(SET)
SET_cont_1.set_pos(int(0),int(0))
SET_cont_1.set_size(320,480)
SET_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)

# create SET_SM1
SET_SM1 = lv.btn(SET_cont_1)
SET_SM1.set_pos(int(60),int(150))
SET_SM1.set_size(120,120)
SET_SM1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SET_SM1_label = lv.label(SET_SM1)
SET_SM1_label.set_text("M1")
SET_SM1.set_style_pad_all(0, lv.STATE.DEFAULT)
SET_SM1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_set_sm1_main_main_default
style_set_sm1_main_main_default = lv.style_t()
style_set_sm1_main_main_default.init()
style_set_sm1_main_main_default.set_radius(60)
style_set_sm1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_set_sm1_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe6,0xe6))
style_set_sm1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_set_sm1_main_main_default.set_bg_opa(255)
style_set_sm1_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_set_sm1_main_main_default.set_border_width(0)
style_set_sm1_main_main_default.set_border_opa(255)
style_set_sm1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_set_sm1_main_main_default.set_text_font(lv.font_montserratMedium_36)
except AttributeError:
    try:
        style_set_sm1_main_main_default.set_text_font(lv.font_montserrat_36)
    except AttributeError:
        style_set_sm1_main_main_default.set_text_font(lv.font_montserrat_16)
style_set_sm1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SET_SM1
SET_SM1.add_style(style_set_sm1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SET_SM2
SET_SM2 = lv.btn(SET_cont_1)
SET_SM2.set_pos(int(155),int(275))
SET_SM2.set_size(80,80)
SET_SM2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SET_SM2_label = lv.label(SET_SM2)
SET_SM2_label.set_text("M2")
SET_SM2.set_style_pad_all(0, lv.STATE.DEFAULT)
SET_SM2_label.align(lv.ALIGN.CENTER,0,0)
# create style style_set_sm2_main_main_default
style_set_sm2_main_main_default = lv.style_t()
style_set_sm2_main_main_default.init()
style_set_sm2_main_main_default.set_radius(40)
style_set_sm2_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_set_sm2_main_main_default.set_bg_grad_color(lv.color_make(0x97,0xe7,0xff))
style_set_sm2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_set_sm2_main_main_default.set_bg_opa(255)
style_set_sm2_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_set_sm2_main_main_default.set_border_width(0)
style_set_sm2_main_main_default.set_border_opa(255)
style_set_sm2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_set_sm2_main_main_default.set_text_font(lv.font_montserratMedium_24)
except AttributeError:
    try:
        style_set_sm2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_set_sm2_main_main_default.set_text_font(lv.font_montserrat_16)
style_set_sm2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SET_SM2
SET_SM2.add_style(style_set_sm2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SET_btn_3
SET_btn_3 = lv.btn(SET_cont_1)
SET_btn_3.set_pos(int(264),int(-8))
SET_btn_3.set_size(50,50)
SET_btn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SET_btn_3_label = lv.label(SET_btn_3)
SET_btn_3_label.set_text("X")
SET_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
SET_btn_3_label.align(lv.ALIGN.CENTER,0,0)
# create style style_set_btn_3_main_main_default
style_set_btn_3_main_main_default = lv.style_t()
style_set_btn_3_main_main_default.init()
style_set_btn_3_main_main_default.set_radius(5)
style_set_btn_3_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_set_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_set_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_set_btn_3_main_main_default.set_bg_opa(0)
style_set_btn_3_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_set_btn_3_main_main_default.set_border_width(0)
style_set_btn_3_main_main_default.set_border_opa(0)
style_set_btn_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_set_btn_3_main_main_default.set_text_font(lv.font_montserratMedium_36)
except AttributeError:
    try:
        style_set_btn_3_main_main_default.set_text_font(lv.font_montserrat_36)
    except AttributeError:
        style_set_btn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_set_btn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SET_btn_3
SET_btn_3.add_style(style_set_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SET_label_1
SET_label_1 = lv.label(SET_cont_1)
SET_label_1.set_pos(int(-2),int(-1))
SET_label_1.set_size(260,35)
SET_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SET_label_1.set_text("Label")
SET_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_set_label_1_main_main_default
style_set_label_1_main_main_default = lv.style_t()
style_set_label_1_main_main_default.init()
style_set_label_1_main_main_default.set_radius(0)
style_set_label_1_main_main_default.set_bg_color(lv.color_make(0x14,0x18,0x1c))
style_set_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_set_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_set_label_1_main_main_default.set_bg_opa(255)
style_set_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_set_label_1_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_set_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_set_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_set_label_1_main_main_default.set_text_letter_space(2)
style_set_label_1_main_main_default.set_text_line_space(0)
style_set_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_set_label_1_main_main_default.set_pad_left(0)
style_set_label_1_main_main_default.set_pad_right(0)
style_set_label_1_main_main_default.set_pad_top(8)
style_set_label_1_main_main_default.set_pad_bottom(0)

# add style for SET_label_1
SET_label_1.add_style(style_set_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_set_cont_1_main_main_default
style_set_cont_1_main_main_default = lv.style_t()
style_set_cont_1_main_main_default.init()
style_set_cont_1_main_main_default.set_radius(0)
style_set_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_set_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_set_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_set_cont_1_main_main_default.set_bg_opa(255)
style_set_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_set_cont_1_main_main_default.set_border_width(2)
style_set_cont_1_main_main_default.set_border_opa(0)
style_set_cont_1_main_main_default.set_pad_left(0)
style_set_cont_1_main_main_default.set_pad_right(0)
style_set_cont_1_main_main_default.set_pad_top(0)
style_set_cont_1_main_main_default.set_pad_bottom(0)

# add style for SET_cont_1
SET_cont_1.add_style(style_set_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create WIFI
WIFI = lv.obj()
WIFI.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_wifi_main_main_default
style_wifi_main_main_default = lv.style_t()
style_wifi_main_main_default.init()
style_wifi_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_wifi_main_main_default.set_bg_opa(0)

# add style for WIFI
WIFI.add_style(style_wifi_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create WIFI_btn_1
WIFI_btn_1 = lv.btn(WIFI)
WIFI_btn_1.set_pos(int(279),int(1))
WIFI_btn_1.set_size(37,49)
WIFI_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
WIFI_btn_1_label = lv.label(WIFI_btn_1)
WIFI_btn_1_label.set_text("X")
WIFI_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
WIFI_btn_1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_wifi_btn_1_main_main_default
style_wifi_btn_1_main_main_default = lv.style_t()
style_wifi_btn_1_main_main_default.init()
style_wifi_btn_1_main_main_default.set_radius(5)
style_wifi_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_wifi_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_wifi_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_wifi_btn_1_main_main_default.set_bg_opa(0)
style_wifi_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_wifi_btn_1_main_main_default.set_border_width(0)
style_wifi_btn_1_main_main_default.set_border_opa(255)
style_wifi_btn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_wifi_btn_1_main_main_default.set_text_font(lv.font_montserratMedium_36)
except AttributeError:
    try:
        style_wifi_btn_1_main_main_default.set_text_font(lv.font_montserrat_36)
    except AttributeError:
        style_wifi_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_wifi_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for WIFI_btn_1
WIFI_btn_1.add_style(style_wifi_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create WIFI_label_1
WIFI_label_1 = lv.label(WIFI)
WIFI_label_1.set_pos(int(41),int(115))
WIFI_label_1.set_size(100,32)
WIFI_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
WIFI_label_1.set_text("name")
WIFI_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_wifi_label_1_main_main_default
style_wifi_label_1_main_main_default = lv.style_t()
style_wifi_label_1_main_main_default.init()
style_wifi_label_1_main_main_default.set_radius(0)
style_wifi_label_1_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_wifi_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_wifi_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_wifi_label_1_main_main_default.set_bg_opa(255)
style_wifi_label_1_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_wifi_label_1_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_wifi_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_wifi_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_wifi_label_1_main_main_default.set_text_letter_space(2)
style_wifi_label_1_main_main_default.set_text_line_space(0)
style_wifi_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_wifi_label_1_main_main_default.set_pad_left(0)
style_wifi_label_1_main_main_default.set_pad_right(0)
style_wifi_label_1_main_main_default.set_pad_top(8)
style_wifi_label_1_main_main_default.set_pad_bottom(0)

# add style for WIFI_label_1
WIFI_label_1.add_style(style_wifi_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create WIFI_name
WIFI_name = lv.textarea(WIFI)
WIFI_name.set_pos(int(151),int(114))
WIFI_name.set_size(144,33)
WIFI_name.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
WIFI_name.set_text("DengsFos")


# create style style_wifi_name_main_main_default
style_wifi_name_main_main_default = lv.style_t()
style_wifi_name_main_main_default.init()
style_wifi_name_main_main_default.set_radius(4)
style_wifi_name_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_wifi_name_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_wifi_name_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_wifi_name_main_main_default.set_bg_opa(255)
style_wifi_name_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_wifi_name_main_main_default.set_border_width(2)
style_wifi_name_main_main_default.set_border_opa(255)
style_wifi_name_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_wifi_name_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_wifi_name_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_wifi_name_main_main_default.set_text_font(lv.font_montserrat_16)
style_wifi_name_main_main_default.set_text_letter_space(2)
style_wifi_name_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_wifi_name_main_main_default.set_pad_left(4)
style_wifi_name_main_main_default.set_pad_right(4)
style_wifi_name_main_main_default.set_pad_top(4)
style_wifi_name_main_main_default.set_pad_bottom(4)

# add style for WIFI_name
WIFI_name.add_style(style_wifi_name_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_wifi_name_main_scrollbar_default
style_wifi_name_main_scrollbar_default = lv.style_t()
style_wifi_name_main_scrollbar_default.init()
style_wifi_name_main_scrollbar_default.set_radius(0)
style_wifi_name_main_scrollbar_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_wifi_name_main_scrollbar_default.set_bg_opa(255)

# add style for WIFI_name
WIFI_name.add_style(style_wifi_name_main_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)


# create WIFI_label_2
WIFI_label_2 = lv.label(WIFI)
WIFI_label_2.set_pos(int(41),int(154))
WIFI_label_2.set_size(100,32)
WIFI_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
WIFI_label_2.set_text("passward")
WIFI_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_wifi_label_2_main_main_default
style_wifi_label_2_main_main_default = lv.style_t()
style_wifi_label_2_main_main_default.init()
style_wifi_label_2_main_main_default.set_radius(0)
style_wifi_label_2_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_wifi_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_wifi_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_wifi_label_2_main_main_default.set_bg_opa(255)
style_wifi_label_2_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_wifi_label_2_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_wifi_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_wifi_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_wifi_label_2_main_main_default.set_text_letter_space(2)
style_wifi_label_2_main_main_default.set_text_line_space(0)
style_wifi_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_wifi_label_2_main_main_default.set_pad_left(0)
style_wifi_label_2_main_main_default.set_pad_right(0)
style_wifi_label_2_main_main_default.set_pad_top(8)
style_wifi_label_2_main_main_default.set_pad_bottom(0)

# add style for WIFI_label_2
WIFI_label_2.add_style(style_wifi_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create WIFI_passward
WIFI_passward = lv.textarea(WIFI)
WIFI_passward.set_pos(int(151),int(153))
WIFI_passward.set_size(144,33)
WIFI_passward.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
WIFI_passward.set_text("DengsFos")


# create style style_wifi_passward_main_main_default
style_wifi_passward_main_main_default = lv.style_t()
style_wifi_passward_main_main_default.init()
style_wifi_passward_main_main_default.set_radius(4)
style_wifi_passward_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_wifi_passward_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_wifi_passward_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_wifi_passward_main_main_default.set_bg_opa(255)
style_wifi_passward_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_wifi_passward_main_main_default.set_border_width(2)
style_wifi_passward_main_main_default.set_border_opa(255)
style_wifi_passward_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_wifi_passward_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_wifi_passward_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_wifi_passward_main_main_default.set_text_font(lv.font_montserrat_16)
style_wifi_passward_main_main_default.set_text_letter_space(2)
style_wifi_passward_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_wifi_passward_main_main_default.set_pad_left(4)
style_wifi_passward_main_main_default.set_pad_right(4)
style_wifi_passward_main_main_default.set_pad_top(4)
style_wifi_passward_main_main_default.set_pad_bottom(4)

# add style for WIFI_passward
WIFI_passward.add_style(style_wifi_passward_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_wifi_passward_main_scrollbar_default
style_wifi_passward_main_scrollbar_default = lv.style_t()
style_wifi_passward_main_scrollbar_default.init()
style_wifi_passward_main_scrollbar_default.set_radius(0)
style_wifi_passward_main_scrollbar_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_wifi_passward_main_scrollbar_default.set_bg_opa(255)

# add style for WIFI_passward
WIFI_passward.add_style(style_wifi_passward_main_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)


# create WIFI_btn_2
WIFI_btn_2 = lv.btn(WIFI)
WIFI_btn_2.set_pos(int(110),int(224))
WIFI_btn_2.set_size(100,50)
WIFI_btn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
WIFI_btn_2_label = lv.label(WIFI_btn_2)
WIFI_btn_2_label.set_text("Connect")
WIFI_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
WIFI_btn_2_label.align(lv.ALIGN.CENTER,0,0)
# create style style_wifi_btn_2_main_main_default
style_wifi_btn_2_main_main_default = lv.style_t()
style_wifi_btn_2_main_main_default.init()
style_wifi_btn_2_main_main_default.set_radius(5)
style_wifi_btn_2_main_main_default.set_bg_color(lv.color_make(0x97,0xe7,0xff))
style_wifi_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_wifi_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_wifi_btn_2_main_main_default.set_bg_opa(255)
style_wifi_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_wifi_btn_2_main_main_default.set_border_width(0)
style_wifi_btn_2_main_main_default.set_border_opa(255)
style_wifi_btn_2_main_main_default.set_text_color(lv.color_make(0x14,0x18,0x1c))
try:
    style_wifi_btn_2_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_wifi_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_wifi_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_wifi_btn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for WIFI_btn_2
WIFI_btn_2.add_style(style_wifi_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1
SEM1 = lv.obj()
SEM1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sem1_main_main_default
style_sem1_main_main_default = lv.style_t()
style_sem1_main_main_default.init()
style_sem1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sem1_main_main_default.set_bg_opa(0)

# add style for SEM1
SEM1.add_style(style_sem1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_cont_2
SEM1_cont_2 = lv.obj(SEM1)
SEM1_cont_2.set_pos(int(0),int(0))
SEM1_cont_2.set_size(320,480)
SEM1_cont_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)

# create SEM1_win_1
SEM1_win_1 = lv.win(SEM1_cont_2, 40)
SEM1_win_1.add_title("some details")
SEM1_win_1_cont = SEM1_win_1.get_content()
SEM1_win_1_cont_label =  lv.label(SEM1_win_1_cont)
SEM1_win_1_cont_label.set_text("this is a \nlong text \nto show \nscrollbar. \nif \nit \nis not \nlong enough, \nadd more content")
# create style style_sem1_win_1_extra_content_main_default
style_sem1_win_1_extra_content_main_default = lv.style_t()
style_sem1_win_1_extra_content_main_default.init()
style_sem1_win_1_extra_content_main_default.set_bg_color(lv.color_make(0xee,0xee,0xf6))
style_sem1_win_1_extra_content_main_default.set_bg_grad_color(lv.color_make(0xee,0xee,0xf6))
style_sem1_win_1_extra_content_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_win_1_extra_content_main_default.set_bg_opa(255)
style_sem1_win_1_extra_content_main_default.set_text_color(lv.color_make(0x39,0x3c,0x41))
try:
    style_sem1_win_1_extra_content_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_sem1_win_1_extra_content_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_win_1_extra_content_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_win_1_extra_content_main_default.set_text_letter_space(0)
style_sem1_win_1_extra_content_main_default.set_text_line_space(2)

# add style for SEM1_win_1_cont
SEM1_win_1_cont.add_style(style_sem1_win_1_extra_content_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

SEM1_win_1_header = SEM1_win_1.get_header()
# create style style_sem1_win_1_extra_header_main_default
style_sem1_win_1_extra_header_main_default = lv.style_t()
style_sem1_win_1_extra_header_main_default.init()
style_sem1_win_1_extra_header_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_sem1_win_1_extra_header_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe6,0xe6))
style_sem1_win_1_extra_header_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_win_1_extra_header_main_default.set_bg_opa(255)
style_sem1_win_1_extra_header_main_default.set_text_color(lv.color_make(0x39,0x3c,0x41))
try:
    style_sem1_win_1_extra_header_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_sem1_win_1_extra_header_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_win_1_extra_header_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_win_1_extra_header_main_default.set_text_letter_space(0)
style_sem1_win_1_extra_header_main_default.set_text_line_space(2)

# add style for SEM1_win_1_header
SEM1_win_1_header.add_style(style_sem1_win_1_extra_header_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

SEM1_win_1.set_pos(int(21),int(173))
SEM1_win_1.set_size(277,242)
SEM1_win_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sem1_win_1_main_main_default
style_sem1_win_1_main_main_default = lv.style_t()
style_sem1_win_1_main_main_default.init()
style_sem1_win_1_main_main_default.set_bg_color(lv.color_make(0xee,0xee,0xf6))
style_sem1_win_1_main_main_default.set_bg_grad_color(lv.color_make(0xee,0xee,0xf6))
style_sem1_win_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_win_1_main_main_default.set_bg_opa(255)
style_sem1_win_1_main_main_default.set_outline_color(lv.color_make(0x08,0x1A,0x0F))
style_sem1_win_1_main_main_default.set_outline_width(0)
style_sem1_win_1_main_main_default.set_outline_opa(255)

# add style for SEM1_win_1
SEM1_win_1.add_style(style_sem1_win_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_sem1_cont_2_main_main_default
style_sem1_cont_2_main_main_default = lv.style_t()
style_sem1_cont_2_main_main_default.init()
style_sem1_cont_2_main_main_default.set_radius(0)
style_sem1_cont_2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sem1_cont_2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_sem1_cont_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_cont_2_main_main_default.set_bg_opa(255)
style_sem1_cont_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_cont_2_main_main_default.set_border_width(2)
style_sem1_cont_2_main_main_default.set_border_opa(0)
style_sem1_cont_2_main_main_default.set_pad_left(0)
style_sem1_cont_2_main_main_default.set_pad_right(0)
style_sem1_cont_2_main_main_default.set_pad_top(0)
style_sem1_cont_2_main_main_default.set_pad_bottom(0)

# add style for SEM1_cont_2
SEM1_cont_2.add_style(style_sem1_cont_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_cont_1
SEM1_cont_1 = lv.obj(SEM1)
SEM1_cont_1.set_pos(int(-320),int(230))
SEM1_cont_1.set_size(320,250)
SEM1_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)

# create SEM1_BTN0
SEM1_BTN0 = lv.btn(SEM1_cont_1)
SEM1_BTN0.set_pos(int(30),int(190))
SEM1_BTN0.set_size(110,50)
SEM1_BTN0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_BTN0_label = lv.label(SEM1_BTN0)
SEM1_BTN0_label.set_text("0")
SEM1_BTN0.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_BTN0_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn0_main_main_default
style_sem1_btn0_main_main_default = lv.style_t()
style_sem1_btn0_main_main_default.init()
style_sem1_btn0_main_main_default.set_radius(5)
style_sem1_btn0_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn0_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn0_main_main_default.set_bg_opa(255)
style_sem1_btn0_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn0_main_main_default.set_border_width(0)
style_sem1_btn0_main_main_default.set_border_opa(255)
style_sem1_btn0_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn0_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn0_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn0_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn0_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_BTN0
SEM1_BTN0.add_style(style_sem1_btn0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_3
SEM1_btn_3 = lv.btn(SEM1_cont_1)
SEM1_btn_3.set_pos(int(30),int(10))
SEM1_btn_3.set_size(50,50)
SEM1_btn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_3_label = lv.label(SEM1_btn_3)
SEM1_btn_3_label.set_text("7")
SEM1_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_3_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_3_main_main_default
style_sem1_btn_3_main_main_default = lv.style_t()
style_sem1_btn_3_main_main_default.init()
style_sem1_btn_3_main_main_default.set_radius(5)
style_sem1_btn_3_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_3_main_main_default.set_bg_opa(255)
style_sem1_btn_3_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_3_main_main_default.set_border_width(0)
style_sem1_btn_3_main_main_default.set_border_opa(255)
style_sem1_btn_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_3_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_3
SEM1_btn_3.add_style(style_sem1_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_4
SEM1_btn_4 = lv.btn(SEM1_cont_1)
SEM1_btn_4.set_pos(int(90),int(10))
SEM1_btn_4.set_size(50,50)
SEM1_btn_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_4_label = lv.label(SEM1_btn_4)
SEM1_btn_4_label.set_text("8")
SEM1_btn_4.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_4_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_4_main_main_default
style_sem1_btn_4_main_main_default = lv.style_t()
style_sem1_btn_4_main_main_default.init()
style_sem1_btn_4_main_main_default.set_radius(5)
style_sem1_btn_4_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_4_main_main_default.set_bg_opa(255)
style_sem1_btn_4_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_4_main_main_default.set_border_width(0)
style_sem1_btn_4_main_main_default.set_border_opa(255)
style_sem1_btn_4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_4_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_4
SEM1_btn_4.add_style(style_sem1_btn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_5
SEM1_btn_5 = lv.btn(SEM1_cont_1)
SEM1_btn_5.set_pos(int(150),int(10))
SEM1_btn_5.set_size(50,50)
SEM1_btn_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_5_label = lv.label(SEM1_btn_5)
SEM1_btn_5_label.set_text("9")
SEM1_btn_5.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_5_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_5_main_main_default
style_sem1_btn_5_main_main_default = lv.style_t()
style_sem1_btn_5_main_main_default.init()
style_sem1_btn_5_main_main_default.set_radius(5)
style_sem1_btn_5_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_5_main_main_default.set_bg_opa(255)
style_sem1_btn_5_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_5_main_main_default.set_border_width(0)
style_sem1_btn_5_main_main_default.set_border_opa(255)
style_sem1_btn_5_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_5_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_5_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_5
SEM1_btn_5.add_style(style_sem1_btn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_6
SEM1_btn_6 = lv.btn(SEM1_cont_1)
SEM1_btn_6.set_pos(int(30),int(70))
SEM1_btn_6.set_size(50,50)
SEM1_btn_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_6_label = lv.label(SEM1_btn_6)
SEM1_btn_6_label.set_text("4")
SEM1_btn_6.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_6_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_6_main_main_default
style_sem1_btn_6_main_main_default = lv.style_t()
style_sem1_btn_6_main_main_default.init()
style_sem1_btn_6_main_main_default.set_radius(5)
style_sem1_btn_6_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_6_main_main_default.set_bg_opa(255)
style_sem1_btn_6_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_6_main_main_default.set_border_width(0)
style_sem1_btn_6_main_main_default.set_border_opa(255)
style_sem1_btn_6_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_6_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_6_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_6
SEM1_btn_6.add_style(style_sem1_btn_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_7
SEM1_btn_7 = lv.btn(SEM1_cont_1)
SEM1_btn_7.set_pos(int(90),int(70))
SEM1_btn_7.set_size(50,50)
SEM1_btn_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_7_label = lv.label(SEM1_btn_7)
SEM1_btn_7_label.set_text("5")
SEM1_btn_7.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_7_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_7_main_main_default
style_sem1_btn_7_main_main_default = lv.style_t()
style_sem1_btn_7_main_main_default.init()
style_sem1_btn_7_main_main_default.set_radius(5)
style_sem1_btn_7_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_7_main_main_default.set_bg_opa(255)
style_sem1_btn_7_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_7_main_main_default.set_border_width(0)
style_sem1_btn_7_main_main_default.set_border_opa(255)
style_sem1_btn_7_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_7_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_7_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_7
SEM1_btn_7.add_style(style_sem1_btn_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_8
SEM1_btn_8 = lv.btn(SEM1_cont_1)
SEM1_btn_8.set_pos(int(30),int(130))
SEM1_btn_8.set_size(50,50)
SEM1_btn_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_8_label = lv.label(SEM1_btn_8)
SEM1_btn_8_label.set_text("1")
SEM1_btn_8.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_8_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_8_main_main_default
style_sem1_btn_8_main_main_default = lv.style_t()
style_sem1_btn_8_main_main_default.init()
style_sem1_btn_8_main_main_default.set_radius(5)
style_sem1_btn_8_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_8_main_main_default.set_bg_opa(255)
style_sem1_btn_8_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_8_main_main_default.set_border_width(0)
style_sem1_btn_8_main_main_default.set_border_opa(255)
style_sem1_btn_8_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_8_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_8_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_8
SEM1_btn_8.add_style(style_sem1_btn_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_9
SEM1_btn_9 = lv.btn(SEM1_cont_1)
SEM1_btn_9.set_pos(int(150),int(70))
SEM1_btn_9.set_size(50,50)
SEM1_btn_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_9_label = lv.label(SEM1_btn_9)
SEM1_btn_9_label.set_text("6")
SEM1_btn_9.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_9_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_9_main_main_default
style_sem1_btn_9_main_main_default = lv.style_t()
style_sem1_btn_9_main_main_default.init()
style_sem1_btn_9_main_main_default.set_radius(5)
style_sem1_btn_9_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_9_main_main_default.set_bg_opa(255)
style_sem1_btn_9_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_9_main_main_default.set_border_width(0)
style_sem1_btn_9_main_main_default.set_border_opa(255)
style_sem1_btn_9_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_9_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_9_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_9_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_9
SEM1_btn_9.add_style(style_sem1_btn_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_10
SEM1_btn_10 = lv.btn(SEM1_cont_1)
SEM1_btn_10.set_pos(int(90),int(130))
SEM1_btn_10.set_size(50,50)
SEM1_btn_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_10_label = lv.label(SEM1_btn_10)
SEM1_btn_10_label.set_text("2")
SEM1_btn_10.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_10_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_10_main_main_default
style_sem1_btn_10_main_main_default = lv.style_t()
style_sem1_btn_10_main_main_default.init()
style_sem1_btn_10_main_main_default.set_radius(5)
style_sem1_btn_10_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_10_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_10_main_main_default.set_bg_opa(255)
style_sem1_btn_10_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_10_main_main_default.set_border_width(0)
style_sem1_btn_10_main_main_default.set_border_opa(255)
style_sem1_btn_10_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_10_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_10_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_10_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_10
SEM1_btn_10.add_style(style_sem1_btn_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_11
SEM1_btn_11 = lv.btn(SEM1_cont_1)
SEM1_btn_11.set_pos(int(150),int(130))
SEM1_btn_11.set_size(50,50)
SEM1_btn_11.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_11_label = lv.label(SEM1_btn_11)
SEM1_btn_11_label.set_text("3")
SEM1_btn_11.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_11_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_11_main_main_default
style_sem1_btn_11_main_main_default = lv.style_t()
style_sem1_btn_11_main_main_default.init()
style_sem1_btn_11_main_main_default.set_radius(5)
style_sem1_btn_11_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_11_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_11_main_main_default.set_bg_opa(255)
style_sem1_btn_11_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_11_main_main_default.set_border_width(0)
style_sem1_btn_11_main_main_default.set_border_opa(255)
style_sem1_btn_11_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_11_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_11_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_11_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_11
SEM1_btn_11.add_style(style_sem1_btn_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_12
SEM1_btn_12 = lv.btn(SEM1_cont_1)
SEM1_btn_12.set_pos(int(150),int(190))
SEM1_btn_12.set_size(50,50)
SEM1_btn_12.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_12_label = lv.label(SEM1_btn_12)
SEM1_btn_12_label.set_text(".")
SEM1_btn_12.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_12_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_12_main_main_default
style_sem1_btn_12_main_main_default = lv.style_t()
style_sem1_btn_12_main_main_default.init()
style_sem1_btn_12_main_main_default.set_radius(5)
style_sem1_btn_12_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_12_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_12_main_main_default.set_bg_opa(255)
style_sem1_btn_12_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_12_main_main_default.set_border_width(0)
style_sem1_btn_12_main_main_default.set_border_opa(255)
style_sem1_btn_12_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_12_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_12_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_12_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_12
SEM1_btn_12.add_style(style_sem1_btn_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_13
SEM1_btn_13 = lv.btn(SEM1_cont_1)
SEM1_btn_13.set_pos(int(210),int(10))
SEM1_btn_13.set_size(50,70)
SEM1_btn_13.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_13_label = lv.label(SEM1_btn_13)
SEM1_btn_13_label.set_text("Deleter")
SEM1_btn_13.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_13_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_13_main_main_default
style_sem1_btn_13_main_main_default = lv.style_t()
style_sem1_btn_13_main_main_default.init()
style_sem1_btn_13_main_main_default.set_radius(5)
style_sem1_btn_13_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_13_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_13_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_13_main_main_default.set_bg_opa(255)
style_sem1_btn_13_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_13_main_main_default.set_border_width(0)
style_sem1_btn_13_main_main_default.set_border_opa(0)
style_sem1_btn_13_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_13_main_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_sem1_btn_13_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_btn_13_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_13_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_13
SEM1_btn_13.add_style(style_sem1_btn_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_14
SEM1_btn_14 = lv.btn(SEM1_cont_1)
SEM1_btn_14.set_pos(int(210),int(90))
SEM1_btn_14.set_size(50,70)
SEM1_btn_14.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_14_label = lv.label(SEM1_btn_14)
SEM1_btn_14_label.set_text("Enter")
SEM1_btn_14.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_14_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_14_main_main_default
style_sem1_btn_14_main_main_default = lv.style_t()
style_sem1_btn_14_main_main_default.init()
style_sem1_btn_14_main_main_default.set_radius(5)
style_sem1_btn_14_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_14_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_14_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_14_main_main_default.set_bg_opa(255)
style_sem1_btn_14_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_14_main_main_default.set_border_width(0)
style_sem1_btn_14_main_main_default.set_border_opa(0)
style_sem1_btn_14_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_14_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_14_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_14_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_14_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_14
SEM1_btn_14.add_style(style_sem1_btn_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_15
SEM1_btn_15 = lv.btn(SEM1_cont_1)
SEM1_btn_15.set_pos(int(210),int(170))
SEM1_btn_15.set_size(50,70)
SEM1_btn_15.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_15_label = lv.label(SEM1_btn_15)
SEM1_btn_15_label.set_text("Save")
SEM1_btn_15.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_15_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_15_main_main_default
style_sem1_btn_15_main_main_default = lv.style_t()
style_sem1_btn_15_main_main_default.init()
style_sem1_btn_15_main_main_default.set_radius(5)
style_sem1_btn_15_main_main_default.set_bg_color(lv.color_make(0xd3,0xd3,0xd3))
style_sem1_btn_15_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_15_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_15_main_main_default.set_bg_opa(255)
style_sem1_btn_15_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_15_main_main_default.set_border_width(0)
style_sem1_btn_15_main_main_default.set_border_opa(0)
style_sem1_btn_15_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_15_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_15_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_15_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_15_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_15
SEM1_btn_15.add_style(style_sem1_btn_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_16
SEM1_btn_16 = lv.btn(SEM1_cont_1)
SEM1_btn_16.set_pos(int(273),int(5))
SEM1_btn_16.set_size(43,18)
SEM1_btn_16.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_16_label = lv.label(SEM1_btn_16)
SEM1_btn_16_label.set_text("<")
SEM1_btn_16.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_16_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_16_main_main_default
style_sem1_btn_16_main_main_default = lv.style_t()
style_sem1_btn_16_main_main_default.init()
style_sem1_btn_16_main_main_default.set_radius(5)
style_sem1_btn_16_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_sem1_btn_16_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_16_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_16_main_main_default.set_bg_opa(255)
style_sem1_btn_16_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_16_main_main_default.set_border_width(0)
style_sem1_btn_16_main_main_default.set_border_opa(0)
style_sem1_btn_16_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_btn_16_main_main_default.set_text_font(lv.font_montserratMedium_24)
except AttributeError:
    try:
        style_sem1_btn_16_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sem1_btn_16_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_16_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_16
SEM1_btn_16.add_style(style_sem1_btn_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_sem1_cont_1_main_main_default
style_sem1_cont_1_main_main_default = lv.style_t()
style_sem1_cont_1_main_main_default.init()
style_sem1_cont_1_main_main_default.set_radius(0)
style_sem1_cont_1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_sem1_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_sem1_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_cont_1_main_main_default.set_bg_opa(255)
style_sem1_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_cont_1_main_main_default.set_border_width(2)
style_sem1_cont_1_main_main_default.set_border_opa(0)
style_sem1_cont_1_main_main_default.set_pad_left(0)
style_sem1_cont_1_main_main_default.set_pad_right(0)
style_sem1_cont_1_main_main_default.set_pad_top(0)
style_sem1_cont_1_main_main_default.set_pad_bottom(0)

# add style for SEM1_cont_1
SEM1_cont_1.add_style(style_sem1_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_para
SEM1_para = lv.dropdown(SEM1)
SEM1_para.set_pos(int(10),int(130))
SEM1_para.set_size(130,30)
SEM1_para.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_para.set_options("Select paramenter\nP\nI\nD\nSpeed\nFoc\nPlace")
SEM1_para.set_symbol(None)

SEM1_para_list = SEM1_para.get_list()
# create style style_sem1_para_extra_list_selected_checked
style_sem1_para_extra_list_selected_checked = lv.style_t()
style_sem1_para_extra_list_selected_checked.init()
style_sem1_para_extra_list_selected_checked.set_radius(3)
style_sem1_para_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_sem1_para_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_sem1_para_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_para_extra_list_selected_checked.set_bg_opa(255)
style_sem1_para_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_sem1_para_extra_list_selected_checked.set_border_width(1)
style_sem1_para_extra_list_selected_checked.set_border_opa(255)
style_sem1_para_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sem1_para_extra_list_selected_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_sem1_para_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_para_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for SEM1_para_list
SEM1_para_list.add_style(style_sem1_para_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_sem1_para_extra_list_main_default
style_sem1_para_extra_list_main_default = lv.style_t()
style_sem1_para_extra_list_main_default.init()
style_sem1_para_extra_list_main_default.set_radius(3)
style_sem1_para_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sem1_para_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_sem1_para_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_para_extra_list_main_default.set_bg_opa(255)
style_sem1_para_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_sem1_para_extra_list_main_default.set_border_width(1)
style_sem1_para_extra_list_main_default.set_border_opa(255)
style_sem1_para_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_sem1_para_extra_list_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_sem1_para_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_para_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_para_extra_list_main_default.set_max_height(90)

# add style for SEM1_para_list
SEM1_para_list.add_style(style_sem1_para_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_sem1_para_extra_list_scrollbar_default
style_sem1_para_extra_list_scrollbar_default = lv.style_t()
style_sem1_para_extra_list_scrollbar_default.init()
style_sem1_para_extra_list_scrollbar_default.set_radius(3)
style_sem1_para_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_sem1_para_extra_list_scrollbar_default.set_bg_opa(255)

# add style for SEM1_para_list
SEM1_para_list.add_style(style_sem1_para_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_sem1_para_main_main_default
style_sem1_para_main_main_default = lv.style_t()
style_sem1_para_main_main_default.init()
style_sem1_para_main_main_default.set_radius(3)
style_sem1_para_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sem1_para_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_sem1_para_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_para_main_main_default.set_bg_opa(255)
style_sem1_para_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_sem1_para_main_main_default.set_border_width(1)
style_sem1_para_main_main_default.set_border_opa(255)
style_sem1_para_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_sem1_para_main_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_sem1_para_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_para_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_para_main_main_default.set_pad_left(6)
style_sem1_para_main_main_default.set_pad_right(6)
style_sem1_para_main_main_default.set_pad_top(8)

# add style for SEM1_para
SEM1_para.add_style(style_sem1_para_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_1
SEM1_btn_1 = lv.btn(SEM1)
SEM1_btn_1.set_pos(int(272),int(-2))
SEM1_btn_1.set_size(45,49)
SEM1_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_btn_1_label = lv.label(SEM1_btn_1)
SEM1_btn_1_label.set_text("X")
SEM1_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
SEM1_btn_1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_sem1_btn_1_main_main_default
style_sem1_btn_1_main_main_default = lv.style_t()
style_sem1_btn_1_main_main_default.init()
style_sem1_btn_1_main_main_default.set_radius(5)
style_sem1_btn_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sem1_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_1_main_main_default.set_bg_opa(255)
style_sem1_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_1_main_main_default.set_border_width(0)
style_sem1_btn_1_main_main_default.set_border_opa(255)
style_sem1_btn_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sem1_btn_1_main_main_default.set_text_font(lv.font_montserratMedium_36)
except AttributeError:
    try:
        style_sem1_btn_1_main_main_default.set_text_font(lv.font_montserrat_36)
    except AttributeError:
        style_sem1_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_1
SEM1_btn_1.add_style(style_sem1_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_option
SEM1_option = lv.dropdown(SEM1)
SEM1_option.set_pos(int(10),int(90))
SEM1_option.set_size(130,30)
SEM1_option.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_option.set_options("Select options\nPole\nAngle\nVelocity\nVLimit\nCurrent Limit\nControlmod")
SEM1_option.set_symbol(None)

SEM1_option_list = SEM1_option.get_list()
# create style style_sem1_option_extra_list_selected_checked
style_sem1_option_extra_list_selected_checked = lv.style_t()
style_sem1_option_extra_list_selected_checked.init()
style_sem1_option_extra_list_selected_checked.set_radius(3)
style_sem1_option_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_sem1_option_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_sem1_option_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_option_extra_list_selected_checked.set_bg_opa(255)
style_sem1_option_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_sem1_option_extra_list_selected_checked.set_border_width(1)
style_sem1_option_extra_list_selected_checked.set_border_opa(255)
style_sem1_option_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sem1_option_extra_list_selected_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_sem1_option_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_option_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for SEM1_option_list
SEM1_option_list.add_style(style_sem1_option_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_sem1_option_extra_list_main_default
style_sem1_option_extra_list_main_default = lv.style_t()
style_sem1_option_extra_list_main_default.init()
style_sem1_option_extra_list_main_default.set_radius(3)
style_sem1_option_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sem1_option_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_sem1_option_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_option_extra_list_main_default.set_bg_opa(255)
style_sem1_option_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_sem1_option_extra_list_main_default.set_border_width(1)
style_sem1_option_extra_list_main_default.set_border_opa(255)
style_sem1_option_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_sem1_option_extra_list_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_sem1_option_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_option_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_option_extra_list_main_default.set_max_height(90)

# add style for SEM1_option_list
SEM1_option_list.add_style(style_sem1_option_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_sem1_option_extra_list_scrollbar_default
style_sem1_option_extra_list_scrollbar_default = lv.style_t()
style_sem1_option_extra_list_scrollbar_default.init()
style_sem1_option_extra_list_scrollbar_default.set_radius(3)
style_sem1_option_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_sem1_option_extra_list_scrollbar_default.set_bg_opa(255)

# add style for SEM1_option_list
SEM1_option_list.add_style(style_sem1_option_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_sem1_option_main_main_default
style_sem1_option_main_main_default = lv.style_t()
style_sem1_option_main_main_default.init()
style_sem1_option_main_main_default.set_radius(3)
style_sem1_option_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sem1_option_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_sem1_option_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_option_main_main_default.set_bg_opa(255)
style_sem1_option_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_sem1_option_main_main_default.set_border_width(1)
style_sem1_option_main_main_default.set_border_opa(255)
style_sem1_option_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_sem1_option_main_main_default.set_text_font(lv.font_FontAwesome5_12)
except AttributeError:
    try:
        style_sem1_option_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_option_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_option_main_main_default.set_pad_left(6)
style_sem1_option_main_main_default.set_pad_right(6)
style_sem1_option_main_main_default.set_pad_top(8)

# add style for SEM1_option
SEM1_option.add_style(style_sem1_option_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_motsel
SEM1_motsel = lv.dropdown(SEM1)
SEM1_motsel.set_pos(int(10),int(50))
SEM1_motsel.set_size(130,30)
SEM1_motsel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_motsel.set_options("MOTTOR\nM1\nM2")
SEM1_motsel.set_symbol(None)

SEM1_motsel_list = SEM1_motsel.get_list()
# create style style_sem1_motsel_extra_list_selected_checked
style_sem1_motsel_extra_list_selected_checked = lv.style_t()
style_sem1_motsel_extra_list_selected_checked.init()
style_sem1_motsel_extra_list_selected_checked.set_radius(3)
style_sem1_motsel_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_sem1_motsel_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_sem1_motsel_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_motsel_extra_list_selected_checked.set_bg_opa(255)
style_sem1_motsel_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_sem1_motsel_extra_list_selected_checked.set_border_width(1)
style_sem1_motsel_extra_list_selected_checked.set_border_opa(255)
style_sem1_motsel_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sem1_motsel_extra_list_selected_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_sem1_motsel_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_motsel_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for SEM1_motsel_list
SEM1_motsel_list.add_style(style_sem1_motsel_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_sem1_motsel_extra_list_main_default
style_sem1_motsel_extra_list_main_default = lv.style_t()
style_sem1_motsel_extra_list_main_default.init()
style_sem1_motsel_extra_list_main_default.set_radius(3)
style_sem1_motsel_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sem1_motsel_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_sem1_motsel_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_motsel_extra_list_main_default.set_bg_opa(255)
style_sem1_motsel_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_sem1_motsel_extra_list_main_default.set_border_width(1)
style_sem1_motsel_extra_list_main_default.set_border_opa(255)
style_sem1_motsel_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_sem1_motsel_extra_list_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_sem1_motsel_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_motsel_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_motsel_extra_list_main_default.set_max_height(90)

# add style for SEM1_motsel_list
SEM1_motsel_list.add_style(style_sem1_motsel_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_sem1_motsel_extra_list_scrollbar_default
style_sem1_motsel_extra_list_scrollbar_default = lv.style_t()
style_sem1_motsel_extra_list_scrollbar_default.init()
style_sem1_motsel_extra_list_scrollbar_default.set_radius(3)
style_sem1_motsel_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_sem1_motsel_extra_list_scrollbar_default.set_bg_opa(255)

# add style for SEM1_motsel_list
SEM1_motsel_list.add_style(style_sem1_motsel_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_sem1_motsel_main_main_default
style_sem1_motsel_main_main_default = lv.style_t()
style_sem1_motsel_main_main_default.init()
style_sem1_motsel_main_main_default.set_radius(3)
style_sem1_motsel_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sem1_motsel_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_sem1_motsel_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_motsel_main_main_default.set_bg_opa(255)
style_sem1_motsel_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_sem1_motsel_main_main_default.set_border_width(1)
style_sem1_motsel_main_main_default.set_border_opa(255)
style_sem1_motsel_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_sem1_motsel_main_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_sem1_motsel_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sem1_motsel_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_motsel_main_main_default.set_pad_left(6)
style_sem1_motsel_main_main_default.set_pad_right(6)
style_sem1_motsel_main_main_default.set_pad_top(8)

# add style for SEM1_motsel
SEM1_motsel.add_style(style_sem1_motsel_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_label_1
SEM1_label_1 = lv.label(SEM1)
SEM1_label_1.set_pos(int(164),int(86))
SEM1_label_1.set_size(133,29)
SEM1_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_label_1.set_text("0.00")
SEM1_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_sem1_label_1_main_main_default
style_sem1_label_1_main_main_default = lv.style_t()
style_sem1_label_1_main_main_default.init()
style_sem1_label_1_main_main_default.set_radius(0)
style_sem1_label_1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe6,0xe6))
style_sem1_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_label_1_main_main_default.set_bg_opa(255)
style_sem1_label_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sem1_label_1_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_label_1_main_main_default.set_text_letter_space(2)
style_sem1_label_1_main_main_default.set_text_line_space(0)
style_sem1_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sem1_label_1_main_main_default.set_pad_left(0)
style_sem1_label_1_main_main_default.set_pad_right(0)
style_sem1_label_1_main_main_default.set_pad_top(8)
style_sem1_label_1_main_main_default.set_pad_bottom(0)

# add style for SEM1_label_1
SEM1_label_1.add_style(style_sem1_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_label_2
SEM1_label_2 = lv.label(SEM1)
SEM1_label_2.set_pos(int(4),int(1))
SEM1_label_2.set_size(260,35)
SEM1_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
SEM1_label_2.set_text("Label")
SEM1_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_sem1_label_2_main_main_default
style_sem1_label_2_main_main_default = lv.style_t()
style_sem1_label_2_main_main_default.init()
style_sem1_label_2_main_main_default.set_radius(0)
style_sem1_label_2_main_main_default.set_bg_color(lv.color_make(0x14,0x18,0x1c))
style_sem1_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_label_2_main_main_default.set_bg_opa(255)
style_sem1_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sem1_label_2_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_label_2_main_main_default.set_text_letter_space(2)
style_sem1_label_2_main_main_default.set_text_line_space(0)
style_sem1_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sem1_label_2_main_main_default.set_pad_left(0)
style_sem1_label_2_main_main_default.set_pad_right(0)
style_sem1_label_2_main_main_default.set_pad_top(8)
style_sem1_label_2_main_main_default.set_pad_bottom(0)

# add style for SEM1_label_2
SEM1_label_2.add_style(style_sem1_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create SEM1_btn_17
SEM1_btn_17 = lv.btn(SEM1)
SEM1_btn_17.set_pos(int(164),int(75))
SEM1_btn_17.set_size(140,50)
SEM1_btn_17.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sem1_btn_17_main_main_default
style_sem1_btn_17_main_main_default = lv.style_t()
style_sem1_btn_17_main_main_default.init()
style_sem1_btn_17_main_main_default.set_radius(5)
style_sem1_btn_17_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_17_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_17_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sem1_btn_17_main_main_default.set_bg_opa(0)
style_sem1_btn_17_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sem1_btn_17_main_main_default.set_border_width(0)
style_sem1_btn_17_main_main_default.set_border_opa(255)
style_sem1_btn_17_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sem1_btn_17_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_sem1_btn_17_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sem1_btn_17_main_main_default.set_text_font(lv.font_montserrat_16)
style_sem1_btn_17_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for SEM1_btn_17
SEM1_btn_17.add_style(style_sem1_btn_17_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)



def menu_btn_9_pressed_1_event_cb(e,MAIN):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(MAIN, lv.SCR_LOAD_ANIM.NONE, 100, 100, False)
menu_btn_9.add_event_cb(lambda e: menu_btn_9_pressed_1_event_cb(e,MAIN), lv.EVENT.PRESSED, None)


def OTHERS_btn_1_pressed_1_event_cb(e,menu):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(menu, lv.SCR_LOAD_ANIM.NONE, 500, 100, False)
OTHERS_btn_1.add_event_cb(lambda e: OTHERS_btn_1_pressed_1_event_cb(e,menu), lv.EVENT.PRESSED, None)


def MAIN_btn_1_pressed_1_event_cb(e,menu):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(menu, lv.SCR_LOAD_ANIM.NONE, 500, 100, False)
MAIN_btn_1.add_event_cb(lambda e: MAIN_btn_1_pressed_1_event_cb(e,menu), lv.EVENT.PRESSED, None)


def menu_btn_8_pressed_1_event_cb(e,SEM1):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(SEM1, lv.SCR_LOAD_ANIM.NONE, 100, 100, False)
menu_btn_8.add_event_cb(lambda e: menu_btn_8_pressed_1_event_cb(e,SEM1), lv.EVENT.PRESSED, None)


def menu_btn_7_pressed_1_event_cb(e,WIFI):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(WIFI, lv.SCR_LOAD_ANIM.NONE, 100, 100, False)
menu_btn_7.add_event_cb(lambda e: menu_btn_7_pressed_1_event_cb(e,WIFI), lv.EVENT.PRESSED, None)


def menu_btn_6_pressed_1_event_cb(e,OTHERS):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(OTHERS, lv.SCR_LOAD_ANIM.NONE, 100, 100, False)
menu_btn_6.add_event_cb(lambda e: menu_btn_6_pressed_1_event_cb(e,OTHERS), lv.EVENT.PRESSED, None)



def menu_btn_5_pressed_1_event_cb(e,TYPE):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(TYPE, lv.SCR_LOAD_ANIM.NONE, 500, 100, False)
menu_btn_5.add_event_cb(lambda e: menu_btn_5_pressed_1_event_cb(e,TYPE), lv.EVENT.PRESSED, None)


def TYPE_RM1M2_pressed_1_event_cb(e,TYPE_TM1M2):
    src = e.get_target()
    code = e.get_code()
    TYPE_TM1M2_event_move_x = lv.anim_t()
    TYPE_TM1M2_event_move_x.init()
    TYPE_TM1M2_event_move_x.set_var(TYPE_TM1M2)
    TYPE_TM1M2_event_move_x.set_values(TYPE_TM1M2.get_x(), 10)
    TYPE_TM1M2_event_move_x.set_time(2)
    TYPE_TM1M2_event_move_x.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM1M2_event_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(TYPE_TM1M2,val))
    lv.anim_t.start(TYPE_TM1M2_event_move_x)
    TYPE_TM1M2_event_move_y = lv.anim_t()
    TYPE_TM1M2_event_move_y.init()
    TYPE_TM1M2_event_move_y.set_var(TYPE_TM1M2)
    TYPE_TM1M2_event_move_y.set_values(TYPE_TM1M2.get_y(), 40)
    TYPE_TM1M2_event_move_y.set_time(2)
    TYPE_TM1M2_event_move_y.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM1M2_event_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(TYPE_TM1M2,val))
    lv.anim_t.start(TYPE_TM1M2_event_move_y)
TYPE_RM1M2.add_event_cb(lambda e: TYPE_RM1M2_pressed_1_event_cb(e,TYPE_TM1M2), lv.EVENT.PRESSED, None)


def TYPE_btn_5_pressed_1_event_cb(e,TYPE_TDRV):
    src = e.get_target()
    code = e.get_code()
    TYPE_TDRV_event_move_x = lv.anim_t()
    TYPE_TDRV_event_move_x.init()
    TYPE_TDRV_event_move_x.set_var(TYPE_TDRV)
    TYPE_TDRV_event_move_x.set_values(TYPE_TDRV.get_x(), 320)
    TYPE_TDRV_event_move_x.set_time(2)
    TYPE_TDRV_event_move_x.set_path_cb(lv.anim_t.path_linear)
    TYPE_TDRV_event_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(TYPE_TDRV,val))
    lv.anim_t.start(TYPE_TDRV_event_move_x)
    TYPE_TDRV_event_move_y = lv.anim_t()
    TYPE_TDRV_event_move_y.init()
    TYPE_TDRV_event_move_y.set_var(TYPE_TDRV)
    TYPE_TDRV_event_move_y.set_values(TYPE_TDRV.get_y(), 100)
    TYPE_TDRV_event_move_y.set_time(2)
    TYPE_TDRV_event_move_y.set_path_cb(lv.anim_t.path_linear)
    TYPE_TDRV_event_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(TYPE_TDRV,val))
    lv.anim_t.start(TYPE_TDRV_event_move_y)
TYPE_btn_5.add_event_cb(lambda e: TYPE_btn_5_pressed_1_event_cb(e,TYPE_TDRV), lv.EVENT.PRESSED, None)



def TYPE_btn_4_pressed_1_event_cb(e,TYPE_TM1M2):
    src = e.get_target()
    code = e.get_code()
    TYPE_TM1M2_event_move_x = lv.anim_t()
    TYPE_TM1M2_event_move_x.init()
    TYPE_TM1M2_event_move_x.set_var(TYPE_TM1M2)
    TYPE_TM1M2_event_move_x.set_values(TYPE_TM1M2.get_x(), -305)
    TYPE_TM1M2_event_move_x.set_time(2)
    TYPE_TM1M2_event_move_x.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM1M2_event_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(TYPE_TM1M2,val))
    lv.anim_t.start(TYPE_TM1M2_event_move_x)
    TYPE_TM1M2_event_move_y = lv.anim_t()
    TYPE_TM1M2_event_move_y.init()
    TYPE_TM1M2_event_move_y.set_var(TYPE_TM1M2)
    TYPE_TM1M2_event_move_y.set_values(TYPE_TM1M2.get_y(), 40)
    TYPE_TM1M2_event_move_y.set_time(2)
    TYPE_TM1M2_event_move_y.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM1M2_event_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(TYPE_TM1M2,val))
    lv.anim_t.start(TYPE_TM1M2_event_move_y)
TYPE_btn_4.add_event_cb(lambda e: TYPE_btn_4_pressed_1_event_cb(e,TYPE_TM1M2), lv.EVENT.PRESSED, None)


def TYPE_btn_3_pressed_1_event_cb(e,TYPE_TM2):
    src = e.get_target()
    code = e.get_code()
    TYPE_TM2_event_move_x = lv.anim_t()
    TYPE_TM2_event_move_x.init()
    TYPE_TM2_event_move_x.set_var(TYPE_TM2)
    TYPE_TM2_event_move_x.set_values(TYPE_TM2.get_x(), 320)
    TYPE_TM2_event_move_x.set_time(2)
    TYPE_TM2_event_move_x.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM2_event_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(TYPE_TM2,val))
    lv.anim_t.start(TYPE_TM2_event_move_x)
    TYPE_TM2_event_move_y = lv.anim_t()
    TYPE_TM2_event_move_y.init()
    TYPE_TM2_event_move_y.set_var(TYPE_TM2)
    TYPE_TM2_event_move_y.set_values(TYPE_TM2.get_y(), 100)
    TYPE_TM2_event_move_y.set_time(2)
    TYPE_TM2_event_move_y.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM2_event_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(TYPE_TM2,val))
    lv.anim_t.start(TYPE_TM2_event_move_y)
TYPE_btn_3.add_event_cb(lambda e: TYPE_btn_3_pressed_1_event_cb(e,TYPE_TM2), lv.EVENT.PRESSED, None)



def TYPE_btn_2_pressed_1_event_cb(e,TYPE_TM1):
    src = e.get_target()
    code = e.get_code()
    TYPE_TM1_event_move_x = lv.anim_t()
    TYPE_TM1_event_move_x.init()
    TYPE_TM1_event_move_x.set_var(TYPE_TM1)
    TYPE_TM1_event_move_x.set_values(TYPE_TM1.get_x(), -305)
    TYPE_TM1_event_move_x.set_time(2)
    TYPE_TM1_event_move_x.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM1_event_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(TYPE_TM1,val))
    lv.anim_t.start(TYPE_TM1_event_move_x)
    TYPE_TM1_event_move_y = lv.anim_t()
    TYPE_TM1_event_move_y.init()
    TYPE_TM1_event_move_y.set_var(TYPE_TM1)
    TYPE_TM1_event_move_y.set_values(TYPE_TM1.get_y(), 100)
    TYPE_TM1_event_move_y.set_time(2)
    TYPE_TM1_event_move_y.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM1_event_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(TYPE_TM1,val))
    lv.anim_t.start(TYPE_TM1_event_move_y)
TYPE_btn_2.add_event_cb(lambda e: TYPE_btn_2_pressed_1_event_cb(e,TYPE_TM1), lv.EVENT.PRESSED, None)



def TYPE_btn_1_pressed_1_event_cb(e,menu):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(menu, lv.SCR_LOAD_ANIM.NONE, 500, 100, False)
TYPE_btn_1.add_event_cb(lambda e: TYPE_btn_1_pressed_1_event_cb(e,menu), lv.EVENT.PRESSED, None)


def WIFI_btn_1_pressed_1_event_cb(e,menu):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(menu, lv.SCR_LOAD_ANIM.NONE, 100, 100, False)
WIFI_btn_1.add_event_cb(lambda e: WIFI_btn_1_pressed_1_event_cb(e,menu), lv.EVENT.PRESSED, None)





def SEM1_btn_16_pressed_1_event_cb(e,SEM1_cont_1):
    src = e.get_target()
    code = e.get_code()
    SEM1_cont_1_event_move_x = lv.anim_t()
    SEM1_cont_1_event_move_x.init()
    SEM1_cont_1_event_move_x.set_var(SEM1_cont_1)
    SEM1_cont_1_event_move_x.set_values(SEM1_cont_1.get_x(), -330)
    SEM1_cont_1_event_move_x.set_time(2)
    SEM1_cont_1_event_move_x.set_path_cb(lv.anim_t.path_linear)
    SEM1_cont_1_event_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(SEM1_cont_1,val))
    lv.anim_t.start(SEM1_cont_1_event_move_x)
    SEM1_cont_1_event_move_y = lv.anim_t()
    SEM1_cont_1_event_move_y.init()
    SEM1_cont_1_event_move_y.set_var(SEM1_cont_1)
    SEM1_cont_1_event_move_y.set_values(SEM1_cont_1.get_y(), 230)
    SEM1_cont_1_event_move_y.set_time(2)
    SEM1_cont_1_event_move_y.set_path_cb(lv.anim_t.path_linear)
    SEM1_cont_1_event_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(SEM1_cont_1,val))
    lv.anim_t.start(SEM1_cont_1_event_move_y)
SEM1_btn_16.add_event_cb(lambda e: SEM1_btn_16_pressed_1_event_cb(e,SEM1_cont_1), lv.EVENT.PRESSED, None)



def SEM1_btn_17_pressed_1_event_cb(e,SEM1_cont_1):
    src = e.get_target()
    code = e.get_code()
    SEM1_cont_1_event_move_x = lv.anim_t()
    SEM1_cont_1_event_move_x.init()
    SEM1_cont_1_event_move_x.set_var(SEM1_cont_1)
    SEM1_cont_1_event_move_x.set_values(SEM1_cont_1.get_x(), 0)
    SEM1_cont_1_event_move_x.set_time(2)
    SEM1_cont_1_event_move_x.set_path_cb(lv.anim_t.path_linear)
    SEM1_cont_1_event_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(SEM1_cont_1,val))
    lv.anim_t.start(SEM1_cont_1_event_move_x)
    SEM1_cont_1_event_move_y = lv.anim_t()
    SEM1_cont_1_event_move_y.init()
    SEM1_cont_1_event_move_y.set_var(SEM1_cont_1)
    SEM1_cont_1_event_move_y.set_values(SEM1_cont_1.get_y(), 230)
    SEM1_cont_1_event_move_y.set_time(2)
    SEM1_cont_1_event_move_y.set_path_cb(lv.anim_t.path_linear)
    SEM1_cont_1_event_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(SEM1_cont_1,val))
    lv.anim_t.start(SEM1_cont_1_event_move_y)
SEM1_btn_17.add_event_cb(lambda e: SEM1_btn_17_pressed_1_event_cb(e,SEM1_cont_1), lv.EVENT.PRESSED, None)


def TYPE_RDRV_pressed_1_event_cb(e,TYPE_TDRV):
    src = e.get_target()
    code = e.get_code()
    TYPE_TDRV_event_move_x = lv.anim_t()
    TYPE_TDRV_event_move_x.init()
    TYPE_TDRV_event_move_x.set_var(TYPE_TDRV)
    TYPE_TDRV_event_move_x.set_values(TYPE_TDRV.get_x(), 10)
    TYPE_TDRV_event_move_x.set_time(2)
    TYPE_TDRV_event_move_x.set_path_cb(lv.anim_t.path_linear)
    TYPE_TDRV_event_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(TYPE_TDRV,val))
    lv.anim_t.start(TYPE_TDRV_event_move_x)
    TYPE_TDRV_event_move_y = lv.anim_t()
    TYPE_TDRV_event_move_y.init()
    TYPE_TDRV_event_move_y.set_var(TYPE_TDRV)
    TYPE_TDRV_event_move_y.set_values(TYPE_TDRV.get_y(), 94)
    TYPE_TDRV_event_move_y.set_time(2)
    TYPE_TDRV_event_move_y.set_path_cb(lv.anim_t.path_linear)
    TYPE_TDRV_event_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(TYPE_TDRV,val))
    lv.anim_t.start(TYPE_TDRV_event_move_y)
TYPE_RDRV.add_event_cb(lambda e: TYPE_RDRV_pressed_1_event_cb(e,TYPE_TDRV), lv.EVENT.PRESSED, None)


def SEM1_btn_1_pressed_1_event_cb(e,menu):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(menu, lv.SCR_LOAD_ANIM.NONE, 100, 100, False)
SEM1_btn_1.add_event_cb(lambda e: SEM1_btn_1_pressed_1_event_cb(e,menu), lv.EVENT.PRESSED, None)







def menu_pressed_1_event_cb(e,MAIN):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(MAIN, lv.SCR_LOAD_ANIM.OVER_TOP, 500, 100, False)
menu.add_event_cb(lambda e: menu_pressed_1_event_cb(e,MAIN), lv.EVENT.PRESSED, None)








def SET_SM1_pressed_1_event_cb(e,SEM1):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(SEM1, lv.SCR_LOAD_ANIM.NONE, 100, 100, False)
SET_SM1.add_event_cb(lambda e: SET_SM1_pressed_1_event_cb(e,SEM1), lv.EVENT.PRESSED, None)


def SET_btn_3_pressed_1_event_cb(e,menu):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(menu, lv.SCR_LOAD_ANIM.NONE, 500, 100, False)
SET_btn_3.add_event_cb(lambda e: SET_btn_3_pressed_1_event_cb(e,menu), lv.EVENT.PRESSED, None)


def TYPE_RM1_clicked_1_event_cb(e,TYPE_TM1):
    src = e.get_target()
    code = e.get_code()
    TYPE_TM1_event_move_x = lv.anim_t()
    TYPE_TM1_event_move_x.init()
    TYPE_TM1_event_move_x.set_var(TYPE_TM1)
    TYPE_TM1_event_move_x.set_values(TYPE_TM1.get_x(), 10)
    TYPE_TM1_event_move_x.set_time(2)
    TYPE_TM1_event_move_x.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM1_event_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(TYPE_TM1,val))
    lv.anim_t.start(TYPE_TM1_event_move_x)
    TYPE_TM1_event_move_y = lv.anim_t()
    TYPE_TM1_event_move_y.init()
    TYPE_TM1_event_move_y.set_var(TYPE_TM1)
    TYPE_TM1_event_move_y.set_values(TYPE_TM1.get_y(), 100)
    TYPE_TM1_event_move_y.set_time(2)
    TYPE_TM1_event_move_y.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM1_event_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(TYPE_TM1,val))
    lv.anim_t.start(TYPE_TM1_event_move_y)
TYPE_RM1.add_event_cb(lambda e: TYPE_RM1_clicked_1_event_cb(e,TYPE_TM1), lv.EVENT.CLICKED, None)


def TYPE_RM2_pressed_1_event_cb(e,TYPE_TM2):
    src = e.get_target()
    code = e.get_code()
    TYPE_TM2_event_move_x = lv.anim_t()
    TYPE_TM2_event_move_x.init()
    TYPE_TM2_event_move_x.set_var(TYPE_TM2)
    TYPE_TM2_event_move_x.set_values(TYPE_TM2.get_x(), 10)
    TYPE_TM2_event_move_x.set_time(2)
    TYPE_TM2_event_move_x.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM2_event_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(TYPE_TM2,val))
    lv.anim_t.start(TYPE_TM2_event_move_x)
    TYPE_TM2_event_move_y = lv.anim_t()
    TYPE_TM2_event_move_y.init()
    TYPE_TM2_event_move_y.set_var(TYPE_TM2)
    TYPE_TM2_event_move_y.set_values(TYPE_TM2.get_y(), 94)
    TYPE_TM2_event_move_y.set_time(2)
    TYPE_TM2_event_move_y.set_path_cb(lv.anim_t.path_linear)
    TYPE_TM2_event_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(TYPE_TM2,val))
    lv.anim_t.start(TYPE_TM2_event_move_y)
TYPE_RM2.add_event_cb(lambda e: TYPE_RM2_pressed_1_event_cb(e,TYPE_TM2), lv.EVENT.PRESSED, None)



# content from custom.py

# Load the default screen
lv.scr_load(MAIN)

while SDL.check():
    time.sleep_ms(5)
