#include <stdio.h>
#include "model.h"
#include "texture_verticles.h"
#include "texture.h"
#include "normal_verticles.h"
#include "time.h"


int main(int argc, char* argv[])
{
    begin();
    Texture texture;
    Model model;
    Vertex vertex;
    TextureVertex texturevertex;
    NormalVertex normalvertex;

    load_model("OBJ/cube.obj", &model);
    print_model_info(&model);
    print_bounding_box(&model,&vertex);
    texture_coords(&texturevertex);
    normal_coords(&normalvertex);
    load_texture("OBJ/12248_Bird_v1_diff.jpg",&texture);
    end();
    return 0;
}
