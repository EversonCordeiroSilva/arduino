#include "LVGLFunctions.h"

lv_obj_t *label;

void setupLVGL()
{
  scr_lvgl_init();

  // Definir cor de fundo para azul
  lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x003a57), LV_PART_MAIN);

  // Criar um rótulo e definir texto em branco
  label = lv_label_create(lv_scr_act());
  lv_label_set_text(label, "Welcome!");
  lv_obj_set_style_text_color(label, lv_color_hex(0xffffff), LV_PART_MAIN);
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
  setRotation(2);
}

void loopLVGL()
{
  lv_timer_handler();
  vTaskDelay(5);
}
void updateLabelText(String text)
{
  lv_label_set_text(label, text.c_str()); // Atualizar o texto do rótulo 
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0); // Reposicionar o rótulo no centro
}