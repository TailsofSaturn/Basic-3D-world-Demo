#include "objects.h"
#include "meshes.h"

//Global Variables for moving around in 3D
jo_camera          cam;
jo_palette         image_pal;


int             cam_pos[3] = {0,-600,0};
int           cam_angle[3] = {0,0,0};
int           cam_tar[3] = {0,-600,1};
int 			dcpos[3]; 


// Print information to screen
void	debug_menu(void)
{
		    //  Write Text to Screen
    jo_printf(0, 0, "              *Test Game*              ");
    jo_printf(0, 3, "Camera Angle: %4d Degrees", cam_angle[1]);
    jo_printf(0, 4, "Camera Position:%7d,%7d,%7d ", cam_pos[0], cam_pos[1], cam_pos[2]);
    jo_printf(0, 5, "Camera Target:  %7d,%7d,%7d ", cam_tar[0], cam_tar[1], cam_tar[2]);
	jo_printf(0, 6, "Camera Fixed Position:%7d,%7d,%7d ", dcpos[0], dcpos[1], dcpos[2]);
    jo_printf(0, 27, "Polygons: %7d ", jo_3d_get_polygon_count());
    jo_printf(0, 28, "Vertices: %7d ", jo_3d_get_vertices_count());
    jo_printf(0, 29, "Displayed Polygons: %7d ", jo_3d_get_displayed_polygon_count());
	}





// Function to draw all objects
void draw_objects(void) {
	

  // Infinite Plane
    jo_3d_push_matrix();
	{
		jo_3d_rotate_matrix(90, 0, 0);
		jo_3d_translate_matrix(0, 0, 0);
		jo_background_3d_plane_a_draw(true);
	}
	jo_3d_pop_matrix();

//Call function for each mesh, array and number of objects
draw_mesh(house, houses, 16);
draw_mesh(mound, mounds, 3);
draw_mesh(cask, casks, 4);
draw_mesh(tos, toss, 1);
}

// Palette for infinite plane
jo_palette          *my_tga_palette_handling(void)
{
     jo_create_palette(&image_pal);
    return (&image_pal);
}

//Draw the infinite plane
void                init_3d_planes(void)
{
    jo_img_8bits    img;

    jo_core_tv_off();

    jo_enable_background_3d_plane(JO_COLOR_Black);

    // FLOOR
    img.data = JO_NULL;
    jo_tga_8bits_loader(&img, JO_ROOT_DIR, "COBFLR.TGA", JO_COLOR_Transparent);
	
    jo_background_3d_plane_a_img(&img, image_pal.id, true, true);
    jo_free_img(&img);
	jo_core_tv_on();
}