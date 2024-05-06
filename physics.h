//Collision

//Wall collission. Function set boundaries that cannot be traversed based on the obj arrays in objects.h

void	wall_collission(obj walls[], int numobj){
	
int i;
for(i=0; i < numobj; i++)
{
	
if (((cam_pos[0]) >= (walls[i].x - walls[i].s)) && ((cam_pos[0]) <= (walls[i].x - (walls[i].s-10))) && ((cam_pos[2]) <= ((walls[i].z)+(walls[i].s-10))) && ((cam_pos[2]) >= ((walls[i].z)-(walls[i].s-10))))
{dcpos[0] = ((walls[i]).x - walls[i].s)<<4;}

if (((cam_pos[0]) <= ((walls[i]).x + walls[i].s)) && ((cam_pos[0]) >= ((walls[i].x) + (walls[i].s-10))) && ((cam_pos[2]) <= ((walls[i].z)+(walls[i].s-10))) && ((cam_pos[2]) >= ((walls[i].z)-(walls[i].s-10))))
{dcpos[0] = ((walls[i]).x + walls[i].s)<<4;}

if (((cam_pos[2]) <= ((walls[i]).z + walls[i].s)) && ((cam_pos[2]) >= ((walls[i].z) + (walls[i].s-10))) && ((cam_pos[0]) <= ((walls[i].x)+(walls[i].s-10))) && ((cam_pos[0]) >= ((walls[i].x)-(walls[i].s-10))))
{dcpos[2] = ((walls[i]).z + walls[i].s)<<4;}

if (((cam_pos[2]) >= ((walls[i]).z - walls[i].s)) && ((cam_pos[2]) <= ((walls[i].z) - (walls[i].s-10))) && ((cam_pos[0]) <= ((walls[i].x)+(walls[i].s-10))) && ((cam_pos[0]) >= ((walls[i].x)-(walls[i].s-10))))
{dcpos[2] = ((walls[i]).z - walls[i].s)<<4;}
}
}


//Terrain collission. Function set new floor height when you walk over small obstacles based on the obj arrays in objects.h

void	terrain_collission(obj mounds[], int numobj){
	
	//Bound Cam height
	int flrmin = -1000;
	if (dcpos[1] > flrmin)
	dcpos[1] = flrmin;
	
	int i;
for(i=0; i < 3; i++)
if (((cam_pos[0]) >= (mounds[i].x - 25)) && ((cam_pos[0]) <= (mounds[i].x + 25)) && ((cam_pos[2]) <= ((mounds[i].z)+25)) && ((cam_pos[2]) >= ((mounds[i].z)-25)))
{	

	flrmin -= 250;
	if (dcpos[1] > flrmin)
	dcpos[1] = flrmin;
}

}

