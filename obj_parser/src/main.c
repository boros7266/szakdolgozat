#include <stdio.h>
#include "model.h"
#include "timer.h"
#include "texture.h"
#include "bounding_box.h"
#include "texture_box.h"


int main(int argc, char* argv[])
{
    start_timer();

    Model model;
    Regular regular;
    BoundingBox bounding_box;
    TextureBox texture_box;
    Texture texture;

    load_model("OBJ/10050_RattleSnake_v4_L3.obj", &model, &regular);
    print_model_info(&model);
    calc_bounding_box(&model,&bounding_box);
    calc_texture_box(&model,&texture_box);
    print_bounding_box(&bounding_box);
    print_texture_box(&texture_box);
    load_texture("OBJ/12248_Bird_v1_diff.jpg",&texture);
    calc_timer_elapsed_time();
    return 0;
}
