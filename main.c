#include "lvgl.h"

int main(int argc, char *argv[])
{
    /*LittlevGL init*/
    lv_init();
    lv_disp_t *disp=lv_linux_fbdev_create();
    lv_linux_fbdev_set_file(disp,"/dev/fb0");

    lv_obj_t * arc_r = lv_arc_create(disp->sys_layer);
    lv_obj_set_size(arc_r, 100, 100);
    lv_arc_set_rotation(arc_r, 135);
    lv_arc_set_bg_angles(arc_r, 0, 270);
    lv_arc_set_value(arc_r, 30);
    lv_obj_center(arc_r);

    while (1) {
        lv_timer_handler();
        lv_tick_inc(100);      /*Tell LVGL that 10 milliseconds were elapsed*/
        usleep(1000*100);//100ms 心跳
    }
}
