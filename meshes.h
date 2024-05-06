//Declare mesh pointers

jo_3d_mesh         *house;
jo_3d_mesh         *mound;
jo_3d_mesh         *cask;
jo_3d_mesh         *tos;



// Function to draw 3D objects
void	draw_mesh(jo_3d_mesh *mesh, obj position[], int numobj){


int i;
for(i=0; i < numobj; i++){
   
jo_3d_push_matrix();
    {
	
	jo_3d_translate_matrix(position[i].x, position[i].y, position[i].z);
	jo_3d_rotate_matrix(position[i].rx, position[i].ry, position[i].rz);
   
    jo_3d_mesh_draw(mesh);
    }
    jo_3d_pop_matrix();

}
}

// Vertices of Houses
	
	house_verts[44][3] = {
	{-125, -250, -125}, 
	{0, -250, -125},
	{0, -125, -125},
	{-125, -125, -125},
	
	
	
	{0, -250, -125},
	{125, -250, -125},
	{125, -125, -125},
	{0, -125, -125},
	
	
	
	{0, -125, -125},
	{125, -125, -125},
	{125, 0, -125},
	{0, 0, -125},
	
	
	{-125, -125, -125},
	{0, -125, -125},
	{0, 0, -125},
	{-125, 0, -125},
	
	
	{-125, -250, 125}, 
	{125, -250, 125},
	{125, 0, 125},
	{-125, 0, 125},
	
	{125, -250, -125},
	{125, -250, 125},
	{125, 0, 125},
	{125, 0, -125},
	
	{-125, -250, -125},
	{-125, -250, 125},
	{-125, 0, 125},
	{-125, 0, -125},
	
	{-125, -375, 0},
	{125, -375, 0},
	{125, -250, -125},
	{-125, -250, -125}, 
	
	{-125, -375, 0},
	{125, -375, 0},
	{125, -250, 125},
	{-125, -250, 125},
	
	{-125, -375, 0},
	{-125, -375, 0},
	{-125, -250, -125},
	{-125, -250, 125},
	
	{125, -375, 0},
	{125, -375, 0},
	{125, -250, -125},
	{125, -250, 125}
	};
	
	
	//Function to create house object
		void create_house(void)
	{
		
			//vertices
	house = jo_3d_create_mesh_from_vertices(11, &house_verts);
	jo_3d_set_mesh_polygon_texture(house, 2, 0);
	jo_3d_set_mesh_polygon_texture(house, 3, 1);
	jo_3d_set_mesh_polygon_texture(house, 1, 2);
	jo_3d_set_mesh_polygon_texture(house, 0, 3);
	jo_3d_set_mesh_polygon_texture(house, 4, 4);
	jo_3d_set_mesh_polygon_texture(house, 4, 5);
	jo_3d_set_mesh_polygon_texture(house, 4, 6);
	jo_3d_set_mesh_polygon_texture(house, 5, 7);
	jo_3d_set_mesh_polygon_texture(house, 5, 8);
	jo_3d_set_mesh_polygon_texture(house, 4, 9);
	jo_3d_set_mesh_polygon_texture(house, 4, 10);
	jo_3d_set_mesh_screen_doors(house, false);
	for (Uint32 i = 0; i < 11; ++i){
       	JO_ADD_FLAG(house->data.attbl[i].atrb, HSSon);
	}
	
	}
	
	
	


// Vertices of mounds

mound_verts[16][3] = {
	
	{-25, 0, 25},
	{0, 0, 25},
	{0, -25, 0},
	{-25, 0, 0},
	
	{-25, 0, 0},
	{0, -25, 0},
	{0, 0, -25},
	{-25, 0, -25},
	
	{0, 0, 25},
	{25, 0, 25},
	{25, 0, 0},
	{0, -25, 0},
	
	{0, -25, 0},
	{25, 0, 0},
	{25, 0, -25},
	{0, 0, -25}
};


//Function to create mound object
	void create_mound(void)
	{
		
	mound = jo_3d_create_mesh_from_vertices(4, &mound_verts);
	jo_3d_set_mesh_polygon_texture(mound, 6, 0);
	jo_3d_set_mesh_polygon_texture(mound, 6, 1);
	jo_3d_set_mesh_polygon_texture(mound, 6, 2);
	jo_3d_set_mesh_polygon_texture(mound, 6, 3);
	jo_3d_set_mesh_screen_doors(mound, false);
	for (Uint32 i = 0; i < 4; ++i){
       	JO_ADD_FLAG(house->data.attbl[i].atrb, HSSon);
	}
	
	}
	

// Vertices of Barrells

cask_verts[36][3] = {
{-20, -30, -20},
{20, -30, -20},
{12, 0, -12},
{-12, 0, -12},

{-20, -30, 20},
{-20, -30, -20},
{-12, 0, -12},
{-12, 0, 12},

{20, -30, -20},
{20, -30, 20},
{12, 0, 12},
{12, 0, -12},

{-20, -30, 20},
{20, -30, 20},
{12, 0, 12},
{-12, 0, 12},

//
{-12, -60, -12},
{12, -60, -12},
{20, -30, -20},
{-20, -30, -20},

{-12, -60, 12},
{-12, -60, -12},
{-20, -30, -20},
{-20, -30, 20},

{12, -60, -12},
{12, -60, 12},
{20, -30, 20},
{20, -30, -20},

{-12, -60, 12},
{12, -60, 12},
{20, -30, 20},
{-20, -30, 20},

{-12, -60, -12},
{12, -60, -12},
{12, -60, 12},
{-12, -60, 12}


};


// Function to create barrells

	void create_cask(void)
	{
		
			//vertices
	cask = jo_3d_create_mesh_from_vertices(9, &cask_verts);
	jo_3d_set_mesh_polygon_texture(cask, 0, 0);
	jo_3d_set_mesh_polygon_texture(cask, 0, 1);
	jo_3d_set_mesh_polygon_texture(cask, 0, 2);
	jo_3d_set_mesh_polygon_texture(cask, 0, 3);
	jo_3d_set_mesh_polygon_texture(cask, 0, 4);
	jo_3d_set_mesh_polygon_texture(cask, 0, 5);
	jo_3d_set_mesh_polygon_texture(cask, 0, 6);
	jo_3d_set_mesh_polygon_texture(cask, 0, 7);
	jo_3d_set_mesh_polygon_texture(cask, 0, 8); 
	//Note, the texture is actually the door texture from the house, but it looks OK
	jo_3d_set_mesh_screen_doors(cask, false);
	for (Uint32 i = 0; i < 9; ++i){
       	JO_ADD_FLAG(house->data.attbl[i].atrb, HSSon);  // High speed scaling as textures are large
	}
	}
	
	
tos_verts [4][3] = {
	{-200, -400, 700},
	{200, -400, 700},
	{200, 0, 700},
	{-200, 0, 700}
};

// Function to create TOS billboard

	void create_tos(void)
	{
		
			//vertices
	tos = jo_3d_create_mesh_from_vertices(1, &tos_verts);
	jo_3d_set_mesh_polygon_texture(tos, 7, 0);
	jo_3d_set_mesh_screen_doors(tos, false);
	for (Uint32 i = 0; i < 1; ++i){
       	JO_ADD_FLAG(house->data.attbl[i].atrb, HSSon);  // High speed scaling as textures are large
	}
	}

	
	

