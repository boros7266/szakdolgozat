#include <stdio.h>
#include "functions.h"



int main(void){
	//Program Start
	begin();
	//OBJ Reading
	OBJ_LOAD();
	//texture count
	texture_count();
	//texture size
	findSize();
	//Program Stop
	end();
return 0;
}
