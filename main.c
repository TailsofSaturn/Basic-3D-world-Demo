/*
** Jo Sega Saturn Engine
** Copyright (c) 2012-2017, Johannes Fetz (johannesfetz@gmail.com)
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the Johannes Fetz nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL Johannes Fetz BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <jo/jo.h>
#include "graphics.h"
#include "controls.h"
#include "physics.h"






//Initialise everything
void initialise(void)
{
	jo_core_init(JO_COLOR_Black);
	jo_3d_camera_init(&cam);
	
	// load textures
    jo_sprite_add_tga(JO_ROOT_DIR, "DOOR.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "WINDOW.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "WALL.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "WINDOW2.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "BIGWALL.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "ROOF.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "MOUNTAIN.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "TOS.TGA", JO_COLOR_Transparent);
	jo_set_tga_palette_handling(my_tga_palette_handling);
	init_3d_planes();
    
	// Would have been better to create a generic function to create objects, but individually made texturing easier
	create_house();
	create_mound();
	create_cask();
	create_tos();
	}


//Draw everything and run controls and physics
void			    my_draw(void)
{
    
    jo_3d_camera_look_at(&cam);
    jo_3d_camera_set_viewpoint(&cam,cam_pos[0],cam_pos[1],cam_pos[2]);
    jo_3d_camera_set_target(&cam,cam_tar[0],cam_tar[1],cam_tar[2]);
	controls();
	wall_collission(houses, 16);
	wall_collission(casks, 4);
	terrain_collission(mounds, 3);
	draw_objects();
	//debug_menu();
	}



void			jo_main(void)
{
	initialise();
	jo_core_add_callback(my_draw);
	slDynamicFrame(ON); //makes nearby objects not dissapear, thanks Ponut :)
	jo_core_run();
}


/*
** END OF FILE
*/
