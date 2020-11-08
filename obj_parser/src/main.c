#include <stdio.h>
#include "model.h"
#include "timer.h"
#include "texture.h"


int main(int argc, char* argv[])
{
    timer_start();

    Model model;
    Regular regular;
    BoundingBox bounding_box;
    TextureBox texture_box;
    Texture texture;

    load_model("OBJ/10050_RattleSnake_v4_L3.obj", &model, &regular, &bounding_box, &texture_box);
    print_model_info(&model);
    print_bounding_box(&bounding_box);
    print_texture_box(&texture_box);
    load_texture("OBJ/12248_Bird_v1_diff.jpg",&texture);
    timer_finish();
    return 0;
}
